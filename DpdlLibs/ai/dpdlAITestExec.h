# File: ai/dpdlAITestExec.h
#
# Example: This Dpdl script generates code via the 'ai'  Dpdl language plug-in and executes it
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Testing generative AI code with Dpdl....")

dpdl_stack_var_put("my_message", "Hello generative AI from Dpdl")

>>ai
	Write a console program in C that print out the first command line parameter and append the string '{{my_message}}'
<<
int exit_code = dpdl_exit_code()
println("generated ai code exit code: " + exit_code)

string my_code = dpdl_stack_buf_get("dpdlainerd_buf")

dpdl_stack_var_put("my_code", my_code)

println("executing generated code...")

dpdl_stack_push("dpdl:applyvars", "dpdl:compile", "param0", "MESSAGE: ")

>>c
{{my_code}}
<<

exit_code = dpdl_exit_code()
println("embedded C code exit code: " + exit_code)
