# Dpdl Wasm Runtime

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
				

by
**SEE Solutions**
&copy;
		

## Dpdl language plug-in 'Wasm' 


This dedicated *Dpdl language plug-in* enables to **execute** <ins>**WebAssembly (WASM)**</ins> and **access** WASM functions directly from dpdl code.

The WASM is growing in popularity for being a cross platform binary instruction format for multiple application domains that range from Web-apps, Desktop and Cloud apps, serverless applications, Edge containers and others.

Many compiler tool-chains nowadays can target also WASM (eg. for C/C++, Rust, JavaScript, etc..) as the WASM format can be executed in all popular browsers, on embedded nodes and Desktop applications. 

Also **Dpdl** supports loading and accessing exported WASM module functions and constructs from dpdl code. This allows to re-use many Wasm libraries and functions available.

The *Dpdl language plug-in* for WASM <ins>includes also a compiler</ins> to compile WAT code into WASM modules, and enables than to call into functions from dpdl code.

The *Dpdl language plug-in* also supports 2 district WASM runtimes available as configurable options.

**example:** compiling WAT code and call wasm module functions from <ins>dpdl</ins>

```python

println("testing embedded WAT compiler and WASM runtime...")

>>wasmc(fibonacci)
	(module
	  (func $fib (export "fib") (param $n i32) (result i32)
	    local.get $n
	    i32.const 2
	    i32.lt_s
	    if
	      i32.const 1
	      return
	    end
	    local.get $n
	    i32.const 2
	    i32.sub
	    call $fib
	    local.get $n
	    i32.const 1
	    i32.sub
	    call $fib
	    i32.add
	    return
	  )
	)
<<
int status_compile = dpdl_exit_code()

raise(status_compile, "Error in compiling WAT code")

# now we can access the exported wasm functions in two differet ways

println("1) we can access the wasm module function with dpdl:")

object module1 = dpdl_wasm_obj_get("fibonacci")

int res_fib = module1.fib(10)

println("fibonacci of 10 is: " + res_fib)

println("finished")
```

### Runtimes available

Two distinct WAMS runtimes are curently available and can be activated by means of configuration on the dpdl stack.

* 1) **WasmEdge**
* 2) **Wasmer**

To cover at best many use cases and technologies, DpdlEngine provides 2 distinct runtimes for executing wasm, each of them providing functionalities to sweet particular use cases. The dpdl language plug-ins have been developed on top of popular open source wasm runtimes available (see References below).

The wasm runtime included supports also **WASIX**, a superset of **WASI (Web Assembly System Interface)**, and **Emscripten** as pluggable extensions.

The *Dpdl language plug-in* for WASM enables also to <ins>**compile**</ins> WebAssembly text format code (WAT) into WebAssembly binary format (WASM) directly, which can than be executed in the selected wasm runtime available.


#### 1) WasmEdge

WasmEdge is a lightweight, high-performance, and extensible WebAssembly runtime that provides and isolated execution sandbox.

It's suitable for many use cases such modern web application architectures, microservices on the edge cloud, serverless SaaS APIs, embedded functions, smart contracts, and smart devices.

WasmEdge supports all standard WebAssembly features and many proposed extensions including some tailored extensions for cloud-native and edge computing uses (WasmEdge network sockets, WasmEdge AI extension).

This runtime can be activated and used in dpdl by pushing the configuration **`dpdlruntime:wasmedge`** on the dpdl runtime before executing dpdl embedded code sections.

**example:**

```python
dpdl_runtime_push("dpdlruntime:wasmedge")
>>js
	here your javascript
<<
int exit_code = dpdl_exit_code()
```

#### 2) Wasmer

Wasmer is a Wasm Runtime that provides a secure and fast sandbox environment supporting **WASIX**, **WASI** and **Emscripten**. The runtime can be accessed from almost every programming language.

Particularly interesting is the integration of **WASIX**, which is an effort to <ins>extend the existing **WASI (Web Assembly System Interface)**</ins> with non-invasive system call extensions that provide support for Networking, Multi-threading, Asynchronous Runtimes, Filesystem, Sub-processes and forking of processes, TTY etc..

This runtime can be activated and used in dpdl by pushing the configuration **`dpdlruntime:wasmer`** on the dpdl runtime before executing dpdl embedded code sections.

