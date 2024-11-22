# Dpdl documentation

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## Dpdl language specification

Dpdl is a <ins>self-contained programming language</ins>, <ins>interpreted</ins>, <ins>statically</ins> as well as <ins>dynamically typed</ins>, with a very <ins>compact footprint</ins> and <ins>portable</ins> to most platforms. There is an on-going development to enable Dpdl code to be compiled also to native code.

Additionally Dpdl allows to embed and execute code of other programming languages directly within Dpdl. Embedded programming language code is executed in form of plug-ins (Dpdl language plug-ins) distributed with the DpdlEngine release package (no additional installations required)

### Features:

* Types supported: **`int`** **`byte`** **`short`** **`float`** **`double`** **`long`** **`string`** **`char`** **`bool`** **`array[]`** **`var`** **`class`** **`object`** **`struct`** **`enum`**
* Multiple native Threads within same script
* support for pointers and references (eg. int *px = &x)
* Inline string expressions allowed
* native data function types to handle data structures **`arr`**, **`vec`**, **`map`**, **`list`** and **`stack`**.
* APIs: Dpdl API, JRE API, MIDP API, and enables to load and access third party java APIs and Native shared libraries
* Access to the full underlying Java Platform API's or any external java libraries
* Access to Native shared libraries with simple approach
* Record Store creation and access via virtual file system
* Support for custom function extensions
* **Multiple embeddable programming languages supported:** ANSI C code, C++, Python, Julia, JavaScript, Lua, Ruby, Java, Groovy, OCaml and Clojure. These **`programming languages code can be embedded and executed directly within Dpdl code`** (interpreted/compiled code).
* Additional programming languages or natural language interpreters can be easily integrated via a defined plug-in interface and configuration
* ANSI C code embedded within Dpdl code can be dynamically compiled in memory at runtime (see option 'dpdl:compile')
* Multi-line structured text, data and code resources
* Asynchronous Task execution
* Static script execution: static code declarations (*.h_static)
* Tools for converting Dpdl code to Java and C/C++ code (in development)


### Dpdl API functions

The Dpdl API functions usable inside Dpdl are listed here:

