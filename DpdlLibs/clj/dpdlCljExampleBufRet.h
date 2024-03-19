# File: tmp/dpdlCljExampleBufRet.h
#
# Example: This Dpdl script compiles and executes an embedded Clojure script that accepts parameters from the Dpdl stack
#			and writes a result to a buffer stack variable that is intercepted again in Dpdl
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedded Clojure...")

dpdl_stack_push("dpdlbuf_result", "my Param 1", "my Param 2")
>>clj
(ns dpdl)
	(defn make-adder [x]
	  (let [y x]
		(fn [z] (+ y z))))

	(def add2 (make-adder 2))

	;; a comment entry point
	(defn dpdl_main[param & more]
			(println "this code is executed in Clojure:)")
			(str "Hello Clojure from Dpdl!:) param: " param " more: " (count more) " res:" (add2 2))
	)

<<

int exit_code = dpdl_exit_code()
println("embedded Clojure exit code: " + exit_code)

string result = dpdl_stack_buf_get("dpdlbuf_result")
println("result: " + result)