**example**:

```python
dpdl_runtime_push("dpdlruntime:wasmedge")
>>ruby
	require "wasmer"
	require "dpdl"
	
	wasm_bytes = Dpdl::dpdl_wasm_obj_get("fibonacci")
	
	store = Wasmer::Store.new
	
	module_ = Wasmer::Module.new store, wasm_bytes
	
	instance = Wasmer::Instance.new module_, nil
	
	# The Wasm module exports a function called `fib`.
	fib = instance.exports.fib
	results = fib(10)

<<
int exit_code = dpdl_exit_code()
```

The 'Wasmer' ruby runtime bindings are available here: https://github.com/wasmerio/wasmer-ruby


## Examples

### Compiling a WAT module that makes use of an external wasm lib functions

```
println("testing embedded WAT compiler and WASM runtime...")

dpdl_runtime_push("dpdlruntime:./DpdlLibs/wasm/code/lib.wasm")

>>wasmc(mycalc)
	(module
	  (type $type0 (func (param i32 i32)(result i32)))
	  (import "lib" "add" (func $math-add (type $type0)))
	  (import "lib" "mul" (func $math-mul (type $type0)))
	
	  (func (export "add_and_square") (param i32 i32) (result i32)
	    (call $math-mul
	      (call $math-add (local.get 0) (local.get 1))
	      (call $math-add (local.get 0) (local.get 1))
	    )
	  )
	
	  (func (export "sum_of_squares") (param i32 i32) (result i32)
	    (call $math-add
	      (call $math-mul (local.get 0) (local.get 0))
	      (call $math-mul (local.get 1) (local.get 1))
	    )
	  )
	)
<<
int status_compile = dpdl_exit_code()

raise(status_compile, "Error in compiling WAT code")

object mycalc = dpdl_wasm_obj_get("mycalc")

println("calculating sum of squares...")

object res1 = mycalc.sum_of_squares(2, 2)

println("res: " + res1)

println("calculating add and square...")

object res2 = mycalc.add_and_square(2, 2)

println("res: " + res2)

println("finished")

```

Here is the WAT code for the external WASM module included: [wasm/code/lib.wat](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/wasm/code/lib.wat)

### WASM Modules

Dpdl script that compiles two WebAssembly modules (in WAT code), with 1st module that exports functions to the 2nd module, to WASM binary format.

The function '*add_and_sub*' exported by the 2nd module is than called from dpdl.

```python

println("testing embedded WAT compiler and WASM runtime...")


>>wasmc(module:math)
	(module
	  (func (export "add") (param i32 i32) (result i32)
	    (i32.add (local.get 0) (local.get 1))
	  )
	  (func (export "sub") (param i32 i32) (result i32)
	    (i32.sub (local.get 0) (local.get 1))
	  )
	)
<<
int status_module1 = dpdl_exit_code()

raise(status_module1, "Error in compiling module 'math'")

dpdl_runtime_push(module:math)
>>wasmc(mycalc)
	(module
	  (type $type0 (func (param i32 i32)(result i32)))
	  (import "math" "add" (func $math-add (type $type0)))
	  (import "math" "sub" (func $math-sub (type $type0)))
	  (func (export "add_and_sub") (param i32 i32) (result i32)
	    (call $math-add
	      (call $math-sub (local.get 0) (i32.const 23))
	      (call $math-sub (local.get 1) (i32.const 23))
	    )
	  )
	)
<<

int status_compile = dpdl_exit_code()

raise(status_compile, "Error in compiling module 'mycalc'")

object module_calc = dpdl_wasm_obj_get("mycalc")

int res_calc1 = module_calc.add_and_sub(100, 200)

println("result is: " + res_calc1)


# alternatively you can also load an already compiled wasm file from file

object module_calc = dpdl_wasm_obj_load("mycalc.wasm")

int res_calc2 = module_calc.add_and_sub(100, 200)

println("result is: " + res_calc2)

bool equal = (res_calc1 != res_calc2)

raise(!equal, "the two results are not equal")

println("finished")

```


### Other examples

In this folder you'll find further Dpdl examples with wasm:

[DpdlLibs/wasm](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/wasm)


### References

- WasmEdge (https://wasmedge.org/)
- Wasmer (https://wasmer.io/)
 



