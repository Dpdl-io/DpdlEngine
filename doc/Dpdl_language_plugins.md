
# Dpdl language plug-ins

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
		
developed by
**SEE Solutions**
&copy; 2003
		
## Dpdl embeddable programming languages

**Multiple programming languages or custom syntax interpreters can be <ins>embedded directly within Dpdl code</ins>** by using the keyword **`>>`**, for example: **>>python**

The execution of embedded programming languages is driven by the Dpdl runtime through a configurable dedicated native interface with plug-in configurable option settings. This allows developers to easily implement custom functionalities in form of plug-ins.

The Dpdl language plug-ins are mostly implemented on top of the official reference implementation of each supported programming language (see 'Embedded language references' section).

No additional installation is required, except add-on libraries.

This plug-in oriented approach allows to integrate also custom syntax or natural language interpreters or all sorts.

### Dpdl supports the embedding of the following languages available as independent Dpdl language plug-ins:

Currently the 'DpdlEngine' release supports and provides the following Dpdl language plug-ins compliant to the corresponding language implementation version.

* **`Embedded C`** (minimal subset of C90)
* **`ANSI C`** (ANSI C99)
* **`Python`**
* **`MicroPython`** (for embedded systems)
* **`Julia`**
* **`JavaScript`**
* **`OCaml`**
* **`Lua`**
* **`Ruby`**
* **`Java`**
* **`Groovy`**
* **`Clojure`**
* **`C++`** (Root)

**Add-on plug-ins available:**

* **`Wasm`** (WAT code Compiler and Wasm Runtime)
* **`Sql`**
* **`Wgsl`** (WebGPU shading language)
* **`Ai`** (DpdlAINerd)


Dpdl language plug-ins can be developed and integrated via defined interfaces and a simple configuration.

### Embedded programming languages - compatibility matrix

| Platform | C (ANSI C99) |Python |Julia |Js |Clojure |Lua |C++ |Ruby |Java |Groovy |OCaml | MicroPython
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux (x86_64) |X|X v3.2|X v1.9.3|X|X v1.12.0|X v5.4|X v6.28|*|X|X v5.0|X v4.01| v1.24.0 |
| Mac OS X (aarch64) |X|X v3.12|X v1.9.3|X|X v1.12.0|X v5.4|X v6.28|X 3.2.2|X|X v5.0|X v4.01| v1.24.0 |
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X|X v1.12.0|X v5.4|*|*|X|X v5.0|X v4.01| v1.24.0 |
| Windows64|X|*|*|X|X v1.12.0|*|*|*|X|X v5.0|X v4.01|X|


Note: The **Dpdl language plug-ins** are <ins>linked and fully compliant with the official programming language software releases</ins> (see 'Embedded language references' below)
 
### Add-on Dpdl language plug-ins - compatibility matrix

| Platform |Wasm |Sql |Wsgl |AI |
| ---  | --- | --- | --- | --- |
| Linux x86_64 |X|X|X|X|
| Mac OS X (aarch64) |X|X|X|X|
| Raspberry PI 3 (armv7)|*|X|*|X|
| Windows64|*|X|*|*|X|

### Dpdl embedded code API

Data and variables can be exchanged with the embedded code via the dpdl stack by using the API functions:

**`dpdl_stack_push(..)`**

**`dpdl_stack_var_put(..)`**

**`dpdl_stack_var_get(..)`**

**`dpdl_stack_var_glob_put(..)`**

**`dpdl_stack_var_glob_get(..)`**

**`dpdl_stack_obj_glob_put(..)`**

**`dpdl_stack_obj_glob_get(..)`**

**`dpdl_stack_buf_put(..)`**

**`dpdl_stack_buf_get(..)`**

**`dpdl_stack_obj_put(..)`**

**`dpdl_stack_obj_get(..)`**

Variables that are pushed on the dpdl stack are passed as parameters to the embedded code.

Variables can also be embedded directly in the code as placeholder, see **`{{var_name}}`**. In the latter case the variables are replaced with the actual values before code compilation and execution.

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

if the stack configuration **`dpdlstack:somekey`** is pushed on the dpdl stack, the stack variables can at a different stage be reused again

```python

dpdl_stack_push("dpdlstack:myconfig", "dpdl:compile", "MyParam1", "MyParam2", ...)

....

# all variables previously set apply 
dpdl_stack_push("dpdlstack:myconfig")

...

```

