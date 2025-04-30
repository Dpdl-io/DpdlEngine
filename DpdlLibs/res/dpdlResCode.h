# File: res/dpdlResCode.h
#
# Example: Test Dpdl code that make use of an code resource that is than dynamically compiled & executes within
#			an embedded C code section
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing the use of code resources that can be compiled into embedded code...")
println("")

println("creating a resource containing some code...")

>>res(my_new_code_f2)
void f2_new(int a, int b){
	printf("f4_new-> a: %d b: %d\n", a, b);
}
<<

println("retrieving the resource...")

object f2_new_res = dpdl_res_obj_get("my_new_code_f2")

raise(f2_new_res, "Error in getting code resource")

println("setting the variables on the stack...")

dpdl_stack_var_put("f2_new_name", "f2_new")
dpdl_stack_obj_put("f2_new_code", f2_new_res)

dpdl_stack_push("dpdl:applyvars", "dpdl:compile")

>>c
#include <stdio.h>

#define NUM_F 2

void f1(int a, int b){
	printf("f1-> a: %d b: %d\n", a, b);
}

{{f2_new_code}}

int dpdl_main(int argc, char **argv){

	void (*f[NUM_F])(int, int) = {f1, {{f2_new_name}}};

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
