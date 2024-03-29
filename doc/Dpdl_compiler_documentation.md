# Dpdl compiler documentation


## Dpdl compiler C (TCC)


C code embedded within Dpdl scripts can be dynamically compiled in memory at runtime (see execution Mode 2)

The C compiler used and executed in form of a Dpdl language plugin is Fabric Bellard's TCC.

### Compiler options

The Dpdl runtime can be parameterized by pushing the corresponding option settings onto the Dpdl stack via the 
function **`dpdl_stack_push(..)`**. The options need to be prefixed with 'dpdl:'

For the embedding of C code the following option settings are available.


#### Option settings

**`dpdl:compile`**

Instructs the Dpdl runtime to compile in memory the embedded C code before executing it (execution Mode 2)

**`dpdl:-I$Path`**

Adds the specified include path reachable by the compiler

Note: The directlry "./lib/native/$Platform/include" is already added per default to the include path where basic includes are present

**`dpdl:-L$Path`**

Adds the specified library path reachable by the compiler and linker

**`dpdl:-l$lib`**

Adds the specified library for the linker

**`dpdl:-D$sym[=val]`**

Defines the preprocessor symbol '$sym' and optionally an associated value. If 'val' in not defined, it defaults to 1.

Function like macros can also be defined, e.g **`dpdl:-DF(a)=a+1`**

**`dpdl:$option**

Any other option supported by the compiler can be passed using the prefix 'dpdl:'


Example:
```c
println("this Dpdl demo shows how C code can be dynamically compiled (in memory at runtime) within Dpdl")

dpdl_stack_push("dpdl:compile", "dpdl:-I./DpdlLibs/C", "dpdl:-I/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include", "dpdl:-L/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/lib")

>>c
#include<stdio.h>
#include<pthread.h>

pthread_t tids[3];
int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
int num[2]={0,0};

void* firstThread(void* arg){
	int ans = 0;
	for(int i=0;i<500;i++){
		ans += numbers[i];
		printf("1: %d\n", i);
	}
	printf("Result Thread 1: %d\n",ans);
	num[0] = ans;
}


void* secondThread(void* arg){
	int ans = 0;
	for(int i=5;i<1000;i++){
		ans+=numbers[i];
		printf("2: %d\n", i);
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
```



