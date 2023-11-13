
# Dpdl - Dynamic Packet Definition Language

				  www.dpdl.io



developed by
**SEE Solutions**


# What is Dpdl?


Dpdl is a <ins>**constrained device**</ins> and <ins>**rapid prototyping** programming language framework</ins> with built-in database technology.
Dpdl enables access to the Java platform API and external java libraries via a dedicated scripting language and supports the <ins>embedding and on-the-fly execution</ins> 
of **ANSI C, C++, Python, Julia, JavaScript, Lua and OCaml** programming languages directly within Dpdl scripts. Embedded ANSI C code can
also be <ins>dynamically compiled in memory at runtime</ins> if the option 'compile' is enabled in order to achieve <ins>faster execution</ins> performance. Other programming language can be implemented
and embedded via a dedicated plugin-in interface and configuration. For example the ROOT C++ Data Analysis framework is also available as Dpdl language plug-in.

## Dpdl ( Java api + Embedded C + 'C++' + Python + Julia + OCaml) = <ins>Powerful and Versatile</ins>

### * Develop faster your ideas
### * On multiple platforms
### * Using the power of multiple programming languages, reusing code
### * Without spending time on installing, compiling and configuring environments
### * Designed for running on constrained devices
### * Compressing, querying and handling data on constrained devices

**DpdlEngine stack overview**

