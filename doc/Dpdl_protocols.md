# Dpdl IoT protocols

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
				
by
**SEE Solutions**
&copy;

IoT is one of the application domains where Dpdl can be used

Dpdl implements various protocols that can be accessed natively or via a higher level Dpdl API.

Currenlty the following protocols are already included and available in Dpdl:

* **Bluetooth** (JSR-82 implementation)
* **CoAP** (Constrained Application Protocol) (IETF standard RFC 7252)


## Bluetooth

Dpdl supports and implements a Bluetooth API via a JSR-82 implementation that can be accessed natively (bluecove) or via the higher level Dpdl API.

The bluetooth api requires a compatible bluetooth stack available on the guest OS.

Currently it works on the following platforms:

* Windows
* Linux (x86_64)
* Raspberry (armV7l)


[Bluetooth Example](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/bluetoothDiscoverySave.h)



## CoAP

Dpdl supports and implements a lightweight CoAP protocol that can be accessed natively (mjCoAP) or via a higher level Dpdl API. 

### Example CoAP server

```python

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

```

### **Example:** CoAP client

```python

string coap_uri = "coap://127.0.0.1/Dpdl"

int port = -1 #  use dynamic port
int max_block_size = 0
int verbose = 0

int response_counter = 0


func onRequestFailure(string message)
	println("Failure: " + message)
end

func onResponse(string response)
	println("Response: " + response)

	response_counter = response_counter + 1
	println("counter: " + response_counter)
	println("")
end


println("starting DpdlCoAPClient..")

object dpdl_coap = new("DpdlCoAPClient", coap_uri, port, max_block_size, verbose)

raise(dpdl_coap, "Error in initializing DpdlCoAPClient")

println("done")

object client
object response_handler

if(dpdl_coap != null)
	client = dpdl_coap.getClient()

	client = cast(client)

	raise(client, "Error: client not initialized correctly")

	println("registering response handler...")
	
	response_handler = new("DpdlCoAPResponseHandler", client)

	println("sending GET request..")

	dpdl_coap.request(coap_uri, "GET", null, null, response_handler)

	println("sending PUT request..")
	
	dpdl_coap.request(coap_uri, "PUT", "TEXT", "Dpdl hello CoAP from client (2)", response_handler)
	
	println("sending GET request..")
	
	dpdl_coap.request(coap_uri, "GET", null, null, response_handler)
	
	#sleep(6000)
		
	println("sending OBSERVE request..")

	dpdl_coap.request(coap_uri, "OBSERVE", null, null, response_handler)
	
	println("done")
else
	println("Client initialization failed")
fi

```






