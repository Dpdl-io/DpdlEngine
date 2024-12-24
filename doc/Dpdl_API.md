# Dpdl API documentation

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		

## Dpdl API documentation

DpdlEngine V1.0
		
This is the Dpdl API documentation. 

The Dpdl API's are available as:
- Native java API's
- Dpdl import Libraries
- Native Libraries
- Dpdl native functions

### Native java APIs

Dpdl allows to load and access java classes and methods (JRE and external java libraries) via the dedicated Dpdl API functions **`loadObj(..)`** and **`getObj(..)`**.

This allows Dpdl to access a broad set of API's and libraries.

By default 'DpdlEngine lite' includes the Java <ins>**JRE API**</ins>, the <ins>**JavaFX API**</ins> and the <ins>**Bluecove JRS-82 API**</ins>, further libraries can be included by means of configuration:

[Java JRE API](http://www.seesolutions.it/apidoc/Java_Platform_API_1_5.html)

[JavaFX API](https://docs.oracle.com/javafx/2/api/index.html)

[Bluetooth JSR-82 API](https://docs.oracle.com/javame/config/cldc/opt-pkgs/api/bluetooth/jsr082/index.html)

**Example:** using a java JRE class 'java.util.MashMap'

```python
object myhashmap = loadObj("HashMap")

myhashmap.put("my key1", "my value 1")

```

The 'DpdlEngine pro' allows also to register dynamically external java libraries as described below.


#### Registering external java libraries at runtime

External java libraries packed in '*.jar' files can be dynamically registered at runtime to make them available in Dpdl:


**Example:**

```python
# register dynamically a jar file containing the java class 'MyTestClass'

int load_lib = DPDLSYS_registerLib("./lib/custom/MyTestLib.jar")

raise(load_lib, "Error in loading java lib")

# now we can instantiate a Dpdl object from the contained java classes

object myobj = loadObj("MyTestClass")

...

```

### Dpdl import Libraries

Auxiliary API libraries can be imported and used via the **`import(..)`** statement.

The import libraries are implemented either in Dpdl (with '*.h' extension located in './DpdlLibs/libs/' folder),
OR are implemented in a native java library that can be configured to be accessed via Dpdl in a easy and straight forward way.


```python
import('io')
import('http')
import('json')
import('native')

import('mylib.h')
```

**`io`**
```python
readStr(string file) return string data
writeStr(string file, string data) return bool status
```

**`http`**

the library exposes the following methods and objects:
 
[Http javalite](https://www.dpdl.io/doc/apidocs/org/javalite/http/Http.html)

```python
getraw(string url) return string response
```

Example:

https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/http/dpdlHttpExample.h

**`json`**
```python
parse(string json) return object json
encode(struct data) return string json
decode(string json, struct data) return struct data
decode(string json, object data) return object data
```

Example:

https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/json/dpdlDecodeJSON.h


**`native`**
```python
loadLib(string lib) return object lib
mapLib(string lib, object class) return object lib
```

Adding custom libraries is straight forward and can be done by simply adding the implementation to the classpath and 
configure the library in the configuration file 'DpdlEngine.ini'

Example:

https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/native/dpdlTestNative.h


### The Native libraries:

Dpdl allows to access natively loaded libraries (libc, msvcrt, etc..) on different operating systems (Linux, Windows, Android) throught a unified interface.

To load and access a native lib the Dpdl 'native' library module needs to be imported.

Example:
```python
import('native')

object libc = native.loadLib("c")

libc.printf("Hello native function call to libc, my msg: %s %d\n", "MEGA", 9)
```

For more details visit the doc:

[Dpdl_native_Interface.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_native_Interface.md)


### Dpdl native functions

The following API function are implemented directly in the DpdlEngine core:

```python
include(string inc_path) return int
import(string lib_path) return int

getObj(string name) return object
loadObj(string name, object params, ...) return object
loadCode(string dpdl_script_ref, object args, ...) return object
genObjCode(object dpdl_obj) return object obj

arr(object elem, ...) return object ArrayList
vec(object elem, ...) return object Vector
map(string elem, ...) return object HashMap
list(object elem, ...) return object LinkedList
stack() return object Stack

cast(object obj) return dpdl_object
typeof(object o) return string type_str
convert(string type, object obj) return object converted_obj
to_int(object val) return int value
to_float(object val) return float value
to_double(object val) return double value
to_long(object val) return long value

array[] ->
size() return int size
getArrObj() return object arraylist
array(object o) return [] array

println(string s)
print(string s)
currentTimeMillis() return long time
nanoTime() return long time
systemExec(string cmd, int wait_for, int verbose_output) return int status
hash(string s) return int res
mod(int val, int mod) return int res
randInt(int bound) return int res
randInt(int bits, int modulo) return int res
nextInt(int modulo) return int res
abs(int val) return int res
sqrt(double val) return double res
substring(string str, int off_start, int off_end) return string res
replace(string str, string find, string replace) return string res
strlen(string str) return int len
endsWith(string str) return int bool
parseInt(string str) return int value
getDateStamp() return string date
getDateField(int field) return int date
getTime() return string time
setStartTime()
getEndTime() return int time
readln() return string line
sleep(int time_ms) return int status
putMemArrayInt(int array_id, int val) return int status
getMemArrayInt(int array_id, int index) return int entry
putMemArrayStr(int array_id, string val) return int status
getMemArrayStr(int array_id, int index) return string entry
allocMemArray(int id, int minsize) return int status
getMemArraySize(int id) return int size
isInArr(int array_id, object obj)
open(string file, string mode) return int handle
eof(int handle) return int status
close(int handle)
write(int handle, string str)
writeStream(int handle, string obj, ..)
read(int handle) return string str
listFiles(string dir) return string array_list
api()
getApi() return string api
exit(int exit_code)
gc()

[Dpdl stack]
dpdl_stack_push(object params, ...)
dpdl_stack_push(string key, object params, ...)
dpdl_stack_buf_put(string key, string value) return int status
dpdl_stack_buf_get(string key) return string value
dpdl_stack_var_put(string key, string value) return int status
dpdl_stack_var_get(string key) return string value
dpdl_stack_var_glob_put(string key, string value) return int status
dpdl_stack_obj_glob_put(string key, object obj) return int status
dpdl_stack_var_glob_get(string key) return string value
dpdl_stack_obj_glob_get(string key) return object obj
dpdl_stack_obj_put(string key, object obj) return int status
dpdl_stack_obj_get(string key) return object obj
dpdl_runtime_push(string param1, ...)
dpdl_res_pop_id() return object res_id
dpdl_res_obj_get(object res_id) return object res
dpdl_res_obj_get_name(string res_name) return object res
dpdl_res_clear()
dpdl_task_pop_id() return object task_id
dpdl_task_obj_get(object task_id) return object task
dpdl_exit_code() return int exit_code

[Exception handling]
raise(object condition) return int status
raise(object condition, string msg) return int status
raise(object condition, string msg, bool exit) return int status
dpdl_print_exception_table()

[thread]
Thread(string func_name) return int thread_id
Thread(string func_name, int interval_ms) return int thread_id
Thread(string func_name, int interval_ms, int nr_iterations) return int thread_id
setThreadPriority(int thread_id, int priority) return int status
dpdl_thread_finalize(int t_id, object param...)

[ActionListenerInterface]
actionPerformed(string event)

[DpdlJavaFXApp]
dpdl_javafx_start(object stage)

[KeyEventHandler]
handleKeyEvent(object key)

[MouseEventHandler]
handleMouseEvent(object event)

[DpdlFXMLController]
handleButtonAction(object event)

[DpdlCoAPServer]
DpdlCoAPServer(int port, int max_block_size, int verbose, int write_mode, string resource, string resource_type, string resource_value) return object coap_server
start() return bool status
setResource(string resource, string resource_type, string resource_value) return bool status

[DpdlCoAPClient]
DpdlCoAPClient(string coap_uri, int port, int max_block_size, int verbose) return object coap_client
getClient() return object dpdl_coap_client
request(string coap_uri, string request, string request_type, string request_value, object DpdlCoAPResponseHandler)

[DpdlCoAPResponseHandler]
onRequestFailure(string message)
onResponse(string response)

[DPDLAPI]
DPDLAPI_getVersion()  return string
DPDLAPI_getEngineVersion() return string
DPDLAPI_getResultSet(int pos, string variableName) return string
DPDLAPI_getNrResults() return int
DPDLAPI_mallocDpdlService(string serviceName) return status
DPDLAPI_selectDpdlService(string serviceName, string chunk, string contraint)  return status
DPDLAPI_swapDpdlChunk(string serviceName, string chunkName) return status
DPDLAPI_processXPath(string filepath, string query) return string result
DPDLAPI_getXPathNrResults() return int
DPDLAPI_getXPathResult(int index) return string result
DPDLAPI_printDpdlScript(string package_name, int mode, string file) return int  desc-> STDOUT: mode = 0   FILE: mode = 1 
DPDLAPI_callExtension(string extension_function) return int
DPDLAPI_clearCache(string class_name) return int
DPDLAPI_processXPathVar(string var_name, string query, string mode, string outputFile) return int
DPDLAPI_createThread(int instance, string script, int priority, int milliseconds) return int status
DPDLAPI_createThread(int instance, string script, int priority, int milliseconds, int nr_iterations) return int status
DPDLAPI_callThread(int instance, String func_name, object param, ...
DPDLAPI_threadRunning(int instance) return int status
DPDLAPI_execScript(string script) return int status
DPDLAPI_execCode(string file) return int status

[DPDLAPI Bluetooth]
DPDLAPI_discoverBTDevices() return status
DPDLAPI_discoverBTFinished() return int status
DPDLAPI_createBTServer(int inquiryCode, int authentication, int authorization, int encryption)  return int status
DPDLAPI_createBTClient(int instance, int inquiryCode, int authentication, int authorization, int encryption) return int device
DPDLAPI_sendClientData(int device, string data) return int status
DPDLAPI_readClientData() return string data
DPDLAPI_clearClientTX(int device) void
DPDLAPI_clearClientRX(int device) void
DPDLAPI_discoveryClientFinished() return int status
DPDLAPI_serviceDiscoveryClientFinished(int client_instance) return int status
DPDLAPI_getClientBTAddr(int client_instance) return string addr
DPDLAPI_getServerBTAddr() return string addr
DPDLAPI_getServerVisibleBTAddr() return string addr
DPDLAPI_searchClientsOnServer() return int status
DPDLAPI_discoveryServerFinished() return int status
DPDLAPI_serviceDiscoveryServerFinished() return int status
DPDLAPI_connectServerToClients() return int status
DPDLAPI_sendServerData(string data) return int status
DPDLAPI_readServerData() return string data
DPDLAPI_disconnectServerToClients() return int status
DPDLAPI_createObexServer(int DISCOVERY_MODE) return int status
DPDLAPI_sendObex(string device, int useAuth, string data) return int status
DPDLAPI_sendObexFile(string device, int useAuth, string file_name) return int status
DPDLAPI_sendObexImage(string img_name) return int status

[DPDLRS]
DPDLLIB_openRS(string name, int auth_mode, int writable, int create) return int rs_id
DPDLLIB_closeRS(int rs_id) return int status
DPDLLIB_deleteRS(string rs_name) return int status
DPDLLIB_openRSId(int idx, string name, int auth_mode, int writable, int create) return int rs_id
DPDLLIB_getNumRecords(int rs_id) return int nr_records
DPDLLIB_enumRecords(int rs_id, int keepUpdated) return int status
DPDLLIB_resetEnum(int rs_id) return int status
DPDLLIB_rebuildEnum(int rs_id) return int status
DPDLLIB_getEnumNumRecords(int rs_id) return status
DPDLLIB_getNextRecordID(int rs_id) return int next_rec_id
DPDLLIB_getRecordSize(int rs_id) return int size_bytes
DPDLLIB_addRSData(int rs_id, string data) return int status
DPDLLIB_setRSData(int rs_id, int rec_id, string data) return int status
DPDLLIB_getRSData(int rs_id, int rec_id) return string data
DPDLLIB_deleteRSData(int rs_id, int rec_id) return int status
DPDLLIB_createFS(string name) return int fs_id
DPDLLIB_unmountFS(int fs_id) return int status
DPDLLIB_mkdirFS(int fs_id, string dir_name) return int status
DPDLLIB_mkfileFS(int fs_id, string dir_name, string file_name) return int f_id
DPDLLIB_writeFS(int fs_id, int f_id, string data) return int status
DPDLLIB_readFS(int fs_id, int f_id) return string data
DPDLLIB_printdirFS(int fs_id) return int status

[DPDLNET]
DPDLLIB_createServer(int server_id, int port) return int status
DPDLLIB_createClient(int client_id, string host, int port) return int status
DPDLLIB_sendClientData(string data) return int status
DPDLLIB_readClientData() return string data

[MIDP]
MIDPLIB_Alert(string title, string msg, int type) return int command
MIDPLIB_Form(int instance, string title) return int component
MIDPLIB_FormAppend(int component, string msg) return int status
MIDPLIB_FormClear(int component)  return int status
MIDPLIB_Canvas(int instance) return int component
MIDPLIB_graphicsSetCurrent(int component)
MIDPLIB_graphicsSetColor(int component, int r, int g, int b)
MIDPLIB_graphicsRepaint(int component)
MIDPLIB_graphicsClear(int component)
MIDPLIB_graphicsDrawString(int component, int x, int y, int anchor)
MIDPLIB_graphicsDrawLine(int component, int x1, int y1, int x2, int y2)
MIDPLIB_graphicsDrawRect(int component, int x, int y, int w, int h)
MIDPLIB_graphicsFillRect(int component, int x, int y, int w, int h)
MIDPLIB_openRS(string name, int auth_mode, int writable, int create) return int rs_id
MIDPLIB_closeRS(int rs_id) return int status
MIDPLIB_getNumRecords(int rs_id) return int nr_records
MIDPLIB_enumRecords(int rs_id, int keepUpdated) return int status
MIDPLIB_resetEnum(int rs_id) return int status
MIDPLIB_getEnumNumRecords(int rs_id) return status
MIDPLIB_getNextRecordID(int rs_id) return int rec_id
MIDPLIB_getRecordSize(int rs_id) return int size_bytes
MIDPLIB_addRSData(int rs_id, string data) return int status
MIDPLIB_setRSData(int rs_id, int rec_id, string data) return int status
MIDPLIB_getRSData(int rs_id, int rec_id) return string data
MIDPLIB_deleteRSData(int rs_id, int rec_id) return int status
MIDPLIB_getCalendarField(int field_name) return int value
```
