# File: dpdlCoAPClient.h
#
# Example: This script implements a CoAP (Constrained Application Protocol) client, compliant with RFC 7252, that sends
#		   PUT, GET and OBSERVE requests to the dpdlCoAPServer.h instance, and intecepts the responses in asynchronous way
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
if(dpdl_coap != null)
	client = dpdl_coap.getClient()
	client = cast(client) # we make sure it's a DpdlObject
	
	println("registering response handler...")
	response_handler = loadObj("DpdlCoAPResponseHandler", client)

	println("sending GET request..")
	dpdl_coap.request(coap_uri, "GET", null, null, response_handler)
	
	println("orig: " + original_msg)
	
	println("sending PUT request..")
	dpdl_coap.request(coap_uri, "PUT", "TEXT", "DpdlCoAPWorks from client (1)", response_handler)
	
	println("sending GET request..")
	dpdl_coap.request(coap_uri, "GET", null, null, response_handler)
	
	#sleep(6000)
		
	println("sending OBSERVE request..")
	dpdl_coap.request(coap_uri, "OBSERVE", null, null, response_handler)
	
	println("done")
else
	println("Client initialization failed")
fi
