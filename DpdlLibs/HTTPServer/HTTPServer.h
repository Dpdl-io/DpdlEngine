# File: HTTPServer.h
#
# Example: simple server to accept and forward data sent from clients HTTPClient.h to other connected clients,
#		   over HTTP protocol
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
include("dpdllib.h")


#main
string host = "127.0.0.1"
int port = 8023
int PTR_SERVER = 0

println("starting server on port: " + port)
int status = DPDLLIB_createServer(PTR_SERVER, port)
println("server started with status: " + status)
while(dpdlTrue)
	print(".")
	sleep(2000)
endwhile

