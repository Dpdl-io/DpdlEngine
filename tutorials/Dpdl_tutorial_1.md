# Dpdl tutorials

![Dpdl](https://www.dpdl.io/images/dpdl-io_blue_small.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy;


# Dpdl tutorial #1

This tutorial shows how you can make use of WebAssemby code function calls within Dpdl.

## Introduction

The 'DpdlEngine' release <ins>**includes** a dedicated 'Dpdl language plug-in' for **loading and executing WASM code** (with WASI support)</ins> and perform function calls to wasm code from Dpdl code. The plug-in <ins>allows also to compile WAT code to wasm on-the-fly</ins>.

WebAssemby (Wasm) is a portable and performant binary instruction format for a stack-based virtual machine that is executed in popular web browsers and clients or on server side runtime applications. Modern compilers like Rust and LLVM based compilers can mostly target also WASM as executable format. 

Many libraries and modules are nowadays available in WASM that can for example be loaded and executed in JavaScript within a web-client or in a native server-less rust application on server side.

For these reasons it may be very handy to be able to load and execute WASM code within your codebase.


## Description

In this tutorial we'll develop a library using the Rust programming language that performs a simple operation. The rust library will be targeted to WASM so that it can be loaded in multiple wasm execution environments.

We'll create a simple Dpdl script that allows to call wasm functions directly via Dpdl function calls. 
We'll also present more articulated example embeds WAT code that is compiled in memory at runtime to WASM and loaded so that the exported functions can also be accessed via ordinary Dpdl function calls.

## Prerequisites

- Java JRE 17
- DpdlEngine that includes Dpdl language plug-in for 'wasm'
- Rust compiler


### DpdlEngine

DpdlEngine requires a java virtual machine to run. Although DpdlEngine is compatible also with earlier versions of java (e.g 1.4), for this setup we'll use java JRE 17.

DpdlEngine is a self-contained software package that you may just extract from the zip archive and run from the contained folder.


### Rust compiler toolchain

To install the Rust compiler toolchain execute the following command (on Linux/MacOS)

```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

install the 'wasm32-wasi' target extension:

```
rustup target add wasm32-wasi
```

## Steps

### Create Dpdl code folder

Create a folder in './DpdlLibs' named 'DpdlWasm'

In this folder we'll put everything needed to run the example

### Rust library

First we create and build the Rust library 'mytest_lib' with WASM as target format.

#### create the rust lib project
```
cd ./DpdlLibs/DpdlWasm
cargo new mytest_lib --lib 
```

The command above will create the project and a sample source file './src/lib.rs'

First we change the library output type, add this entry to 'Cargo.toml'
```
[lib]
crate-type = ["cdylib"]
```

Let's edit the './src/lib.rs' as follows:

```rust
use std::env;

#[no_mangle]
pub extern "C" fn print_env() {
  println!("environmental variables:");
  for (key, value) in env::vars() {
    println!("{}: {}", key, value);
  }
}
```

The above rust code exports a function 'print_env' that simply prints the environment variables


#### build the library with 'wasm32-wasi' target

```
cd mytest_lib
cargo build --target wasm32-wasi --release
```

You'll now find the wasm executable 'mytest_lib.wasm' in the folder './target/wasm32-wasi/release'
 

### Dpdl code

Now we create a simple Dpdl code script that allows to load and call the rust library function.

We create a file named 'test_wasm.h' in the folder './DpdlLibs/DpdlWasm' with the following code:

```python
println("testing access to wasm functions...")

object mylib = dpdl_wasm_obj_load("./DpdlLibs/DpdlWasm/mytest_lib/target/wasm32-wasi/release/mytest_lib.wasm")

raise(mylib, "Error in loading wasm lib")

println("printing environment variables...")

mylib.my_print_env()

println("finished")

```

When executed, the Dpdl code above will print the environment variables via the rust wasm library.


#### Further integration possibilities

We present also a more articulated example that may come useful when handling wasm code. Sometimes it might be necessary add some glue code for binding wasm code.

As the Dpdl language plug-in 'wasm' comes also with an embedded WAT code compiler, we can compile and access some additional functionalities directly through the loaded wasm runtime.

The Dpdl code below loads the rust wasm library into the runtime, compiles an embedded WAT code section that depends on the wasm library to WASM. The WAT code in this case is pretty simple, it imports the rust library function and exports it under a different name.

```python
println("now we add some WAT gluecode that is also compiled to wasm to access the library...")

dpdl_runtime_push("dpdlruntime:./DpdlLibs/DpdlWasm/mytest_lib/target/wasm32-wasi/release/mytest_lib.wasm")
>>wasmc(mylib)
(module
  (import "lib" "print_env" (func $print-env))

  (func (export "my_print_env")
    (call $print-env)
  )
)
<<
int status_compile = dpdl_exit_code()

raise(status_compile, "Error in compiling WAT code")

object mylib = dpdl_wasm_obj_get("mylib")

println("printing environment variables...")

mylib.my_print_env()

println("done")
```

 
