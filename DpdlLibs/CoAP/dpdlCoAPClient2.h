# File: dpdlCoAPClient2.h
#
# Example: This script implements a CoAP (Constrained Application Protocol) client, compliant with RFC 7252, that sends
#		   PUT requests to the dpdlCoAPServer.h instance. The script is called within the startClientThread.h and is 
#		   iterated continuously until the thread is terminated.
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#

# call back function for DpdlCoAPResponseHandler
func onRequestFailure(string message)
	println("Failure: " + message)
end

# call back function for DpdlCoAPResponseHandler
func onResponse(string response)
	println("Response: " + response)
	response_counter = response_counter + 1
	println("counter: " + response_counter)
	println("")
end


# main
string coap_uri = "coap://127.0.0.1/Dpdl"

int port = -1 #  use dynamic port
int max_block_size = 0
int verbose = 0

int response_counter = 0
string original_msg = null

println("allocating DpdlCoAPClient..")
object dpdl_coap = loadObj("DpdlCoAPClient", coap_uri, port, max_block_size, verbose)
println("done")
object client
object response_handler

string msg
string msg_header = "DpdlCoAPWorks from client (2)"
int random_nr = 0

if(dpdl_coap != null)
	client = dpdl_coap.getClient()
	client = cast(client) # we make sure it's a DpdlObject
	
	println("registering response handler...")
	response_handler = loadObj("DpdlCoAPResponseHandler", client)
	
	random_nr = randInt(16, 1000)
	random_nr = abs(random_nr)
	msg = msg_header + " " + random_nr
	println("sending PUT request: " + msg)
	dpdl_coap.request(coap_uri, "PUT", "TEXT", msg, response_handler)
	
	println("done")
	# we call the garbage collector at each iteration
	gc()
else
	println("Client initialization failed")
fi
