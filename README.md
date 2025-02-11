
# Dynamic Packet Definition Language

<p align="center">
	<img src="https://www.dpdl.io/images/dpdl-io.png" width="60%" height="60%">
</p>

				  www.dpdl.io



developed by
**SEE Solutions**
&copy; 2003


## Dpdl - rapid development programming language and constrained device framework

**Dpdl** is a <ins>rapid development **programming language**</ins> and <ins>**constrained device framework**</ins> with built-in database technology.

The Dpdl language constructs and syntax is simple yet powerful and follows an object oriented paradigm **interoperable with the java platform APIs and external java and native shared libraries**.

Dpdl comes with a very compact and portable **execution engine** with an **extensible API interface** that enables also to execute code of multiple programming languages directly embedded within the same code base, simultaneously.

Dpdl provides access to <ins>**java platform API's, Native shared libraries, Wasm modules and GPU compute**</ins> and enables the <ins>**embedding** and **execution**</ins> of multiple programming languages like <em>C, C++, Python & MicroPython, Julia, JavaScript, Lua, Ruby, Java, PHP, Perl, Groovy,, Clojure, Wgsl and OpenCL</em> <ins>**directly embedded within Dpdl code**</ins>. Everything comes already included with the DpdlEngine, **<ins>No additional installations required</ins>**.

The core Dpdl engine has the **capability to run even on memory scarce devices and platforms** via an included dedicated kilobyte range virtual machine.

### Dpdl is <ins>**Self-contained**</ins>, <ins>**Portable**</ins> and <ins>**Highly customizable**</ins> via an extensible interface.

<p align="center">
	<img src="https://www.dpdl.io/images/platform/Dpdl_programming_language_framework_small.png" width="95%" height="95%">
</p>

### Dpdl = ( Java Api's + C + 'C++' + Python + Julia + JavaScript + Java + Lua + Ruby + PHP + Perl + Groovy + Clojure + Wat/Wasm + Wgsl + OpenCL + AI) = <ins>Powerful and Versatile</ins>

Custom code and syntax interpreters can be implemented and integrated in form of **'<ins>Dpdl language plug-ins</ins>'** and code execution engines can be added as extensions and embedded via a dedicated interface and configuration.

This allows developers to easily create and integrate custom syntax and language interpreters of all sorts. For example the ROOT C++ Data Analysis framework from Cern is also available as **'Dpdl language plug-in'**.

The included **Dpdl language plug-in** 'DpdlAINerd' (**DAN**) enables also to <ins>**automatically generate**</ins> via <ins>**AI generative code**</ins> programming language code and content or data, embed it automatically directly within Dpdl code and execute the code right away. Alternatively the generated code can be rewritten to a new file and executed in a subsequent step.

Additionally, the 'DpdlPacket' data container provides a convenient way to package and handle data efficiently on memory scarce devices.

## Dpdl is designed to:

### * Develop your ideas faster
### * On multiple platforms
### * Using the power of multiple programming languages and API's within a single source
### * Reuse code
### * No need to install, compile and configure environments
### * Runs on constrained devices
### * Compressing, querying and handling data efficiently on constrained devices
### * Self-contained, No additional dependencies required (except add-on libraries)
### * Facilitate rapid prototyping for Hardware programming
### * Support for IoT protocols such as Bluetooth(tm) and CoAP
### * Plug-in oriented
### * Leverage prototyping with built-in <ins>AI generative code</ins> plug-in


**DpdlEngine stack overview**

<p align="center">
	<img src="http://www.dpdl.io/images/platform/Dpdl_Dynamic_Packet_Definition_Language_components_thumb.jpg">
</p>

### Dpdl is designed to be <ins>Compact</ins>, <ins>Robust</ins>, <ins>Extensible</ins> and <ins>Portable</ins> to almost every platform

Common IoT protocol stacks such as **Bluetooth(tm)** and **CoAP** (Constrained Application Protocol) are integrated by default and other third party libraries and protocols can be added as extensions.

The included Dpdl language plug-in '**DpdlAINerd**' (**DAN**) makes <ins>use of **AI generative code** to automatically generate and embed executable code and content or data</ins> by natural language descriptions contained inside Dpdl code.

Dpdl enables integration of different technologies to leverage fast prototyping and foster research and development.


## Features

