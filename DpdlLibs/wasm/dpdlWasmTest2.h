# File: wasm/dpdlWasmTest2.h
#
# Example: Dpdl script that compiles an embedded WebAssembly WAT script that has
#          dependecies on an already compiled wasm library (./wasm/code/lib.wasm) see lib.wat,
#          to binary WASM format and makes calls to the exported wasm functions from Dpdl
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
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