[Dpdl API Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

As Dpdl can access java classes directly, the whole Java JRE API and any other configured java library is available inside Dpdl.
Refer to the java documentation for Dpdl objects loaded with **`loadObj(..)`** and **`getObj(..)`**


### Types

Dpdl support the following type definitions:
```c++
int i = 1
short s = 10s
float f = 0.1
double d = 10000.0d
long l = 1000L
byte b = 0x01 
string s = "mystr"
char c = 'a'
bool t = true
myarr[] = [1, 0.3, 23.0d, 1000L, 0x09, "mydata"]
var v = "some variable type var"
class myClass cl
object myobj = loadObj(...)
object myobj_static = getObj(...)
struct myStruct a
enum myenum e
```

Note: numbers must have the following suffix: doubles with '**d**', long with '**L**' and short end with '**s**'


### Function and Control flow

**`function`** definition
```python
func myFunction(string param, object param....)

end
```

**`function`** definition with return type

Specifying the return type of a function **<ins>is optional</ins>**, it enforces a further check on the execution and improves code readability

```python
func myFunction(object param....) return int

end
```

**`if`** statement
```python
if(<expression>)

fi
```

**`if elseif`** statement
```python
if(<expression>)

elseif

else

fi
```

**`while`** statement
```python
while(<expression>)

endwhile
```

**`for`** statement
```python
for(<expression>)

endfor
```

### Operators

**Arithmetic:** 
	
* **`+`** (addition)
* **`-`** (subtraction)
* **`*`** (multiplication)
* **`/`** (division)
* **`^`** (power)
* **`%`** (modulo)
* **`-`** (negate a value eg. -x)
	
Note: for multiplication (*) it's necessary to have blank spaces between the numbers and operator (eg. 1 * 2). 
		This is currently not allowed '1\*2' but will be in future
	
**Logical:**

* **`&&`** (and)
* **`||`** (or)
* **`!`** (not)
	
**Comparators:**

* **`>`** (greater than)
* **`<`** (less than)
* **`>=`** (grater than equal)
* **`<=`** (less than equal)
* **`==`** (equal)
* **`!=`** (not equal)
	
	
### Data Function Types

Dpdl has some built-it data function types for handling <ins>**vectors**</ins>, <ins>**maps**</ins>, <ins>**linked-lists**</ins> and <ins>**stacks**</ins>

The objects returned by these functions have <ins>all methods and fields as the corresponding java classes</ins> (**ArrayList**, **Vector**, **HashMap**, **LinkedList**, **Stack**)

```python
# ArrayList
object my_arr = arr("supports multiple types", 1, 2, 3, 4.0, 5.0, 6.0d)

# Vector
object my_vec = vec(1, 2, 3, 4, "my element1", 0.23, 999.9d, 100000L, ...)

# HashMap (key:value)
object my_map = map("a:1", "b:2", "c:3", ...)

# LinkedList
object my_list = list("A", "Costa", 1, 0.3, 999.9d, 10000L, ...)

# Stack
object my_stack = stack()
```

**Example:**
```python
object myvec = vec("a", "b", "c", 1, 2, 3)

bool isIn = myvec.contains("c")

println("the vector contains 'c': " + isIn)

object mystack = stack()

mystack.push("my item")

```

### In-line string expressions

Strings can contain in-line expressions that are evaluated at runtime, when the string is defined. The expression can be embedded in a string within the keyword **`${ }`**
This may reduce code at some performance expense.

**Example:**
```python
int a = 10
int b = 20
string mystr = "my result is ${a + b}"
println("mystr: " + mystr)
```

The expressions can also contain function calls like in the following examples:

**Example:**
```python
string input = "some input"
string mystr = "this is a my result ${ myFunc(input) }"
println("mystr: " + mystr)
```

Example using 'sqrt(...)' function:

```python
double dv = 9.0d

println("result is ${ sqrt(dv) }")
```

The code snippet above gives the following output:
```
result is 3.0
```

Note: Currently only one in-line expression definition '${ ... }' is allowed inside a given string. Coming releases will support multiple expression in-linings within a given string. 


### Multi-line structured text, data and code resources

By using the **`>>res(...)`** keyword it's possible to embed multi-line structured text, data or code resources and retrieve and access them as an object.

The resources are stacked on the dpdl stack and can be accessed by 'id' or by 'name' at any execution point.

Stack variables available on the current execution stack can be referenced via place-holders in the resource that are than compiled into the returned object at every invocation.

This approach provides a flexible and readable way to handle different kind of resources like structured text, data and code.


**Example:**
```python
println("testing access to embedded multi-line resources...")

dpdl_stack_var_put("msg", "Hello World")
>>res(my_html)
<html>
<body>
<p>{{msg}} from Dpdl</p>
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

# we can change the stack variable 'msg', which is than also updated in the returned resource object
dpdl_stack_var_put("msg", "Hello World again!!!")

object myhtml3 = dpdl_res_obj_get("my_html")

println(myhtml3)

```

### Arrays

Arrays are defined with **`[ ]`**

Arrays are dynamic and can grow or shrink in size

Arrays elements can have multiple types and can be accessed also as a java [ArrayList](https://docs.oracle.com/javase/1.5.0/docs/api/java/util/ArrayList.html) object (see **`myarray.getArrObj()`** )

Array can be initialized directly, via a **`string`** and also with **`struct`**

Example:
```python
myarrmix[] = [1, 0.3, 23.0d, 1000L, 0x09, "mega"]

myarray[] = "1 1.0 0x01 test Dpdl Dynamic Packet Definition Language"

# this returns an arraylist
myarray2[0]  = myarray.getArrObj()

object myarrayobj = myarray2[0]

bool b = myarrayobj.contains("Dpdl")

println("array contains Dpdl: " + b) 
```

The array elements be pure or embedded in a string and can be separated with blank space ' ', with comma ' , ' or with semicolon ' ; '. All are valid.

```python
myemptyarr[] = []
myarr1[] = [1 2 3 4 5]
myarr2[] = [1, 2, 3, 4, 5]
myarr3[] = [1; 2; 3; 4; 5]
arr0[] = ""
arr1[] = "1 2 3 4 5"
arr2[] = "1,2,3,4,5"
arr3[] = "1;2;3;4;5"
arr4[] = "[1,2,3,4,5]"
```

Initializing an array with a **`struct`**:
```c
struct myStruct a
arr[] = array(a)
```

Multidimensional arrays will be supported in the coming release

#### Looping through arrays

1) looping through an array with  **`for`**  or  **`while`**  statements:
```python
myarr[] = [1, 2, 3, 4, 5]
int c = 0
for(c < myarr.size())
	println("myarr[" + c + "]=" + myarr[c])
	c=c+1
endfor
```

2) looping through an an array with a java **`iterator`**

All methods of the java class 'ArrayList' can be accessed

```python
myarr[] = [1, 0.3, 23.0d, 1000L, 0x09, "mega"]
println("myarr: " + myarr)

object myarrobj = myarr.getArrObj()

object iter = myarrobj.iterator()

while(iter.hasNext())
	println("myarr element: " + iter.next())
endwhile
```

### Class

Dpdl allows to define and use **`class`** objects. This type definition is similar to the class type found in C++ or Java.

* Class objects can contains all variable types

* Class objects can define a constructor that is called upon initialization

* Class objects can contain function definitions

* Class objects can be entirely compiled into java bytecode (in development), and therefore can be passed to java methods.

**Example:**
```python
class A {
	int id = 1
	string s = "A"

	struct myStruct data

	func A(int x)
		id = x
	end

	func printit()
		println("an A class function with id: " + id)
		println("data: " + data)
	end

}

# instance with constructor
class A mya(1)

mya.printit()

# instance without constructor
class A mya2

mya.printit()
```


### Struct

Dpdl supports the type **`struct`**, with the following definitions:

* Structs may contain other 'struct' variable declarations (but not 'struct' definitions)