* **DpdlEngine is optimized to run on a wide range of platforms** (JavaME, J2SE, any all VMs >= 1.4 Spec). The core engine runs also on Java 1.1 spec compliant VMs. This makes it possible to run Dpdl also on very small footprint Virtual Machines (eg. JamVM, miniJVM, and others).
* **Dpdl API provides access to the complete underlying Java JRE platform API's and to external java and Native shared libraries**
* **Multiple 'Dpdl language plug-ins' available (embeddable programming languages):** <em>C, C++, Python, MicroPython, Julia, JavaScript, Lua , Ruby, Java, PHP, Perl, Groovy, Clojure, Wgsl and OpenCL</em> **programming language code can be <ins>embedded and executed directly within Dpdl code**</ins> (interpreted/compiled code)
* **Everything is already included**, **No additional installations required** (except add-on libraries)
* **Further programming languages and syntax interpreters can be embedded via a dedicated kernel execution interface in form of plug-ins**
* **Includes embedded C compiler:** On-the-fly compilation of embedded ANSI C code <ins>in memory at runtime</ins> -> <ins>very Fast compile time!!!</ins>
* **Wasm runtime** Dpdl language plug-in included allows to access 'Wasm' module functions from Dpdl and from embedded language code. Also WAT code can be directly compiled on-the-fly and executed.
* **Built-in Dpdl scripting engine with support for custom extensions** -> allows to dynamically add language features at runtime
* **Dpdl C API enables to execute Dpdl code embedded within programs written in C** 
* **On the fly conversion/compilation of Dpdl types 'class' and 'struct' into native java bytecode classes**
* **Support for common IoT protocol stacks such as Bluetooth(tm)** (JSR-82) and
**CoAP (Constrained Application Protocol)** (IETF standard RFC 7252)
* **Packing data in a 'DpdlPacket' is a convenient way to optimize and speedup access to data**.
The speedup is x 25 times faster compared to a standard record store access
* **Virtual record store filesystem**
* **Double precision floating point emulation**
* **XML** with XPath parser
* **JSON**
* **Easy integration of custom libraries**
* **Small footprint**, Only **`372 Kb`** for DpdlEngine, that can be stripped down to <ins>**`80 Kb`** for minimal setup</ins>
* Allows to **automatically generate and embed generative AI programming code within Dpdl** using the 'DpdlAINerd' (DAN) Dpdl language plug-in
* Allows to **scale computations on GPUs using the 'OpenCL' and 'Wgsl' (WebGPU shading language) Dpdl language plug-in**
* Open Source **Dpdl language plug-ins**

Dpdl enables to combine the <ins>portability and vast API availability</ins> of Java and Python, the <ins>computational power</ins> of Julia, the <ins>expressiveness</ins> of Lua and Clojure, the simplicity of Ruby and Groovy, the <ins>web-enablement</ins> of JavaScript and WebAssembly (Wasm), the <ins>power</ins> of C/C++ programming language within the same Dpdl source code, and provides a simple access to <ins>**java Api's, Native shared libraries, Wasm modules and GPU compute**</ins>.

Further, Dpdl can be used to encode, store, control and query data efficiently also on small memory footprint devices via a custom data container referred to as '**DpdlPacket**'. A DpdlPacket is a structured, highly compressed packet of data which can be managed and queried very efficiently on memory scarce devices. A DpdlPacket may may also include Dpdl code for custom setups.

These features make Dpdl a powerful rapid development platform for industrial applications, education and research, in particular also due to the fact that software written with Dpdl will be enabled to access thousands of existing high-quality software libraries.

### Small Memory footprint:

* **DpdlEngine core** (<ins>**Minimal**</ins> configuration) **`80 Kb`**
* **DpdlEngine** (<ins>**Full**</ins> configuration) **`372 Kb`**
* **DpdlNative library** (includes embedded C **Interpreter** and **Compiler**) **`278 Kb`**

* <ins>**TOTAL SIZE** of DpdlEngine</ins> (**Dpdl Full configuration with embedded C compiler/interpreter**) = **`650 Kb`**
 
The size of the DpdlEngine core can be stripped down to **`80 Kb`** for a minimal setup.


## Quick Links

### Documentation

[Dpdl Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)
  
