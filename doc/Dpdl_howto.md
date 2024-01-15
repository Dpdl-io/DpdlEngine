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


## Dpdl data

### Mapping data in 'json' format

Data in **`json`** format can be mapped to data structures and objects with the 'json' import lib.

**`json.parse(..)`**

This function returns an object that is a map (key/value) of the specified 'json' data.
The object returned implements the same methods as available in a java [HashMap](https://docs.oracle.com/javase/1.5.0/docs/api/java/util/HashMap.html)
The values of the map for example can than be accessed via **`get(..)`** function.

Example:
```python
import('json')

string json_data = "{\"menu\": { \"id\": \"file\", \"value\": \"File\", \"popup\": { \"menuitem\": [ {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},{\"value\": \"Open\", \"onclick\": \"OpenDoc()\"}, {\"valu\": \"Close\", \"onclick\": \"CloseDoc()\"} ] }}"

object json_obj = json.parse(json_data, 0)

println("json_obj: " + json_obj)

object menu_obj = json_obj.get("menu")

bool b = menu_obj.containsKey("id")

println("menu_obj contains key 'id': " + b)

object id = menu_obj.get("id")
println("id: " + id)

object value = menu_obj.get("value")
println("value: " + value)

object popup_obj = menu_obj.get("popup")
println("popup_obj: " + popup_obj)
```

Iterating over json data can be performed in the same way as iterating over a 'HashMap' object:

Example:
```python
object map = json.parse(json_str, 0)

object keys = map.keySet()
object iter = keys.iterator()

object key, val
while(iter.hasNext())
	key = iter.next()
	val = map.get(key)
	println("" + key + "=" + val)
endwhile
```


**`json.decode(..)`**

This function can be used to map json data to a given Dpdl **`struct`** or **`object`**

The tags and values of the json data are mapped to the corresponding variable names and types in Dpdl.

Example:
```python
import('json')

struct Entry {
	int id
	string title
	string url
}

struct Entry myentry

string json_data = "{\"id\":317,\"title\":\"my title\",\"url\":\"https://myurl.test\"}"

myentry = json.decode(json_data, myentry)

println("id: " + myentry.id)
println("title: " + myentry.title)
println("url: " + myentry.url)
```

In the same way as illustrated in the example above, also java classes can be mapped in the same way.
In this case the java class just needs to implement the 'getter' and 'setter' methods for each tag. (e.g setId(int id)).
See example 'app/getnews/dpdlGetNews2.h'


### Storing and accessing data in a Record Store

Dpdl allows to store and access data in Record Stores.

Example:
```python
import("dpdllib.h")
import("dpdlRS.h")

# main
println("testing record store..")

println("creating a record store...")

int rs_id = createRS("myrecords", AUTHMODE_ANY, dpdlTrue, dpdlTrue)

raise(rs_id, "Error: unable to create record store")

println("record store created with id: " + rs_id)

int rec_id
string data
int cnt
while(cnt < 10)
	data = "my test data " + cnt

	rec_id = addRecord(rs_id, data)

	println("record added with id: " + rec_id)

	cnt = cnt+1
endwhile

println("reading data from record store...")

enumRecords(rs_id, dpdlTrue)


while(rec_id != -1)
	rec_id = getNextRecordID(rs_id)
	if(rec_id != -1)
		println("getting record with id: " + rec_id)
		data = getRecord(rs_id, rec_id)
		println("rec_id: " + rec_id + " data: " + data)
	fi
endwhile

println("closing record store...")

closeRS(rs_id)

println("done")
```

Note: On JavaME and J2ME platforms, the platform specific Record Store is used (javax.microedition.rms.RecordStore), without the need to
adapt the code.




