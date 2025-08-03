
# Dpdl language plug-ins (embedded code sections)

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
		
developed by
**SEE Solutions**
&copy; 2003


Dpdl introduces the concept of arbitrary '*embedded code sections*' that can be executed inside Dpdl code via dedicated plug-ins available (see **Dpdl language plug-ins**).

In this way <ins>**multiple programming languages** and **custom syntax interpreters**</ins> can be <ins>**embedded and executed** directly within Dpdl code</ins>, simultaneously and of multiple types.

The execution of embedded code is driven by the Dpdl runtime through a configurable dedicated native interface with plug-in configurable option settings. 

The plug-in oriented approach allows developers to develop and integrate also custom syntax or natural language interpreters or all sorts usable inside Dpdl code.


### Dpdl supports the embedding and execution of the following language code, available in from of 'Dpdl language plug-ins':

The current 'DpdlEngine' release has the following <ins>**Dpdl language plug-ins**</ins> available, for different platforms (see compatibility Matrix):

* **`C`** compiled code (full ANSI C99) & interpreted code (minimal subset of C90)
* **`C++`**
* **`Python`**
* **`MicroPython`** (for embedded systems)
* **`Julia`**
* **`JavaScript`**
* **`OCaml`**
* **`Lua`**
* **`Ruby`**
* **`Java`**
* **`PHP`**
* **`Perl`**
* **`Groovy`**
* **`V`**
* **`Clojure`**
* **`Modelica`**

NOTE: In case of programming languages, the available **Dpdl language plug-ins** are implemented on top of the official reference implementation of each supported programming language as listed below (see 'Embedded language references' section) and include everything needed to run the code, <ins>No additional installation are needed (except user libraries)</ins>.

#### Add-on 'Dpdl language plug-ins' available:

* **`Wasm`** -> *WAT* Compiler and *Wasm Runtime*
* **`Sql`** -> query databases via *SQL*
* **`Wgsl`** -> WebGPU shading language (*WGSL*)
* **`OCL`** -> Open Computing Language (*OpenCL*)
* **`Ai`**  -> see [doc/DpdlAINerd.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlAINerd.md)


#### In development 'Dpdl language plug-ins' (available soon in coming releases):

* **`quantum`** -> *OpenQWASM* compiler and executor to leverage Quantum Computing capabilities



## Table of Contents

<table>

<tr><td width=33% valign=top>

