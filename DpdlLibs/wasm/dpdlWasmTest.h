# File: wasm/dpdlWasmTest.h
#
# Example: Dpdl script that compiles a WebAssembly WAT script to binary WASM format and makes calls
#			to the exported functions from both, Dpdl and javascript
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

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

println("status_compile: " + status_compile)

# now we can access the exported wasm functions in two differet ways

println("1) we can access the wasm module function with Dpdl:")

object module1 = dpdl_wasm_obj_get("fibonacci")

println("module1 is of type: " + typeof(module1))

object res_fib = module1.fib(10)

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

