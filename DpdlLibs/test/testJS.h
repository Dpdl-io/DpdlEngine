# File: test/testJS.h
#
# Example:
# This Dpdl script executes a function with an embedded 'js' javascript within a loop. Used to stress-test
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

func myJsFunc(string msg, int n) int
	println("myJsFunc(..)")

	dpdl_stack_push(msg, n)
	>>js
	var m, len
	if(scriptArgs.length >= 2){
		m = scriptArgs[0];
		len = scriptArgs[1];
	}else{
		m = "null"
		len = 10
	}
	for (let i = 0; i < len; i++) {
		std.printf("msg: %s %d\n", m, i)
	}
	<<
	int js_code = dpdl_exit_code()
	return js_code
end

# main
println("testing embedded js...")

int c = 0
string str = ""
int status = -1
setStartTime()
for(c < 1000)
	str = "Msg:" + c
	status = myJsFunc(str, 1000)
	println("js status: " + status)
	println("--------------------------------")
	c = c+1
endfor
int ms = getEndTime()
println("finished! in " + ms + " ms")

