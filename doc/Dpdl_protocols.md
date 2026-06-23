# Dpdl protocols

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
				
by
**SEE Solutions**
&copy;


Dpdl includes support for some connection protocols that can be accessed either natively or via a higher level Dpdl APIs.

Currently the following protocols are per default included and usable within dpdl code:

* **Bluetooth** (JSR-82 implementation)
* **CoAP** (Constrained Application Protocol) (IETF standard RFC 7252)
* others will follow...



## Bluetooth protocol

Dpdl supports and implements a Bluetooth API, compliant to JSR-82 specification, that can be accessed either directly, or via a higher level Dpdl BT API.

The bluetooth functionality requires a compatible bluetooth stack available on the guest OS.

Currently the following platforms are supported:

* Windows
* Linux (x86_64)
* Raspberry (armV7l)

### Example bluetooth device discovery

The following example implements a device discovery that is performed using the higher level Dpdl BT API

```python
include("dpdllib.h")
include("dpdlBT.h")

func runDiscovery()
     int s1 = searchServerDevices()
     int status_discovery = 0
     int service_discovery = 0
     int counter = 0
     if(s1 == dpdlTrue)
	     while (status_discovery != 1) && (service_discovery != 1)
	         status_discovery = discoveryFinished(BT_SERVER_MODE)
	         service_discovery = serviceDiscoveryFinished(BT_SERVER_MODE)
	         print(".")
	         counter = counter+1
	         sleep(3000)
	     endwhile
     else
     	println("No working Bluetooth stack found")
     fi
end

func showDevicesFound()
	 string dev = "n"
	 int dev_found = 0
     while(dev != "null")
          dev = DPDLAPI_getServerVisibleBTAddr()
          if(dev != "null")
              println("dev visible: " + dev)
			  dev_found = dev_found+1
          fi
     endwhile
end


println("starting BT device discovery...")

int status = DPDLAPI_createObexServer(BT_GIAC_MODE)

if(status)
	println("discovering BT devices...")

	runDiscovery()

	showDevicesFound()

	println("done")
else
	println("Error: unable to initialize bluetooth discovery")
fi
```

As show case, here the same implementation of bluetooth device discovery that saves the devices found also in a persistent record store: [DpdlLibs/bluetoothDiscoverySave.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/bluetoothDiscoverySave.h)

## CoAP protocol

Dpdl supports and implements a lightweight CoAP protocol that can be accessed either directly, or via a higher level Dpdl API. 

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

### Example CoAP client

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
	
	sleep(1000)
		
	println("sending OBSERVE request..")

	dpdl_coap.request(coap_uri, "OBSERVE", null, null, response_handler)
	
	println("done")
else
	println("Client initialization failed")
fi

```






