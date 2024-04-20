# File: dpdlCBench.h
#
# Example: Sample Dpdl script with embedded C (Mode 2)
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("Benchmarking Dpdl embedded C with compile option...")

dpdl_stack_push("dpdlbuf_myresult", "dpdl:compile", "dpdl:-I./DpdlLibs/C")
>>c
	#include <stdio.h>
	#include <time.h>
	
	extern void dpdl_stack_buf_put(char *buf);

	int main(int argc, char **argv){
		printf("Dpdl C Bench\n");
		printf("\n");
		time_t start;
		time_t end;
	    time(&start);
	    int c;
		for(c = 0; c < 5000000; c++){
			printf("iter %d \n", c);
		}

		time(&end);
		printf("\n");
		double exec_time = difftime(end, start);

		char res[256];
		sprintf(res, "my result Exec time: %lf \n", exec_time);

		dpdl_stack_buf_put(res);
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()
println("embedded C exit code: " + exit_code)

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")
println("result: " + buf)
