# Dpdl HowTo's

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## Code Execution

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

### Generating a native java bytecode object from a 'struct'

The dpdl type **`struct`** can be used to represent data structures within a Dpdl program, almost like in the C programming language.

Dpdl 'struct' can conveniently also be <ins>**compiled into a pure native java bytecode object**</ins>, and accessed and handled in the same way as ordinary java objects (classes).

The Dpdl API function **`genObjCode(...)`** accepts as input defined Dpdl objects, in this case a 'struct' and compiles it to native java
bytecode object. The returned object can than be handled as accessed as an ordinary object and therefore also be used in native java code.

When defining an embedded java code section via **`>>java`** keyword, the contained java <ins>methods are also compiled</ins> into bytecode. 


Example:

```python

struct A {
	string id = "myid"
	int account = 23
	double myd = 999.9d
	float myf = 1.9
	long myl = 10000000L
	short mys = 100s
	byte myb = 0x01B
	char mych = 'A'
	bool mybool = true
	object myobj = null

	>>java
	public int myNativeJavaFunc(int val){
		System.out.println("myNativeJavaFunc() val=" + val);
		
		int myi = 0;
		for(int i = 0; i < 10000000; i++){
			myi=i;
		}
		val=myi;
		return (val+3);
	}
	<<

	func testFunc()
		println("testFunc()")
		return 888
	end
}

# main
println("generating pure java bytecode from a struct...")

struct A a

a.testFunc()

object myAobj = genObjCode(a)

println("myAobj: " + myAobj)

println("myAobj.id: " + myAobj.id)
println("myAobj.account: " + myAobj.account)

println("calling pure java method...")

setStartTime()
int res = myAobj.myNativeJavaFunc(23)
int ms = getEndTime()

println("res: " + res)

println("finished in " + ms + " milliseconds")
```

This approach, allows to speedup performance critical sections (see also Dpdl_native_interface.md)

The native struct function 'myNativeJavaFunc' call in the example above executes in avg. **`12 ms`** (on 'Apple M2 pro').

Note: The embedded '>>java' code section that is forseen to be compiled into the needs to be defined <ins>before any other embedded code functions</ins>, and Only the first '>>java' section is compiled into bytecode in the resulting object.
		

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

Data can be exchanged with the embedded code via the Dpdl stack or simply by returning data from the functions called.

The Dpdl API functions **`dpdl_stack_push(..)`** etc... can be used to push variables or data onto the Dpdl Stack which are than forwarded to the embedded code
as standard parameters in most cases, or alternatively replaced via variable placeholder (see {{varname}} )

The embedded code can also write data to the Dpdl stack which can than be intercepted again in Dpdl code via a given keyword 'dpdlbuf_*' that
is pushed as a string variable onto the Dpdl stack prior to the embedding of the code.

Within the embedded C code the function **`dpdl_stack_buf_put(..)`** can be used to write data (a char* buffer) to the memory buffer mapped
to the keyword specified. The maximum size of the memory buffer is currently fixed to 4096 bytes (but can be changed in the registered version of DpdlEngine)

Example:

```python
println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0d
string a = "test"

dpdl_stack_obj_put("my_int_var", 10)
dpdl_stack_var_put("my_name_var", "A.Costa is my name")

dpdl_stack_push("dpdl:applyvars", "dpdlbuf_var1",n, x, a)

>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		int my_i = {{my_int_var}};
		char *my_n = "{{my_name_var}}";
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


### Using the 'include(..)' function

To modularize code it's convenient to create a set of files/modules that can be used in the main code script file.

The **`include(..)`** function serves this purpose.

Example:

```python
include("myincludedir/module1.h")

println("calling a function defined in module1...")
int ret = myFuncMod1()
...
```

The path of the files to be included need always to be relative to the script folder root directory,
e.g. if the main script is located in the folder 'test' (i.e. ./DpdlLibs/test) containing different folders with subfolders (i.e inc1, inc2 and inc1/sub, inc2/sub),
the include path need to be always relative to the root dir (e.g include("inc1/mymodule.h") include(inc1/sub/mymobule...). This applies also for includes within subfolders.


### Generative AI code and execution with 'DpdlAINerd' (DAN)

The Dpdl language plug-in 'DpdlAINerd' (DAN) allows to generate code and data or content via popular AI engines (currently OpenAI, more to come).

This is a powerful tool for fast prototyping and experimenting with code.

The following example shows one possible execution path:

```python
println("Testing generative AI code with Dpdl....")

dpdl_stack_var_put("my_message", "Hello generative AI from Dpdl")

>>ai
	Write a console program in C that print out the first command line parameter and append the string '{{my_message}}'
<<
int exit_code = dpdl_exit_code()
println("generated ai code exit code: " + exit_code)

string my_code = dpdl_stack_buf_get("dpdlainerd_buf")

dpdl_stack_var_put("my_code", my_code)

println("executing generated code...")

dpdl_stack_push("dpdl:applyvars", "dpdl:compile", "param0", "MESSAGE: ")

>>c
{{my_code}}
<<

exit_code = dpdl_exit_code()
println("embedded C code exit code: " + exit_code)
```

Check the documentation for more info: [DpdlAINerd.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlAINerd.md)


### Embedding multi-line structured text, data and code resources


The **`>>res(...)`** keyword allows to embed multi-line structured text, data and code resources.

The resources can be stacked and retrieved where in the code they are needed.

**Example:**

```python
println("testing access to embedded multi-line resources...")

>>res(my_html)
<html>
<body>
<p>Hello World from Dpdl</p>
</body>
</html>
<<