![Dpdl stack](http://www.dpdl.io/images/platform/Dpdl_Dynamic_Packet_Definition_Language_components_thumb.jpg)

### Dpdl is designed to be simple, very compact, robust, extendible and portable to almost every platform.
By combining the portability and vast API availability of Java and Python, the computational power of Julia, the expressiveness of Lua and 
OCaml, the web enablement of JavaScript and the power of C/C++ programming language, Dpdl is provides a powerful development platform for industrial
applications, education and research.

Common IoT protocol stacks such as **Bluetooth(tm)** and **CoAP** (Constrained Application Protocol)
are integrated by default and third party libraries and functions can be added as extensions.

Sample Dpdl script (Bluetooth device discovery using Dpdl high level BT API):
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

Dpdl can be used to encode, store, control and query data efficiently especially on small memory footprint
devices and to foster rapid application development. Dpdl comes with a very compact and portable
**scripting engine** and an **extensible API interface** for the development of mobile
applications and embedded system software.

The Dpdl language constructs and syntax is kept simple and follows an object oriented paradigm
interoperable with the Java platform API and external java libraries.

Standard **ANSI C code** (a subset of C90 and full C99 standard), **C++, Python, Julia, JavaScript, Lua and the OCaml** functional programming language
can be **embedded and executed on-the-fly directly within Dpdl scripts** (interpreted and also compiled code).
This makes Dpdl suitable for a wide range of use-cases and in particular also for hardware programming.


A list of 14 examples/tests can be found in the following Dpdl script, as explained later:

[dpdlLibExamples.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlLibExamples.h)


## Why Dpdl?

Dpdl can be used to implement applications in various domains, in particular for small
memory footprint devices and for rapid application development, teaching and research.

The 'DpdlPacket' data container is a highly optimized way to store, query and access data
on devices that have limited memory and storage capabilities. 

**Dpdl can be used:**

* As rapid application development platform
* As an embedded scripting engine for applications
* A library module
* As utility tool
* to handle efficiently data on memory constrained devices
	
	
### Features

* **DpdlEngine is optimized to run on a wide range of platforms** (J2ME, JavaME, J2SE, any other JVM >= 1.4 Spec, compiled DpdlVM for target platform)
* **Built-in Dpdl scripting engine with support for custom function extensions** (DpdlExtension interface)
* **Dpdl scripting API provides access to the complete underlying Java JRE platform and to external API libraries**
* **ANSI C code, C++, Python, Julia, JavaScript, Lua and OCaml language can be embedded and executed** directly within Dpdl scripts (interpreted/compiled code), a subset of C90 standard, POSIX compliant
* On-the-fly compilation of embedded ANSI C code at runtime (via option 'dpdl:compile') -> very fast compile time
* Other programming languages can be embedded by configuration and via a dedicated interface (see [DpdlCustom] tag in DpdlEngine.ini) 
* Support for pointers and references
* **Support for common IoT protocol stacks such as Bluetooth(tm)** (JSR-82) and
**CoAP (Constrained Application Protocol)** (IETF standard RFC 7252)
* **Packing data in a 'DpdlPacket' is a convenient way to optimize and speedup access to data**.
The speedup is x 25 times faster compared to a standard record store access
* **Virtual filesystem** for record stores
* **Double precision floating point emulation** layer
* **XML** with XPath parser
* **JSON**
* **Fast Prototyping**
* Tools for converting Dpdl scripts to Java and C/C++ code


### Access to the complete JRE Java platform API and external java libraries


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

In this way all java libraries defined in class definition configuration file (./DpdlLibs/libs/classes.txt) can be loaded and accessed.
The default configuration includes Java 5 Platform API (1.5), and bluecove Bluetooth JSR-82.

The default configuration can be extended or updated to resolve additional java APIs (editing of class definition configuration file)

#### Dpdl API access documentation (default configuration)


[Java 5 API](http://www.seesolutions.it/apidoc/Java_Platform_API_1_5.html)

[Bluetooth JSR-82 API](http://www.seesolutions.it/apidoc/Bluetooth_JSR82_API.html)


## Dpdl embeddable programming languages

Multiple programming languages can be embedded within **Dpdl** scripts via a the keyword '**>>**'
Programming languages can be developed and integrated via a dedicated plug-in interface and configuration. 

### Currenlty the following programming languages are supported:

* **C** interpreted code (minimal subset of C90)
* **ANSI C**  (full ISO C99) either interpreted, or compiled in memory and dynamically executed at runtime (see 'dpdl:compile')
* **Python**
* **Julia**
* **JavaScript**
* **Lua**
* **OCaml**
* **ROOT C++**

### Open source Dpdl embedded language plug-ins

Some Dpdl embedded language plug-ins are published as open source projects:
* ROOT C++
* More will follow...

https://github.com/Dpdl-io-org/Dpdl_language_plugins

### Embedding of 'ROOT C++'

ROOT is a powerful Data Analysis Framework developed by CERN (https://root.cern/) .

ROOT C++ code can be embedded within Dpdl via the keyord '**>>root**'

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
 
### Embedded C code

Dpdl allows the embedding and on-the-fly execution of **ANSI C code** directly within Dpdl scripts. The C code is interpreted OR compiled in memory at runtime (if option '**dpdl:compile**' is enabled),
via a native Dpdl library that has a very small footprint and **includes all essential C libraries** and language constructs (ISO standard C90/C99, **POSIX** compliant) with
**no external dependencies**.

Custom libraries and functions can be integrated and linked via a straight forward implementation configuration approach.

### The following modes (options) are available for executing embedded C code:

* Interpreted C code (<ins>minimal subset of C90</ins>) --> easy integration of custom extensions. No compile time overhead (**default**)
* Compiled (in memory at runtime) or interpreted C code (<ins>ANSI C99</ins>) --> fast compile time and FAST execution (can be activated via options '**dpdl:C99**' and '**dpdl:compile**'
This operation mode supports ANSI C (full ISO C99 standard) and many GNUC extensions including inline assembly (complex and imaginary numbers are currently excluded)

The faster and more complete execution mode can be activated by pushing the option '**dpdl:C99**' or '**dpdl:compile**' on the dpdl stack (-> see 'dpdl_stack_push(..)'):
The 'dpdl:compile' option works for the following platforms: i386, x86_64, ARM

Example Dpdl script with embedded C code:
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

This is a more complete example of the usage of embedded C code within Dpdl:

[dpdlEmbeddedC.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlEmbeddedC.h)

The Dpdl native API library 'dpdlnativeapi' provides also a Security check to guarantee that the library have not been compromised.
Therefore the embedded C code execution cannot be mangled internally and guarantees the correct execution of C code.
In the case the library is updated, the corresponding verification checksums needs to be adjusted in 'DpdlEngine.ini" config.

**Dpdl embedded C library documentation:**
[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)


### Embedding of 'Python'

Python code can be embedded within Dpdl scripts by using the keyword '**>>python**'.
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

#### Supported python platforms (library 'dpdlpython')

Currently the 'DpdlEngine lite' release includes the native Dpdl Python library '**libdpdlpython**' for **MacOS (arm64)**, **Linux (x86_64)** and Raspberry PI 3 (armv7l)

* on **Linux:** Python version 3.2m (gcc version 4.4.7)
* on **MacOS:** Python version 3.12 (clang version 14.0.3)
* on **Raspberry PI 3**: Python version 3.2m (gcc version 4.4.11)
* <ins>Windows version will follow soon</ins> in the coming release
	
### Embedding of 'Julia'

Julia is a powerful and performant computational programming language  (https://julialang.org)

Julia code can be embedded within Dpdl via the keyord '**>>julia**'

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

### Embedding of 'JavaScript'

JavaScript is the ideal programming language for web applications as it's supported by all popular web browsers.

JavaScript code can be embedded within Dpdl via the keyword '**>>js**'

Example Dpdl script embedding 'JavaScript' that intercepts parameters pushed on the dpdl stack and accesses java classes
```python
# main
println("test embedding javascript ...")

dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
dpdl_stack_var_put("var2", "This variable comes from Dpdl (var2)")

>>js
    print("Hello javascript from Dpdl: ");
    print("")
    print("var1: " + var1);
    print("var2: " + var2);
    print("The number PI is equal to: " + java.lang.Math.PI);
    print("")
    var importFile = new JavaImporter(java.util);  
    var a = new importFile.ArrayList();  
    a.add(12);  
    a.add(20);  
    print(a);  
    print(a.getClass());          
<<

int exit_code = dpdl_exit_code()

println("embedded js exit code: " + exit_code)
```

### Embedding of 'Lua'

Lua code can be embedded within Dpdl scripts by using the keyword '**>>lua**'.

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

### Embedding of 'OCaml' (experimental)

Currently the functional programming language '**OCaml**' (https://ocaml.org/) is supported, via package (http://www.ocamljava.org/),
and can be embedded directly within Dpdl scripts with the keyword '**>>ocaml**'
The library allows also to compile on the fly OCaml code in order to speedup execution.

Example Dpdl script with embedded 'OCaml' code:
```python
println("testing Dpdl embedded OCaml..")


# parameter to instruct the Dpdl runtime to compile the embedded code (faster execution). Without this option the code is interpreted
dpdl_stack_push("compile")

# we add a variable to the dpdl stack so that we can access it in the embedded OCaml
dpdl_stack_var_put("mydpdlvar", "Dpdl interacts with OCaml")

>>ocaml
external get_binding : string -> 'a = "script_get_binding";;

let dpdl_var = get_binding "mydpdlvar"
print_endline "mydpdlvar:"
print_endline dpdl_var 

let string_of_float f =
  let s = format_float "%.12g" f in
  let l = string_length s in
  let rec loop i =
    if i >= l then s ^ "."
    else if s.[i] = '.' || s.[i] = 'e' then s
    else loop (i + 1)
  in
    loop 0
    
    print_endline "Output:"
    print_string f 
    print_string "\n";
<<

int exit_code = dpdl_exit_code()

println("embedded OCaml exit code: " + exit_code);

```

### Other programming languages

Other programming languages can be easily integrated in Dpdl via a dedicated plug-in interface and configuration. Please feel free to suggest your opinion on the
'Discussion' section on the DpdlEngine GitHub repository

## Supported Platforms

Dpdl runs on a wide range of platforms and provides also a small footprint java virtual machine,
released as open-source, that can  be compiled for almost every platform as soon as
an ANSI C compiler is available for the target platform.

### Dpdl is compatible with:

* J2ME MIDP (Mobile Information Device Profile) -> MIDP 1.0 and MIDP 2.0 (CLDC 1.0, CLDC 2.0)
* Java ME CLDC & GCF (JSR 360)
* Java ME Embedded Profile (JSR 361)
* Java versions >= 1.4 and later
* Java > 1.1 (but without 'loadObj' and 'getClass' methods)
* Platforms with ANSI C compiler where the included open source virtual machine can be compiled

DpdlEngine V1.0 has been tested on:

	* MacOS arm64
	* Linux x86_64
	* Raspberry PI 3 (armv7)
	* Windows 64-bit
	* Android
	* JavaME
	* J2ME (MIDP 2.0)
		
		
### Embedded languages - compatibility matrix

(X + version) **Supported**

(*) **available soon**

| Platform |Embedded ANSI C |Python |Julia |JavaScript |OCaml |Lua |ROOT C++ |go |ch C/C+ |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux x86_64 |X|X v3.2|X v1.9.3|X|X v4.01|X v5.4|X v6.28|*|*|
| Mac OS X (arm64) |X|X v3.12|X v1.9.3|X|X v4.01|X v5.4|X v6.28|*|*|
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X|X v4.01|X v5.4|*|*|*|
| Windows64|X|*|*|X|X v4.01|*|*|*|*|

	
## Roadmap

Dpdl is currently developed by SEE Solutions and the following integrations has been defined: 

* Native API support for Tensorflow and Tensorflow lite
* OpenAI integration
* Blockchain integration (smart contracts)
* Nostr client API


## Documentation

The Dpdl framework and API documentation are available via the following links:
 

[Dpdl Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)

[Dpdl scripting API Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

[Dpdl embedded languages](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_languages.md)

[Dpdl embedded minimal C library Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

 Dpdl Java API Documentation (available soon)


## Download 'DpdlEngine lite' release package (Trial version)

The 'DpdlEngine lite' release (v1.0) can be downloaded and try for Free (with some limitations),
from the dpdl.io download page:

[DpdlEngine lite DOWNLOAD form](https://www.dpdl.io/index_download.html)

Documentation and Updates are updated regularly on the official DpdlEngine GitHub repository:
[DpdlEngine GitHub](https://github.com/Dpdl-io/DpdlEngine)

Check the 'DpdlEngine lite' release limitations/restrictions, compared to the full DpdlEngine version, in the last section of this document.

Suggestion and contributions to enhance Dpdl are very welcome and can be submitted on the discussion section on GitHub:
[Dpdl discussion](https://github.com/Dpdl-io/DpdlEngine/discussions)


## What is a DpdlPacket?

A DpdlPacket is a compact, highly compressed executable packet of data with built-in
database technology that can be created based on a defined Dpdl code definition. 
A DpdlPacket can than be allocated and queried efficiently via API
interfaces available for Java and for the built-in Dpdl scripting language.
In particular Dpdl is very efficient on J2ME and JavaME platforms and
has a high degree of backward compatibility.

A DpdlPacket contains 1 - n chunks of compressed data that can be allocated, queried and
deallocated when data is not used.

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
    include("dpdllib.h") nl
    println("OnInit()") nl
}

import virtual DATA none  {
        class BolzanoPhone volatile phonebook_visual {
              DATA::string const name;
              DATA::string using phoneNR;
              DATA::string using  e-mail;
              #defineGUI Default <PhoneBook>  <Enter name and surname:>
              
              catch DPDL_Script OnDecode() {
                 include("dpdllib.h") nl
                 include("dpdlRS.h") nl
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


The database technology in Dpdl has been developed since year 2003 and started with a BsC thesis.

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


## What does the free 'DpdlEngine lite' version provide?


The 'DpdlEngine lite' release is available for Free to try with some limitations (see section below),
and can be used to exploit the features of Dpdl and to develop small applications
or utility tools. Some auxiliary Dpdl libraries are released under the open-source GNU
license.


'DpdlEgine lite' includes:

	- The 'DpdlClient' console application that allows to execute a set of commands
	  for interacting with the core DpdlEngine
	  
	- Dpdl scripting engine with API libraries (Support for Embedded C, C++, Python, Julia, JavaScript, Lua and OCaml)
	
	- Example Dpdl scripts (located in './DpdlPackets/' and './DpdlLibs/' folder)
	
	- Example DpdlPacket (dpdl_PHONEBOOK.dpdl) with corresponding
	  Dpdl code definition file
	


## Dpdl scripting Examples


To execute the examples enter DpdlClient console and use the '-load' command:
```
-load
enter the Dpdl script name to execute:
arraylistExample.h @TEST1
```
The scripts can also be run via the API function DPDLAPI_execCode(..) or with the '-load' parameter at startup.

A set of examples/Tests can be found in the script './DpdlLibs/dpdlLibExamples.h',
where different Tests/Examples can be executed individually via tagged execution, by supplying the @TAG attribute along with the filename.
i.e. arraylistExample.h @TEST1


* Example Dpdl script that shows how <ins>C</ins> code and <ins>Python</ins> can be embedded and executed within Dpdl

	[dpdlFullExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlFullExample.h)
	
* Example Dpdl script that embeds C++ code and uses ROOT API libraries to solve a linear equations in 4 different ways

	[root/dpdlRootSolver.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/root/dpdlRootSolver.h)
	
* Example Dpdl script that compresses and de-compresses a string of data using the Java platform API

	[dataCompress.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dataCompress.h)
	
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
	
* Set of 14 examples/tests. The examples make use of @TAG execution to allow execution of each individual example.
	
	[dpdlLibExamples.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlLibExamples.h)
	
	```
	-load
	dpdlLibExamples.h @TEST1
	```
	
	dpdlLibExamples.h @TEST2 etc..
	
	....

* Example Dpdl script that embeds 'Julia' code to execute a set of threads that call a native C Dpdl API function

  [julia/dpdlJuliaThread.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/julia/dpdlJuliaThread.h)
  
* Load a Dpdl script object "LoadCodeFunc.h" via 'loadCode(..)' and call one of its functions

	[testLoadCode.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testLoadCode.h)
	
	[LoadCodeFunc.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/LoadCodeFunc.h)
	
* Parse JSON and access data types

	[testDpdlJSON.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/testDpdlJSON.h)
	
* Embedded C code execution within Dpdl script
	
	[dpdlSimpleC.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlSimpleC.h)
		
* Embedded Python code execution within Dpdl script
	
	[dpdlEmbedPython.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlEmbedPython.h)
	
* Embedded Lua code execution within Dpdl script
	
	[dpdlLuaBufRet.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlLuaBufRet.h)
	
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
	
* Creates a graphical user interface with some UI components (Button, Panel, Checkbox, List, draw Panel) using Java Swing classes. The list is updated, the button command is intercepted with the
  'actionPerformed' function, the checkbox status is printed, and a text and rectangle is drawn at random location on the draw panel.
	
	[dpdlGUIExample.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlGUIExample.h)
	
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



## 'DpdlEngine lite' release limitations/restrictions

	
The 'DpdlEngine lite' release software package is available for Free to try and has the following limitations/restrictions:

* At startup, the DpdlEngine requires the execution of a validation script.
The script simply accesses a html website at https://www.dpdl.io for validation (NO data is collected or stored, it's a simple get html).
	  
The validation script can be inspected here: 
[./DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h)

* The DpdlEngine parameters and configuration file 'DpdlEngine.ini' can be customized only in the registered version
	
* The class definition file (classes.txt), used for dynamic loading and resolving of library classes via loadObj(..) and getClass(..) methods can be edited only in the registered version of Dpdl.
	
* The execution of Dpdl scripts is limited to 500 lines of code, embedded language code (C, C++, Python, Julia, JavaScript, Lua and OCaml) is limited to 100 lines of code per section.
	
* The Dpdl scripting API function 'systemExec' is available only in the registered version of Dpdl
	
* The interface API to develop custom API extensions (DpdlExtension) is available only in the registered version of Dpdl
	
* The compilation/encoding of DpdlPackets via Dpdl code definition files (ex. dpdl_PHONEBOOK.c) is available only in the registered version of Dpdl
	
* The Dpdl java API is available only in the registered Dpdl version (but Dpdl scripting API is fully available)

* The 'Thread(..)' API function is available only in the registered version of Dpdl (use createThread(..) instead, it provides similar functionality)

* Native 'dpdlpython' api for embedding python within Dpdl scripts is not available on Windows OS

* Dpdl scripts included with 'include(...)' supports execution of embedded code only in the registered version of Dpdl

**NOTE:** The native Dpdl library for embedded C support within Dpdl scripts is currently available for MacOS, Linux x86_64, Windows 64-bit and Raspberry Pi. 
More builds will follow. Eventually it might be necessary to recompile it for some versions of the platform.
Contact us if this is the case.


## How to order a 'full' DpdlEngine license?

To buy a full featured DpdlEngine license with no limitations/restrictions, regular updates and support,
please submit your request via the following request form: 

https://www.dpdl.io/index_order.html

Or just write an e-mail to info@dpdl.io

## Downloads

### Dpdl embedded language plug-in Add-ons:

The following Dpdl language plug-in Add-on contains the Dpdl native library for embedding 'ROOT' and 'Julia' languages.

Available soon...
https://www.dpdl.io/downloads/Dpdl_language_plugins.zip






