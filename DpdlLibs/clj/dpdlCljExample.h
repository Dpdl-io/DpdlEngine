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
(ns dpdl)
	(defn make-adder [x]
	  (let [y x]
		(fn [z] (+ y z))))

	(def add2 (make-adder 2))

	;; a comment entry point
	(defn dpdl_main[^objects param]
			(println (str "Hello Clojure from Dpdl!:) 1st param: " (first param) " res:" (add2 2)))
			(int 1)
	)
<<

int exit_code = dpdl_exit_code()
println("embedded Clojure exit code: " + exit_code)