object resid = dpdl_res_pop_id()

println("resource id: " + resid)

object myhtml = dpdl_res_obj_get(resid)

println("myhtml: ")

println(myhtml)

# same, but via res name
object myhtml2 = dpdl_res_obj_get("my_html")

println(myhtml2)
```

A more articulated example of embedding and executing code resources is the following:

```python
println("test executing code resources...")
println("")

>>res(my_content)

	This is some strcuctured content
				:)
			   MEGA

		 {{my_custom_msg}}

<<

dpdl_stack_var_put("my_custom_msg", "Dpdl has been developed by A.Costa")

object content = dpdl_res_obj_get("my_content")

println("some content:")
println(content)

println("creating code resources...")
println("")

>>res(java_method_printA)

static void printA(){
	System.out.println("printA: " + 888);
}

printA();

<<

>>res(dpdl_struct_printS)
struct S {
	int x = 23
	int y = 888
	string str = "S"
	object so = loadObj("String", "This is a test")

	func print()
		println("S:")
		println("x=" + x + " y=" + y + " str=" + str + " so=" + so)
	end
}

struct S mys
mys.print()

<<

println("executing java code resource...")
println("")

object printA = dpdl_res_obj_get("java_method_printA")

dpdl_stack_var_put("code_java_printA", printA.toString())

dpdl_stack_push("dpdl:applyvars")
>>java

{{code_java_printA}}

<<
int exit_code = dpdl_exit_code()

println("embedded java exit code: " + exit_code)

println("executing dpdl code resource...")

object code = dpdl_res_obj_get("dpdl_struct_printS")

string code_str = code.toString()

int status_exec = DPDLAPI_execScript(code_str)

println("status exec: " + status_exec)

```

### Embedding Dpdl in C code

Dpdl can be conveniently embedded and executed also in C code.

**Example:** executing a Dpdl source file

```c
#include <stdio.h>
#include "dpdl.h"

int main(int argc, char **argv){
	printf("executing Dpdl from C...\n");

	char *dpdl_src_file = "test/testString.h";

	int ret = dpdl_exec_script(dpdl_src_file);

	printf("ret: %d\n", ret);

	return 0;
}
```


**Example:** executing plain Dpdl code

```c
#include <stdio.h>
#include "dpdl.h"

char *dpdl_src_code = "" 
			"int c = 0	\n"
		  	"for(c < 1000)	\n"
			"	println('This is Dpdl from C=' + c)	\n"
			"	c=c+1\n	\n"
			"endfor	\n";

int main(int argc, char **argv){
	printf("executing Dpdl code from C...\n");

	int ret = dpdl_exec_code(dpdl_src_code);

	printf("ret: %d\n", ret);

	return 0;
}
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


### Querying a Database via the Dpdl 'sql' language plug-in

A specific Dpdl language plug-in allows to execute queries on a specific database (JDBC compliant) and retrieve the results as form of vector.
The queries can be embedded in Dpdl code via the keyword **`>>sql`**

The plug-in will connect to the specified database connection string and credentials that have been pushed onto the Dpdl stack.

Variables that are needed to construct the queries can be also pushed onto the Dpdl stack and referenced in the embedded query with: {{$my_variable}}

The result is retrieved from the Dpdl stack in form of a Vector, it can be a pure vector (default), or a vector of maps (see 'db_data_mode' parameter). The latter
enables to access the fields via a key/value approach.

Example (in this case a vector of maps is retrieved)

```python
println("performing database SQL queries with Dpdl...")

dpdl_stack_var_put("db_url", "jdbc:postgresql://127.0.0.1:5432/mytestdb")
dpdl_stack_var_put("db_user", "testuser")
dpdl_stack_var_put("db_pass", "189923")
dpdl_stack_var_put("db_data_mode", "map")

dpdl_stack_var_put("id", "23")

dpdl_stack_push("dpdlbuf_res")

>>sql
	SELECT id, name, surname, email from mytable where id={{id}}
<<

object result = dpdl_stack_obj_get("dpdlbuf_res")

raise(result, "Error: dpdl stack buffer is null")

println("type of result: " + typeof(result))

int rs_size = result.size()

println("nr. or results: " + rs_size)

println("iterating over result set...")

object id, name, surname, email

int c = 0
object entry_map
for(c < rs_size)
	println("-----------------------------------")
	entry_map = result.get(c)

	id = entry_map.get("id")
	name = entry_map.get("name")
	surname = entry_map.get("surname")
	email = entry_map.get("email")

	println("id: " + id)
	println("name: " + name)
	println("surname: " + surname)
	println("e-mail: " + email)

	println("-----------------------------------")

	c=c+1

endfor

println("finished")
```


### Storing and accessing data in a Record Store

Dpdl allows to store and access data in Record Stores.
The Record Store functions can be used directly (via DPDLAPI_* calls), or with the functions defined in the import library 'dpdlRS.h' 

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
int cnt = 0
while(cnt < 10)
	data = "my test data " + cnt

	rec_id = addRecord(rs_id, data)

	raise(rec_id, "Error in adding record")

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

Note: On JavaME and J2ME platforms, the platform specific Record Store is used transparently (javax.microedition.rms.RecordStore), without the need to
adapt the code.


## Common Errors

### Julia

- Packages imported not available

```
Dpdl Julia Exception -> ArgumentError 
```

Solution->
Kmport the missing packages via the 'julia' package manager and make sure the symlink './dpdl_env_paths/JULIA_DEPOT_PATH' points to 
your current Julia package depot



