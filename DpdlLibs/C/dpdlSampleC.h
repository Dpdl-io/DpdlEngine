# File: C/dpdlSampleC.h
#
# Example: This Dpdl script pushes parameters on the dpdl stack and executes embedded ANSI C code (interpreted Mode 1)
#
# (c)opyright 2009
# SEE Solutions
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
include("dpdllib.h")

func testEmbeddedC(int n, double x, string a)
	println("pushing vars onto the dpdl stack: " + n + " " + x + " " + a)
	
	dpdl_stack_push(n, x, a)
	
	println("executing interpreted C code...")
	println("-------------------------------")
	
	>>c
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <unistd.h>
	#include <math.h>
	
	typedef int u32;
	
	struct data
	{
    	int id;
    	int node;
	};

	enum keys
	{
    	a = 3,
    	b = 6,
    	c = 9,
    	e = 11
	};

	struct data mydata;
	enum keys mykeys;
	
	int testEmbeddedC(double x, int n, int *a) {
	    int i;
	    printf("x = %f\n", x);
	    for(i=0; i<n; i++){
	       printf("a[%d] = %d\n", i, a[i]);
	       a[i] = i + 100;
	    }
	    a[0] = 100;
	    return 0;
	}
	
	/* main entry */
	int main(int argc, char **argv)
	{
	 	printf("********************************\n");
		printf("hello embedded C from Dpdl\n\n");
		
		time_t time_start;
		time(&time_start);
		
		u32 myint = 3;
		
		mydata.id = 22;
		mydata.node = 369;
		
		printf("id: %d\n", mydata.id);
		printf("node: %d\n", mydata.node);
		printf("keys: %d %d %d %d\n", a, b, c, e);
		printf("myint: %d\n", myint);
		
		struct data *ptr_data = &mydata;

		printf("ptr_data->id = %d\n", ptr_data->id);
		printf("ptr_data->node = %d\n\n", ptr_data->node);
		
	    int cnt;	
	    printf("num params: %d\n", argc);
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    
	    int n;
	    double x;
	    char param[256];
	    sscanf(argv[0], "%d", &n);
		sscanf(argv[1], "%lf", &x);
		sscanf(argv[2], "%s", &param);
		
		printf("myparam: %s\n", &param); 
		int mynum[6] = {1, 2, 3, 4, 5, 6};
		
		x = 23.0;
		testEmbeddedC(x, n, &mynum);
		printf("\n");
		
		goto math_operations;
 		{
        	int b;
        	
			math_operations:
			printf("Math operations:\n\n");
			printf("%f\n", sin(0.12));
			printf("\n");
			
			goto finish;
    	}
    	
   	finish:
    	sleep(1);
    	time_t time_end;
    	time(&time_end);
    	
    	double exec_time = difftime(time_end, time_start);
    	printf("total exec_time (sec): %f\n", exec_time);
	    	    
	    return 0;
	}
	<<
	println("-------------------------------")
	
	int exit_code = dpdl_exit_code()
	println("finished executing embedded C code: " + exit_code)
	
end


# main
println("testing embedded C code (Mode 2 interpreted) from Dpdl")

string a = "a1 a2 a3 a4 a5 a6"
int n = 6
double x = 10.0d

testEmbeddedC(n, x, a)

>>c
	#include <stdio.h>
	
	printf("Finished!!!\n");
<<