* Structs can call functions defined in the outer scope

* Variable shadowing is enabled

* Structs can contain 'struct functions' that can be called. Within struct functions all 'struct' variables can be accessed in READ mode. Changing a struct variable within a 'struct' function changes the variable <ins>only during the function scope</ins>.

* Structs can contain multiple embedded code sections in various programming languages (eg. **`>>c`**)

* Structs can be used to initialize arrays, (see 'array(...)' function)

* Structs can contain arrays[], but currently accessing and via $struct.arr[] is not yet possible -> this will be allowed very soon,
a workaround is to assign the array to an object and access the object instead.

* Structs cannot contain variable definitions of 'class' type

* Structs can conveniently be <ins>compiled into java bytecode</ins> and accessed as an object instead, see '**genObjCode(...)**' -> this might be useful for exchanging data with native java classes


Example:
```c
struct myStruct {
	int x = 10
	float f = 0.1
	double d = 0.3d
	long l = 1000L
	byte b = 0x01
	string s = "Test"
	object so = loadObj("String", "my java obj in struct")
		
	println("myStruct: " + s)
	
	func myStructCall()
		println("myStructCall: " + s + " so: " + so)
		return 1
	end
	
	func myStructCallNativeC()
		>>c
		#include <stdio.h>

		printf("Hello myStructCallNativeC from C\n");
		<<
	end
}

struct myStruct a

println("a.x: " + a.x)

a.x = 23

println("a.x: " + a.x)

int x = a.myStructCall()

println("ret val: " + x)

my_arr[] = array(a)

println("my_arr: " + my_arr)
```

#### 'struct' compiled as java bytecode


The type 'struct' can also be conveniently compiled at runtime into a java bytecode object (java class) by using the **`genObjCode(...)`** api function.

This may be useful for exchanging data structures with other native java classes or to speedup performance critical function calls.

Structs that are compiled into java bytecode can contain 1 embedded **`>>java`** section containing native java methods which are than also compiled as bytecode into the generated object. <ins>Only the first embedded code definition</ins> is compiled into the resulting object. Other embedded code sections are executed only.


**Example:**
```c
struct A {
	int x = 10
	float f = 0.1
	double d = 0.3d
	long l = 1000L
	byte b = 0x01
	string s = "Test"
	object so = loadObj("String", "my java obj in struct")
	
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
	
	println("myStruct: " + s)
	
	func myStructCall()
		println("myStructCall: " + s + " so: " + so)
		return 1
	end
}

struct A a

object myAobj = genObjCode(a)

println("myAobj: " + myAobj + " is of type: " + typeof(myAobj))

println("myAobj.x: " + myAobj.x)
println("myAobj.f: " + myAobj.f)
println("myAobj.s: " + myAobj.s)

println("calling native java function....")

setStartTime()
int res = myAobj.myNativeJavaFunc(23)
int ms = getEndTime()

println("res: " + res + " executed in " + ms + " milliseconds (ms)")
```

This approach allows to speedup performance critical sections.

The native struct function 'myNativeJavaFunc' call in this example executes in avg. **`12 ms`** (on 'Apple M2 pro').


### Enum

Dpdl supports the type **`enum`**

The keywords by default have increasing **`int`** values starting from **1**. Desired values can be assigned explicitly.

**Example:**
```c
enum myStatus {
	PENDING,DONE, ERROR, RUNNING=23
}

enum myStatus status
println("init status: " + status.RUNNING)
println("done status: " + status.DONE)
println("enum values can also be accessed directly: " + DONE)
```

Note: Currently the comma separated tags and values need to be defined on different lines than the starting 'enum var {' definition (this will be fixed in the next release)

### Pointers

Dpdl supports a form of **`pointers`** (eg. int *ptr = &x ).

This allows to have a variable that references another variable.

The types for which pointers are currently supported:

* int
* byte
* string
* char
* float
* double
* short
* var
* object
* struct


**Example:**
```c
int i = 10
string s = "Mega"

println("i: " + i)
println("s: " + s)

int *i_p = &i
int *s_p = &s

println("i_p: " + *i_p)
println("s_p: " + *s_p)

s = s + " added"

println("i_p: " + *i_p)
println("s_p: " + *s_p)

```

Check out the following example for a deeper insight:

[dpdlPointers.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlPointers.h)

