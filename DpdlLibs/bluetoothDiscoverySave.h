# File: bluetoothDiscoverySave.h
#
# Example: Discovery of bluetooth devices and save the discovered device addresses in a record store
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
import("dpdllib.h")
import("dpdlBT.h")
import("dpdlRS.h")

func runDiscovery()
     int status = DPDLAPI_searchClientsOnServer()
     int status_discovery = dpdlFalse
     int service_discovery = dpdlFalse
     int counter = 0
     if(status == dpdlTrue)
	     while (status_discovery != dpdlTrue) && (service_discovery != dpdlTrue)
	         status_discovery = DPDLAPI_discoveryServerFinished()
	         service_discovery = DPDLAPI_serviceDiscoveryServerFinished()
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
              saveData(dev)
			  dev_found = dev_found + 1
          fi
     endwhile
end

func saveData(string data)
     if(BT_DEV_RS != -1)
         int id = addRecord(BT_DEV_RS, data)
         println("rec ID:" + id)
         println("data saved")
     fi
end

#main
println("BT device discovery inited")
int x = DPDLAPI_createObexServer(BT_GIAC_MODE)
println("opening record store 'BluetoohDevices'...")
int BT_DEV_RS = createRS("BluetoohDevices", AUTHMODE_ANY, dpdlTrue, dpdlTrue)
enumRecords(BT_DEV_RS, dpdlTrue)
println("discovering BT devices...")
runDiscovery()
showDevicesFound()
int total_btdevices  =  getNrRecords(BT_DEV_RS)
println("Total Bluetooth devices discovered: " + total_btdevices)
println("closing record store")
closeRS(BT_DEV_RS)
println("done")
