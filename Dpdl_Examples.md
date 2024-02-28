# Dpdl Examples

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## How to run the examples

The Dpdl example scripts are located in the './DpdlLibs/' folder and can be executed in different ways:

1) using the **`DpdlClient`** console application with commands
2) or directly via the '-load' parameter at startup
3) or using the API function call DPDLAPI_execCode(..).

The script path per default configuration need to be relative to the './DpdlLibs/' folder

### 1) **`DpdlClient`** console application

```
-load
enter the Dpdl script name to execute:
arraylistExample.h [@TEST1]
```

### 2) At startup with the '-load' command

```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -jar DpdlEngine_V1.0_release.jar -load test/testArray.h
```
Note: On newer versions of java (from Oracle), in order to access specific java 'modules' within Dpdl, you may need to enable them with the option '--add-opens'

### 3) Using the Dpdl API

```python
println("executing dpdl script...")
int s = DPDLAPI_execCode("mydpdlscript.h")
println("status: " + s)
```

The Dpdl sample scripts and Dpdl sample applications published on this repository are released under the MIT License.


## Dpdl samples

* Example Dpdl script that downloads json news data and decodes it to a struct

	[app/getnews/dpdlGetNews.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/app/getnews/dpdlGetNews.h)

* Example Dpdl app that uses the JavaFX library to render and animate chemical molecules in 3D

	[graphics/dpdl3DJavaFX_molecule.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/graphics/dpdl3DJavaFX_molecule.h)
	
	<img src="https://www.dpdl.io/images/platform/examples/Dpdl_3D_Example2_with_JavaFX.png" width="65%" height="65%">

* Example 'dummy' Dpdl script that shows some functionalities provided by Dpdl

	[dpdl_overview.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdl_overview.h)

* Example Dpdl script that shows how <ins>C</ins> code and <ins>Python</ins> can be embedded and executed within Dpdl

	[dpdlFullExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlFullExample.h)
	
* Example Dpdl script that embeds C++ code and uses ROOT API libraries to solve a linear equations in 4 different ways

	[root/dpdlRootSolver.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/root/dpdlRootSolver.h)
	
* Example Dpdl script that embeds javascript code (with  Mode2 using qjs) that loads an object implemented in a native C library (see point.c)

	[js/dpdlQJsPoint.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/js/dpdlQJsPoint.h) 

* Example Dpdl script that launches multiple threads

	[concurrent/testConcurrency1.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/concurrent/testConcurrency1.h)
	
* Example Dpdl script that uses the JavaFX java library to render UI (Graphical User Interface) elements via a FXML definition.
	
	[ui/dpdlGUIJavaFX.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ui/dpdlGUIJavaFX.h)
		
	<img src="https://www.dpdl.io/images/platform/examples/Dpdl_UI_Example_with_JavaFX.png" width="35%" height="35%">
		
* Example Dpdl script that shows how to use the type 'struct'

	[test/testStruct.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/test/testStruct.h)
	
* Example Dpdl script that shows how exceptions can be raised and handled

	[testRaiseException.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testRaiseException.h)

* Example Dpdl script that parses an XML document with the xml pull parser

	[xml/dpdlXMLParser.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/xml/dpdlXMLParser.h)
	
* Example Dpdl script that compresses and de-compresses a string of data using the Java platform API

	[dataCompress.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dataCompress.h)
	
* Example Dpdl script with embedded ANSI C code that is compiled in memory and executed at runtime, the result is than intercepted

	[C/dpdlCcompileBufRet.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/C/dpdlCcompileBufRet.h)
	
* Example Dpdl app that uses the JavaFX java library to create a sample UI (Graphical User Interface) application via a FXML definition and used CSS to create the layout.

	[ui/dpdlGUIJavaFX_css.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ui/dpdlGUIJavaFX_css.h)
	
	<img src="https://www.dpdl.io/images/platform/examples/Dpdl_UI_Example_with_JavaFX_and_css.png" width="75%" height="75%">
	
* Example Dpdl script that executes an embedded 'Julia' script to plots data using the 'Plots' package, and to save the chart as PDF

	[julia/dpdlJuliaPlot.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/julia/dpdlJuliaPlot.h)
	
* Example Dpdl script using pointers and references

	[dpdlPointers.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlPointers.h)
	
* Example Dpdl script embedding ANSI C code (ISO C99) that is dynamically compiled in memory at runtime (fast) and executed

	[C/dpdlCcompileExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/C/dpdlCcompileExample.h)

* Example Dpdl script that embeds JavaScript that intercepts some parameters that have been pushed on the dpdl stack

	[js/dpdlJsExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/js/dpdlJsExample.h)
	
* Example Dpdl script (embedded C code compiled at runtime) that launches threads (pThreads) to sum numbers

	[C/dpdlCThreadExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/C/dpdlCThreadExample.h)
	
* Example Dpdl script that shows to to execute embedded C code accepting parameters pushed on the dpdl_stack, and writes some result back to a buffer variable. The execution time is measured.

	[bench/testC.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/bench/testC.h)
	
* Example Dpdl script that embeds 'Julia' code to execute a set of threads that call a native C Dpdl API function

  [julia/dpdlJuliaThread.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/julia/dpdlJuliaThread.h)
  
* Load a Dpdl script object "LoadCodeFunc.h" via 'loadCode(..)' and call one of its functions

	[testLoadCode.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testLoadCode.h)
	
	[LoadCodeFunc.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/LoadCodeFunc.h)
	
* Example Dpdl app that uses the JavaFX java library to visualize a website within a WebView component

	[ui/dpdlGUIJavaFX_web.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ui/dpdlGUIJavaFX_web.h)
	
