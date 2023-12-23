# File: HTTPClient.h
#
# Example: simple client to broadcast data to clients over HTTP protocol via a HTTPServer.h instance
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
import("dpdllib.h")


#main
string host = "127.0.0.1"
int port = 6666
int PTR_CLIENT = 0

# Change the client id to run multiple clients and receive data
string CLIENT_ID = "34523527"

println("starting client...")
int status_client = DPDLLIB_createClient(PTR_CLIENT, host, port)
println("server started with status: " + status_client)

int counter = 0
string data = "null"
int s = dpdlFalse
while(dpdlTrue)
	println("sending data...")
	s = DPDLLIB_sendClientData(PTR_CLIENT, "data:" + counter + ":" + CLIENT_ID)
	println("status: "+ s)
	sleep(1000)
	println("reading data...")
	data = DPDLLIB_readClientData(PTR_CLIENT)
	if(strlen(data) > 8)
		# we receive only data from other clients, not from our client id
		if(substring(data, strlen(data)-8, strlen(data)) != CLIENT_ID) 
			println("data: " + data)
		fi
	fi
	counter = counter + 1
endwhile
