# File: js/dpdlQJsBufRet.h
#
# Example:
# Dpdl script that embeds javascript via 'qjs' that writes a result string buffer to the Dpdl stack which is than intercepted in Dpdl
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("testing quick js...")

dpdl_stack_push("dpdlbuf_var1", 23)
>>qjs
"use strict";

function main(args) {
	console.log('embedded javascript...');
	var result = "This is my Result=";
	if(scriptArgs > 0){
		std.printf("parameter: %d\n", scriptArgs[0]);
		result = result + scriptArgs[0];
	}

    dpdl_stack_buf_put(result);
}

var args;
if (typeof scriptArgs != "undefined") {
    args = scriptArgs;
} else if (typeof arguments != "undefined") {
    args = arguments;
} else {
    args=[1000];
}

main(args);
<<
int exit_code = dpdl_exit_code()
println("Dpdl embedded qjs terminated with exit code: " + exit_code)

string res_buf = dpdl_stack_buf_get("dpdlbuf_var1")
println("result: ")
println(res_buf)

