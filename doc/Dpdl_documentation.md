# Dpdl Documentation

				www.dpdl.io

	


## Dpdl scripting language

**Features:**
* Types supported (**int, byte, double, float, long, string, bool, array[], object**, struct)
* Native Threads
* support for pointers and references (eg. int *px = &x)
* APIs: native API, Dpdl API, MIDP API, JRE API
* Access to the full underlying Java Platform API (JRE) or other external java libraries
* Record Store creation and access with virtual file system support
* Static script execution: static code declarations (*.h_static) are executed only once in a Thread
* Support for custom function extensions
* Embeddable languages: **ANSI C code, C++, Python, Julia, JavaScript, Lua and OCaml**. These programming can be embedded directly within Dpdl scripts (interpreted/compiled code).
* Other programming languages can be easily integrated via a defined plug-in interface and configuration
* ANSI C code embedded within Dpdl scripts can be dynamically compiled in memory at runtime (see option 'dpdl:compile')
* Tools for converting Dpdl scripts to Java and C/C++ code (in development)


### Variables

Dpdl support the following type definitions:
```python
int i = 1
float f = 0.1
double d = 1.0d
long l = 1000L
byte b = 0x01 
string s = "mystr"
bool t = true | false
array[] = "1 1.0 0x01 test"
object myobj = loadObj(..)
struct myStruct a
```

### Array

Arrays are defined with '[]'

