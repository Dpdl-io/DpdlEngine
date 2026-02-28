# Dpdl IoT protocols

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
				
developed by
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

[CoAP client Example](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPClient2.h)





