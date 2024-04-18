# File: ai/dpdlAICodeSort.h
#
# Example: This Dpdl script converts a natural language description into code that can be executed.
#			This code needs to be executend with the '-load $file @gen', a password is currently required (see doc)
#			The DpdEngine will than generate a file within the same directory with the '_gen' suffix
#			The code below generated the file 'ai/dpdlAICodeSort_gen.h' located in the same directory
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Dpdl example that leverages generative AI for code execution...")

println("generating code to sort a list of numbers...")

dpdl_stack_push("dpdlbuf_result", "1 43 63 634 64 21 3 6 346 34 1000 23 55")

>>ai
>>clj
Write a functions with clojure programming language named 'dpdl_main', with namespace 'dpdl', accespts as parameter a java array
of objects, take the first string containing numbers (separated by white spaces), sorts the numbers and returns a string with
the numbers sorted.

<<

int exit_code = dpdl_exit_code()
println("embedded ai generated exit code: " + exit_code)

string result = dpdl_stack_buf_get("dpdlbuf_result")
println("sorted numbers result: " + result)