Arrays support multiple types and can be accessed also as a [ArrayList](https://docs.oracle.com/javase/1.5.0/docs/api/java/util/ArrayList.html) object (see getObj() )

Example:
```python
myarray[] = "1 1.0 0x01 test Dpdl Dynamic Packet Definition Language"

# this returns an arraylist
myarray2[0]  = myarray.getObj()

object myarrayobj = myarray2[0]

bool b = myarrayobj.contains("Dpdl")

println("array contains Dpdl: " + b) 
```

The array elements can be separated with blank space ' ', with comma ',' or with simicolon ';'. All are valid.

```
arr1[] = "1 2 3 4 5"
arr2[] = "1,2,3,4,5"
arr3[] = "1;2;3;4;5"
arr4[] = "[1,2,3,4,5]"
```

### Struct

Dpdl supports the type 'struct'

Example:
```c
struct myStruct {
	int x = 10
	float f = 0.1
	double d = 0.3d
	long l = 1000L
	byte b = 0x01
	string s = "Test"
}

struct myStruct a

println("a.x: " + a.x)
a.x = 23
println("a.x: " + a.x)
```

### Pointers

Dpdl supports a form of 'pointers' (eg. int *ptr = &x ), as in C/C++, Objective-C, go and others.

The types supported by pointers are:

* int
* string
* float
* double
* object



Example:
```python
func myFuncPtr(object *testp, string *sp, int *xp)
	*sp = *testp + " " + *sp + " " + "TIE"
	*xp = 369
end

func printVarAndPtr()
	println("test_obj: " + test_obj)
	println("s: " + s)
	println("x: " + x)
	println("testp: " + *testp)
	println("sp: " + *sp)
	println("xp: " + *xp)
	println("")
end

# main
println("testing pointers...")
println("")

# variables
object test_obj = loadObj("String", "MEGA")
string s = "mega"
int x = 10
int z = 3

# pointers
object *testp = &test_obj
int *xp = &x
string *sp = &s

printVarAndPtr()

println("changing vars....")
s = "metatie"
x = 100

printVarAndPtr()


println("call myFuncPtr(..)")
println("")
myFuncPtr(testp, sp, xp)
println("Value changed: " + *sp)
println("Value changed: " + *xp)

float f = 1.0
double d = 2.0d
object str = loadObj("String", "TestPtr")

println("assign pointers...")
println("")
float *fp = &f
double *dp = &d
object *str_p = &str

println("*fp: " + *fp)
println("*dp:" + *dp)
println("*str_p: " + *str_p)

println("done")
```

### Dpdl Threads

Threads can be created inside Dpdl scripts with the 'Thread(..)' api function.

Multiple threads are allowed inside a single Dpdl script.

The function 'Thread(..)' accepts as parameters a function callback and the time interval for the thread iteration (in milliseconds).
Optionally the number of iterations for a Thread can also be provided

Example Thread(..) invocation:
```python
int thread_id = Tread("myFunc", 1000, [3])
```

Example starting 2 threads
```python
func myThreadFunc1()
	println("Hello from thread 1")
end

func myThreadFunc2()
	println("Hello from thread 2")
end

# start a thread with an interval of 2000 milliseconds
println("starting a Dpdl threads...")
int tId1 = Thread("myThreadFunc1", 2000)
if(tId1 != -1)
	println("Thread started with id: " + tId1)
else
	println("Error in starting thread")
fi

# start a thread with an interval of 7000 ms and for 3 iterations
int tId2 = Thread("myThreadFunc2", 7000, 3)
if(tId2 != -1)
	println("Thread started with id: " + tId2)
else
	println("Error in starting thread")
fi
```

### Function and Control flow

**function** definition
```python
func myFunction(string param, object param....)

end
```

**if** statement
```python
if(<expression>)

fi
```

**if else** statement
```python
if(<expression>)

elseif

else

fi
```

**while** statement
```python
while(<expression>)

endwhile
```

### Arithmetic and logical operators

**Arithmetic:** 
	
* addition: +
* subtraction: -
* multiplication: *
* division: /
* modulo: %
* negate a value: - (eg. -1)
	
Note: for multiplication (*) it's necessary to have blank spaces between the numbers and operator (ec. 1 * 2). This is currently not allowed: 1*2
	
**Logical:**

* &&
* ||
* ! 
	
**Comparators:**

* > (greater than)
* < (less than)
* >= (grater than equal)
* <= (less than equal)
* == (equal)
* != (not equal)
	
	
### Dpdl API functions

The Dpdl API functions usable inside Dpdl scripts are listed here:

[Dpdl scripting API Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)


### DpdlObject's and Java bindings

Dpdl can access the underlying classes of a given JRE implementation or any other external java library.

The classes are loaded within a DpdlObject that is handled by the Dpdl runtime.

Static classes can be accessed via '**getClass(..)**' method and instance classes via '**loadObj(..)**' method.

The class references are resolved via the 'classes.txt' file located in the folder ./DpdlLibs/libs/.
You may add your own class references here with the syntax: '$full_class_name $class_alias'

NOTE: Only the full registered version of Dpdl allows editing of this file. The default 'DpdlEngine lite' configuration contains
the class references of Java Platform JRE 1.5 and Bluetooth JSR-82 API.

Example:
```python
# static class loading
object calendar = getClass("Calendar")
object cal_inst = calendar.getInstance()
int day_ = cal_inst.get(calendar.DATE)
println("day: " + day_)

# instance class loading
object str = loadObj("String", "Test MyString")
int idx = str.indexOf(" ")
string substr = str.substring(idx)
println(substr)
```

### Load Dpdl script as DpdlObject

Dpdl scripts can be loaded as an ordinary DpdlObject

```python
println("test loadCode(..) with dpdl script LoadCodeFunc.h")

object mycode = loadCode("LoadCodeFunc.h")

string mystr1 = "Test"
object mystr2 = loadObj("String", "MEGA")

mycode.testFunc("LoadCodeFunc", mystr1, mystr2)

println("done")
```

The script file loaded in the example above 'LoadCodeFunc.h' may also define a **constructor**, which is called
iff parameters are supplied.

LoadCodeFunc.h
```python
# constructor
func LoadCodeFunc(string map)
	println("object LoadCodeFunc loaded")
	println("map: " + map.toString())
end

...
```

The constructor is called if a parameter is supplied
```python
object mymap = loadObj("HashMap")
object mycode = loadCode("LoadCodeFunc.h", mymap)
```



### Dpdl embedded C code

Dpdl allows the embedding and execution of ANSI C code (a minimal subset of C90, and ISO C99 standard) directly within Dpdl scripts.

Embedded C code can be executed in 2 different modes:

1) Interpreted C code (<ins>minimal subset of C90</ins>) --> easy integration of custom extensions. No compile time overhead (**default mode**)
2) Compiled (in memory at runtime) or interpreted C code (<ins>ANSI C99</ins>) --> fast compile time and FAST execution (can be activated via options '**dpdl:C99**' and '**dpdl:compile**'

The faster and more complete execution mode (2) can be activated by pushing the option '**dpdl:C99**' or '**dpdl:compile**' on the dpdl stack (-> see 'dpdl_stack_push(..)'):

The C code is executed with mode (1) includes only a minimal subset of the C library and is POSIX compliant (also on Windows OS). It's very compact (only ca. 400 Kb on Raspberry Pi) and has no extra dependencies.
Custom libraries and functions can be implemented and added if needed via dpdl api functions.

To embed C code within Dpdl scripts use the keyword '**>>c**' to start the embedded code, and the keyword '**<<**' to end the embedded code (Note: The keyword has to be on a single line)

Example:
```python
println("executing embedded C code..")
>>c
	#include <stdio.h>
	
	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);
```

Parameters and data can be passed to the interpreter via the '**dpdl_stack_push(..)**' API function.
Data can be written to and read from to the dpdl stack using the '**dpdl_stack_buf_put(..)**' and '**dpdl_stack_buf_get()**' API functions.

Pushing a variable 'dpdlbuf_*" on the dpdl stack, allows to later retrieve by the data buffer that has been written
in the C code via the '**dpdl_stack_buf_put**' function (for example the result of a calculation)

Example:
```python
println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0d
string a = "test"

dpdl_stack_push("dpdlbuf_var1",n, x, a)

>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    	char *buf = "My result";
		dpdl_stack_buf_put(buf);
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);
string buf = dpdl_stack_buf_get("dpdlbuf_var1")
println("response buffer: " + buf)
```

The default memory stack size for the C interpreter is kept small and is configured to be 128 Kb.

The stack size can be customized by applying configurable settings.

The Dpdl native API library 'dpdlnativeapi' provides a Security check to guarantee that the library have not been compromised.
Therefore the embedded C code execution cannot be mangled internally and guarantees the correct execution of C code.
In the case the library is updated, the corresponding verification checksums needs to be adjusted in 'DpdlEngine.ini" config.

**Dpdl embedded C library documentation:**
[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)


### Embedding of Python

Python code can be embedded within Dpdl script by using the keyword '**>>python**'.

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

**Note:** The environment variable '**PYTHONHOME**' and '**PYTHONPATH**' need to be set correctly for finding the python libraries
```
export PYTHONHOME=/your_path/to/python/install_dir/
export PYTHONPATH=/your_path/to/python/install_dir/
``` 

The indentation needs to be consistent with the Python language specification.

The Dpdl runtime considers the '**>>python**' tag as starting indentation point

example (correct):
```python
println("start executing a python script...")

>>python
print("Hello py\n")
<<
	
println("finished")
```

example (Wrong -> gives IndentationError: unexpected indent):
```python
println("start executing a python script...")

>>python
	print("Hello py\n")
<<
	
println("finished")
```

### Supported platforms

Currently the 'DpdlEngine lite' release includes the native Python library '**libdpdlpython**' for **MacOS (arm64)**, **Linux (x86_64)** and Raspberry PI 3 (armv7l)

**Linux:** Python version 3.2m (gcc version 4.4.7)
**MacOS:** Python version 3.12 (Apple clang version 14.0.3)
**Raspberry PI 3**: Python version 3.2m (gcc version 4.4.11)
Windows version will follow soon in the coming release


Support for more platforms will be released soon. MicroPython will also be available as option.

### Embedded OCaml code (experimental)

Dpdl supports the embedding of OCaml code directly within Dpdl scripts through the **'>>ocaml'** keyword.

The embedded OCaml code is executed by the Dpdl runtime through the 'ocamljava' library (http://www.ocamljava.org/) and
requires the following jar library located in the lib folder './lib': 'ocamlrun-scripting.jar' 

If the 'compile' option has been set (OCaml code is compiled at runtime to improve speed), also the 'ocamljava.jar'
needs to be present in the lib folder.

Example Dpdl script with embedded 'OCaml' code:
```python
println("testing Dpdl embedded OCaml..")


# parameter to instruct the Dpdl runtime to compile the embedded code (faster execution). Without this option the code is interpreted

dpdl_stack_push("dpdl:compile")

# we add a variable to the dpdl stack so that we can access it in the embedded OCaml
dpdl_stack_var_put("var1", "Hello OCaml from Dpdl")
dpdl_stack_var_put("nr_iter", "Dpdl")
>>ocaml
external get_binding : string -> 'a = "script_get_binding";;

let s : string = get_binding "var1";;
let n = Int32.to_int (get_binding "nr_iter");;

for i = 1 to n do print_endline s done;;
<<

int exit_code = dpdl_exit_code()

println("embedded OCaml exit code: " + exit_code);

```

NOTE: The 'ocamljava' library can be downloaded from http://www.ocamljava.org/downloads/
	
### Exception handling using 'raise(..)'

Exceptions can be handled with the 'raise(..)' function. 

The following conditions are checked and an exception is raised if the conditions == false:

	* string -> (condition =! "null") ? true : false 
	* int -> (condition =! -1) : true : false
	* bool -> (condition == true) ? true : false
	* object -> (condition =! null) ? true : false


The raise(..) function can be called in the following ways:

```python
raise(object condition)
raise(object condition, string msg)
raise(object condition, string msg, bool exit)
```

Example:
```python
string s1 = "nul(l)"
raise(s1, "s1 is null")

println("testing int raise")
int i = 1
raise(i, "i == -1")

println("testing bool raise")
bool b = true
raise(b, "b == false")

println("testing object raise")
object o = loadObj("String", "test")
raise(o, "o == null")

println("testing bool expression raise")
raise(o =! null, "o =! null")

dpdl_print_exception_table()
```

In order to enable the execution of OCaml code via the keyword '**>>ocaml**', the 'ocamlrun-scripting.jar' library jar file
located in the lib folder (./lib) is required (download from www.ocamljava.org)

If the 'compile' option has been set (the OCaml code is compiled at runtime to improve speed) --> dpdl_stack_push("compile"),
also the 'ocamljava.jar' file needs to be present in the './lib' folder.

Other programming languages may also be supported in future. Please feel free to suggest your opinion on the
Discussion section on the DpdlEngine GitHub repository


### Extensions

The Dpdl language can be extended by implementing specific interfaces for custom
function and variable declarations.

The implemented extensions can be registered via settings in the "Extensions" section
defined in the 'DpdlEngine.ini' configuration file.

Example of a custom print function, myprintln(..):
```java
import dpdl.dpdlDpdlEngine.scripting.BasicDpdlExtension;

public class MyTestDpdlExtension extends BasicDpdlExtension{

    public Object dpdlCall(String name,ArrayList param) throws DpdlException {
			// implement you methods here
    }
}
```


## DpdlClient

DpdlClient is a console application that allows to use Dpdl via commands.

The following commands are available:
```
 -l  List DpdlPackets installed
 -i  Install DpdlPacket
 -d  Uninstall DpdlPacket
 -la List DpdlPackets allocated
 -a  Allocate DpdlPacket
 -da Deallocate DpdlPacket
 -qp Query DpdlPacket (needs to be allocated first)
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

To run to DpdlClient console application you need Java JRE >= 1.5 and run the following command:
```
java -jar DpdlEngine_V1.0_release.jar
```

To execute a Dpdl script directly use the '-load' parameter at DpdlEngine startup:
```
java -jar DpdlEngine_V1.0_release.jar -load yourScript.h
```

NOTE: The newer release of Java (Java20) has introduced the concepts of 'modules'. A compliant 
version of DpdlEngine will be released soon.

If you need to run the DpdlClient on the latest version of Java, use the following command and add the modules you want to access via Dpdl scripting:

```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -cp ./lib/mjcoap.jar -jar DpdlEngine_V1.0_release.jar
```


## 'DpdlPacket' definition language

Dpdl allows to create compressed packets of data via a DpdlPacket code definition. The data in a DpdlPacket can be organized
in chunks of highly compressed data, along with database indexes. Data chunks can be allocated, queried and deallocated when not
needed anymore. This allows a very efficient method of accessing and searching big amounts of data in memory constrained 
devices.

Dpdl scripting can be embedded in the DpdlPacket code definition and allows to trigger its execution on predefined callbacks.
This makes a DpdlPacket an executable packet of data.

This is an example DpdlPacket code definition (a phonebook database):
```c++
call(dpdlInterpreter)
::module dpdl_PHONEBOOK_BZ
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

The DpdlPacket as defined above, can be allocated and queried via Dpdl scripting API or via the equivalent Java API

```python
int status = DPDLAPI_swapDpdlChunk("dpdl_PHONEBOOK_BZ", "BolzanoPhone")
if(status == dpdlTrue)
	status = DPDLAPI_selectDpdlService("dpdl_PHONEBOOK_BZ",, "BolzanoPhone", "armin 369")
fi
```

The first time a DpdlPacket is allocated (swapped), data is decompressed in a temporary storage. This process takes some time for the 1st allocation,
but is immediate for subsequent allocations, as long as the DpdlPacket is not explicitly deallocated.

### Data Types

A DpdlPacket chunk allocation supports the following types:

```c++
int
string
char
double
float
long
byte
Image
class
xml
dpdlpacket
```

## Run Dpdl scripts

To run the Dpdl scripting examples start the DpdlClient by executing the following script:

on Linux/MacOS
```
./run_DpdlClient.sh
```

on Windows
```
./run_DpdlClient.bat
```


You can execute Dpdl scripts in the following ways:

	* Load and execute the Dpdl script file with the -load command
	* Input the script directly in the DpdlClient command console with the -exec command ( with closing </script> tag)
	* Via '-load' parameter to the DpdlClient startup script/command
	* Trough the Dpdl API.


1) using 'load' command:
```
-load
enter the Dpdl script file to execute:
arraylistExample.h
```

2) using 'exec' command:
```python
-exec
<script>
string str = "this is a test"
println(str)
</script>
```

