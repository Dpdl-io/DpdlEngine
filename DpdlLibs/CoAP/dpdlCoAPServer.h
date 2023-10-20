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

# main
int port = 5683
int max_block_size = 0
int verbose = 0
bool write_mode = true

string resource = "/Dpdl"
string resource2 = "/Dpdl/myRes"
string resource_type = "TEXT"
string resource_value = "Hello Dpdl CoAP"
bool status

println("starting CoAP server...")
object coap_server = loadObj("DpdlCoAPServer", port, max_block_size, verbose, write_mode, resource, resource_type, resource_value)
coap_server.start()
println("started successfully")
# wait for the server to boot
sleep(3000)
println("adding resource: " + resource2)
status = coap_server.setResource(resource2, "TEXT", "A.Costa")
println("status: " + status)
