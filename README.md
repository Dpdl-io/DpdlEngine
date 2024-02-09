
# Dynamic Packet Definition Language

<p align="center">
	<img src="https://www.dpdl.io/images/dpdl-io.png" width="60%" height="60%">
</p>

				  www.dpdl.io



developed by
**SEE Solutions**
&copy; 2003


# What is Dpdl?

Dpdl is a <ins>**rapid development** programming language</ins> and <ins>**constrained device** framework</ins> with built-in database technology.
Dpdl and enables access to the Java platform JRE API and to any external java library via a dedicated API.
Dpdl supports also the <ins>embedding and on-the-fly execution</ins>  of other programming languages (**ANSI C, C++, Python, Julia, JavaScript, Lua, Ruby and OCaml**) directly within Dpdl scripts.
Therefore Dpdl allows access to thousands of existing high-quality libraries.

Dpdl is self contained and is highly customizable via a dedicated extension interface. Further programming languages can be implemented and embedded via a dedicated plugin-in interface and configuration.
For example the ROOT C++ Data Analysis framework from Cern is also available as Dpdl language plug-in.


<p align="center">
	<img src="https://www.dpdl.io/images/platform/Dpdl_programming_language_framework_small.png" width="95%" height="95%">
</p>

## Dpdl = ( Java Api's + Embedded C + 'C++' + Python + Julia + JavaScript + Lua + Ruby + OCaml) = <ins>Powerful and Versatile</ins>

### * Develop your ideas faster
### * On multiple platforms
### * Using the power of multiple programming languages and API's
### * Reuse code
### * No need to install, compile and configure environments
### * Runs on constrained devices
### * Support for IoT protocols such as Bluetooth(tm) and CoAP
### * Compressing, querying and handling data efficiently on constrained devices

**DpdlEngine stack overview**

