# File: app/simple/dpdlSimpleJavaAndC.h
#
# Example: Simple Dpdl script that embeds a 'Java' code block that is compiled and executed at runtime,
#			and executes also an embedded 'C' code
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("executing embedded java code block...")

string str = "this is my str parameter"
int i = 100
float f = 0.2
double d = 9999.9d

dpdl_stack_push(str, "./Test/TestRead.txt", i, f, d)

>>java

System.out.println("Parameters: ");
System.out.println("	arg0: " + arg0);
System.out.println("	arg1: " + arg1);
System.out.println("	arg2: " + arg2);
System.out.println("	arg3: " + arg3);
System.out.println("	arg4: " + arg3);

static void myMethod1(){
	System.out.println("myMethod1: " + 1);
}

myMethod1();
myMethod2();

static void myMethod2(){
	System.out.println("method2: " + 2);
}

for(int x = 0; x < 3; x++){
	System.out.println("x: " + x);
}

File myfile = new File(arg1);

StringBuilder stringBuilder = new StringBuilder();

try{
	BufferedReader reader = new BufferedReader(new FileReader(myfile));

	String line = null;
	while ((line = reader.readLine()) != null) {
		stringBuilder.append(line);
	}
}catch(Exception e){
	System.out.println("Error in reading file");
}

System.out.println("myfile content is: " + stringBuilder.toString());

return 1;
<<

int exit_code = dpdl_exit_code()
println("embedded java exit code: " + exit_code)

println("")

println("executing embedded C code...")

int n = 6
double x = 10.0d
string a = "test"

dpdl_stack_push("dpdlbuf_var1",n, x, a)

>>c
	#include <stdio.h>
	#include <stdlib.h>
	#include <dpdl.h>

	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    int n_val = atoi(argv[0]);
	    float x_val = atoi(argv[1]);
	    float result = n_val * x_val;

	    char buf[256];
	    sprintf(buf, "My %s result is %f", argv[2], result);

		dpdl_stack_buf_put(buf);

	    return 0;
	}
<<
exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code);
string buf = dpdl_stack_buf_get("dpdlbuf_var1")

println("")

println("response buffer result: " + buf)

println("")

println("finished")