### Embedding C

#### keyword **`>>c`**

```
>>c
	your C code
<<
```

#### Modes of execution


C code can be executed in 2 different modes:

1) Interpreted C code (<ins>minimal subset of C90</ins>)
2) Compiled C code (in memory at runtime) (most <ins>ANSI C99</ins>)


#### Mode 1 (minimal and interpreted code)

The code is executed via a native Dpdl library that has a very small footprint (278 Kb) and **includes all essential C libraries**
and language constructs with **no additional dependencies** required.

Custom libraries and functions can be integrated and linked via a straight forward implementation configuration approach.

**Features:**

easy integration of custom extensions. No compile time overhead, minimal but all basic C libraries and headers already included, no dependencies, POSIX compliant (**default Mode**)

**Minimal embedded C library documentation, for Mode (1):**
[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

#### Mode 2 (full and compiled code)

This mode can be activated via the dpdl stack option '**dpdl:compile**'.

This operation mode supports ANSI C (almost full ISO C99 standard) and many GNUC extensions including inline assembly on x86. cComplex and imaginary numbers are currently not available.

The 'dpdl:compile' option currently is available for the following platforms: **Linux (x86_64) MacOS (arm64), Raspberry (armv7l), Windows 64**. 

The embedded C compiler is built on the super fast <ins>**Fabrice Bellard's TCC**</ins>.

For mode (2) a basic set of include headers are located in the folder './lib/native/$platform/include', additional dependencies can be added via the options 'dpdl:-I' and 'dpdl:-L'


* The embedded C code for mode (1) may, or may not include a 'main(..)' function. 
If the main function is defined, parameters which are pushed to the Dpdl stack via the 'dpdl_stack_push(..)' function
are passed as parameters to the main function in the C code.

* The embedded C code for mode (2) must contain a 'main(..)' or a '**dpdl_main(..)**' function

#### Example execution Mode (1) (without main(..) function):
```python
println("my Dpdl script embeds some C code")

>>c
#include <stdio.h>

printf("Hello C from Dpdl\n");
<<
```

Note: When compiling and executing embedded C with mode (2), the appropriate 'include' and 'lib' paths need to be pushed on the dpdl stack so that
the Dpdl runtime is able to find your libraries. A set of default platform directories are searched for include files and libraries (eg. /usr/include etc.)

#### Example execution Mode (1) (with main(..) function) -> function accepting parameters, and writing a result to the Dpdl stack:

```python
println("my Dpdl script embeds some C code")

dpdl_stack_push("dpdlbuf_myresult", "param1", "param 2", 23)
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
    dpdl_stack_buf_put("my result from C");
    return 0;
}
<<
int exit_code = dpdl_exit_code()
println("finished executing embedded C code: " + exit_code)

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")
println("response buffer: " + buf)
```

#### Example with embedded C code which is compiled in memory at runtime

For the dynamic on-the-fly compilation of the embedded C code (mode 2), the option '**dpdl:compile**' and eventually further compiler
parameters needs to be pushed on the dpdl stack. The compilation is performed in memory and per default does not generate
any output files. Output files may be generated by activating a specific option.

Using this approach is useful for achieving optimal speed of the executing C code.
This operation mode supports ANSI C (full ISO C99 standard) and many GNUC extensions including inline assembly (complex and imaginary numbers are currently excluded)

The default location for include header files is './lib/native/$platform/include', and for library files (static and dynamic) in './lib/native/$platform'
Custom include and library settings can be provided with the options 'dpdl:-I$INC_DIR' and 'dpdl:-L$LIB_DIR' pushed on the dpdl stack.

```python
# main
println("this Dpdl example shows how C code can be dynamically compiled (in memory at runtime) and executed on Dpdl")

# we instuct the Dpdl runtime to compile the C code
dpdl_stack_push("dpdlbuf_myresult", "dpdl:compile", "dpdl:-I./DpdlLibs/C", "var1")

>>c
#include <stdio.h>

extern void dpdl_stack_buf_put(char *buf);
	
static inline void * my_memcpy(void * to, const void * from, size_t n)
{
// NOTE: inline assembly is avaiable only on i386 and X86_64 platforms, but compiles also on ARM
int d0, d1, d2;
__asm__ __volatile__(
        "rep ; movsl\n\t"
        "testb $2,%b4\n\t"
        "je 1f\n\t"
        "movsw\n"
        "1:\ttestb $1,%b4\n\t"
        "je 2f\n\t"
        "movsb\n"
        "2:"
        : "=&c" (d0), "=&D" (d1), "=&S" (d2)
        :"0" (n/4), "q" (n),"1" ((long) to),"2" ((long) from)
        : "memory");
		return (to);
}

int dpdl_main(int argc, char **argv){
	printf("This code will be compiled before it's being executed...\n");
	int i = 0;
	while(i < 30000000){
		printf("The Future is NOW ^ %d \n", i);
		i++;
	}

	char *str_src = "MEGA source";
	char str_dest[256];
	//my_memcpy(str_dest, str_src, strlen(str_src));
	//printf("copied str: %s\n", str_dest);
	dpdl_stack_buf_put(str_src);
	return 0;
}
<<
int exit_code = dpdl_exit_code()
println("embedded C compiled and run with exit code: " + exit_code)

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")
println("result: " + buf)
```

#### Documentation C libraries (interpreted Mode 1)

[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

#### Documentation C compiler (compiled Mode 2)

[Dpdl compiler documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_compiler_documentation.md)


### Embedding Python

#### keyword **`>>python`**

```python
println("testing embedding python code")
println("")

>>python
languages = ['Dpdl', 'C', 'Python', 'OCaml']

for language in languages:
	print(language)
<<
int exit_code = dpdl_exit_code()

println("embedded python exit code: " + exit_code)
```

NOTE: In order to be able to access python packages (installed via pip), the following environment variables must be set:

```
export PYTHONHOME=$YOUR_LOCAL_PYTHON_INSTALL_DIR
export PYTHONPATH=$YOUR_LOCAL_PYTHON_INSTALL_LIB_DIR
```

When embedding python it's important to have the correct indentation as defined by the python specification. Dpdl will consider the 'tab' ( \t ) for indentation.

#### Supported python platforms (library 'dpdlpython')

Currently the 'DpdlEngine lite' release includes the native Dpdl Python library '**libdpdlpython**' for **MacOS (arm64)**, **Linux (x86_64)** and Raspberry PI 3 (armv7l)

* on **Linux:** Python version 3.2m (gcc version 4.4.7)
* on **MacOS:** Python version 3.12 (clang version 14.0.3)
* on **Raspberry PI 3**: Python version 3.2m (gcc version 4.4.11)
* <ins>Windows version will follow soon</ins> in the coming release


### Embedding MicroPython

MicroPython is an efficient implementation of the Python 3 programming language that is optimised to run on microcontrollers and in constrained environments.

MicroPython can be embedded directly within Dpdl via the following keyword.

#### keyword **`>>mpython`**

```python
println("testing embedded micropython code...")

>>mpython
for i in range(10000):
	print('iter {:08}'.format(i))

try:
	1/0
except Exception as er:
	print('caught exception', repr(er))

address_book = {'Costa A.':'2604 Crosswind Drive','Alexis B.':'1301 Hillview Drive','Billy I.':'3236 Goldleaf Lane'}

print("'ACosta' address: " + address_book['Costa A.'])

import gc
print('run GC collect')
gc.collect()

print('finish')

<<
int exit_code = dpdl_exit_code()

println("exit code: " + exit_code)
```

On Linux x86_64 for example the Dpdl language plug-in library 'libdpdlmicropython.so' is just about **`194 kb`**


##### MicroPython libraries

The python libraries usable using 'MicroPython' within the Dpdl language plug-in are available on the official MicroPython GitHub repository:

[micropython-lib](https://github.com/micropython/micropython-lib)

**Documentation:**

https://docs.micropython.org/en/latest/library/index.html



### Embedding Julia

Julia is a powerful high performance computing programming language with many scientific library packages.

https://julialang.org/

#### keyword **`>>julia`**

```python
println("testing embedding of 'julia' code...")

dpdl_stack_push("dpdlbuf_var1")

>>julia
println("applying muladd(A, B, z) ->")
println("")

A=[1.0 2.0; 3.0 4.0]
B=[1.0 1.0; 1.0 1.0]
z=[0, 100]

result = muladd(A, B, z)

result_str = string(result)

myresult_return = "matrix muladd(A, B, z): " * result_str

write_buf = @ccall dpdl_stack_buf_put(myresult_return::Ptr{UInt8})::Int32
return 1
<<

int exit_code = dpdl_exit_code()
println("embedded julia code exit code: " + exit_code)
```

NOTE: The native Dpdl library 'dpdljulia' is not included in the 'DpdlEngine lite' release, and needs to be downloaded and
      deployed separately (see 'Downloads' section in README.md)


### Embedding 'JavaScript'

JavaScript is the ideal programming language for web applications as it's supported by all popular web browsers.

JavaScript code can be embedded within Dpdl via the keyword **`>>js`** or **`>>qjs`**

JavaScript can be executed with 2 Modes:
1) Using the 'QuickJS' javascript engine from Fabrice Bellard, ES2023 compliant '**>>qjs**' (<ins>Suggested mode</ins>)
2) Using the 'Nashorn' javascript engine '**>>js**' -> available only on JRE version 11 to 15


#### Mode (1)

The QuickJS engine used provides a powerful and complete API (supports ES2023 spec https://tc39.es/ecma262/2023/)
to interact with the javascript engine at low level.
Custom native functions and objects can be implemented as shared libraries and accessed inside javascript code.

You can find examples in the folder './DpdlLibs/js/'

Refer to the official 'QuickJS' documentation for more info about the functions available:

[QuickJS doc](https://www.dpdl.io/doc/qjs/quickjs.pdf)

[JS Bignum extensions](https://bellard.org/quickjs/jsbignum.pdf)

The libraries **`std`** and **`os`** are already imported and accessible with 'std.*' and 'os.*' respectively.

The native Dpdl api function **`dpdl_stack_buf_put(..)`** is available to write data to the 'dpdlbuf_*' variable pushed on the dpdl stack.
See example: https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/js/dpdlJsCalcPi.h


##### keyword **`>>qjs`**

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

#### Mode (2)

##### keyword **`>>js`**

```python

dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
>>js
your javascript code 
print(var1)....
<<
```

NOTE: The Dpdl embedded javascript plug-in needs specific features that must be supported by the java JRE/JDK implementation.
	  Not all java virtual machines support these features. In future releases the V8 JavaScript engine will be supported.


#### Passing data to the embedded javascript

Variables can be passed to the embedded javascript by pushing them onto the Dpdl stack with the api function **`dpdl_stack_push(..)`**

Example that passes an integer variable and an array to the embedded js code:
```python
int val = 23
arr[] = [1, 2, 3, 4]

dpdl_stack_push(val, arr)
>>qjs
	var sa;
	var arr;
	var v;
	if(scriptArgs.length > 1){
		v = scriptArgs[0];
		sa = scriptArgs[1];
		arr = sa.split(",");
		std.printf("val=%d\n", v);
		console.log(arr);
	}else{
		sa = "";
	}
	for(let i = 0; i < arr.length; i++) {
		std.printf("arr[%d]=%d\n", i, arr[i]);
	}
<<
int exit_code = dpdl_exit_code()
println("Dpdl js exited with exit code: " + exit_code)
```

### Embedding Lua

#### keyword **`>>lua`**

```
>>lua
	your Lua code
<<
```

The embedded 'Lua' code may or may not include a 'main(..)' function.
If the 'main(..)' function is defined, parameters which are pushed to the Dpdl stack via the 'dpdl_stack_push(..)' function
are passed as parameters to the main function in the Lua code via a table type.


#### Example without main(..):

```python
println("my Dpdl script embeds some Lua script...")

>>lua
io.write("TEST ")
print()
<<
```

#### Example with main(..):

The parameters pushed on the Dpdl stack are passed to the Lua 'main(..)' function as table.
The main function returns also a table which is buffered info the stack variable defined 'dpdlbuf_var1'

```python
println("my Dpdl script embeds some Lua script...")

dpdl_stack_push("dpdlbuf_var1", "name", "Alexis", "surname", "Kunst")

>>lua
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

println("embedded Lua exit code: " + exit_code)

string resp_buf = dpdl_stack_buf_get("dpdlbuf_var1")

println("Lua response buffer: ")
println(resp_buf)
```

### Embedding Ruby

#### keyword **`>>ruby`**

```ruby
println("Dpdl is embedding some ruby code...")

>>ruby
	$global_variable = 23

	$dpdl_ret = 0

	puts "Hello World from ruby inside Dpdl"

	class Class1
	   def print_global
	   	   puts "Global variable in Class1 is #$global_variable"

		   for a in 1..5000 do
			   puts "This is a TEST #{a}"
		   end
	   end
	end
	class Class2
	   def print_global
		  puts "Global variable in Class2 is #$global_variable"
	   end
	end

	class1obj = Class1.new
	class1obj.print_global
	class2obj = Class2.new
	class2obj.print_global

	$dpdl_ret = 1
<<
int exit_code = dpdl_exit_code()
println("embedded ruby code exit code: " + exit_code)

```

### Embedding Java

#### keyword **`>>java`**

Java code blocks i.e a body of a method, can be embedded with the keyword **`>>java`**.

```python
println("testing embedding of java code...")

string str = "my test param"
int x = 100
float f = 0.3
double d = 99.9d

dpdl_stack_push(str, x, f, d)

>>java
System.out.println("Parameters: ");
System.out.println("	arg0: " + arg0);
System.out.println("	arg1: " + arg1);
System.out.println("	arg2: " + arg2);
System.out.println("	arg3: " + arg3);

static void myMethod1(){
	System.out.println("myMethod1: " + 1);
}

myMethod1();
myMethod2();

static void myMethod2(){
	System.out.println("method2: " + 2);
}

for(int x = 0; x < arg1; x++){
	System.out.println("x: " + x);
}
return 1;
<<

int exit_code = dpdl_exit_code()
println("embedded java exit code: " + exit_code)
```

The embedded java code must return a value, either of type 'int' or a 'String'

Parameters that are pushed onto the Dpdl stack are accessible in java via the variable names 'args0, args1, ....argsN'

The following imports are predefined so that contained code can be accessed classes directly:

- java.io.*
- java.util.*
- java.time.*
- java.sql.*

Example with a return buffer:
```python
println("testing buf return from embedded java...")

dpdl_stack_push("dpdlbuf_myres", 10)

>>java
static void myM(int val){
	System.out.println("myM: " + val);
}

myM(arg0);

String res = "";
for(int i = 0; i < arg0; i++){
	res = res + i;
}

return res;
<<
exit_code = dpdl_exit_code()
println("embedded java exit code: " + exit_code)

string resp_buf = dpdl_stack_buf_get("dpdlbuf_myres")
println("response buffer: " + resp_buf)
```

The Dpdl language plug-in uses the 'Janino' library to compile code blocks:

Refer to the 'Janino' documentation for the java language features supported: http://janino-compiler.github.io/janino/

### Embedding Groovy

Groovy code can be embedded and executed within Dpdl using the keyword **`>>groovy`**

The execution entry point is the a groovy method 'dpdl_main(Object[] param, Object var_map)' which receives as parameters all the parameters and variables from the current Dpdl stack.

**Example:**
```python
println("reading a file line by line with 'Groovy'")

dpdl_stack_push("./Test/see_solutions.html")
>>groovy

def dpdl_main(Object[] param, Object var_map){
	String myfile = (String)param[0];
	new File(myfile).eachLine { line ->
	  println line
	}
	return 1;
}

<<
int exit_code = dpdl_exit_code()

println("embedded groovy exit code: " + exit_code)
```

The 'var_map' object is a 'HashMap' containing variables and objects that have been pushed onto the execution stack.

The 'dpdl_main' method needs to return an object, either of type Integer or != null


### Embedding ROOT C++ Data Analysis Framework


https://root.cern/gallery/

The ROOT toolkit provides full featured APIs for Data visualization, modeling, statistics and many other.

ROOT C++ code can be embedded within Dpdl with the keyword '**>>root**'

NOTE: The native Dpdl library 'dpdlroot' is not included in the 'DpdlEngine lite' release, and needs to be downloaded and deployed separately (see 'Downloads' section in README.md)
		You can even request the plugin source code for building the plug-in yourself if you have specific requirements for your platform. Write to info@dpdl.io


#### keyword **`>>root`**

```python
println("test embedded ROOT C/C++...")

>>root
   TImage *img = TImage::Open("./Test/Dpdl.png");
   if (!img) {
      printf("Error: Could not open image\n");
      return;
   }
 
   img->WriteImage("./Test/Dpdl.jpg");
<<

int exit_code = dpdl_exit_code()

println("embedded ROOT exit code: " + exit_code)
```

### Embedding Clojure

#### keyword **`>>clj`**

The functional programming language 'Clojure' can be embedded within Dpdl via the keyword **`>>clj`**

The embedded 'Clojure' code is compiled before execution. The function 'dpdl_main' is the entry point

Example Dpdl code with embedded 'Clojure':
```python
println("testing embedded Clojure...")

dpdl_stack_var_put("arg1", "test1")
dpdl_stack_var_put("arg2", "test2")

>>clj
(ns dpdl)
	(defn make-adder [x]
	  (let [y x]
		(fn [z] (+ y z))))

	(def add2 (make-adder 2))

	;; a comment entry point
	(defn dpdl_main[^objects param]
			(str "Hello Clojure from Dpdl!:) 1st param: " (first param) " res:" (add2 2)))

<<

int exit_code = dpdl_exit_code()
println("embedded Clojure exit code: " + exit_code)
```

### Embedding SQL

#### keyword **`>>sql`**

This particular Dpdl language plug-in enables to embed SQL statements within Dpdl via the keyword **`>>sql`**

The language plug-in automatically connects to the database specified and retrieves the results that can than be accessed in Dpdl via an object from the Dpdl stack.

The connection parameters **`db_url`** **`db_user`** **`db_pass`** need to be pushed onto the Dpdl stack as variables.

Variables that are needed to construct the embedded query can also be pushed onto the Dpdl stack and referenced within double curly brackets eg. **`{{my_var}}`**


Example Dpdl code with embedded 'SQL':
```python
println("testing 'sql' queries with Dpdl...")

dpdl_stack_var_put("db_url", "jdbc:postgresql://127.0.0.1:5432/mytestdb")
dpdl_stack_var_put("db_user", "testuser")
dpdl_stack_var_put("db_pass", "189923")

dpdl_stack_var_put("id", "888")

dpdl_stack_push("dpdlbuf_res")

>>sql
	SELECT id, name, surname, email from mytable where id={{id}}
<<

object result = dpdl_stack_obj_get("dpdlbuf_res")

raise(result, "Error: dpdl stack buffer is null")

int rs_size = result.size()

object id, name, surname, email

int c = 0
object entry
for(c < rs_size)
	println("-----------------------------------")
	entry = result.get(c)
	id = entry.get(0)
	name = entry.get(1)
	surname = entry.get(2)
	email = entry.get(3)

	println("id: " + id)
	println("name: " + name)
	println("surname: " + surname)
	println("e-mail: " + email)

	println("-----------------------------------")

	c=c+1

endfor

println("finished")
```

Note: The 'DpdlEngine lite' release includes only the 'postgresql' JDBC driver. Additional drivers to connect to different databases must eventually be installed.


### OCaml (Experimental)

#### keyword **`>>ocaml`**

Currently the functional programming language '**OCaml**' (https://ocaml.org/) is supported, via package (http://www.ocamljava.org/),
and can be embedded directly within Dpdl scripts with the keyword **`>>ocaml`**
The library allows also to compile on the fly OCaml code in order to speedup execution.

```
>>ocaml
	your OCaml code
<<
```

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

NOTE: The Dpdl language plugin for OCaml uses 'OCaml-java' library (http://www.ocamljava.org) which requires Java 1.7 or later to successfully compile and run generated java bytecode.


### Embedded language references

- c -> https://bellard.org/tcc/tcc-doc.html
- python -> https://www.python.org/
- mpython -> https://micropython.org/
- julia -> https://julialang.org/
- javascript -> ECMAScript (Oracle nashorn) for '>>js' && QuickJS (https://bellard.org/quickjs/quickjs.html) for '>>qjs' 
- lua -> https://www.lua.org/
- ruby -> https://www.ruby-lang.org
- root (C++) -> https://root.cern/
- java -> http://janino-compiler.github.io/janino/
- groovy -> https://groovy-lang.org/
- ocaml -> http://www.ocamljava.org/
- clj -> https://clojure.org/

- wgsl -> https://www.w3.org/TR/webgpu/
- wasm -> https://webassembly.org/
 
 
