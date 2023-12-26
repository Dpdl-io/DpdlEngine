# File: C/dpdlCcompileBufRet.h
#
# Example: Sample Dpdl script that executes an embedded C code returning a result buffer
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
println("Dpdl embedded C with compile option and buffer return...")

dpdl_stack_push("dpdlbuf_myresult", "dpdl:compile", "dpdl:-I./DpdlLibs/C", "dpdl:-I/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include", "dpdl:-L/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/lib")
>>c
	#include <stdio.h>
	#include <time.h>

	extern void dpdl_stack_buf_put(char *buf);

	int main(int argc, char **argv){
		printf("Dpdl C Buf return\n");
		printf("\n");
		time_t start; // use int when compile option is not set
		time_t end; // use int when compile option is not set
	    time(&start);
	    int c;
		for(c = 0; c < 5000000; c++){
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
