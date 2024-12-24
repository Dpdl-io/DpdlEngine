# Dpdl Wasm Runtime

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		

## Dpdl 'Wasm' plug-in


Dpdl provides also a dedicated Dpdl language plug-in that enables to <ins>**compile, run** and **access** a **WebAssembly (WASM)**</ins> runtime **directly from Dpdl**.

Wasm is growing in popularity for being a cross platform binary instruction format for multiple application domains that range from Web-apps, Desktop and Cloud apps, serverless applications, Edge containers and others.

Many compiler toolchains nowadays can target also WASM (eg. for C/C++, Rust, JavaScript, etc..). Wasm can than be executed via a dedicated runtime in browsers, embedded nodes or Desktops. 

Also <ins>**Dpdl** supports loading and accessing exported Wasm module functions and constructs</ins>. This allows to re-use many libraries and functions compiled to wasm directly in Dpdl.

**Example (compiling WAT and call wasm module functions from <ins>'dpdl'</ins> and from <ins>'javascript'</ins>):**

```python

# main
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

println("2) we can also access the wasm module function with javascript:")

>>js
const wasmMod = new Dpdl.dpdl_wasm_obj_get("fibonacci")
const wasmInst = new WebAssembly.Instance(wasmMod, {});
const { fib } = wasmInst.exports;
for (let i = 0; i < 10; i++) {
  console.log(fib(i));
}
<<
int exit_code = dpdl_exit_code()

println("embedded javascript wasm fib exit code: " + exit_code)

println("finished")
```

**Example:** (compile a WAT script with dependencies to an already compiled WASM file and make function calls from Dpdl

[wasm/dpdlWasmTest2.h](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/wasm/dpdlWasmTest2.h)


In this folder you'll find further Dpdl examples with wasm:

[DpdlLibs/wasm](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/wasm)


### Runtimes available:

To cover at best many use cases and technologies, DpdlEngine provides 2 distinct runtimes for executing wasm, each of them providing functionalities to sweet particular use cases. The dpdl language plug-ins have been developed on top of popular open source wasm runtimes available (see References below).

The wasm runtime included supports also **WASIX**, a superset of **WASI (Web Assembly System Interface)**, and **Emscripten** as pluggable extensions.

The Wasm dpdl language plug-in provided enables <ins>also to **compile WebAssembly**</ins> text format code (WAT) to WebAssembly binary format (WASM) directly, which can than be executed in the selected wasm runtime available.

As mentioned the dpdl wasm plug-in implements two distinct runtime:

#### 1) WasmEdge

WasmEdge is a lightweight, high-performance, and extensible WebAssembly runtime that provides and isolated execution sandbox. It's suitable for many use cases such modern web application architectures, microservices on the edge cloud, serverless SaaS APIs, embedded functions, smart contracts, and smart devices.

WasmEdge supports all standard WebAssembly features and many proposed extensions including some tailored extensions for cloud-native and edge computing uses (WasmEdge network sockets, WasmEdge AI extension).

This runtime can be activated and used in Dpdl by pushing the configuration **`dpdlruntime:wasmedge`** on the dpdl runtime before executing dpdl embedded code sections.

Example:

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

This runtime can be activated and used in Dpdl by pushing the configuration **`dpdlruntime:wasmer`** on the dpdl runtime before executing dpdl embedded code sections.

Example:

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
sum = instance.exports.fib
results = fib.(10)

<<
int exit_code = dpdl_exit_code()
```

The 'Wasmer' ruby runtime bindings are available here: https://github.com/wasmerio/wasmer-ruby


## Some Examples

### Modules

Dpdl script that compiles two WebAssembly modules (in WAT code), with 1st module that exports functions to the 2nd module, to WASM binary format. The function 'add_and_sub' exported by the 2nd module is than called from Dpdl

```python

# main
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


### References

- WasmEdge (https://wasmedge.org/)
- Wasmer (https://wasmer.io/)
 



