# File: test/testCfuncPtr.h
#
# Example: Test Dpdl code that compiles (in memory) & executes embedded C code that implements function pointers
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing embedded C code that makes use of function pointers...")

dpdl_stack_push("dpdl:compile")

>>c
#include <stdio.h>

#define NUM_F 3

void f1(int a, int b){
	printf("f1-> a: %d b: %d\n", a, b);
}

void f2(int a, int b){
	printf("f2-> a: %d b: %d\n", a, b);
}

void f3(int a, int b){
	printf("f3-> a: %d b: %d\n", a, b);
}

int dpdl_main(int argc, char **argv){

	void (*f[NUM_F])(int, int) = {f1, f2, f3};

	int a, b;
	int i;
	for(i = 0; i < NUM_F; i++){
		a = 10*i;
		b = 20*i;
		f[i](a, b);
	}

	return 0;
}

<<

int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code)
