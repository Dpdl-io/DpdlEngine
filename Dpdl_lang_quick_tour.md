# Dpdl (Dynamic Packet Definition Language)

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy;	



## Dpdl language quick Tour


### Contents

<table>
<tr><td width=33% valign=top>

* [Hello World](#hello-world)
* [Simple](#simple)
* [Object oriented](#object-oriented)
* [Interoperable with JVM classes](#interoperable-with-jvm-classes)
* [Performance](#performance)
* [Native library access](#native-library-access)
* [C compatibility for data structures](#c-compatibility-for-data-structures)
* [Multiple programming languages can be embedded and executed directly inside Dpdl code](#multiple-programming-languages-can-be-embedded-and-executed-directly-inside-dpdl-code)
* [Dpdl to native java bytecode generation at runtime](#dpdl-to-native-java-bytecode-generation-at-runtime)
* [Optimizations via native C code 'embedded code sections'](#optimizations-via-native-c-code-embedded-code-sections)
* [AI generative code inside Dpdl](#ai-generative-code-inside-dpdl)
* [Dpdl can be executed very efficiently from C code](#dpdl-can-be-executed-very-efficiently-from-c-code)


</td></tr>
</table>



### Hello World

```python
println("Hello World")
```

In case when parameters are passed as command line arguments

```python
func dpdl_main(object args)
	println("Hello World with arguments: " + args " with the type: " + typeof(args))
end
```


### Simple 

Dpdl example loading a json data string into a dpdl `struct` which can than be accessed

```c
import('json')


string myjson_str = "'"
{
  "mystr": "Hello Dpdl JSON",
  "i_num": 10,
  "f_num": 0.2,
  "d_num": 23.1,
  "b_val": true
}
"'"

struct myJsonData {
	string mystr
	int i_num
	float f_num
	double d_num
	bool b_val
}

struct myJsonData data

data = json.decode(myjson_str, data)

println("data.mystr: " + data.mystr)
println("data.i_num: " + data.i_num)
println("data.f_num: " + data.f_num)
println("data.d_num: " + data.d_num)
println("data.b_val: " + data.b_val)

```

Support for string interpolation and string templates

```python
func myCalc(long nr_iter)
	int x, y
	float z
	double res
	
	int i
	for(i < nr_iter)
		x = i % 100
		y = i % 200
		res = res + x * y 
		
		println("x = $x, y = $y")
		
		println("x + y is equal to ${ x + y }")
		
		i=i+1
	endfor
	
	return res
end

long size = 100000L

double res = myCalc(size)

println("result: " + res)

```

* [Contents](#contents)

### Object oriented

Dpdl is intrinsically object oriented

```python

class Vehicle {
	string type
	
	func Vehicle(string type_)
		this.type = type_
	end
	
	func getType() string
		return type
	end
	
	func setType(string type_)
		type = type_
	end
}

class Car extends Vehicle {

	string brand
	
	func Car(string type)
		super(type)
		this.brand = "unknown"
	end
	
	func Car(string type, string brand)
		super(type)
		this.brand = brand
	end
	
	func getBrand()
		return brand
	end
}

class Car mycar("Jeep", "Mercedes")

println("The type of my car is: " + mycar.getType() + " and the brand is: " + mycar.getBrand())

class Car yourcar("Suv")

yourcar.setType("Porsche")

println("The type of your car is: " + yourcar.getType() + " and the brand is: " + yourcar.getBrand())

```

* [Contents](#contents)


### Interoperable with JVM classes

Dpdl can access classes of any underlying JVM platform and of any external Java, Kotlin, Scala, Groovy and Clojure library.

The following Dpdl code for example makes use of a '**java.util.HashMap**', enabling access to all methods of the underlying jre classes

```python
object mymap = new("HashMap")

mymap.put(1, "Test 1")
mymap.put(2, "Test 2")
mymap.put(3, "Test 3")

println("iterating over Map key/values...")

object keys = mymap.keySet()
object iter = keys.iterator()

object key, val
while(iter.hasNext())
	key = iter.next()
	val = mymap.get(key)
	println("" + key + "=" + val)
endwhile
```

Access to any other custom java classes and libraries


```python
object mycls = new("test.MyTestCalc", 1, 2, 3, 23.0)

mycls.mycreateSum()

```

* [Contents](#contents)


### Performance

Dpdl allows to choose the optimal libraries for creating best performance critical applications

Here for example a Dpdl implementation of a 3D model visualization app for chemical molecules (in this case hydrogen) using the JavaFX library. The model can be rotated freely with mouse events

[graphics/dpdl3DJavaFX_molecule.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/graphics/dpdl3DJavaFX_molecule.h)

<p align="center">	
	<img src="https://www.dpdl.io/images/platform/examples/Dpdl_3D_Example2_with_JavaFX.png" width="85%" height="85%">
</p>

[VIDEO of Dpdl sample 3D application](https://youtu.be/82SRI_L3vLc)


* [Contents](#contents)


### Native library access

Dpdl enables access to Native library functions seamlessly.

```python
import('native')


println("loading native 'libc' library...")

object libc = native.loadLib("c")

raise(libc, "Error in loading library")

println("getting 'uid' and 'gid'...")

int uid = libc.getuid()
println("uid: " + uid)

int gid = libc.getgid()
println("gid: " + gid)

string env_java = libc.getenv("JAVA_HOME")
println("environmental variable java: " + env_java)

int page_size = libc.getpagesize()
println("page_size: " + page_size)

println("")
println("setting a new environment variable...")

int stat = libc.setenv("MY_ENV", "this is my MEGA env", 1)
println("status: " + stat)

println("opening file in RW mode for writing...")

object fcntl = getObj("Fcntl")

int fh = libc.open("./Test/TestWriteNative.txt", fcntl.O_RDWR)

raise(fh, "Error in opening file")

println("writing values...")

int i = 3
double d = 999.5d
float f = 23.0
long l = 10000000L

char ch1 = 'X'
char ch2 = 'D'
char ch3 = 'P'
char ch4 = 'D'
char ch5 = 'L'
char ch6 = 'X'
char ch7 = '\0'

object size = new("size_t")
size.setValue(4096L)

long size_l = size.longValue()

object memory = libc.malloc(4096)
memory.setMemory(0L, 4096L, 0x00B)

println("memory: " + typeof(memory))

object bytebuf = memory.getByteBuffer(0L, size_l)

bytebuf.putInt(i)
bytebuf.putDouble(d)
bytebuf.putFloat(f)
bytebuf.putLong(l)

bytebuf.putChar(ch1)
bytebuf.putChar(ch2)
bytebuf.putChar(ch3)
bytebuf.putChar(ch4)
bytebuf.putChar(ch5)
bytebuf.putChar(ch6)
bytebuf.putChar(ch7)

object sz = libc.write(fh, memory, size)

println("nr of bytes written: " + sz)

libc.close(fh)

```

* [Contents](#contents)


### C compatibility for data structures

Dpdl ensures C compatibility for data structures.

The dpdl type `struct` can be passed to C functions as an equivalent C 'struct' (see dpdl api function  `genObjCodeC(...)`)

For example assume we have a C library called 'my_native' ( libmy_native.so) with the following function definition:

```c
struct myS {
	int id;
	....
};

int my_function(const struct myS *data, int value){
	...
}
```

The native library C function can be called from Dpdl with an interoperable `struct` data structure and semantics

```c
import('native')

struct myS {
	int id = 23
	string desc = "my description"
	string data = "some data from myA"
	int x
	int y
}

struct myS s

println("s: " + s)

println("type of 's' is : " + typeof(s))


object s_structC = genObjCodeC(s)

println("s_structC: " + s_structC + " type: " + typeof(s_structC))

object mylib = native.loadLib("my_native")

int value = 888
int ret = mylib.my_function(s_structC.ByReference(), value)

println("returned value: " + ret)

```

* [Contents](#contents)


### Multiple programming languages can be embedded and executed directly inside Dpdl code

Dpdl enables the use multiple programming languages right inside Dpdl code, of multiple types, simultaneously and at native speed.

**Example:**

```python
println("with Dpdl you can embed and execute code sections in many different programming languages, simultaneously and of multiple types...")
println("Everything is already included, NO need to install additional dependencies :)")
println("")

println("embedding some C code...")

>>c
	#include <stdio.h>

	int v = 1000;
	float x = 23.0;
	char *m = "this message is printed in c";

	for(int i = 0; i < v; i++){
		printf("msg: %s %d %lf\n", m, i, x);
	}
<<

int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code)
println("")

println("embedding some javascript code...")


dpdl_stack_push("my Hello Message!!!")
>>js
	import { fib } from "./DpdlLibs/js/fib_module.js";

	var a_message = "null";

	if(scriptArgs.length > 0){
		a_message = scriptArgs[0];
	}
	std.printf("Message = %s %d", a_message, 23);
	console.log('');
	console.log('this fibonacci calculation is perfomed in javascript');
	console.log("fib(10)=", fib(10));
<<

exit_code = dpdl_exit_code()

println("embedded javascript exit code: " + exit_code)
println("")

println("you can embed many other languages too...")

println("we list them with via embedded python code:")

>>python
languages = ['C', 'C++', 'Python', 'JavaScript', 'Julia', 'Lua', 'Ruby', 'Java', 'PHP', 'Perl', 'Groovy', 'Clojure', 'Modelica']

for language in languages:
	print(language)
<<

exit_code = dpdl_exit_code()

println("embedded python exit code: " + exit_code)
println("")

```

See ['Dpdl language plug-ins'](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_language_plugins.md) for more info


* [Contents](#contents)


### Dpdl to native java bytecode generation at runtime

The dpdl types `class`and `struct` can also be compiled into java bytecode classes at runtime

```python
class A {

	int id
	string str
	var obj = null

	func A(int id_, string str_, object obj_)
		id = id_
		str = str_
		obj = obj_
	end

	func print()
		println("id: " + id)
		println("str: " + str)
		println("obj: " + obj)
	end

	>>java
	public int myNativeJavaMethod(int val){
		System.out.println("myNativeJavaMethod()");

		int myi = 0;
		for(int i = 0; i < 1000000; i++){
			System.out.println("iter: " + i + " val: " + (val+i));
			myi=i;
		}
		val=myi;
		return (val+3);
	}
	<<
}


println("testing 'genObjCode(..)' on type class...")
println("")

println("initialization with constructor:")

object so = new("String", "MEGA test")

class A mya(23, "a Test is this", so)

println("mya: " + mya + " is of type: " + typeof(mya))

println("mya.id: " + mya.id)
println("mya.str: " + mya.str)
println("mya.obj: " + mya.obj)


println("")
println("generating java class object...")

object myAobj = genObjCode(mya)

println("myAobj: " + myAobj + " is of type: " + typeof(myAobj))

println("myAobj.id: " + myAobj.id)
println("myAobj.str: " + myAobj.str)
println("myAobj.obj: " + myAobj.obj)

println("calling native java bytecode method on java class...")

setStartTime()

int res = myAobj.myNativeJavaMethod(23)

int ms = getEndTime()

println("res: " + res)

println("finished in " + ms + " milliseconds (ms)")

```

* [Contents](#contents)


### Optimizations via native C code 'embedded code sections'

Dpdl enables to optimize dpdl functions via embedded C code sections that are compiled and executed at native speed.

```c

func myOptimizedMatrixCalculation(string mata, string matb, int m_size) int

	dpdl_stack_var_put("mat_a", mata)
	dpdl_stack_var_put("mat_b", matb)

	dpdl_stack_obj_put("size_matrix", m_size)

	dpdl_stack_push("dpdlbuf_myresult", "dpdl:applyvars", "dpdl:compile", "parameters can also be passed here for example...", 1, 2, 3.3)

	>>c
	#include <stdio.h>

	#define SIZE {{size_matrix}}

	int a[SIZE][SIZE] = {{mat_a}};
	int b[SIZE][SIZE] = {{mat_b}};

	int result[SIZE][SIZE];

	extern void dpdl_stack_buf_put(char *buf);


	void matMult(int *a, int *b, int *result, int size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				*(result + i * size + j) = 0;
				for (int k = 0; k < size; k++) {
					*(result + i * size + j) += *(a + i * size + k) * *(b + k * size + j);
				}
			}
		}
	}

	void writeMatrixResult(char *res_buf, int *mat, int size) {
		int rb = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				rb += sprintf(res_buf+rb, "%d ", *(mat + i * size + j));
			}
			rb += sprintf(res_buf+rb, "\n");
		}
	}

	int dpdl_main(int argc, char **argv) {

		printf("init optimized matrix multiplication matMult\n");

		printf("# params: %d\n", argc);
	    for (int p = 0; p < argc; p++){
	        printf("	param #%d: %s\n", p, argv[p]);
	    }

		matMult((int *)a, (int *)b, (int *)result, SIZE);

		char my_result[256];

		printf("result matrix:\n");

		writeMatrixResult(my_result, (int *)result, SIZE);

		dpdl_stack_buf_put(my_result);

		return 0;
	}
	<<

	return dpdl_exit_code()

end


println("multiplying two matrixes with optimized embedded native C code")

int mat_size = 2

println("mat_size: " + mat_size)

string mat_a = "{{1, 2}, {3, 4}}"

string mat_b = "{{1, 2}, {3, 4}}"

int status = myOptimizedMatrixCalculation(mat_a, mat_b, mat_size)

raise(status, "Error in matrix calculation")

string res_buf = dpdl_stack_buf_get("dpdlbuf_myresult")

println("result: ")

println(res_buf)

```

* [Contents](#contents)


### AI generative code inside Dpdl

Dpdl supports AI assisted coding with help of the **Dpdl language plug-in** '`DpdlAINerd`'

The example below generates, compiles and executes AI generated code (via DeepSeek, OpenAI, etc..) right away

```python
println("testing the Dpdl language plug-in 'DpdlAINerd' to automatically generate and execute code...")

>>ai
	>>c
	write a console program in C that implements the famous SNAKE game, with colorful graphics using ncurses colors
<<
int exit_code = dpdl_exit_code()

raise(exit_code, "Error in generating code from natural language description")

println("exit code: " + exit_code)

println("finished")
```

* [Contents](#contents)


### Dpdl can be executed very efficiently from C code

Dpdl can be easily embedded in C/C++ libraries and applications

Either directly executing plain dpdl code

```c
#include <stdio.h>
#include "dpdl.h"

char *dpdl_src_code =   ""
			"println('Dpdl Hello World from C code')"
			"int c = 0	\n"
		  	"for(c < 1000)	\n"
			"	println('This is Dpdl iteration #' + c)	\n"
			"	c=c+1\n	\n"
			"endfor	\n";

int main(int argc, char **argv){
	printf("executing Dpdl code from C...\n");

	int ret = dpdl_exec_code(dpdl_src_code);

	printf("ret: %d\n", ret);

	return 0;
}
```

Or by loading an external dpdl source code file ( *.dpdl or *.h )

```c
#include <stdio.h>
#include "dpdl.h"

int main(int argc, char **argv){
	printf("executing Dpdl from C...\n");

	char *dpdl_src_file = "test/testString.dpdl";

	int ret = dpdl_exec_script(dpdl_src_file);
	
	printf("ret: %d\n", ret);

	return 0;
}
```

* [Contents](#contents)


### Check the full Documentation for a deeper insight

[Dpdl Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)


