# File: dpdlCoAPClient.h
#
# Example: This script implements a CoAP (Constrained Application Protocol) server, compliant with RFC 7252, that exposes
#		   defined resources and accepts connections and requests from CoAP clients
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#

int port = 5683
int max_block_size = 0
int verbose = 0
bool write_mode = true

string resource = "/Dpdl"
string resource2 = "/Dpdl/myRes"
string resource_type = "TEXT"
string resource_value = "Hello Dpdl CoAP"

println("starting CoAP server...")

object coap_server = new("DpdlCoAPServer", port, max_block_size, verbose, write_mode, resource, resource_type, resource_value)

bool server_status = coap_server.start()

if(server_status){

	println("server initializing...")

	sleep(1000)

	println("started successfully")

	println("adding resource: " + resource2)

	bool status = coap_server.setResource(resource2, "TEXT", "A.Costa")

	println("status: " + status)

else
	println("Error in starting server")
fi
