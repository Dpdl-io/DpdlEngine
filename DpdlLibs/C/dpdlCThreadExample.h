# File: dpdlCThreadExample.h
#
# Example: This Dpdl script compiles and executes and embedded C code that sums numbers using multiple threads
#
# (c)opyright 2009
# SEE Solutions
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("this Dpdl demo shows how C code can be dynamically compiled (in memory at runtime) on Dpdl")

# we instuct the Dpdl runtime to compile the C code
dpdl_stack_push("dpdl:compile", "dpdl:-I./DpdlLibs/C", "dpdl:-I/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include", "dpdl:-L/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/lib")

>>c
#include<stdio.h>
#include<pthread.h>

pthread_t tids[3];
int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
int num[2]={0,0};

void* firstThread(void* arg){
	int ans = 0;
	for(int i=0;i<5;i++){
		ans += numbers[i];
	}
	printf("Result Thread 1: %d\n",ans);
	num[0] = ans;
}


void* secondThread(void* arg){
	int ans = 0;
	for(int i=5;i<10;i++){
		ans+=numbers[i];
	}
	printf("Result Thread 2: %d\n",ans);
	num[1]=ans;
}

void* sum(void* arg){
	pthread_join(tids[0],NULL);
	pthread_join(tids[1],NULL);
	int ans = num[0]+num[1];
	printf("Result Final: %d\n",ans);
}

int dpdl_main (int param){

	pthread_create(&tids[0],NULL,firstThread,(void*)NULL);
	pthread_create(&tids[1],NULL,secondThread,(void*)NULL);
	pthread_create(&tids[2],NULL,sum,(void*)NULL);
	pthread_join(tids[2],NULL);
	printf("finished\n");

	return 1;
}
<<
int exit_code = dpdl_exit_code()

println("embedded C code compiled and run with exit code: " + exit_code)
