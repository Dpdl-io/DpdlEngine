# File: wasm/dpdlWasmModules.h
#
# Example: Dpdl script that compiles two WebAssembly modules (in WAT code), with 1st module that exports functions to the 2nd module,
#			to WASM binary format. The function 'add_and_sub' exported by the 2nd module is than called from Dpdl.
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

include('wasm/dpdlwasm.h')

# main
println("testing embedded WAT compiler and WASM runtime...")

dpdl_stack_push("dpdlstack:mywasm", "dpdl:compile")

>>wasm(module:math)
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
>>wasm(mycalc)
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

i32 res_calc1 = module_calc.add_and_sub(100, 200)

println("result is: " + res_calc1)


# alternatively you can also load an already compiled wasm file from file

object module_calc = dpdl_wasm_obj_load("mycalc.wasm")

i32 res_calc2 = module_calc.add_and_sub(100, 200)

println("result is: " + res_calc2)

bool equal = (res_calc1 != res_calc2)

raise(!equal, "the two results are not equal")

println("finished")
