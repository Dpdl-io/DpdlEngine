/**
 file: test_dpdl_code_exec.c

 This example C program shows how to execute a given Dpdl script file within a C program.
 The execution time in micro-seconds is measured

 Author: ac@dpdl.io
  
*/
#include <stdio.h>
#include <sys/time.h>

#include "dpdl.h"

long time_diff_microseconds(struct timeval start, struct timeval end) {
    long seconds = end.tv_sec - start.tv_sec;
    long useconds = end.tv_usec - start.tv_usec;
    return seconds * 1000000 + useconds;
}

int main(int argc, char **argv){

	printf("executing Dpdl from C...\n");

	struct timeval start, end;

	char *dpdl_src_file = "test/testString.h";

	gettimeofday(&start, NULL);

	int ret = dpdl_exec_script(dpdl_src_file);

	gettimeofday(&end, NULL);

	printf("\n");
	
	printf("ret: %d\n", ret);

	printf("exec time (micro sec): %lu\n", time_diff_microseconds(start, end));

	return 0;
}