3) using the -load command as startup parameter:
```
run_DpdlClientScript.sh 
```

4) using the Dpdl API
```
int status = DPDLAPI_execCode("sample.h", "null)
``

Here you can find all methods available for the Dpdl scripting API: 

[Dpdl_API](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

Dpdl allows to access all java classes of the underlying JRE environment,
providing access to the whole Java platform API via the loadObj(..) and the getClass(..)
Dpdl scripting API methods.

In this way Dpdl can access the classes and api of external java libraries.

Example (using String java class with method 'contains(..)':
```python
object str = loadObj("String", "This is my Java object string")
bool contains = str.contains("Java")
if(contains)
	println("The string contains the word 'Java'")
else
	println("The string does NOT contain the word 'Java'")
fi
```

The class references resolved by the methods 'loadObj' and 'getClass' are defined via the class reference file:
./DpdlLibs/libs/classes.txt

NOTE: This file can be edited or complemented only in the registered, Licensed version of Dpdl.


**Example:** (Compress and de-compress a string of data)
```python

#main

object str = loadObj("String", "my data for Dpdl")
println("string to compress: " + str)

object byte_out = loadObj("ByteArrayOutputStream")
object zip_out = loadObj("GZIPOutputStream", byte_out)

println("compressing...")
zip_out.write(str.getBytes())
zip_out.close()
println("data compressed successfully")

