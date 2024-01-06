# File: dpdlCBench.h
#
# Example: Sample Dpdl script with embedded C (Mode 2)
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("Benchmarking Dpdl embedded C with compile option...")

dpdl_stack_push("dpdl:compile", "dpdl:-I./DpdlLibs/C")
>>c
	#include <stdio.h>
	#include <time.h>
	
	int main(int argc, char **argv){
		printf("Dpdl C Bench\n");
		printf("\n");
		time_t start; // use time_t when compile option is set
		time_t end; // use time_t when compile option is set
	    time(&start);
	    int c;
		for(c = 0; c < 5000000; c++){
			printf("iter %d \n", c);
		}

		time(&end);
		printf("\n");
		double exec_time = difftime(end, start);
		printf("Exec time: %lf \n", exec_time);
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);
