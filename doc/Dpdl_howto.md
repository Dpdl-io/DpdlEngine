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


## Execute a Dpdl script in iterative way

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


## Loading a Dpdl script as an object

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

