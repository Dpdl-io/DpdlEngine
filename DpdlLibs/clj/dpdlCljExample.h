# File: clj/dpdlCljExample.h
#
# Example: This Dpdl script compiles and executes an embedded Clojure script
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedded Clojure...")

dpdl_stack_var_put("arg1", "test1")
dpdl_stack_var_put("arg2", "test2")

>>clj
(ns dpdl) (defn dpdl_main[param]
			(str "Hello clojure from Dpdl!:) param: " param " "))
<<

int exit_code = dpdl_exit_code()
println("embedded Clojure exit code: " + exit_code)
