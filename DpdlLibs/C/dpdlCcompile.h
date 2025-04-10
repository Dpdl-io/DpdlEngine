# File: C/dpdlCcompile.h
#
# Example: Test Dpdl script that compiles (in memory) & executes embedded C code. A result buffer is intercepted in Dpdl
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Dpdl embedded C with compile option and buffer return...")

dpdl_stack_push("dpdlbuf_myresult", "dpdl:compile", "dpdl:-I./DpdlLibs/C/include", "dpdl:-F./DpdlLibs/C/lib/mydpdlc.c", "dpdl:-F./DpdlLibs/C/lib/mymodule.c")
>>c
	#include <stdio.h>
	#include <time.h>
	#include "mydpdlc.h"
	#include "mymodule.h"


	extern void dpdl_stack_buf_put(char *buf);

	int dpdl_main(int argc, char **argv){
		printf("testC native...\n");
		printf("\n");
		dpdl_foo();
		my_module_func();
		time_t start; // use int when compile option is not set
		time_t end; // use int when compile option is not set
	    time(&start);
	    int c;
		for(c = 0; c < 5; c++){
			printf("iter %d \n", c);
		}

		time(&end);
		printf("\n");
		double exec_time = difftime(end, start);
		printf("Exec time: %lf \n", exec_time);
		char buf[256];
		sprintf(buf, "my result is %lf", exec_time);
		dpdl_stack_buf_put(buf);
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()
println("embedded C exit code: " + exit_code);

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")
println("result: " + buf)
