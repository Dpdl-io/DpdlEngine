# File: ai/dpdlAITestData.h
#
# Example: The code below uses 'DpdlAINerd' Dpdl language plug-in to generate json data for testing purposes.
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("generating a json file with DpdlAINerd plug-in....")

>>ai
generate a sample json file which contains all fields for a personal identity document (ID)
<<

int exit_code = dpdl_exit_code()

println("generative ai exit code: " + exit_code)

string my_test_json = dpdl_stack_buf_get("dpdlainerd_buf")

println("this is my sample json:")

println(my_test_json)