* [Dpdl embedded code](#dpdl-embedded-code)
* [Dpdl embedded code API](#dpdl-embedded-code-api)
* [Dpdl embedded programming languages compatibility Matrix](#dpdl-embedded-programming-languages-compatibility-matrix)
* [Embedding 'C' code](#embedding-c-code)
* [Embedding 'Python' code](#embedding-python-code)
* [Embedding 'MicroPython' code](#embedding-micropython-code)
* [Embedding 'Julia' code](#embedding-julia-code)
* [Embedding 'JavaScript' code](#embedding-javascript-code)
* [Embedding 'Lua' code](#embedding-lua-code)
* [Embedding 'Ruby' code](#embedding-ruby-code)
* [Embedding 'Java' code](#embedding-java-code)
* [Embedding 'Groovy' code](#embedding-groovy-code)
* [Embedding 'CPP' code (C++)](#embedding-cpp-code)
* [Embedding 'Clojure' code](#embedding-clojure-code)
* [Embedding 'PHP' code](#embedding-php-code)
* [Embedding 'SQL' code](#embedding-sql-code)
* [Embedding 'OCaml' code](#embedding-ocaml-code)
* [Embedding 'Modelica' code](#embedding-modelica-code)

</td></tr>
</table>


## Dpdl embedded code

Dpdl enables the embedding and execution of arbitrary *embedded code sections* within Dpdl code, which can be other programming languages as well as custom syntaxes or even natural language descriptions that are than evaluated and processed by AI inference.

### embedding code within Dpdl

Code of other than Dpdl can be embedded and executed inside Dpdl by using the *embedding keyword* **`>>`** (ex. >>python )


**Example:** dpdl code with an embedded C code section

```python
println("executing some C code...."

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

println("embedded C exit code: " + exit_code)

```

* [Table of Contents](#table-of-contents)


## Dpdl embedded code API

Data and variables can be exchanged with the embedded code via the dpdl runtime stack by using the API functions:

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


**Example:**

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

if the stack configuration **`dpdlstack:somekey`** is pushed on the dpdl stack, the stack variables can at a different stage be reused again

```python

dpdl_stack_push("dpdlstack:myconfig", "dpdl:compile", "MyParam1", "MyParam2", ...)

....

# all variables previously set apply 
dpdl_stack_push("dpdlstack:myconfig")

...

```

* [Table of Contents](#table-of-contents)

### Dpdl embedded programming languages - compatibility Matrix

(X + version) **Available**

(*) **coming soon**

| Platform | C | Python | Julia | Js | Modelica | Lua | C++ | Ruby | Java | Groovy | MicroPython | V | PHP | Perl | Clojure | OCaml |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux (x86_64) |X|X v3.2|X v1.9.3|X|X v3.6|X v5.4|X v14.0.3|*|X|X v5.0|X v1.24.0 |v0.4.9 |X v5.3 |X v5.40.0 |X v1.12.0 |X v4.01|
| Mac OS X (aarch64) |X|X v3.12|X v1.9.3|X|X v3.6|X v5.4|X v14.0.3|X 3.2.2|X|X v5.0|X v1.24.0 |v0.4.9 |X v5.3 |X v5.40.0 |X v1.12.0 |X v4.01|
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X|X v3.6|X v5.4|*|*|X|X v5.0|X v1.24.0 |v0.4.9 |X v5.3 |X v5.40.0 |X v1.12.0 |X v4.01|
| Windows64|X|*|*|X|X v3.6|*|*|*|X|X v5.0|*|v0.4.9 |*|*|X v1.12.0 |X v4.01|


Note: The **Dpdl language plug-ins** are <ins>linked and fully compliant with the official programming language software releases</ins> (see 'Embedded language references' below)
 
#### Add-on Dpdl language plug-ins - compatibility Matrix

| Platform |Wasm |Sql |Wsgl |OCL (OpenCL) |AI |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 |X|X|X|X|X|
| Mac OS X (aarch64) |X|X|X|X|X|
| Raspberry PI 3 (armv7)|*|X|*|*|X|
| Windows64|*|X|*|*|X|


#### Size of 'Dpdl language plug-ins'

The size of each individual Dpdl language plug-in varies depending on the language implementation.

Here just some examples for the size (in kilobyte), for each 'Dpdl lanugage plug-in':

| Platform | C | MicroPython |Python |Js |Lua |...|
| ---  | --- | --- | --- | --- | --- | --- |
| Linux (x86_64) |278 Kb|194 Kb|2491 Kb|2856 Kb|174 Kb|...|

The 'Dpdl language plug-ins' for other available platforms have similar sizes, but vary slightly.


* [Table of Contents](#table-of-contents)

### Embedding 'C' code

'C' code can be embedded and executed within Dpdl by using the keyword **`>>c`** and can be executed in '*compiled*' or '*interpreted*' form.

#### keyword **`>>c`**

```
>>c
	your C code
<<
```

**Example Dpdl code with embedded 'C' code:**

```python
println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0d
string a = "test"

dpdl_stack_push("dpdlbuf_var1", n, x, a)

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

#### Modes of execution


C code can be executed in 2 different modes:

1) Interpreted C code (Mode 1) --> <ins>minimal subset of C90</ins>)
2) Compiled C code (Mode 2) --> compiled in memory at runtime, supports <ins>ANSI C99</ins>


### Plug-in documentation/Specification

[specs/Dpdl_embed_C_spec.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/specs/Dpdl_embed_C_spec.md)


* [Table of Contents](#table-of-contents)


### Embedding 'Python' code

'Python' code can be embedded and executed within Dpdl by using the keyword **`>>python`**


#### keyword **`>>python`**

**Example Dpdl code with embedded 'Python' code:**

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


* [Table of Contents](#table-of-contents)


### Embedding 'MicroPython' code

MicroPython is an efficient implementation of the Python 3 programming language that is optimised to run on microcontrollers and in constrained environments.

'MicroPython' can be embedded and executed directly within Dpdl via the following keyword **`>>mpython`**.

#### keyword **`>>mpython`**

**Example Dpdl code with embedded 'MicroPython' code:**

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

The python user libraries for 'MicroPython' usable with this Dpdl language plug-in are available on the official MicroPython GitHub repository:

[micropython-lib](https://github.com/micropython/micropython-lib)

**Documentation:**

https://docs.micropython.org/en/latest/library/index.html


* [Table of Contents](#table-of-contents)


### Embedding 'Julia' code

Julia is a powerful high performance computing programming language with many scientific library packages (https://julialang.org/)

'Julia' code can be embedded and executed within Dpdl by using the keyword **`>>julia`**

#### keyword **`>>julia`**

**Example Dpdl code with embedded 'Julia' code:**

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


* [Table of Contents](#table-of-contents)


### Embedding 'JavaScript' code


'JavaScript' code can be embedded and executed within Dpdl via the keyword **`>>js`** or **`>>qjs`**


**Example Dpdl code with embedded 'JavaScript' code:**

```python
println("testing embedded js...")

dpdl_stack_push("dpdlbuf_var1", 23)
>>qjs
"use strict";

function main(args) {
	console.log('embedded javascript...');
	var result = "This is my Result=";
	if(scriptArgs > 0){
		std.printf("parameter: %d\n", scriptArgs[0]);
		result = result + scriptArgs[0];
	}

    dpdl_stack_buf_put(result);
}

var args;
if (typeof scriptArgs != "undefined") {
    args = scriptArgs;
} else if (typeof arguments != "undefined") {
    args = arguments;
} else {
    args=[1000];
}

main(args);
<<
int exit_code = dpdl_exit_code()
println("Dpdl embedded qjs terminated with exit code: " + exit_code)

string res_buf = dpdl_stack_buf_get("dpdlbuf_var1")
println("result: ")
println(res_buf)
```

### Plug-in documentation/Specification

[specs/Dpdl_embed_JS_spec.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/specs/Dpdl_embed_JS_spec.md)


* [Table of Contents](#table-of-contents)


### Embedding 'Lua' code

'Lua' code can be embedded and executed within Dpdl by using the keyword **`>>lua`**

#### keyword **`>>lua`**

```
>>lua
	your Lua code
<<
```

**Example Dpdl code with embedded 'Lua' code:**

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

### Plug-in documentation/Specification

[specs/Dpdl_embed_Lua_spec.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/specs/Dpdl_embed_Lua_spec.md)


* [Table of Contents](#table-of-contents)


### Embedding 'Ruby' code

'Ruby' code can be embedded and executed within Dpdl by using the keyword **`>>ruby`**

#### keyword **`>>ruby`**

The 'Ruby' programming language code can be embedded within Dpdl using the keyword **`>>ruby`**

**Example Dpdl code with embedded 'Ruby' code:**

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

* [Table of Contents](#table-of-contents)


### Embedding 'Java' code

'Java' code can be embedded and executed within Dpdl by using the keyword **`>>java`**

#### keyword **`>>java`**

Java code blocks i.e a body of a method, can be embedded with the keyword **`>>java`**.

**Example Dpdl code with embedded 'Java' code:**

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

**Example with a return buffer:**

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


* [Table of Contents](#table-of-contents)


### Embedding 'Groovy' code

'Groovy' code can be embedded and executed within Dpdl using the keyword **`>>groovy`**

The execution entry point is the a groovy method 'dpdl_main(Object[] param, Object var_map)' which receives as parameters all the parameters and variables from the current Dpdl stack.

**Example Dpdl code with embedded 'Groovy' code:**

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

The 'dpdl_main' method needs to return an object, either of type Integer or an Object != null


* [Table of Contents](#table-of-contents)


### Embedding 'CPP' code

'C++' code can be embedded within Dpdl with the keyword '**>>cpp**'

https://root.cern/gallery/

#### keyword **`>>cpp`**

**Example Dpdl code with embedded 'C++' code that rewrites an image format using of the ROOT framework libraries:**

The ROOT toolkit from Cern provides full featured APIs for Data visualization, modeling, statistics and many other

```python
println("test embedded C++ using ROOT libraries...")

>>cpp
   TImage *img = TImage::Open("./Test/Dpdl.png");
   if (!img) {
      printf("Error: Could not open image\n");
      return;
   }
 
   img->WriteImage("./Test/Dpdl.jpg");
<<

int exit_code = dpdl_exit_code()

println("embedded C++ exit code: " + exit_code)
```

* [Table of Contents](#table-of-contents)


### Embedding 'Clojure' code

'Clojure' code can be embedded and executed within Dpdl by using the keyword **`>>clojure`**

#### keyword **`>>clj`**

The functional programming language 'Clojure' can be embedded within Dpdl via the keyword **`>>clj`**

The embedded 'Clojure' code is compiled before execution. The function 'dpdl_main' is the entry point

**Example Dpdl code with embedded 'Clojure' code:**

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

* [Table of Contents](#table-of-contents)


### Embedding 'PHP' code

'PHP' code can be embedded and executed within Dpdl by using the keyword **`>>php`**

#### keyword **`>>php`**

The web scripting language PHP can be embedded within Dpdl code using the keyword **`php`**

The Dpdl language plug-in is developed on top of PH7, an efficient compiler and interpreter for PHP (v5.3) 

**Example Dpdl with embeddd 'PHP' code:** (reading a CSV file, counting the fields in each line, and print the values. A record with )

```python
println("testing embedded php code execution...")
println("")

dpdl_stack_push("dpdlbuf_d1", "Test/stockdata.csv")

>>php
	$row = 1;
	$rec_nr = 0;
	if( count($argv) > 0 ){
		$file = $argv[0];
	}else{
		die("Error no input file provided");
	 }
	if (($handle = fopen($file, "r")) !== FALSE) {
		while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
			$num = count($data);
			echo "$num fields in line $row:\n";
			$row++;
			for ($c=0; $c < $num; $c++) {
				echo $data[$c] . "\n";
			}
		}
		fclose($handle);
		$rec_nr = $row;
	}else{
		die("IO error while opening CSV file: $file");
	}

	dpdl_stack_buf_put("nr. of records parsed is " . $rec_nr);
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded php code")

string result = dpdl_stack_buf_get("dpdlbuf_d1")

println("")
println("result: " + result)
println("")
println("finished")
```

* [Table of Contents](#table-of-contents)


### Embedding 'SQL' code

'SQL' code can be embedded and executed within Dpdl by using the keyword **`>>sql`**

#### keyword **`>>sql`**

This particular Dpdl language plug-in enables to embed SQL statements within Dpdl via the keyword **`>>sql`**

The language plug-in automatically connects to the database specified and retrieves the results that can than be accessed in Dpdl via an object from the Dpdl stack.

The connection parameters **`db_url`** **`db_user`** **`db_pass`** need to be pushed onto the Dpdl stack as variables.

Variables that are needed to construct the embedded query can also be pushed onto the Dpdl stack and referenced within double curly brackets eg. **`{{my_var}}`**


**Example Dpdl code with embedded 'SQL' query:**

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


* [Table of Contents](#table-of-contents)


### Embedding 'OCaml' code

'OCaml' code can be embedded and executed within Dpdl by using the keyword **`>>ocaml`**

#### keyword **`>>ocaml`**

Currently the functional programming language '**OCaml**' (https://ocaml.org/) is supported, via package (http://www.ocamljava.org/),
and can be embedded directly within Dpdl scripts with the keyword **`>>ocaml`**
The library allows also to compile on the fly OCaml code in order to speedup execution.

```
>>ocaml
	your OCaml code
<<
```

**Example Dpdl script with embedded 'OCaml' code:**

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


* [Table of Contents](#table-of-contents)


### Embedding 'Modelica' code

'Modelica' code can be embedded and executed within Dpdl by using the keyword **`>>modelica`**

The 'Dpdl language plug-in' **`>>modelica`** is implemented on top to the *OpenModelica* compiler

**Example Dpdl script with embedded 'Modelica' code:**

```python
println("executing a bouncing ball physical model simulation using embedded Modelica code...")

float coeff_restitution = 0.7
float initial_height = 9.81

dpdl_stack_obj_put("cR", coeff_restitution)
dpdl_stack_obj_put("gA", initial_height)

dpdl_stack_push("dpdl:applyvars")

>>modelica

model BouncingBall
  parameter Real e={{cR}} "coefficient of restitution";
  parameter Real g={{gA}} "gravity acceleration";
  Real h(fixed=true, start=1) "height of ball";
  Real v(fixed=true) "velocity of ball";
  Boolean flying(fixed=true, start=true) "true, if ball is flying";
  Boolean impact;
  Real v_new(fixed=true);
  Integer foo;

equation
  impact = h <= 0.0;
  foo = if impact then 1 else 2;
  der(v) = if flying then -g else 0;
  der(h) = v;

  when {h <= 0.0 and v <= 0.0,impact} then
    v_new = if edge(impact) then -e*pre(v) else 0;
    flying = v_new > 0;
    reinit(v, v_new);
  end when;

end BouncingBall;

simulate(BouncingBall, outputFormat="csv");

<<

int exit_code = dpdl_exit_code()

println("model simulation exit code: " + exit_code)
```

### Embedded language references

- c -> https://www.dpdl.io/doc/dpdl_tcc/Dpdl_C_Compiler_reference_documentation.html
- java -> https://www.dpdl.io/doc/dpdl_java/Dpdl_Java_Compiler_reference_documentation.html
- python -> https://www.python.org/
- mpython -> https://micropython.org/
- julia -> https://julialang.org/
- javascript -> ECMAScript (Oracle nashorn) for '>>js' && QuickJS (https://bellard.org/quickjs/quickjs.html) for '>>qjs' 
- lua -> https://www.lua.org/
- ruby -> https://www.ruby-lang.org
- C++ (Root) -> https://root.cern/
- php -> https://ph7.symisc.net/features.html
- groovy -> https://groovy-lang.org/
- v -> https://vlang.io/
- ocaml -> http://www.ocamljava.org/
- clj -> https://clojure.org/
- modelica -> https://openmodelica.org/

- ocl -> https://registry.khronos.org/OpenCL/specs/3.0-unified/html/OpenCL_C.html
- wgsl -> https://www.w3.org/TR/webgpu/
- wasm -> https://webassembly.org/
 
 
