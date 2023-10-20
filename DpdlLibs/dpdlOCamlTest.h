# File: dpdlOCaml.h
#
# Example: This Dpdl script pushes parameters on the dpdl stack and executes embedded OCaml code
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#

# main
println("testing Dpdl embedded OCaml...")

dpdl_stack_push("donotcompile")

dpdl_stack_var_put("var1", "Hello OCaml from Dpdl")
dpdl_stack_var_put("nr_iter", "Dpdl")

>>ocaml

external get_binding : string -> 'a = "script_get_binding";;

let s : string = get_binding "var1";;
let n = Int32.to_int (get_binding "nr_iter");;

for i = 1 to n do print_endline s done;;

<<

int exit_code = dpdl_exit_code()

println("embedded OCaml exit code: " + exit_code);
