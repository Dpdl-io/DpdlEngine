# File: dpdlCcompileExample.h
#
# Example: This Dpdl script compiles (in memory at runtime) and executes embedded ANSI C code
#
# (c)opyright 2009
# SEE Solutions
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("this Dpdl example shows how C code can be dynamically compiled (in memory at runtime) and executed on Dpdl")

# we instuct the Dpdl runtime to compile the C code
dpdl_stack_push("dpdl:compile", "dpdl:-I./DpdlLibs/C", "var1")

>>c
#include <stdio.h>

static inline void * my_memcpy(void * to, const void * from, size_t n)
{
// NOTE: inline assembly is avaiable only on i386 and X86_64 platforms, but compiles also on ARM
int d0, d1, d2;
__asm__ __volatile__(
        "rep ; movsl\n\t"
        "testb $2,%b4\n\t"
        "je 1f\n\t"
        "movsw\n"
        "1:\ttestb $1,%b4\n\t"
        "je 2f\n\t"
        "movsb\n"
        "2:"
        : "=&c" (d0), "=&D" (d1), "=&S" (d2)
        :"0" (n/4), "q" (n),"1" ((long) to),"2" ((long) from)
        : "memory");
		return (to);
}

int dpdl_main(int argc, char **argv){
	printf("This code will be compiled before it's being executed...\n");
	int i = 0;
	while(i < 30000000){
		printf("The Future is NOW ^ %d \n", i);
		i++;
	}

	char *str_src = "MEGA source";
	char str_dest[256];
	//my_memcpy(str_dest, str_src, strlen(str_src));
	//printf("copied str: %s\n", str_dest);
	return 0;
}
<<
int exit_code = dpdl_exit_code()

println("embedded C compiled and run with exit code: " + exit_code)