![Dpdl stack](http://www.dpdl.io/images/platform/Dpdl_Dynamic_Packet_Definition_Language_components_thumb.jpg)

### Dpdl is designed to be <ins>Simple</ins>, <ins>Compact</ins>, <ins>Robust</ins>, <ins>Extensible</ins> and <ins>Portable</ins> to almost every platform.
By combining the <ins>portability and vast API availability</ins> of Java and Python, the <ins>computational power</ins> of Julia, the <ins>expressiveness</ins> of Lua and 
OCaml, the simplicity of Ruby, the <ins>web-enablement</ins> of JavaScript and the <ins>power</ins> of C/C++ programming language, Dpdl is provides a powerful development platform for industrial
applications, education and research.

The Dpdl language constructs and syntax is kept simple and follows an object oriented paradigm interoperable with the java platform API and any external java libraries.

Common IoT protocol stacks such as **Bluetooth(tm)** and **CoAP** (Constrained Application Protocol)
are integrated by default and third party libraries and functions can be added as extensions.

### Sample Dpdl script (Bluetooth device discovery using high level Dpdl BT API):
```python
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
	 string dev = "n"
	 int dev_found = 0
     while(dev != "null")
          dev = DPDLAPI_getServerVisibleBTAddr()
          if(dev != "null")
              println("bluetooth device visible: " + dev)
              saveData(dev)
			  dev_found = dev_found + 1
          fi
     endwhile
 else
 	println("No working Bluetooth stack found")
 fi
```

Dpdl can be used to encode, store, control and query data efficiently also on small memory footprint
devices and is foreseen to foster rapid application development. Dpdl comes with a very compact and portable
**scripting engine** and an **extensible API interface** for the development of mobile
applications and embedded system software. Embedded ANSI C code and OCaml can also be <ins>dynamically compiled in memory at runtime</ins>
in order to achieve <ins>faster execution</ins> performance.

This makes Dpdl suitable for a wide range of use-cases and in particular also for <ins>Hardware programming</ins>.

### Small Memory footprint:
* DpdlEngine core (full configuration) **`372 Kb`**
* DpdlNative library with (Embedded C interpreter/compiler) **`278 Kb`**

* Total size of DpdlEngine (Dpdl + C) = **`650 Kb`** Only
 
The size of the DpdlEngine core can be stripped down to **`60 Kb`** with a basic configuration if needed.

### Dpdl small sample apps

#### Get and decode News in JSON format 

This is a small sample app written with Dpdl that gets the top 10 news stories via http get in json format:

[app/getnews/dpdlGetNews.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/app/getnews/dpdlGetNews.h)

Note: The example 'app/getnews/dpdlGetNews2.h' is identical, but data is decoded in a java object instead of a struct

#### Dpdl Example using external Java libraries

This is a 3D model visualization of chemical molecules using the JavaFX library. The model can be rotated freely with mouse events.

[graphics/dpdl3DJavaFX_molecule.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/graphics/dpdl3DJavaFX_molecule.h)
	
<img src="https://www.dpdl.io/images/platform/examples/Dpdl_3D_Example2_with_JavaFX.png" width="75%" height="75%">


You can find more Dpdl examples on the following page: 
[Dpdl_Examples.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)


## Why Dpdl?

Dpdl is suitable for rapid application development in various domains, in particular also for small development of
applications on small memory footprint devices, and can be used as embedded scripting engine for various applications.

The main nature of Dpdl is for enabling rapid development, code reuse and allow a high degree of portability while being simple,
extensible and compact. Further, developers can benefit from the possibility to use multiple programming languages due to the fact
that a vaster set of APIs are available for a given platform.
Dpdl has also built-in constructs that enable dynamic code generation.

The **`DpdlPacket`** data container is a highly optimized way to store, query and access data
on devices that have limited memory and storage capabilities.

**Dpdl can be used as:**

* Rapid application development platform
* Embedded scripting engine
* Library module
* Utility tool
* Data handling on memory constrained devices
* Development of Domain Specific Languages (DSL)
	

### Features

* **DpdlEngine is optimized to run on a wide range of platforms** (J2ME, JavaME, J2SE, any other JVM >= 1.4 Spec, and any platform where DpdlVM can be compiled for the target platform)
* **Built-in Dpdl scripting engine with support for custom extensions** (DpdlExtension interface) -> allows to dynamically add language features
* **Dpdl scripting API provides access to the complete underlying Java JRE platform API and to external Java libraries**
* **ANSI C code, C++, Python, Julia, JavaScript, Lua , Ruby and OCaml language can be embedded and executed** directly within Dpdl scripts (interpreted/compiled code)
* Other programming languages can be embedded by configuration and via a dedicated interface (see [DpdlCustom] tag in DpdlEngine.ini)
* On-the-fly compilation of embedded ANSI C code in memory at runtime (via option 'dpdl:compile') -> very fast compile time 
* **Support for common IoT protocol stacks such as Bluetooth(tm)** (JSR-82) and
**CoAP (Constrained Application Protocol)** (IETF standard RFC 7252)
* **Packing data in a 'DpdlPacket' is a convenient way to optimize and speedup access to data**.
The speedup is x 25 times faster compared to a standard record store access
* **Virtual record store filesystem**
* **Double precision floating point emulation** layer
* **XML** with XPath parser
* **JSON**
* **Fast Prototyping**
* Tools for automatically converting Dpdl scripts to Java , C/C++ and V code
* small footprint, Only **650 Kb** for core DpdlEngine + Embedded C interpreter and compiler


## Access to the complete JRE Java platform API and any external java libraries


The Dpdl scripting language API allows to access all classes and methods of the <ins>underlying Java Platform (JRE)</ins> and <ins>external java libraries</ins>.

**Example:** using a java HashMap (which is resolved to java.util.HashMap)
```python
object map, s

map=loadObj("HashMap")
map.put(1,"Dpdl")
map.put(2,"Packet")
map.put(3,"Definition")
map.put(4,"Language")

s=map.get(1)
println(s)
s=map.get(4)
println(s)
```

Iterate over the obove HashMap using the same objects and methods as provided by the java API:
```python
object es = map.entrySet()
object iter = es.iterator()
object ep
while(iter.hasNext())
	ep = iter.next()
	println("key=" + ep.getKey() + " value=" + ep.getValue())
endwhile
```

In this way all java libraries defined in class definition configuration file (./DpdlLibs/libs/classes.txt) can be loaded and accessed.

The default configuration currently includes <ins>Java 5 Platform API (1.5)</ins>, and <ins>bluecove Bluetooth JSR-82</ins>.

The default configuration <ins>can be easily extended or updated</ins> to resolve additional java APIs by editing the class definition configuration file.


#### Dpdl Java API access documentation (default configuration)

[Java 5 API](http://www.seesolutions.it/apidoc/Java_Platform_API_1_5.html)

[Bluetooth JSR-82 API](https://docs.oracle.com/javame/config/cldc/opt-pkgs/api/bluetooth/jsr082/index.html)

Additional API's can be added to the class definition file as needed.

## Dpdl embeddable programming languages

Multiple programming languages can be embedded within the same **Dpdl** script via a the keyword **`>>`**.
Further programming languages can be developed and integrated via a dedicated plug-in interface and configuration. 

### Currenlty the following programming languages are supported:

* **`C interpreted`** code (minimal subset of C90 with standard C libs included)
* **`ANSI C`**  (full ISO C99 standard) compiled in memory and dynamically executed at runtime (see 'dpdl:compile')
* **`Python`**
* **`Julia`**
* **`JavaScript`**
* **`Lua`**
* **`Ruby`**
* **`OCaml`**
* **`ROOT C++`**


#### Dpdl example with embedded 'ROOT C++' code

ROOT is a powerful Data Analysis Framework developed by CERN (https://root.cern/) .

ROOT C++ code can be embedded within Dpdl via the keyord **`>>root`**

Example Dpdl script embedding 'ROOT C++':

<img src="http://www.dpdl.io/images/platform/Dpdl_ROOT_example.png" width="60%" height="60%">

```python
# main
println("test embedded ROOT C++...")

>>root
auto canvas = new TCanvas("c","Graph2D example",0,0,700,600);

double x, y, z, P = 6.;
int np = 200;
auto dt = new TGraph2D();
auto r = new TRandom();
for (int N=0; N<np; N++) {
	x = 2*P*(r->Rndm(N))-P;
	y = 2*P*(r->Rndm(N))-P;
	z = (sin(x)/x)*(sin(y)/y)+0.2;
	dt->SetPoint(N,x,y,z);
}
dt->Draw("tri1 p0");
canvas->Modified(); canvas->Update();
<<

int exit_code = dpdl_exit_code()
println("embedded ROOT exit code: " + exit_code)
```

NOTE: The native Dpdl library 'dpdlroot' needs to be downloaded and deployed separately (see Download section below)
 
### Dpdl with embedded C code

Dpdl allows the embedding and on-the-fly execution of **ANSI C code** directly within Dpdl scripts with the keyword **`>>c`**
The C code can be embedded with 2 different Modes:
 
1) <ins>Interpreted</ins>
2) <ins>Compiled in memory at runtime</ins> (if option '**dpdl:compile**' is enabled)


Example Dpdl script with embedded C code (Mode 1):
```c
# main
# starting with Dpdl, pushing parameters on the stack and embedding C code

println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0
string a = "test"

dpdl_stack_push(n, x, a)

>>c
#include <stdio.h>

int main(int argc, char **argv){
	printf("Hello C from Dpdl!\n");
	printf("\n");
	printf("num params: %d\n", argc);
	int cnt;
    for (cnt = 0; cnt < argc; cnt++){
        printf("	param %d: %s\n", cnt, argv[cnt]);
    }
    return 0;
}
<<
int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);

# again Dpdl code...

object str = loadObj("String", "Dpdl embedded C")
bool b = str.contains("C")
println("Dpdl contains C: " + b)
```

### Embedding other programming languages

Other programming languages can be easily integrated in Dpdl via a dedicated plug-in interface and configuration. Please feel free to suggest your opinion on the
'Discussion' section on the DpdlEngine GitHub repository

## Supported Platforms

Dpdl runs on a wide range of platforms and provides also a small footprint java virtual machine,
released as open-source, that can  be compiled for almost every platform as soon as
an ANSI C compiler is available for the target platform.

### Dpdl itself is compatible with:

* J2ME MIDP (Mobile Information Device Profile) -> MIDP 1.0 and MIDP 2.0 (CLDC 1.0, CLDC 2.0)
* Java ME CLDC & GCF (JSR 360)
* Java ME Embedded Profile (JSR 361)
* Java versions >= 1.4 and later
* Java > 1.1 (but without 'loadObj' and 'getClass' methods)
* All Platforms where the included open source virtual machine (written in C) can be compiled

DpdlEngine V1.0 has been tested on:

	* MacOS aarch64
	* Linux x86_64
	* Raspberry PI 3 (armv7l)
	* Windows 64-bit
	* Android
	* JavaME
	* J2ME (MIDP 2.0)
		
Note: The DpdlEngine needs to be re-packaged for running on Android, JavaME and J2ME

### Embedded programming languages - compatibility matrix

(X + version) **Supported**

(*) **available soon**

| Platform |Embedded ANSI C |Python |Julia |JavaScript |OCaml |Lua |ROOT C++ |Ruby |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux x86_64 |X|X v3.2|X v1.9.3|X|X v4.01|X v5.4|X v6.28|*|
| Mac OS X (aarch64) |X|X v3.12|X v1.9.3|X|X v4.01|X v5.4|X v6.28|X 3.2.2|
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X|X v4.01|X v5.4|*|*|
| Windows64|X|*|*|X|X v4.01|*|*|*|

	
## Documentation

The Dpdl framework and API documentation are available via the following links:
 

[Dpdl Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)

[Dpdl scripting API Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

[Dpdl embedded languages](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_languages.md)

[Dpdl embedded minimal C library Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

[Dpdl Examples](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)

 Dpdl Java API Documentation (available only for the registered version of DpdlEngine)


## Download

See 'Download' page for more details:

[Download](https://github.com/Dpdl-io/DpdlEngine/blob/main/Download.md)


## Roadmap

Dpdl is currently developed by SEE Solutions and the following integrations has been defined: 

* Front-End compiler based on LLVM for compiling Dpdl scripts to IR


### Embedding of 'Python' code

Python code can be embedded within Dpdl scripts by using the keyword **`>>python`**.
MicroPython will also be supported as option in the coming release.

Example Dpdl script with embedded 'Python' code:
```python
println("testing embedding python code")
println("")

>>python
languages = ['Dpdl', 'C', 'Python', 'OCaml']

for language in languages:
	print(language)
<<
println("")

int exit_code = dpdl_exit_code()

println("embedded python exit code: " + exit_code);
```

### Embedding of 'Julia' code

Julia is a powerful and performant computational programming language  (https://julialang.org)

Julia code can be embedded within Dpdl via the keyord **`>>julia`**

Example Dpdl script embedding 'Julia' that generates a Plot and saves the result as PDF file:
<img src="http://www.dpdl.io/images/platform/Dpdl_Julia_example.png" width="60%" height="60%">
```python
#main
println("Testing Plot data with Julia programming language...")

>>julia
using Plots

x = range(0, 10, length=100)
y1 = sin.(x)
y2 = cos.(x)
p = plot(x, [y1 y2])

savefig(p, "./Test/myplot.pdf")

dispose_status = @ccall dpdl_julia_dispose()::Int32
return 1
<<

int exit_code = dpdl_exit_code()
println("finished with exit code: " + exit_code)
```
NOTE: The native Dpdl library 'dpdljulia' needs to be downloaded and deployed separately (see Download section below)


### Embedding of 'JavaScript' code

JavaScript is the ideal programming language for web applications as it's supported by all popular web browsers.

JavaScript code can be embedded within Dpdl via the keyword **`>>js`** or  **`>>qjs`**

Dpdl allows the embedding of javascript with 2 different Modes:
1) Using the 'Nashorn' javascript engine embedded in the Java platform '>>js'
2) Using the 'QuickJS' javascript engine from Fabrice Bellard '>>qjs'


Example:
```python
println("testing embedded qjs...")

dpdl_stack_push("my Hello Message!!!")
>>qjs

import { fib } from "./DpdlLibs/js/fib_module.js";

var a_message = "null";

console.log(scriptArgs)
console.log('Dpdl sends a message with QuickJS');

if(scriptArgs.length > 0){
	a_message = scriptArgs[0];
}
std.printf("Message = %s %d", a_message, 23);
console.log('');
console.log("fib(10)=", fib(10));
<<

int exit_code = dpdl_exit_code()
println("Dpdl qjs exited with exit code: " + exit_code)
```

QuickJS provides a powerful and complete API to interact with the javascript engine at low level.
Custom native functions and objects can be implemented as shared libraries and loaded in javascript.
You can find examples in the folder './DpdlLibs/js/'
		

### Embedding of 'Lua' code

Lua code can be embedded within Dpdl scripts by using the keyword **`>>lua`**.

Example Dpdl script with embedded 'Lua' code:
```python
println("testing embedding Lua within Dpdl....")

string buffer_key = "dpdlbuf_result"

dpdl_stack_push(buffer_key, "name", "Alexis", "surname", "Kunst")

>>lua
function doSomeAlg()
	local home_dir = os.getenv("HOME")
	print("user home: ", home_dir)
	
	local x = os.clock()
	    local s = 0
	    for i=1,100 do 
	    	s = s + i
	    	io.write(".")
	    end
	    print("")
	    print(string.format("elapsed time: %.2f\n", os.clock() - x))
end

function paramLen(T)
  local count = 0
  for _ in pairs(T) do count = count + 1 end
  return count
end

function dpdl_main(params)
	local num_params = paramLen(params)
	io.write("dpdl_main call with number of params: ")
	io.write(num_params)
	print()
	print("executing my embedded algorithm...")
	print("")
	doSomeAlg()
	print()
	print("returning param values in 'uppercase'")
	local tab_out = {numfields=1}
	for k,v in pairs(params) do
		tab_out.numfields = tab_out.numfields + 1
		tab_out[tostring(k)] = string.upper(tostring(v))
	end
	tab_out.numfields = tostring(tab_out.numfields)
	return tab_out
end
<<

int exit_code = dpdl_exit_code()

println("embedded lua exit code: " + exit_code)

string resp_buf = dpdl_stack_buf_get(buffer_key)
println("lua response buffer: ")
println(resp_buf)
```


## Dpdl Examples

Further Dpdl examples can be found on this page:

[Dpdl_Examples.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)


## What is a DpdlPacket?

A DpdlPacket is a compact, highly compressed executable packet of data with built-in
database technology that can be created based on a defined Dpdl code definition. 
A DpdlPacket can than be allocated and queried efficiently via API
interfaces available for Java and for the built-in Dpdl scripting language.
In particular Dpdl is very efficient on J2ME and JavaME platforms and
has a high degree of backward compatibility.

A DpdlPacket contains 1 - n chunks of compressed data that can be allocated, queried and
deallocated when data is not used anymore.

All kind of data can be packed into a DpdlPacket.

### DpdlPacket

![DpdlPacket](http://www.dpdl.io/images/platform/DpdlPacket_FlowChart.jpg)

The 'DpdlEngine lite' release package includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl)
and the corresponding Dpdl code definition file [dpdl_PHONEBOOK.c](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlPackets/dpdl_PHONEBOOK_BZ.c) used to encode
the DpdlPacket. Refer to the [Dpdl_documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)
for how to allocate, execute and perform queries on a DpdlPacket.

Example of DpdlPacket code definition (dpdl_PHONEBOOK.c)
```cpp
call(dpdlInterpreter)
::module dpdl_PHONEBOOK
::module_SPEC 23452
::model 836
::dpdlVersion 1.0

OPTIONS {
    TARGET = CDC & CLDC
    KVM = 1.0
    ZIP = true
    CHECKSUM = true
    SIGNATURE = true
    ENCRYPTION(RSA) = false
}

#defineDpdlEncoding UTF-8

#defineDB phone_bz | ./Test/BolzanoPhone.csv | null null

#defineSQL query_ SELECT name, phoneNR, e-mail FROM phone_bz end

#defineProtocol-cHtml phonebook_visual phone_book.html

import extern SystemData

catch DPDL_Script OnInit() {
    import("dpdllib.h") nl
    println("OnInit()") nl
}

import virtual DATA none  {
        class BolzanoPhone volatile phonebook_visual {
              DATA::string const name;
              DATA::string using phoneNR;
              DATA::string using  e-mail;
              #defineGUI Default <PhoneBook>  <Enter name and surname:>
              
              catch DPDL_Script OnDecode() {
                 import("dpdllib.h") nl
                 import("dpdlRS.h") nl
                 println("OnDecode()") nl
                 string time = getTime() nl
                 println("storing access time..." + time) nl
                 int rs_id = createRS("AccessStats", AUTHMODE_ANY, dpdlTrue, dpdlTrue) nl
                 int rec_id = addRecord(rs_id, time) nl
                 int status = closeRS(rs_id) nl
                 println("done status: " + status) nl
              }
        }
}
#defineD BolzanoPhone source phone_bz SQL query {
                CHUNK entry [6];
                struct BTree DENSE_INDEX hashing *name
                entry.content { name , phoneNR , e-mail }
                entry.name TAG(0xef) const (string) = 20;
                entry.phoneNR TAG(0xefe) (string) = 15;
                entry.e-mail TAG(0xefee) (string) = 30;
}
```

This is an example Dpdl sript that show how a 'DpdlPacket' can be allocated and queried:

[testDpdlDB2.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testDpdlDB2.h)

The database technology in Dpdl has been developed since year 2003 when the first applications where developed for mobile devices.

It started with a BsC thesis by A.Costa:

[Advanced database techniques in Dpdl : dynamic packet definition language ; a portable data protocol for small embedded systems](https://unibz.primo.exlibrisgroup.com/permalink/39UBZ_INST/hl3dt9/alma9928450240001241)


## What is the DpdlClient console application?

The DpdlClient console application included in the 'DpdlEngine lite' release is a small console application
that exposes some functionalities of Dpdl via a simple command line console. Dpdl scripting code can be
executed and DpdlPackets handled. The same functionalities can be accessed via the java or Dpdl scripting API.

These are the console commands available:
```
Usage: 
 -l  List DpdlPackets installed
 -i  Install DpdlPacket
 -d  Uninstall DpdlPacket
 -la List DpdlPackets allocated
 -a  Allocate DpdlPacket
 -da Deallocate DpdlPacket
 -qp Query DpdlPacket
 -c Create DpdlPacket
 -libs  List Dpdl libraries
 -slib  Show library
 -api   List Dpdl API functions
 -exec  Type && Execute a Dpdl script, between <script>...  </script>
 -load  Load && Execute a Dpdl script file (relative path to./DpdlLibs/ eg. arraylistExample.h)
 -bench  Run a query benchmark test (on DpdlPacket dpdl_PHONEBOOK)
 -h  Help
 -q  quit
```