object compressed_str = byte_out.toString()
println("compressed string: " + compressed_str)

println("decompressing...")
object byte_in = compressed_str.getBytes()

object byte_arr_in = loadObj("ByteArrayInputStream", byte_in)
object zip_in = loadObj("GZIPInputStream", byte_arr_in)

object in_reader = loadObj("InputStreamReader", zip_in)
object buf_reader = loadObj("BufferedReader", in_reader)

string decompressed_str = ""
string line = ""
while(line != null)
	line = buf_reader.readLine()
	if(line != null)
		decompressed_str = decompressed_str + line
	fi
endwhile
println("decompressed: " + decompressed_str)

```


## DpdlPacket example (installation, allocation and query)

The Demo release of Dpdl includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl) that has 48877 data entries (name, phoneNR, e-email).

The packet is approximately 1,2 MB in size and has been encoded with the following Dpdl source script (dpdl_PHONEBOOK.c):


To run the example

1. start the DpdlClient by executing the following script:

on Linux/MacOS
```
./run_DpdlClient.sh
```

on Windows
```
./run_DpdlClient.bat
```

2. install the DpdlPacket (dpdl_PHONEBOOK.dpdl) which is located in the folder ./DpdlServices/data/

	execute the command -i and enter the packet name: 
	
	```
	-i
	enter the DpdlPacket to install:
	dpdl_PHONEBOOK
	```
	


3. allocate the DpdlPacket and the corresponding data chunk:

	execute the command -a and enter the packet name and data chunk name to allocate:
	
	```
	-a
	enter the DpdlPacket to allocate ($dpdl_packet:$chunk_name:)
	dpdl_PHONEBOOK:BolzanoPhone
	```
	
	The DpdlPacket will be de-compressed and allocated ready to query. The 1st time a packet is allocated it takes 
	some time, subsequent allocations are immediate

	
4. run the query console example script

	execute the command -load and enter the query console example script:
	
	```
	-load
	enter the Dpdl script name to execute:
	testDpdlDB2.h
	```
	
	
	The script allows to perform either a single query, or n sequential or random queries, and measures the execution
	time for searching and accessing data:
	
		1) To perform a single query (press 'q')
		
		2) To execute sequential or random queries, for each of the data entries (press ENTER)
		   and than enter '**armin**' as constraint base name, which is part of the key of each data entry:
		   i.e. "armin 1, armin 2, ..."
		   
		   For random vs. sequential queries comment or uncomment the following line of code in the script
		   -> i #abs(search_rand_int) 
		

## DpdlEngine configuration

Dpdl provides the following configuration options for the DpdlEngine, through the 'DpdlEngine.ini' config file

'DpdlEngine.ini' example:
```
[DpdlBase]
MAX_SCRIPT_THREADS=3
MAX_BTCLIENTS=1
MAX_DATA_STRUCTURES=10
MAX_GUI_DEFINITIONS=10
MAX_RESULT_SET=100
MAX_CONSTRAINTS=2
MAX_VAR=50
POINTERS=10
MAX_MENU_ENTRIES=10
MAX_MULTIPLE_DECOMP_STORES=4
DPDL_STORAGE_PATH=./DpdlServices/data/
DPDL_SCRIPT_REPOSITORY=./DpdlScripts/
DPDL_LIBRARY_PATH=./DpdlLibs/
IS_BTREE_CACHE_ACTIVE=true
IS_PAGER_CACHE_ACTIVE=false
PRELOAD_CACHE_PAGER=4096
MAX_SPACE=32000000
[DpdlConfig]
EXEC_STARTUP_CODE=false
DPDL_NATIVE_LIB=dpdlnativeapi
[DpdlPath]
DPDL_JAVA_LIB_PATH=./lib:./lib/ext
[DpdlExtensions]
mytestext=dpdl.dpdlDpdlEngine.extensions.MyTestDpdlExt
[DpdlCustom]
python=dpdlpython
lua=dpdllua
julia=dpdljulia
root=dpdlroot
test=dpdltest
```
Note: This file can be edited only in the registered version of Dpdl

	
## Performance Benchmarks

### Embedded C

As the embedded C code is interpreted at runtime, it's obviously a bit slower than compiled C code, but 
interpreted code offers the advantage of easy and fast portability, reduces the complexity of compilation
for different target platforms and hence speeds up the development process.

This simple benchmark gives the following results:

* **Dpdl script embedded C code**, mode (1), execution time: 8.0 seconds
* **Dpdl script runtime compiled C code**, mode (2), execution time: 5.0 seconds
* **Compiled C code** (gcc compiler), execution time: 5.0 seconds
* **Compiled Java code**, execution time: 5.7 seconds

C code used for benchmark:
```c
	#include <stdio.h>
	#include <time.h>
	
	int main(int argc, char **argv){
		printf("Dpdl C Bench\n");
		printf("\n");
	    time_t start;
	    time_t end;
	    time(&start);
	    int c;
		for(c = 0; c < 5000000; c++){
			printf("iter %d \n", c);
		}
		time(&end);
		printf("\n");
		double exec_time = difftime(end, start);
		printf("Exec time: %lf", exec_time);
	    return 0;
	}
```

Java code used for benchmark:
```java
public class testCBench {

	public testCBench(){
		System.out.println("testCBench()");
	}

	void run(){
		long start = System.currentTimeMillis();
		for(int c = 0; c < 5000000; c++){
			System.out.println("iter " + c);
		}
		long end = System.currentTimeMillis();
		System.out.println("Exec time: " + (end-start));
	}

	public static void main(String[] args){
		new testCBench().run();		
	}
}
```

### DpdlPacket data query and access

The benchmark has been performed on a data set of 48877 entries (name, phone nr, e-mail), with the 'name' numbered
sequentially i.e 'armin 1', 'armin 2', etc.

48877 queries with a random number has key constraint have been performed:
	* With data packed in a DpdlPacket
	* Data stored in a simple RecordStore
	

#### DpdlPacket queries

Average execution time for 48877 random queries: 2 milliseconds


#### Record Store data access (on JavaME Embedded Profile)

Queries on a JavaME RecordStore are feasible only with via RecordFilter and RecordComparator classes) but which is not applicable 
in terms of speed (too slow).

Anyhow the average record store access time for 48877 entries is: 55 milliseconds

