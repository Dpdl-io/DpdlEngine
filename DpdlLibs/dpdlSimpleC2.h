# File: dpdlSimpleC2.h
#
# Example: This Dpdl script pushes parameters on the dpdl stack and executes embedded ANSI C code
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#

# main
# starting with Dpdl, pushing parameters on the stack and embedding C

println("testing embedded C code in Dpdl")

int n = 6
double x = 10.0d
string a = "test"

dpdl_stack_push(n, x, a)

>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		dpdl_stack_push(1);
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("ebedded C exit code: " + exit_code);

# again Dpdl...

object str = loadObj("String", "Dpdl embedded C")
bool b = str.contains("C")
println("Dpdl contains C: " + b)
println("testing dpdlbuf_...")
string buf_key = "dpdlbuf_1"
dpdl_stack_push(buf_key)
>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	printf("writing to buf...\n");
	char *buf = "MEGA";
	dpdl_stack_buf_put(buf);
	
<<
string buf = dpdl_stack_buf_get(buf_key)
println("response buffer: " + buf)
