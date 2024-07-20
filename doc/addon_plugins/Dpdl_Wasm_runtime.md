# Dpdl Wasm Runtime

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		

## Dpdl 'Wasm' plug-in


Dpdl provides also a dedicated dpdl language runtime plug-in that enables to <ins>compile, run and access **WebAssembly (WASM)**</ins> **directly in Dpdl**.

As Wasm is growing in popularity for being a cross platform binary instruction format for multiple application domains that range from Web-apps, Desktop and Cloud apps, serverless applications, Edge containers and others. Many programming languages nowadays can be targeted to Wasm format that can be executed via a dedicated runtime in browsers or embedded nodes.

To cover at best many use cases and technologies, DpdlEngine provides 2 different runtimes for executing wasm, each of them providing functionalities to sweet particular use cases. The dpdl language plug-ins have been developed on top of popular open source wasm runtime available (see References below).

The wasm runtime included supports also **WASI (Web Assembly System Interface)**, **WASIX (a superset of WASI)** and **Emscripten** as pluggable extensions.

The Wasm dpdl language plug-in enables <ins>also to compile WebAssembly</ins> text format scripts (WAT) to WebAssembly binary format (WASM) directly, which can than be executed in the selected wasm runtime available.

**Example (compiling WAT and call wasm module functions from 'dpdl' and from 'javascript'):**

```python
include('dpdlwasm.h')

# main
println("testing embedded WAT compiler and WASM runtime...")

dpdl_stack_push("dpdlstack:mywasm", "dpdl:compile")

>>wasm(fibonacci)
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

i32 res_fib = module1.fib(10)

println("fibonacci of 10 is: " + res_fib)

println("2) we can also access the wasm module function with javascript:")

dpdl_stack_push("dpdlruntime:wasmer")
>>js
const wasmInst = new WebAssembly.Instance(wasmModule, {});
const { fib } = wasmInst.exports;
for (let i = 0; i < 10; i++) {
  console.log(fib(i));
}
<<
int exit_code = dpdl_exit_code()

println("wasm fib exit code: " + exit_code)

println("finished")
```


### Runtimes available:

As mentioned the dpdl wasm plug-in implements two distinct runtime:

#### 1) WasmEdge

WasmEdge is a lightweight, high-performance, and extensible WebAssembly runtime that provides and isolated execution sandbox. It's suitable for many use cases such modern web application architectures, microservices on the edge cloud, serverless SaaS APIs, embedded functions, smart contracts, and smart devices.

WasmEdge supports all standard WebAssembly features and many proposed extensions including some tailored extensions for cloud-native and edge computing uses (WasmEdge network sockets, WasmEdge AI extension).

This runtime can be activated and used in Dpdl by pushing the configuration **`dpdlruntime:wasmedge`** on the dpdl stack before executing dpdl embedded code sections.

Example:

```python
dpdl_stack_push("dpdlruntime:wasmedge")
>>js
here your javascript
<<
int exit_code = dpdl_exit_code()
```

#### 2) Wasmer

Wasmer is a Wasm Runtime that provides a secure and fast sandbox environment supporting **WASIX**, **WASI** and **Emscripten**. The runtime can be accessed from almost every programming language.

Particularly interesting is the integration of **WASIX**, which is an effort to <ins>extend the existing **WASI (Web Assembly System Interface)**</ins> with non-invasive system call extensions that provide support for Networking, Multi-threading, Asynchronous Runtimes, Filesystem, Sub-processes and forking of processes, TTY etc..

This runtime can be activated and used in Dpdl by pushing the configuration **`dpdlruntime:wasmer`** on the dpdl stack before executing dpdl embedded code sections.

Example:

```python
dpdl_stack_push("dpdlruntime:wasmedge")
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


### References 

- WasmEdge (https://wasmedge.org/)
- Wasmer (https://wasmer.io/)
- WATB (https://github.com/WebAssembly/wabt)
 



