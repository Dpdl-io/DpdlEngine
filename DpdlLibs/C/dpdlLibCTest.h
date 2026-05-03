# File: C/dpdlLibCTest.h
#
# Example: Dpdl example that compiles an 'embedded code section' in C into a native shared library, in this case saved in a given folder.
#			A subsequent 'embedded code section' in C code makes use of the newly generated native shared library functions
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Dpdl example with embedded C library generation and code that used it right away")
println("")

println("preparing environment ...")

dpdl_stack_push("dpdlstack:createlib", "dpdl:compile", "dpdl:-shared", "dpdl:-o./DpdlLibs/C/lib_out/libmyalgorithm.so")

dpdl_stack_push("dpdlstack:mycode", "dpdl:compile", "dpdl:-I./DpdlLibs/C/include", "dpdl:-L./DpdlLibs/C/lib_out", "dpdl:-lmyalgorithm")

println("we compile a small C library, and than use it in the next embedded code setion")

println("creating library...")

dpdl_stack_push("dpdlstack:compilelib")

>>c
	#include <stdio.h>

	void my_alg_calc1(){
		printf("my_alg_calc1() call\n");
	}

	void my_alg_calc2(){
		printf("my_alg_calc2() call\n");
	}

<<
int status_lib = dpdl_exit_code()

raise(status_lib, "Error in creating C library")

println("library is available: " + status_lib)
println("")

println("executing my code...")

dpdl_stack_push("dpdlstack:mycode")

>>c(my_alg_data)

	#include <stdio.h>
	#include <time.h>
	#include "dpdl.h"

	extern void dpdl_stack_buf_put(char *buf);

	int dpdl_main(int argc, char **argv){
		printf("testC native...\n");
		printf("\n");
		dpdl_foo();
		time_t start;
		time_t end;
		time(&start);
		int i;
		for(i = i; i < 5; i++){
			printf("iter %d \n", i);
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

println("embedded C exit code: " + exit_code)

string buf = dpdl_stack_buf_get("my_alg_data")

println("result: " + buf)
