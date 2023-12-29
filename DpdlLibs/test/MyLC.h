# File: test/MyLC.h
#
# Example: Test Dpdl script loaded by test/testLoad.h
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func MyLC()
	println("MyLC()")
end

func myFunc()
	println("myFunc()")
end

func myFuncStructPrint(struct a)
	println("a: " + a)
	println("a.id: " + a.id)
	println("a.y: " + a.y)
end

func myFuncStructMod(struct a)
    a.id = "this is a NEW A"
    a.y = 79
	return a
end

func myNativeFunc() int
	println("myNativeFunc() executing embedded C...")
	dpdl_stack_push("dpdl:compile")
	setStartTime()
	>>c
	#include <stdio.h>
	#include <time.h>

	int dpdl_main(int argc, char **argv){
		printf("Dpdl C Buf return\n");
		int c;
		for(c = 0; c < 100000; c++){
			printf("iter %d \n", c);
		}
		return 0;
	}
	<<
	int exit_code = dpdl_exit_code()
	println("embedded C exit code: " + exit_code)

	int ms = getEndTime()
	println("exec time ms: " + ms)

	return exit_code
end

# main
string s = "this is my loaded Obj"
int x = 23
object mystr = loadObj("String", "MyLoadObj str")

return 1