[Dpdl API Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

[Dpdl language plug-ins](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_language_plugins.md)

[Dpdl embedded minimal C library Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

[Dpdl compiler documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_compiler_documentation.md)

[Dpdl Native Interface](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_native_Interface.md)

[Dpdl GPU Compute](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/addon_plugins/Dpdl_GPU_compute.md)

[Dpdl Wasm runtime](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/addon_plugins/Dpdl_Wasm_runtime.md)

[DpdlClient](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlClient.md)

[DpdlPacket](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlPacket.md)

[DpdlAINerd](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlAINerd.md)


### More...

[Dpdl Examples](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)

[Dpdl HowTo's](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_howto.md)

[Dpdl Tutorials](https://github.com/Dpdl-io/DpdlEngine/blob/main/tutorials/Dpdl_tutorials.md)


## Dpdl sample code

### Sample Dpdl code that make use of type 'class' Inheritance and Polymorphism

```python

struct property {
	int max_weight_gr
	float max_height_m
	string desc = null
}

class Animal {
	int id
	string name
	struct property info = {100000, 2.5,.}

	func Animal(int id_)
		id = id_
		name = "No name"

		println("new Animal() with id: " + id + " info: " + info)
	end

	func Animal(int id_, string name_)
		id = id_
		name = name_

		println("new Animal() with id: " + id + " and name: " + name + " - info: " + info)
	end

	func print()
		println("This is an Animal")
	end

	func makeSound()
		println("kind of animal is not defined")
	end

	func getHashMap()
		object h_map = loadObj("HashMap")

		info_arr[] = array(info)
		int i = 0
		for(i < info_arr.size())
			h_map.put(i, info_arr[i])
			i=i+1
		endfor

		return h_map
	end
}

class Dog : Animal {

	func Dog(int id_, string name_)
		super(id_, name_)

		info.max_weight_gr = 8000
		info.max_height_m = 0.5
		info.desc = "this breed is Shitzu"

		println("new Dog() with id: " + id + " and name: " + name + " - info: " + info)
	end

	func print()
		println("This is a Dog with name: " + name)
	end

	func makeSound()
		println("WOOF WOOF")
	end

	func makeSound(int times) int
		int ret_val

		dpdl_stack_push(times)

		>>java
			int iter = arg0.intValue();
			for(int i = 0; i < iter; i++){
				System.out.println("WOOF");
			}
			return 1;
		<<
		ret_val = dpdl_exit_code()

		return ret_val
	end

}

class Cat : Animal {

	func Cat(int id_, string name_)
		super(id_, name_)

		info.max_weight_gr = 1000
		info.max_height_m = 0.25
		info.desc = "thie breed is Siamese"

		println("new Cat() with id: " + id + " and name: " + name + " - info: " + info)
	end

	func print()
		println("This is a Cat with name: " + name)
	end

	func makeSound()
		println("MIAUU MIAUU")
	end

	func makeSound(int beep) int
		int ret_val

		dpdl_stack_obj_put("iter", beep)

		dpdl_stack_push("dpdl:applyvars")
		>>c
			#include <stdio.h>
			#include <unistd.h>

			// we output the character to ring 'bell' in the console
			for(int i = 0; i < {{iter}}; i++){
				putchar('\a');
			}
			return 23;
		<<
		ret_val = dpdl_exit_code()

		return ret_val
	end

}

println("testing class type Inheritance and Polymorphism...")
println("")

class Animal ani(1)

ani.print()
ani.makeSound()

println("")

class Dog mydog(2, "Rosa")

mydog.print()
mydog.makeSound()
int sd = mydog.makeSound(10)

object map_dog = mydog.getHashMap()
println("map dog: " + map_dog)

var entry_di = map_dog.get(0)
println("1st entry: " + entry_di +  " is of type: " + typeof(entry_di))

println("")

class Cat mycat(3, "Minni")

mycat.print()
mycat.makeSound()
int sc = mycat.makeSound(3)

object map_cat = mycat.getHashMap()
println("map cat: " + map_cat)

var entry_ci = map_dog.get(1)
println("2nd entry: " + entry_ci +  " is of type: " + typeof(entry_ci))

println("")
println("finished")
```

### Sample Dpdl code that makes use of embedded 'Groovy' code to read a file line by line and print it to the console

```python
println("reading a file line by line using embedded 'Groovy' code...")

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

Below you can find a more complex example of how Dpdl can be used to accomplish even complex tasks:

### Sample Dpdl code (GELU neural network activation function the runs on GPUs using embedded 'Wgsl' code):

```python
import('native')

# main
println("testing Wgsl algorithm on GPU...")

println("loading native libraries 'c' and 'dpdlgpu'...")

object libc = native.loadLib("c")

object libgpu = native.loadLib("dpdlgpu")

raise(libgpu, "Error in loading 'dpdlgpu' lib")

println("getting dpdlgpu lib version...")

string ver = libgpu.DPDLNATIVE_GPU_getVersion()

println("version: " + ver)

# we allocate a data buffer with 10000 entries
long DATA_SIZE = 10000L
long byte_cnt = 4L

# indexes of the tensors & kernel created
int idx_tensor_in = 1
int idx_tensor_out = 1
int idx_kernel = 1

println("allocating input buffer...")

object input_arr = libc.malloc(DATA_SIZE * byte_cnt)
input_arr.setMemory(0L, DATA_SIZE * byte_cnt, 0x00)

object output_arr = libc.malloc(DATA_SIZE * byte_cnt)
input_arr.setMemory(0L, DATA_SIZE * byte_cnt, 0x00)

println("populating input data...")

long cnt = 0L
float f_val
int tmp
for(cnt < DATA_SIZE)
	tmp = randInt(16, 1000)
	f_val = to_float(tmp)

	input_arr.setFloat(cnt, f_val)

	cnt = cnt+1L
endfor

int status_in = libgpu.DPDLNATIVE_GPU_createTensorInputS1x1(idx_tensor_in, "f32", DATA_SIZE, input_arr)
int status_out =  libgpu.DPDLNATIVE_GPU_createTensorOutputS1x1(idx_tensor_out, "f32", DATA_SIZE)


dpdl_stack_var_put("precision", "f32")
dpdl_stack_var_put("workgroup_size", "256, 1, 1")

dpdl_stack_push("dpdl:applyvars")

>>wgsl
const SCALE_FACTOR: f32 = 0.7978845608028654; // sqrt(2.0 / Math.PI)

@group(0) @binding(0) var<storage, read_write> inp: array<{{precision}}>;
@group(0) @binding(1) var<storage, read_write> out: array<{{precision}}>;

@compute @workgroup_size({{workgroup_size}})
fn main(
    @builtin(global_invocation_id) GlobalInvocationID: vec3<u32>) {
    let i: u32 = GlobalInvocationID.x;
    if (i < arrayLength(&inp)) {
        let x: f32 = inp[i];
        out[i] = select(0.5 * x * (1.0 + tanh(SCALE_FACTOR
                 * (x + .044715 * x * x * x))), x, x > 10.0);
    }
}
<<
int exit_code = dpdl_exit_code()

println("Wgsl exit code: " + exit_code)

int status_kernel = libgpu.DPDLNATIVE_GPU_createKernelS1x1(idx_kernel, idx_tensor_in, idx_tensor_out, DATA_SIZE)

int status_dispatch = libgpu.DPDLNATIVE_GPU_dispatchKernel(idx_kernel)

int wait_copy = libgpu.DPDLNATIVE_GPU_waitCopyCPU(idx_kernel, idx_tensor_out, output_arr, DATA_SIZE)

println("OUTPUT: ")

float f_val_in, f_val_out
long c = 0L
for(c < DATA_SIZE)
	f_val_in = input_arr.getFloat(c)
	f_val_out = output_arr.getFloat(c)

	println(f_val_in + "=" + f_val_out)

	c = c+1L
endfor

println("finished")

```

### Full featured sample Prototype Applications developed with Dpdl

In this GitHub repository you can find full featured working prototype applications written with Dpdl:

[Dpdl-sample-Apps](https://github.com/Dpdl-io/Dpdl-sample-Apps)


### Dpdl example to Get and decode News via http in JSON format 

This is a small sample app written with Dpdl that gets the top 10 news stories via http in 'json' format:

[app/getnews/dpdlGetNews.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/app/getnews/dpdlGetNews.h)


### Dpdl implementation of SHA-1 hash algorithm

Implementation of SHA-1 hash algorithm entirely written in Dpdl

[app/dpdlSHA-1/dpdlSHA-1impl.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/app/dpdlSHA-1/dpdlSHA-1impl.h)


### Dpdl example using external java libraries

This is a 3D model visualization of chemical molecules (in this case hydrogen) using the JavaFX library. The model can be rotated freely with mouse events (ported to Dpdl from javafx examples)

[graphics/dpdl3DJavaFX_molecule.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/graphics/dpdl3DJavaFX_molecule.h)

<p align="center">	
	<img src="https://www.dpdl.io/images/platform/examples/Dpdl_3D_Example2_with_JavaFX.png" width="85%" height="85%">
</p>

[VIDEO of Dpdl sample 3D application](https://youtu.be/82SRI_L3vLc)


### Simple Dpdl example that executes an embedded 'java' code and an embedded 'C' code directly within Dpdl

[app/simple/dpdlSimpleJavaAndC.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/app/simple/dpdlSimpleJavaAndC.h)


### Dpdl example that uses the 'sql' Dpdl language plug-in to retrieve data from a database and handle the result set

The Dpdl script connects to the database and performs a query, retrieves and prints out the result set, encodes the result set to a json string, and 
than decodes the json string to an object that can be accessed as a HashMap

[sql/dpdlSqlExampleJson.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/sql/dpdlSqlExampleJson.h) 


### Dpdl example that uses the 'Wgsl' Dpdl language plug-in to scale computations directly on GPU's

The Dpdl script implements a high-performing neural network activation function (GELU) on GPUs using the dpdl language plug-in 'Wgsl' that allows to embed and execute WGSL code (WebGPU Shading language) directly within Dpdl.

[wgsl/dpdlWgslTest.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/wgsl/dpdlWgslTest.h)


### More Dpdl Examples
	
You can find more Dpdl code snippet on the following page: 
[Dpdl_Examples.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)

Or full featured Applications written with Dpdl in the following repository:

[Dpdl-sample-Apps](https://github.com/Dpdl-io/Dpdl-sample-Apps)


## Why Dpdl?

Dpdl is suitable for <ins>rapid application development</ins> in various domains and can be used as embedded scripting engine for various applications, in particular also for development of applications on <ins>small memory footprint devices</ins>.

The main nature of Dpdl is for enabling rapid development, fast prototyping, code reuse and allow a high degree of portability while being simple,
extensible and compact. Further, developers can benefit from the possibility to use multiple programming languages due to the fact
that a vaster set of APIs are available for a given platform.

Dpdl has also built-in constructs that enable dynamic code generation for <ins>**generative AI code**</ins> and provides a dedicated plug-in interface for developing and embedding custom language interpreter plug-ins of all sorts.

The **`DpdlPacket`** data container is a highly optimized way to store, query and access data
on devices that have limited memory and storage capabilities.

The AI Dpdl language plug-in '**DpdlAINerd**' (**DAN**) can be used to speed-up the prototyping and development process by leveraging generative AI code for embedded code and data within Dpdl.

**Dpdl can be used as:**

* Rapid application development platform
* Embedded scripting engine
* Development of Domain Specific Languages (DSL)
* Data handling on memory constrained devices
* AI generative code
* Library module
* Testing framework for heterogeneous code bases
* Utility tool
	

## Access to the complete Java platform JRE API's and external java libraries


The Dpdl API allows to access all classes and methods of the <ins>underlying Java Platform (JRE)</ins> and of any <ins>external java library</ins>.

**Example:** using a java HashMap (which interfaces to <em>java.util.HashMap</em>)

```python
object map, s

map=loadObj("HashMap")
map.put(1,"Dpdl")
map.put(2,"Packet")
map.put(3,"Definition")
map.put(4,"Language")

s=map.get(1)
println(s)
s=map.get(4)
println(s)
```

Iterate over the obove HashMap using the same objects and methods as provided by the java API:

```python
object es = map.entrySet()
object iter = es.iterator()
object ep
while(iter.hasNext())
	ep = iter.next()
	println("key=" + ep.getKey() + " value=" + ep.getValue())
endwhile
```

In this way all java libraries defined in class definition configuration file can be loaded and accessed in Dpdl.

The default configuration currently includes <ins>Java Platform API</ins>, the <ins>JavaFX</ins> API and <ins>bluecove Bluetooth JSR-82</ins>.

The default configuration <ins>can be easily extended or updated</ins> to resolve additional java APIs by editing the class definition configuration file.

#### Dpdl Java API's access documentation (default configuration)

The default set of classes accessible with Dpdl is defined to be the following set. Additional classes and API's can be added by means of a simple configuration.

The methods of the classes that are accessible are referred to the current JRE instance on which Dpdl is running.

[Java API](http://www.seesolutions.it/apidoc/Java_Platform_API_1_5.html)

[JavaFX API](https://docs.oracle.com/javafx/2/api/index.html)

[Bluetooth JSR-82 API](https://docs.oracle.com/javame/config/cldc/opt-pkgs/api/bluetooth/jsr082/index.html)

It's worth mentioning here that 'Java' code can also be embedded directly within Dpdl as described below.

Here just a quick example:

```python
println("Dpdl can also embed native java code...")

object mystr = loadObj("String", "this is a Dpdl object mapped to java api, a str parameter")
int x = 23

dpdl_stack_push(mystr, "./Test/TestRead.txt", x)

>>java

System.out.println("Parameters: ");
System.out.println("	arg0: " + arg0);
System.out.println("	arg1: " + arg1);
System.out.println("	arg2: " + arg2);

static void myMethod1(){
	System.out.println("myMethod1: " + 1);
}

myMethod1();

for(int x = 0; x < arg2; x++){
	System.out.println("x: " + x);
}

File myfile = new File(arg1);

return 1;
<<
int exit_code = dpdl_exit_code()
println("embedded java exit code: " + exit_code)

```

## **Dpdl language plug-ins** (Dpdl embeddable programming languages)

Multiple programming languages can be embedded and executed within the same **Dpdl** code via configurable **Dpdl language plug-ins** by
using the keyword **`>>`**.

Further programming languages and syntax interpreters can be developed and integrated via a dedicated plug-in interface and configuration if form of **Dpdl language plug-ins**.

This enables basically every sort of programming language or natural language interpreter to be embedded directly in Dpdl code.

This features is very useful for rapid development and rapid prototyping and is also a key feature for generative code.

### Currently the following programming languages can be embedded within Dpdl:

* **`C interpreted`** code (minimal subset of C90 with standard C libs included and avaiable in the Dpdl runtime)
* **`C compiled`** code (almost full ISO C99 standard) compiled in memory and dynamically executed at runtime (see 'dpdl:compile')
* **`Python`**
* **`MicroPython`** (ideal for embedded systems)
* **`Julia`**
* **`JavaScript`**
* **`Lua`**
* **`Ruby`**
* **`OCaml`**
* **`Java`**
* **`PHP`**
* **`Perl`**
* **`Groovy`**
* **`Clojure`**
* **`C++`** (Root)

**available Add-on 'Dpdl language plug-ins':**

* **`Wasm`** -> WAT Compiler and Wasm Runtime
* **`Sql`** -> query databases via SQL
* **`Wgsl`** -> WebGPU shading language
* **`OCL`** -> Open Computing Language (OpenCL)
* **`Ai`**  -> see [doc/DpdlAINerd.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlAINerd.md)


See this doc for more details: [Dpdl_embedded_languages.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_languages.md)

#### Dpdl example with embedded 'C++' (Root) code

ROOT is a powerful Data Analysis Framework developed by CERN (https://root.cern/) .

ROOT C++ code can be embedded within Dpdl via the keyord **`>>root`**

Example Dpdl code embedding 'C++' (Root):

<img src="http://www.dpdl.io/images/platform/Dpdl_ROOT_example.png" width="60%" height="60%">

```python
# main
println("test embedded ROOT C++...")

>>root
auto canvas = new TCanvas("c","Graph2D example",0,0,700,600);

double x, y, z, P = 6.;
int np = 200;
auto dt = new TGraph2D();
auto r = new TRandom();
for (int N=0; N<np; N++) {
	x = 2*P*(r->Rndm(N))-P;
	y = 2*P*(r->Rndm(N))-P;
	z = (sin(x)/x)*(sin(y)/y)+0.2;
	dt->SetPoint(N,x,y,z);
}
dt->Draw("tri1 p0");
canvas->Modified(); canvas->Update();
<<

int exit_code = dpdl_exit_code()
println("embedded ROOT exit code: " + exit_code)
```
 
### Dpdl with embedded C code

Dpdl allows the embedding and on-the-fly execution of **ANSI C code** directly within Dpdl code with the keyword **`>>c`**

The C code can be embedded with 2 different Modes:
 
1) <ins>Interpreted code</ins> (Mode 1)
2) <ins>Compiled code</ins> (Mode 2) -> in memory at runtime


Example Dpdl code with embedded C code (Mode 1 - interpreted):

```c
# main
# starting with Dpdl, pushing parameters on the stack and embedding C code

println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0
string a = "test"

dpdl_stack_push(n, x, a)

>>c
#include <stdio.h>

int dpdl_main(int argc, char **argv){
	printf("Hello C from Dpdl!\n");
	printf("\n");
	printf("num params: %d\n", argc);
	int cnt;
    for (cnt = 0; cnt < argc; cnt++){
        printf("	param %d: %s\n", cnt, argv[cnt]);
    }
    return 0;
}
<<
int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);

# again Dpdl code...

object str = loadObj("String", "Dpdl embedded C")
bool b = str.contains("C")
println("Dpdl contains C: " + b)
```

### Embedding other programming languages

Other programming languages or natural language interpreters can be easily integrated in Dpdl via a dedicated plug-in interface and configuration (**Dpdl language plug-ins**). Please feel free to suggest your opinion on the 'Discussion' section on the DpdlEngine GitHub repository


## AI generative code with '**DpdlAINerd**' (**DAN**) Dpdl language plug-in

The Dpdl language plug-in 'DpdlAINerd' (DAN) allows to generate and embed code via popular AI engine (eg. OpenAI, Google Vertex AI, CodePal etc..)

see doc for more info:
[doc/DpdlAINerd.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlAINerd.md)


## Supported Platforms

Dpdl runs on a wide range of platforms and supports also a small footprint kilobyte range java virtual machine that can be compiled for almost every platform as soon as an ANSI C compiler is available for the target platform.

### Dpdl itself is compatible with:

* Java ME CLDC & GCF (JSR 360)
* Java ME Embedded Profile (JSR 361)
* Java versions >= 1.4 and later
* Java 1.1 - 1.3 (without 'loadObj' and 'getObj' methods)
* Platforms with ANSI C compiler where the included kilobyte range java virtual machine can be compiled

DpdlEngine V1.0 has been tested on:

	* MacOS aarch64
	* Linux x86_64
	* Raspberry PI 3 (armv7l)
	* Windows 64-bit
	* Android
	* JavaME
	* J2ME (MIDP 2.0)
		
Note: The 'DpdlEngine lite' release needs to be re-packaged for running on Android, JavaME and J2ME

### Embedded programming language plug-ins - compatibility matrix

Currently the 'DpdlEngine' release supports and provides the following Dpdl language plug-ins compliant to the corresponding language implementation version.

(X + version) **Supported**

(*) **available soon**

| Platform | C | Python |Julia |Js |Clojure |Lua |C++ |Ruby |Java |Groovy |MicroPython | PHP | Perl | OCaml |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux (x86_64) |X|X v3.2|X v1.9.3|X|X v1.12.0|X v5.4|X v14.0.3|*|X|X v5.0|X v1.24.0 |X v5.3 |X v5.40.0 |X v4.01|
| Mac OS X (aarch64) |X|X v3.12|X v1.9.3|X|X v1.12.0|X v5.4|X v14.0.3|X 3.2.2|X|X v5.0|X v1.24.0 |X v5.3 |X v5.40.0 |X v4.01|
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X|X v1.12.0|X v5.4|*|*|X|X v5.0|X v1.24.0 |X v5.3 |X v5.40.0 |X v4.01|
| Windows64|X|*|*|X|X v1.12.0|*|*|*|X|X v5.0|*|*|*|X v4.01|


### Add-on Dpdl language plug-ins - compatibility matrix

| Platform |Wasm |Sql |Wsgl |OCL (OpenCL)|AI |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 |X|X|X|X|X|
| Mac OS X (aarch64) |X|X|X|X|X|
| Raspberry PI 3 (armv7)|*|X|*|*|X|
| Windows64|*|X|*|*|X|

	
## Documentation

The Dpdl framework and API documentation is available via the following links:
 

### Documentation

[Dpdl Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)
  
[Dpdl API Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_API.md)

[Dpdl language plug-ins](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_language_plugins.md)

[Dpdl embedded minimal C library Documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

[Dpdl compiler documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_compiler_documentation.md)

[Dpdl Native Interface](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_native_Interface.md)

[Dpdl GPU Compute](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/addon_plugins/Dpdl_GPU_compute.md)

[Dpdl Wasm runtime](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/addon_plugins/Dpdl_Wasm_runtime.md)

[DpdlClient](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlClient.md)

[DpdlPacket](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlPacket.md)

[DpdlAINerd](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/DpdlAINerd.md)


### More...

[Dpdl Examples](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)

[Dpdl HowTo's](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_howto.md)

[Dpdl Tutorials](https://github.com/Dpdl-io/DpdlEngine/blob/main/tutorials/Dpdl_tutorials.md)


 Dpdl Java API Documentation (available only for the registered version of DpdlEngine)


## Download

See 'Download' page for more details:

[Download](https://github.com/Dpdl-io/DpdlEngine/blob/main/Download.md)


## Roadmap

Dpdl is currently developed by SEE Solutions and the following integrations has been defined: 

* Back-end compiler that compiles Dpdl code to native machine code for most target architectures (LLVM)
* Dpdl-IDE and provide also plug-ins for popular IDEs (IntelliJ, eclipse, MSVS)


### Embedding of 'Python' code

Python code can be embedded within Dpdl code by using the keyword **`>>python`**.
MicroPython will also be supported as option in the coming release.

Example Dpdl code with embedded 'Python' code:

```python
println("testing embedding python code")
println("")

>>python
languages = ['Dpdl', 'C', 'Python', 'Clojure']

for language in languages:
	print(language)
<<
println("")

int exit_code = dpdl_exit_code()

println("embedded python exit code: " + exit_code);
```

### Embedding of 'Julia' code

Julia is a powerful and performant computational programming language  (https://julialang.org)

Julia code can be embedded within Dpdl via the keyord **`>>julia`**

Example Dpdl code embedding 'Julia' that generates a Plot and saves the result as PDF file:
<img src="http://www.dpdl.io/images/platform/Dpdl_Julia_example.png" width="60%" height="60%">

```python
#main
println("Testing Plot data with Julia programming language...")

>>julia
using Plots

x = range(0, 10, length=100)
y1 = sin.(x)
y2 = cos.(x)
p = plot(x, [y1 y2])

savefig(p, "./Test/myplot.pdf")

dispose_status = @ccall dpdl_julia_dispose()::Int32
return 1
<<

int exit_code = dpdl_exit_code()
println("finished with exit code: " + exit_code)
```
NOTE: The native Dpdl library 'dpdljulia' needs to be downloaded and deployed separately (see Download section below)


### Embedding of 'JavaScript' code

JavaScript is the ideal programming language for web applications as it's supported by all popular web browsers.

JavaScript code can be embedded within Dpdl via the keyword **`>>js`** or  **`>>qjs`**

Dpdl allows the embedding of javascript with 2 different Modes:
1) Using the 'QuickJS' javascript engine from Fabrice Bellard '>>qjs' (Suggested)
2) Using the 'Nashorn' javascript engine embedded in the Java platform '>>js'


Example:

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

QuickJS provides a powerful and complete API to interact with the javascript engine at low level.
Custom native functions and objects can be implemented as shared libraries and loaded in javascript.
You can find examples in the folder './DpdlLibs/js/'
		

### Embedding of 'Lua' code

Lua code can be embedded within Dpdl code by using the keyword **`>>lua`**.

Example Dpdl code with embedded 'Lua' code:
```python
println("testing embedding Lua within Dpdl....")

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

### Embedding 'SQL' for querying and retrieving results from a Database (JDBC compliant)

A dedicated Dpdl language plug-in allows to directly inject SQL statements and retrieve the result sets. Connection, query and packing the results are performed 
directly by the plug-in

Example Dpdl code with embedded 'SQL':
```python
println("testing 'sql' queries with Dpdl...")

dpdl_stack_var_put("db_url", "jdbc:postgresql://127.0.0.1:5432/mytestdb")
dpdl_stack_var_put("db_user", "testuser")
dpdl_stack_var_put("db_pass", "189923")

dpdl_stack_push("dpdlbuf_res")

>>sql
	SELECT id, name, surname, email from mytable
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


## Dpdl Examples

Further Dpdl examples can be found on this page:

[Dpdl_Examples.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Dpdl_Examples.md)


## What is a DpdlPacket?

A DpdlPacket is a compact, highly compressed executable packet of data with built-in database technology that
can be created based on a defined Dpdl code definition.
 
A DpdlPacket can than be allocated and queried efficiently via API interfaces available for Java and for the built-in Dpdl language.

In particular Dpdl is very efficient on J2ME and JavaME platforms and has a high degree of backward compatibility.

A DpdlPacket contains 1 - n chunks of compressed data that can be allocated, queried and deallocated when data is not used anymore.

All kind of data can be packed into a DpdlPacket.

### DpdlPacket

![DpdlPacket](http://www.dpdl.io/images/platform/DpdlPacket_FlowChart.jpg)

**Example DpdlPacket definition source file:**

[dpdl_PHONEBOOK.dpdlpkt](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlPackets/dpdl_PHONEBOOK_BZ.dpdlpkt) 

The 'DpdlEngine lite' release package includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl) and the corresponding Dpdl code definition file used to encode the DpdlPacket.

Refer to the [Dpdl_documentation](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_documentation.md)
for how to allocate, execute and perform queries on a DpdlPacket.

Example of DpdlPacket code definition (dpdl_PHONEBOOK.c)
```cpp
call(dpdlInterpreter)
::module dpdl_PHONEBOOK
::module_SPEC 23452
::model 836
::dpdlVersion 1.0

OPTIONS {
    TARGET = CDC & CLDC
    KVM = 1.0
    ZIP = true
    CHECKSUM = true
    SIGNATURE = true
    ENCRYPTION(RSA) = false
}

#defineDpdlEncoding UTF-8

#defineDB phone_bz | ./Test/BolzanoPhone.csv | null null

#defineSQL query_ SELECT name, phoneNR, e-mail FROM phone_bz end

#defineProtocol-cHtml phonebook_visual phone_book.html

import extern SystemData

catch DPDL_Script OnInit() {
    import("dpdllib.h") nl
    println("OnInit()") nl
}

import virtual DATA none  {
        class BolzanoPhone volatile phonebook_visual {
              DATA::string const name;
              DATA::string using phoneNR;
              DATA::string using  e-mail;
              #defineGUI Default <PhoneBook>  <Enter name and surname:>
              
              catch DPDL_Script OnDecode() {
                 import("dpdllib.h") nl
                 import("dpdlRS.h") nl
                 println("OnDecode()") nl
                 string time = getTime() nl
                 println("storing access time..." + time) nl
                 int rs_id = createRS("AccessStats", AUTHMODE_ANY, dpdlTrue, dpdlTrue) nl
                 int rec_id = addRecord(rs_id, time) nl
                 int status = closeRS(rs_id) nl
                 println("done status: " + status) nl
              }
        }
}
#defineD BolzanoPhone source phone_bz SQL query {
                CHUNK entry [6];
                struct BTree DENSE_INDEX hashing *name
                entry.content { name , phoneNR , e-mail }
                entry.name TAG(0xef) const (string) = 20;
                entry.phoneNR TAG(0xefe) (string) = 15;
                entry.e-mail TAG(0xefee) (string) = 30;
}
```

This is an example Dpdl sript that show how a 'DpdlPacket' can be allocated and queried:

[dpdlpacket/testDpdlDB2.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlpacket/testDpdlDB2.h)

The database technology in Dpdl has been developed since year 2003 when the first applications where developed for mobile devices.

It started with a BsC thesis by A.Costa:

[Advanced database techniques in Dpdl : dynamic packet definition language ; a portable data protocol for small embedded systems](https://unibz.primo.exlibrisgroup.com/permalink/39UBZ_INST/hl3dt9/alma9928450240001241)


## What is the DpdlClient console application?

The DpdlClient console application included in the 'DpdlEngine lite' release is a small console application
that exposes some functionalities of Dpdl via a simple command line console. Dpdl code can be
executed and DpdlPackets handled. The same functionalities can be accessed via the java or Dpdl API.

These are the console commands available:
```
Usage: 
 -l  List DpdlPackets installed
 -i  Install DpdlPacket
 -d  Uninstall DpdlPacket
 -la List DpdlPackets allocated
 -a  Allocate DpdlPacket
 -da Deallocate DpdlPacket
 -qp Query DpdlPacket
 -c Create DpdlPacket
 -libs  List Dpdl libraries
 -slib  Show library
 -api   List Dpdl API functions
 -exec  Type && Execute a Dpdl script, between <script>...  </script>
 -load  Load && Execute a Dpdl script file (relative path to./DpdlLibs/ eg. arraylistExample.h)
 -bench  Run a query benchmark test (on DpdlPacket dpdl_PHONEBOOK)
 -h  Help
 -q  quit
```