NOTE: Due to the nature of how pointers are implemented, to gain maximum performance (via a static allocation), currently it's required to
		use the same variable names when pointers are passed to functions, (eg, when passing a pointer int *px to a function, the function must
		use '*px' as parameter name in the function signature -> func testFunc(int *px,...)


This feature will be further developed.
	
### Function return type

By default functions can return any possible variable type, or none.

To improve code readability and enforce a further check on the function return type, it's possible to specify a
specific return type in the function definition via return type specifiers **`func myfunc() $type`**.

The return type specifiers are optional. For functions that do not return any value, **`void`** can be specified as function return type.

The variable type **`var`** is always accepted for all return types as the values are dispatched at runtime.


Example:
```c
func testFuncRetInt() int
	println("testFuncRetInt")
	return 23
end

func testFuncRetFloat() float
	println("testFuncRetFloat")
	return 0.22
end

func testFuncVoid() void
	println("this function does not return a value")
end

int y = testFuncRetInt()
var yv = testFuncRetInt()
println("y: " + y)
println("yv: " + yv)
testFuncVoid()
```

### Dpdl Threads

Threads can be created inside Dpdl with the **`Thread(..)`** api function.

Multiple threads are allowed inside a single Dpdl script.

The function 'Thread(..)' accepts as parameters a function callback and the time interval for the thread iteration (in milliseconds).
Optionally the number of iterations for a Thread can also be provided

Further parameters passed to the 'Thread(..)' function are than passed also to the callback function.

Example Thread(..) with default iteration interval of 1000 ms:
```python
int thread_id = Tread("myFunc")
```

Example Thread(..) with iteration interval of 3000 ms:
```python
int thread_id = Tread("myFunc", 3000)
```

Example Thread(..) with iteration interval of 3000 ms, and 23 iterations:
```python
int thread_id = Tread("myFunc", 3000, 23)
```

Example starting 2 threads
```python
func myThreadFunc1(int t_id)
	println("Hello from thread: " + t_id)
end

func myThreadFunc2(int t_id)
	println("Hello from thread: " + t_id)
end

# start a thread with an interval of 2000 milliseconds
println("starting a Dpdl threads...")
int tId1 = Thread("myThreadFunc1", 2000)
if(tId1 != -1)
	println("Thread started with id: " + tId1)
else
	println("Error in starting thread")
fi

# we make a pause to guarantee not lock conditions
sleep(3000)
# start a thread with an interval of 7000 ms and for 3 iterations
int tId2 = Thread("myThreadFunc2", 7000, 3)
if(tId2 != -1)
	println("Thread started with id: " + tId2)
else
	println("Error in starting thread")
fi
```

#### Thread GC

The Dpdl Rutime can be configured to automatically run the garbage collector 'gc()' after a given number of iterations.
See **`GC_THREAD_EXEC`** parameter in 'DpdlEngine.ini'. The value '-1' invalidates this feature.

	
### DpdlObject's and Java bindings

Dpdl can access the underlying classes of a given java compliant JRE implementation or any other external java library.

The classes are loaded and wrapped in a DpdlObject that is handled by the Dpdl runtime which make the java classes accessible to Dpdl.

Static classes can be accessed via **`getObj(..)`** function, and instance classes can be created via **`loadObj(..)`** function.

The java class references are resolved via the class definition file which can be updated statically to resolve further classes, and can be also dynamically loaded and updated via the function call 'DPDLSYS_registerLib(...)'

By default, the name of the java class to be loaded must be specified without the java package path, i.e 'String' and NOT 'java.lang.String'. But this can be adjusted, even with custom naming.
For some java classes that have duplicate entries as base name, the corresponding path prefix has to be specified when loading
an object.

The java classes where a path prefix applies are listed here: [doc/Dpdl_class_resolve.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_class_resolve.md)

Note: the <ins>deprecated function 'getClass'</ins> is still supported for some time for backwards compatibility. The function '**getObj**' should be used instead.


**Example:**
```python
# static class loading
object calendar = getObj("Calendar")
object cal_inst = calendar.getInstance()
int day_ = cal_inst.get(calendar.DATE)
println("day: " + day_)

# instance class loading
object str = loadObj("String", "Test MyString")
int idx = str.indexOf(" ")
string substr = str.substring(idx)
println(substr)
```

### Default configuration resolves the following API's:

The set of classes accessible with Dpdl (default) is defined to be the following set.
The methods of the classes that are accessible are referred to the current JRE instance on which Dpdl is running.

[Java API](http://www.seesolutions.it/apidoc/Java_Platform_API_1_5.html)

[JavaFX API](https://docs.oracle.com/javafx/2/api/index.html)

[Bluetooth JSR-82 API](https://docs.oracle.com/javame/config/cldc/opt-pkgs/api/bluetooth/jsr082/index.html)


Additional API's and classes can be added to the class definition file as needed with the syntax: '$full_class_name $class_alias'.

NOTE: Only the full registered version of Dpdl allows editing of the class definition file. The default 'DpdlEngine lite' configuration contains
only the class references of Java Platform JRE 1.5, JAVAFX and Bluetooth JSR-82 API.


### Dynamic loading of java API's

As mentioned above, java classes (or APIs), can be also be dynamically loaded and accesses at runtime by calling the function 'DPDLSYS_registerLib(...)'. The function accepts as parameter the path of a JAR file containing the java classes.

This approach, compared to registering the classes statically in the class file definition, has a minimal overhead with the advantage to enable loading of many different libraries not foreseen in the standard setup.

**Example:**
```python
int load_lib = DPDLSYS_registerLib("./lib/custom/MyTestLib.jar")

raise(load_lib, "Error in loading java lib")

# now we can instantiate a Dpdl object from the contained java classes

object myobj = loadObj("MyTestClass")

string mydata = myobj.getData()

println("my data: " + mydata)

println("now you can access all classes, methods and fields of the java classes contained in the specified jar file")
```

### Notes:

Referencing object variables currently support 1 level of indirection only ('date.toString().toUpparCase()' will not work currently, but is in development)

This is the correct approach:
```python
object date = loadObj("Date")
object datestr = date.toString()
println(datestr.toUpperCase())
```

### Load Dpdl code as DpdlObject

Dpdl code can be loaded as an ordinary DpdlObjects with the function **`loadCode(..)`**.

The object can be accessed like an other object except that the function calls currently must include also the name of the script loaded -> this will be changed in next releases so that the calls are the same as for other objects.

Loading a Dpdl script as an object has some advantages with respect to just include a given Dpdl script with via the 'include' statement:

- The code runs in a dedicated interpreter instance -> more convenient especially for multi-threading applications.
- Variables have a dedicated scope
- Performance improvements when using multiple extensions

```python
println("test loadCode(..) with dpdl script LoadCodeFunc.h")

object mycode = loadCode("LoadCodeFunc.h")

string mystr1 = "Test"
object mystr2 = loadObj("String", "MEGA")

mycode.testFunc("LoadCodeFunc", mystr1, mystr2)
mycode.ID = "set my id"
int x = mycode.getX("LoadCodeFunc")
string cid = mycode.ID

println("done")
```

The script file loaded in the example above 'LoadCodeFunc.h' may also define a **constructor**, which is called
iff parameters are supplied.

LoadCodeFunc.h
```python
# constructor
func LoadCodeFunc(object map)
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


### Types

#### **`object`** type

All types in Dpdl can be handled as objects.

The type 'object' is in first place used to load java objects available within Dpdl (see 'loadObj(...)' function), but can serve as a super type compatible with all other types.

Every type can be assigned to an **`object`** variable. But not the other way around.

**Example:**
```python
int myi = 9999
object myiobj = myi
```

IFF you want to re-assign an already declared and assigned object to a variable with same name of <ins>different type</ins>, you must redefine the object as follows:
```python
int myi = 9999
float myf = 999.9
object myiobj = myi
object myiobj = myf
```
Note: 'DPDL_ALLOW_VAR_REDEFINITION' must be enabled if you want to allow variable redefinition within same scope

##### casting to **`object`** type

Primitive types such as **int, float, double, long, short, byte, char, string and var** can be casted and compliant to the equivalent java object type.

In this way it's possible to access all methods of the object available on the underlying JRE platform.

**Example:**
```python
int x = 10

object o_x = x

float f_x = o_x.floatValue()

println("f_x: " + f_x)

string s = "Dpdl is a rapid prototyping programming language"

object s_o = s

println("s_o: " + s_o.length())
```

In Java notation you would write the equivalent 'f_x' assignment as follows:
```java
float f_x = new Integer(10).floatValue()
```

#### **`var`** type

The **`var`** variable can have an arbitrary type and is dispatched at runtime by type inference.

Therefore the 'var' type can accept any type in a function.


```python
func myFuncVar(var a, var b)
	println("a:" + a + " type: " + typeof(a))
	println("")
	println("b:" + a + " type: " + typeof(b))
	println("")
end

int x = 10
float y = 0.3
myFuncVar(x, y)
```

#### Abstraction using 'var' type:

It might be useful to abstract a given type.

Consider the following example:
```c
struct myA a
struct myA aa
double dist = calculateDistance(a, aa)
```

The function 'calculateDistance(..)' can accept the parameters as follows:
```c
func calculateDistance(var p1, var p2) double
    float dx = p2.x - p1.x
    float dy = p2.y - p1.y
    return sqrt(dx * dx + dy * dy)
end
```
and is equivalent to:
```c
func calculateDistance(struct p1, struct p2) double
    float dx = p2.x - p1.x
    float dy = p2.y - p1.y
    return sqrt(dx * dx + dy * dy)
end
```

#### Determining the Type of a variable

The type of a given variable can be determined with the **`typeof(..)`** function

ex:
```python
var s = "this is a string"
var i = 10
println("var 's' is a: " + typeof(s))
println("var 'i' is a: " + typeof(i))
```

The above statement will print out:
```
var 's' is a: string
var 'i' is a: int
```

For clarity, a variable other than 'var' type can also be determined:
```python
int i = 10
println("variable 'i' is of type: " + typeof(i))
```

By determining the type of a 'struct' variable type, the type returned contains also a type identifier.
eg.
```c
struct A a
println("variable 'a' is of type: " + typeof(a))
```
The above statements will return **`struct:A`**


Whenever a java object is loaded, the type of the variable returned by **`typeof(..)`** is the name of the class.

eg.
```python
object map = loadObj("HashMap")
println("variable 'map' is of type: " + typeof(map))
```
The above statement will return **`HashMap`**


#### Variable re-definition

Redefinition of variables within the same scope is allowed by the default configuration, in this case a 'Warning' is issued.

This configuration can be disabled by changing the parameters '**DPDL_ALLOW_VAR_REDEFINITION**' and '**DPDL_VAR_REDEFINITION_WARNING**' in configuration file 'DpdlEngine.ini' 

In 'while' and 'for' loops it's advised, if possible, to allocate variables in the outer scope. This increases also performance and avoids allocations.


#### Converting types


Some variable types can be converted either by casting or by using the **`convert(..)`** function.

Casting numeric values can be performed using the functions **`to_int(..)`** , **`to_float(..)`** or **`to_double(..)`**

**Example:**
```python
float f = 999.3
double d = 2000000.5d

int fint = to_int(f)
int dint = to_int(d)

println("fi: " + fint)
println("di: " + dint)
```

Other conversions, for example from string to a numeric type can be performed with the **`convert(..)`** function.

The function accepts as parameter the 'type' (as returned also by typeof(..)) and the variable to be converted.

Currently the following conversions are supported, more will follow:

*int float double object** -> **`string`**

**int** -> **`float`**

**float** -> **`string`**

**float, double** -> **`int`**


**Example:**
```python
int xc = 10
float f = 0.3
double d = 23.0d

println("converting to string...")

string xcs = convert("string", xc)
println("xcs: " + xcs)

string fs = convert("string", f)
println("fs: " + fs)

string ds = convert("string", d)
println("ds: " + ds)
```


### Exception handling using 'raise(..)'

Exceptions can be handled with the **`raise(..)`** function. 

The following conditions are checked and an exception is raised if the expression on the type condition evaluates to 'false':

* string -> **`(condition =! "null")`** ? true : false 
* int -> **`(condition =! -1)`**  : true : false
* bool -> **`(condition == true)`**  ? true : false
* object -> **`(condition =! null)`**  ? true : false


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

### Asynchronous 'Task' execution

The keyword  **`>>task`** allows to execute Dpdl code sections asynchronously.

The code runs in an isolated execution instance and is thread safe to the embedding code.

The running 'Task' object can be accessed by popping the task id from the dpdl stack and than calling the function 'dpdl_task_obj_get(object task_id)' which
returns a 'Task' object which provides access to all functions needed to control the task execution (eg. interrupt, sleep, join, etc.)

The task id is a unique identifier (UUID) like for example 312b01c1-9837-47f7-9c24-f5ec24fb9857

**Example:**
```python
println("testing Dpdl tasks...")

>>task
	println("this is a dpdl Task that runs asynchronously")

	int c = 0
	while(c < 10)
		print(".")
		c=c+1
		sleep(2000)
	endwhile

	println("task finished")
<<

int exit_code = dpdl_exit_code()

object task_id = dpdl_task_pop_id()

println("task started with exit code: " + exit_code + " and task id: " + task_id)

int c = 0
for(c < 5)
	print("#")
	c=c+1
	sleep(2000)
endfor

object task_obj = dpdl_task_obj_get(task_id)

task_obj.sleep(20000L)

println("finished")
```


### 'Import' and 'Include' statements

#### Import 

Dpdl libraries can be imported via the **`import`** statement.

Import libraries can be of native Dpdl object type, or can be simply other Dpdl library scripts.

The default location for imported Dpdl script library code is './DpdlLibs/libs/'.

Dpdl object type libraries can be implemented and added with a straight forward configuration. They can be implemented in java or other languages and wrapped into a dedicated interface extension that can be registered via a configuration. 

You can import available libraries or place your own libs in the dedicated directory and import the code with the following statement:

```python
import("dpdllib.h")

println("Dpdl version: " + DpdlLibVersion)
```

#### Include

A Dpdl script may include other Dpdl scripts with the **`include`** statement.

The functions and variables of the included code are than available also in the main module.

Example:
```python
include("testImportInc.h")
import("dpdllib.h")

println("DpdlLib version: " + DpdlLibVersion)
println("myx: " + myx)
```

The path needs to be relative to the folder where the executed script is located. 

NOTE: Currently the 'include' statement need to be placed <ins>before any defined 'import' statements</ins> -> this will change in the next release


### Embedding of other programming languages directly within Dpdl (Dpdl language plug-ins)

A particular feature of Dpdl is the possibility to embed and execute other programming languages directly within Dpdl code. This feature enables
to use the appropriate language and libraries for particular implementation needs.

The code of other programming languages can be embedded by simply using the keyword **`>>`** along with the language specifier.

See [Dpdl_embedded_languages.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_languages.md) for more details.

Data and variables can be exchanged with the embedded code via the dpdl stack by using the API functions:

**`dpdl_stack_var_put(..)`**

**`dpdl_stack_var_get(..)`**

**`dpdl_stack_push(..)`**

**`dpdl_stack_buf_put(..)`**

**`dpdl_stack_buf_get(..)`**

**`dpdl_stack_obj_put(..)`**

**`dpdl_stack_obj_get(..)`**

**`dpdl_stack_var_glob_put(..)`**

**`dpdl_stack_var_glob_get(..)`**

**`dpdl_stack_obj_glob_put(..)`**

**`dpdl_stack_obj_glob_get(..)`**


Variables pushed on the dpdl stack are passed as parameters to the embedded code, and can also be embedded directly in the code as placeholder, see **`{{var_name}}`**.
In the latter case the variables are replaced with the actual values before code compilation and execution.


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
	
	int dpdl_main(int argc, char **argv){
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


### Dpdl embedded C code

Dpdl allows the embedding and execution of ANSI C code (a minimal subset of C90, and full ISO C99 standard) directly within Dpdl code.

The C interpreter and compiler is available as Dpdl language plug-in with a very compact footprint of only **`375 Kb`** on Raspberry Pi,
with no extra dependencies required.

To embed C code within Dpdl code use the keyword '**>>c**' to start the embedded code, and the keyword '**<<**' to end the embedded code.
Note: The keyword has to be on a single line


Embedded C code can be executed in 2 different Modes:

1) Interpreted C code (<ins>minimal subset of C90</ins>) --> easy integration of custom extensions. No compile time overhead, minimal standard C library <ins>standard headers already included</ins> (**default mode**)

2) Compiled (in memory at runtime) C code (full <ins>ANSI C99</ins>) --> fast compile time and FAST execution. Searches default locations for lib path and include path. Further paths to standard C headers and lib files may be set via 'dpdl:-I' and 'dpdl:-L' options. Some default include files are available under the foder './lib/native/$platform/include/' -> This mode can be enabled via the option '**dpdl:compile**'

#### Mode 1 (interpreted)

The C code is executed with Mode(1) includes only a minimal subset of the C library and is POSIX compliant (also on Windows OS).
Custom libraries and functions can be implemented and added if needed via dpdl api functions.

The default memory stack size for the C interpreter is kept small and is currently configured to be 128 Kb.

The stack size can be customized by applying configurable settings.

**Minimal embedded C library documentation:**
[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

Example **Mode (1)**:
```python
println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0d
string a = "test"

dpdl_stack_push("dpdlbuf_var1",n, x, a)

>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	int dpdl_main(int argc, char **argv){
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

#### Mode 2 (compiled in memory)

The faster and more complete execution Mode(2) can be activated by pushing the option **`dpdl:compile`** on the dpdl stack (-> see 'dpdl_stack_push(..)').

The built-in compiler searches the default library and include files on the OS. 
A basic set of include headers are also available in the folder **`./lib/native/$platform/include`**.

Additional include header files or library files can be provided with the options **`dpdl:-I`** and **`dpdl:-L`**

see the following documentation for more info
[doc/Dpdl_compiler_documentation.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_compiler_documentation.md) 

Example **Mode (2)**:
```python
println("Benchmarking Dpdl embedded C with compile option...")

dpdl_stack_push("dpdlbuf_myresult", "dpdl:compile", "dpdl:-I./DpdlLibs/C")
>>c
	#include <stdio.h>
	#include <time.h>
	
	extern void dpdl_stack_buf_put(char *buf);

	int dpdl_main(int argc, char **argv){
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

		char res[256];
		sprintf(res, "my result Exec time: %lf \n", exec_time);

		dpdl_stack_buf_put(res);
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()
println("embedded C exit code: " + exit_code)

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")
println("result: " + buf)
```

Parameters and data can be passed to the dpdl stack via the '**dpdl_stack_push(..)**' API function.
Data can be written to and read from to the dpdl stack using the '**dpdl_stack_buf_put(..)**' and '**dpdl_stack_buf_get()**' API functions.

Pushing a variable 'dpdlbuf_*" on the dpdl stack, allows to later retrieve in Dpdl the data buffer that has been written
in the C code via the '**dpdl_stack_buf_put**' function, for example the result of a calculation.


Note: For Mode(2), in order to use the function dpdl_stack_buf_put(..), instead of importing 'dpdl.h', it's required to declare 'extern void dpdl_stack_buf_put(char *buf);' 


### Embedding of Python

Python code can be embedded within Dpdl code by using the keyword '**>>python**'.

Example Dpdl code with embedded 'Python' code:
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

The indentation needs to be consistent with the Python language specification

The Dpdl runtime considers the '**>>python**' tag (\t) as starting indentation point

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

#### Supported platforms (Python language plugin)

Currently the 'DpdlEngine lite' release includes the native Python library '**libdpdlpython**' for **MacOS (arm64)**, **Linux (x86_64)** and Raspberry PI 3 (armv7l)

**Linux:** Python version 3.2m (gcc version 4.4.7)
**MacOS:** Python version 3.12 (Apple clang version 14.0.3)
**Raspberry PI 3**: Python version 3.2m (gcc version 4.4.11)
Windows version will follow soon in the coming release


Support for more platforms will be released soon. MicroPython will also be available as option.


### Embedded OCaml code (experimental)

Dpdl supports also the embedding of 'OCaml' code directly within Dpdl code through the **'>>ocaml'** keyword.

The embedded OCaml code is executed by the Dpdl runtime through the 'ocamljava' library (http://www.ocamljava.org/) and
requires the following jar library located in the lib folder './lib': 'ocamlrun-scripting.jar' 

If the 'dpdl:compile' option has been set, the OCaml code is compiled at runtime to improve speed.
The 'ocamljava.jar' in this case needs to be present in the 'lib' folder. 

Example Dpdl code with embedded 'OCaml' code:
```python
println("testing Dpdl embedded OCaml..")

#
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
	

In order to enable the execution of OCaml code via the keyword '**>>ocaml**', the 'ocamlrun-scripting.jar' library jar file
located in the lib folder (./lib) is required (download from www.ocamljava.org)

If the 'dpdl:compile' option has been set (the OCaml code is compiled at runtime to improve speed) --> dpdl_stack_push("compile"),
also the 'ocamljava.jar' file needs to be present in the './lib' folder.

### Dpdl Stack buffers

To exchange data between native Dpdl code and the supported embedded languages, Dpdl provides a mechanism to exchange buffers of data.

By pushing a string variable with the following definition: 'dpdlbuf_$varname' on the Dpdl stack via the function **`dpdl_stack_push(..)`**,
the data written or returned by the embedded code (eg. C code) can be retrieved in the native Dpdl code via the function **`dpdl_stack_buf_get(..)`**

Example:
```c
string buf_key = "dpdlbuf_var1"
dpdl_stack_push(buf_key)
>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	printf("writing to buf...\n");
	char *buf = "This data comes from embedded C";
	dpdl_stack_buf_put(buf);
	
<<
string buf = dpdl_stack_buf_get(buf_key)
println("response buffer: " + buf)
```
The method to write data to the buffer within the embedded language is language dependent, either it's written with the
function **`dpdl_stack_buf_put(..)`** or in some cases returned by the embedded function itself, as in 'Lua' for example,
where the a data 'table' is returned and written to the Dpdl stack buffer.

Example with embedded 'Lua':
```python
println("testing embedding lua....")

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

### Dpdl Runtime parameters

Some Dpdl runtime behavior can be parameterized by pushing dedicated parameters on the dpdl stack by using the function
**`dpdl_stack_push(..)`**

Each Dpdl language plug-in can be parameterized in this way (see plug-in spec)

Example:
```
dpdl_stack_push("dpdl:compile","dpdl:-I./DpdlLibs/C")
```

#### Compile options

Embedded ANSI C code and OCaml code can be compiled on-the-fly in memory at runtime in order to speedup execution.

**Compiles embedded code before execution:**
```
dpdl:compile
```

See this doc for more details: [Dpdl_compiler_documentation.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_compiler_documentation.md)


#### Code substitution

**Applies the variables to the embedded code:**
```
dpdl:applyvars
```

See this doc for more details: [Dpdl_compiler_documentation.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_compiler_documentation.md)


### Dpdl C API

Dpdl code can be executed also embedded in a C program. 

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

char *dpdl_src_code =  "int c = 0	\n"
		  	"for(c < 1000)	\n"
				"println(\"This is Dpdl from C=\" + c)	\n"
				"c=c+1\n	\n"
			"endfor	\n";

int main(int argc, char **argv){
	printf("executing Dpdl code from C...\n");

	int ret = dpdl_exec_code(dpdl_src_code);

	printf("ret: %d\n", ret);

	return 0;
}
```


### Current limitations

- Currently recursion is currently not directly supported with pure Dpdl code. Work is progress.
- Currently dpdl arrays only have one dimension. But creating an array of arrays is possible.


## Considerations

### Dynamic function allocations

Due to the fact that Dpdl allows to dynamically implement custom function and variable extensions at runtime,
a call to a non existing function currently does not necessarily throw an unrecoverable error due to the fact that in a subsequent call, 
the the function may than be available.

This feature is useful for dynamically generated code implementations and will be evaluated accordingly.

A call to a non existent function will therefore not generate an unrecoverable exception, but will only return -1 if the function is not available.

Example:
```python
int s = my_non_existing_func()

println("s: " + s)
```



## Small 'dummy' Dpdl sample app

[Small Dpdl sample app](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/app/dummy)


## Dpdl API

[Dpdl_API](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

	
## Performance Benchmarks

### Embedded C

The embedded C code executed with mode (1) is interpreted at runtime, it's obviously a bit slower than compiled C code with mode (2). But interpreted code offers the advantage of easy and fast portability, reduces the complexity of compilation
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
po
48877 queries with a random number has key constraint have been performed:
	* With data packed in a DpdlPacket
	* Data stored in a simple RecordStore
	

#### DpdlPacket queries

Average execution time for 48877 random queries: 2 milliseconds


#### Record Store data access (on JavaME Embedded Profile)

Queries on a JavaME RecordStore are feasible only with via RecordFilter and RecordComparator classes) but which is not applicable 
in terms of speed (too slow).

Anyhow the average record store access time for 48877 entries is: 55 milliseconds

## HowTo's

Here you can find some HowTo's that may be useful

[Dpdl_howto.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_howto.md)


### Working development drafts:

Here you can find the features that are currently in development phase and will be released soon in the coming releases of DpdlEngine:

[Dpdl_drafts.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_drafts.md)

