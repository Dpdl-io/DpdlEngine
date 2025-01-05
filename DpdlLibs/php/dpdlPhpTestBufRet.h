# File: php/dpdlPhpTestBufRet.h
#
# Example: Dpdl Example with embedded PHP code that writes a buffer of data to the dpdl stack
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#


# main
println("testing embedded php code execution...")
println("")

dpdl_stack_push("dpdlbuf_data1")

>>php
	$mydata = "This data comes from php and is a Test";

	dpdl_stack_buf_put($mydata);

<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded php code")

string res = dpdl_stack_buf_get("dpdlbuf_data1")

println("RES: " + res)

println("")
println("finished")