* Parse JSON file and access data types

	[json/testDpdlJSON.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/json/testDpdlJSON.h)
	
* Parse JSON file and decode data into a struct

	[json/dpdlDecodeJSON.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/json/dpdlDecodeJSON.h)
	
* Example Dpdl script that updates the fields of a struct type via a dedicated thread

	[test/testStructThread.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/test/testStructThread.h)
	
* Embedded C code execution within Dpdl script
	
	[dpdlSimpleC.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlSimpleC.h)
		
* Embedded Python code execution within Dpdl script
	
	[python/dpdlEmbedPython.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/python/dpdlEmbedPython.h)
	
* Embedded Lua code execution within Dpdl script
	
	[lua/dpdlLuaBufRet.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/lua/dpdlLuaBufRet.h)
	
* Emedded Ruby code execution within Dpdl script

	[ruby/dpdlRubyExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ruby/dpdlRubyExample.h)

* Performs a discovery of bluetooth devices and saves the device addresses discovered in a record store
  
	[bluetoothDiscoverySave.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/bluetoothDiscoverySave.h)
  	
* Executes the bluetoothDiscoverySave.h script continuously in a dedicated Thread instance
	
	[dpdl_startup.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdl_startup.h)
	
* Array definition, population and access
	
	[arraylistExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/arraylistExample.h)
	

* Downloads a html website from a URL and saves the content in a local file

	[downloadWebURL.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/downloadWebURL.h)
	

* Inline execution of Dpdl scripting code

	[dpdlCodeExecExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlCodeExecExample.h)
	

* Accepts connections from a bluetooth server application and intercepts commands

	[DpdlConsoleBT_client.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/DpdlConsoleBT_client.h)
	
	[DpdlConsoleBT_client.h_static](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/DpdlConsoleBT_client.h_static)
	
* Uses the Dpdl API library DoubleEmul and FloatEmul to emulate floating point and double precision math operations
	
	[dpdlFloatDoubleEmul.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlFloatDoubleEmul.h)
	
* Dpdl script that shows how to read and write data to a virtual record store filesystem

	[fs/dpdlVirtualFS.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/fs/dpdlVirtualFS.h)
	
* Creates a graphical user interface with some UI components (Button, Panel, Checkbox, List, draw Panel) using Java Swing classes. The list is updated, the button command is intercepted with the
  'actionPerformed' function, the checkbox status is printed, and a text and rectangle is drawn at random location on the draw panel.
	
	[ui/dpdlGUIExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ui/dpdlGUIExample.h)
	
* Drawing functions on a UI Canvas on J2ME devices
	
	[J2MEDrawDemo.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/J2MEDrawDemo.h)
	
* Save and access data from a record store

	[recordStoreExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/recordStoreExample.h)
		

* Test read and write access to record stores

	[testRSConcurrency.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testRSConcurrency.h)
	

* Simple console application to allocate and perform queries on the supplied DpdlPacket dpdl_PHONEBOOK. The script allows to perform single queries, or n sequential or random queries, and measures the execution
	time. Comment or uncomment the following line of code in the script -> i #abs(search_rand_int) 
	
	[testDpdlDB2.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testDpdlDB2.h)
	
* BTObexServer (client/server)

  Sample application that implements sending of SMS via bluetooth to discovered devices. The messages to be sent are
  read from a record store. An auxiliary script (ImportantMsgWriter.h) can be used to store messages to be delivered
  in the record store
  
	[BTObexServer/BTObexServer.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/BTObexServer/BTObexServer.h)
	
	[BTObexServer/BTObexServer.h_static](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/BTObexServer/BTObexServer.h_static)
	
* HTTPServer:
  
  Simple client server application to send and receive broadcasted messages via HTTP protocol.
	
	[HTTPServer/HTTPServer.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/HTTPServer/HTTPServer.h)
	
	[HTTPClient/HTTPServer.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/HTTPServer/HTTPClient.h)
	
	How to run:
	
		1) start the server: HTTPServer/HTTPServer.h
		
		2) start the 1st client: HTTPServer/HTTPClient.h
		
		3) start the 2nd client, but first change the CLIENT_ID in the HTTPClient.h script
	
* CoAP (client/server):

	Client server application that implements PUT, GET, OBSERVE requests via CoAP (Constrained Application Protocol).
	The clients can create resources and perform PUT, GET or OBSERVE requests on the resources created.
	
	Once the dpdlCoAPServer.h is started, the observe client (dpdlCoAPClient.h) can be initialized in a 2nd console,
	and a second client (dpdlCoAPClient2.h) that performs PUT requests can be initialized in a 3rd console by starting
	it in a dedicated thread via the script 'startClientThread.h'
	
	[CoAP/dpdlCoAPServer.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPServer.h)
	
	[CoAP/dpdlCoAPClient.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPClient.h)
	
	[CoAP/dpdlCoAPClient2.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/CoAP/dpdlCoAPClient2.h)
	
	[CoAP/startClientThread.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/CoAP/startClientThread.h)
	
	How to run:
	
		1) start the server: CoAP/dpdlCoAPServer.h
		
		2) start the 1st client: CoAP/dpdlCoAPClient.h
		
		3) start the 2nd client in a thread instance: CoAP/startClientThread.h


* Small 'dummy' sample application

 	[app/dummy/dpdl_sample.h](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/app/dummy)
 	
 	
* Set of 14 examples/tests. The examples make use of @TAG execution to allow execution of each individual example.
	
	[dpdlLibExamples.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlLibExamples.h)
	
	```
	-load
	dpdlLibExamples.h @TEST1
	```
	
	dpdlLibExamples.h @TEST2 etc..
	
	....