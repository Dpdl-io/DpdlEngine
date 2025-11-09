# File: js/dpdlQJsExample.h
#
# Example:
# This Dpdl script executes an embedded 'js' javascript that prints out a message pushed on the dpdl stack and loads a module to calc fib
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedded js...")

dpdl_stack_push("my Hello Message!!!")
>>js

import { fib } from "./DpdlLibs/js/fib_module.js";

var a_message = "null";

console.log(scriptArgs)
console.log('Dpdl sends a message with QuickJS');

if(scriptArgs.length > 0){
	a_message = scriptArgs[0];
}
std.printf("Message = %s %d", a_message, 23);
console.log('');
console.log("fib(10)=", fib(10));
<<

int exit_code = dpdl_exit_code()
println("embedded js exited with exit code: " + exit_code)

