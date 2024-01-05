# Dpdl HowTo

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## Script Execution

### Execute a Dpdl script directly, without entering the Dpdl console

```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -jar DpdlEngine_V1.0_release.jar -load test/testArray.h
```
Note: On newer versions of java (from Oracle), in order to access specific java 'modules' within Dpdl, you may need to enable them with the option '--add-opens'


### Execute a Dpdl script in iterative way

In order to execute a given Dpdl script in an iterative way the script can be executed within a dedicated thread instance using
the Dpdl API function **`DPDLAPI_createThread(..)`**.

The following script executes a given dpdl script (i.e a bluetooth discovery process) as a dedicated thread instance, with a given thread priority
and at a given time interval, over and over.
This is particularly useful for processes that need a stable and robust iteration mechanism.

Example:
```python
import("dpdllib.h")

int processInstance = 0
int PROCESS_REFRESH = 5000
int server = -1

server = DPDLAPI_createThread(processInstance, "bluetoothDiscoverySave.h", dpdlNormPriority, PROCESS_REFRESH)

raise(server, "The process did not start correctly")

println("process started successfully")
```
The advantage in using 'DPDLAPI_createThread(..)' compared to a normal 'Thread(..)' is the fact that the DPDLAPI_createThread(..)
runs the script in a dedicated interpreter execution environment, improving performance and reducing dead-lock pitfalls.

The above script can than be run also in the Dpdl console with the '-load' command.


## Dpdl code

### Loading a Dpdl script as an object

In some circumstances it may be convenient to load a given Dpdl script as an object. 
This offers some advantages compared to the standard 'include(..)' function.
In this case the script is executed within a dedicated interpreter instance and is therefore better for example in a multi-threaded scenario or in the case more DpdlExtensions are loaded and executed.

Note that function calls to dpdl script loaded objects must include the base name of the script loaded. This approach has been chosen for
better readability and also due to performance improvements.

Example dpdl script that loads a dpdl script as object
```c
struct myA {
	string id = "this is an A"
	int y = 23
}

# main
struct myA ana

object myload = loadCode("test/MyLC.h")
myload.myFunc("MyLC")
println("s: " + myload.s)
println("x: " + myload.x)
println("mystr: " + myload.mystr)

myload.s = "assigning a new str"
println("s: " + myload.s)

object mynewstr = loadObj("String", "This is my NEW str")
myload.mystr = mynewstr
println("NEW mystr: " + myload.mystr)

println("printing a struct...")
myload.myFuncStruct("MyLC", ana)
```

MyLC.h
```c
func MyLC()
	println("MyLC()")
end

func myFunc()
	println("myFunc()")
end

func myFuncStruct(struct a)
	println("a: " + a)
	println("a.id: " + a.id)
	println("a.y: " + a.y)
end

# main
string s = "this is my loaded Obj"
int x = 23
object mystr = loadObj("String", "MyLoadObj str")

return 1
```
Note: The dpdl script loaded must always return a status (int) in order to load successfully (1) or with error (-1)


### Data exchange with embedded code via the Dpdl stack

The embedding of other programming languages within Dpdl is straight forward and requires only the appropriate keyword e.g. **`>>c`**
to initialize the embedding of code. Exchanging data with embedded code is a bit more tricky.

Data can be exchanged with the embedded code via the Dpdl stack.

The function **`dpdl_stack_push(..)`** can be used to push variables onto the Dpdl Stack which are than forwarded to the embedded code
as standard parameters in most cases.

The embedded code can also write data to the Dpdl stack which can than be intercepted again in Dpdl code via a given keyword that
is pushed as a string variable onto the Dpdl stack prior to the embedding of the code.

Within the embedded C code the function **`dpdl_stack_buf_put(..)`** can be used to write data (a char* buffer) to the memory buffer mapped
to the keyword specified. The maximum size of the memory buffer is currently fixed to 4096 bytes (but can be changed in the registered version of DpdlEngine)

The size of 
The following example shows how this can be done with embedded C code:
```python
dpdl_stack_push("dpdlbuf_myvar1")
>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	printf("writing to buf...\n");
	char *buf = "MEGA";
	dpdl_stack_buf_put(buf);
	
<<
string buf = dpdl_stack_buf_get(""dpdlbuf_myvar1"")
println("response buffer: " + buf)
```


