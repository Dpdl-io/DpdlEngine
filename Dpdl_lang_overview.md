# Dpdl language Overview

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	



## Dpdl language quick Tour


### Hello World

```python
println("Hello World")
```

In case you want to pass parameters to the code

```python
func dpdl_main(object args)
	println("Hello World with arguments: " + args " with the type: " + typeof(args))
end
```


### Simple 

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

### Object oriented


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
}

class Car mycar("Jeep", "Mercedes")

println("The type of my car is: " + mycar.getType() + " and the brand is: " + mycar.getBrand())

class Car yourcar("Suv")

yourcar.setType("Porsche")

println("The type of your car is: " + yourcar.getType() + " and the brand is: " + yourcar.getBrand())

```

### Interoperable with JVM and java classes


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

or access any other custom java classes


```python
object mycls = new("test.MyTest", 1, 2, 3, 23.0)

mycls.mycreateSum()

```



### Native library access

```python
println("loading native 'libc' library...")

object clib = native.loadLib("c")

raise(clib, "Error in loading library")

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

int fh = clib.open("./Test/TestWriteNative.txt", fcntl.O_RDWR)

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

object memory = clib.malloc(4096)
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

object sz = clib.write(fh, memory, size)

println("nr of bytes written: " + sz)

clib.close(fh)
```

### C compatibility for data structures

assume we have a C library called 'my_native' ( libmy_native.so) with the following function

```c
struct myS {
	int id;
	....
};

int my_function(const struct myS *data, int value){
	...
}
```

The native library C function can be called from Dpdl with an interoperable data structure and semantics

```python

struct myS {
	int id = 23
	string desc = "my description"
	string data = "some data from myA"
	int x, y
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

### Multiple programming languages can be embedded and executed directly inside Dpdl (see **`Dpdl language plug-ins`**)


```python
println("with Dpdl you can embed and execute code sections in many different programming languages, simultaneously and of multiple types...")
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
>>qjs
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

### Check the full Documentation for a deeper insight

[Dpdl Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)


