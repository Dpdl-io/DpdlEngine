# File: ai/dpdlAICodeSort_gen.h
#
# Example: The code below was generated automatically starting from the Dpdl source file 'ai/dpdlAICodeSort.h'
#		   using the DpdlAINerd (DAN) Dpdl language plug-in
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Dpdl example that leverages generative AI for code execution...")

println("generating code to sort a list of numbers...")

dpdl_stack_push("dpdlbuf_result", "1 43 63 634 64 21 3 6 346 34 1000 23 55")

>>clj
(ns dpdl)

(defn dpdl_main [nums]
  (let [num-str (.toString (aget nums 0))
        num-list (map #(Integer/parseInt %) (clojure.string/split num-str #"\s+"))
        sorted-nums (sort num-list)
        result (clojure.string/join " " (map #(str %) sorted-nums))]
    result))
<<

int exit_code = dpdl_exit_code()
println("embedded ai generated exit code: " + exit_code)

string result = dpdl_stack_buf_get("dpdlbuf_result")
println("sorted numbers result: " + result)


