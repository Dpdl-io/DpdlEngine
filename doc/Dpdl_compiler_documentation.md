# Dpdl and C compiler documentation

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003 

## Dpdl

Dpdl provides a mechanism to compile variables and code constructs in embedded code templates at runtime. This enables an easy and straight forward way of complementing or setting  variables or code sections inside the embedded code definitions.

### Option settings

**`dpdl:applyvars`**

Variables that have been pushed onto the dpdl stack via **`dpdl_stack_var_put(..)`**, **`dpdl_stack_obj_put(..)`** etc., can be references inside embedded code with **`{{var_name}}`**. The dpdl stack configuration 'dpdl:applyvars' needs to be provided to apply the code substitution.

**Example:**

```python
println("embedding some code...")

int x = 23

dpdl_stack_var_put("my_var", "This is a message")
dpdl_stack_obj_put("my_int", x)

dpdl_stack_push("dpdl:applyvars")
>>c
#include <stdio.h>

int x = {{my_int}};
printf("{{my_var}}: %d\n", x);

<<

int exit_code = dpdl_exit_code()
println("embedded code exit code: " + exit_code)
```

## C Compiler

Within Dpdl code, embedded C code can be dynamically <ins>compiled in memory at runtime</ins> (see execution Mode (2))

The C compiler implemented in form of a **Dpdl language plugin** is based on the <ins>super fast Fabrice Bellard's TCC</ins>.


### Library and include paths

Even though the embedded C compiler Dpdl language plug-in comes with a minimal set of header files located in '**./lib/native/$platform/include**', by default the Dpdl language plug-in searches for 'include' and 'lib' files in the following paths:

**Linux/Unix:**

```
/usr/include
/usr/lib
```

**MacOS:**

```
/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include/
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib/
```

**Windows:**

```
MinGW or equivalent installation 'include' and 'lib' folders
```

Additional include and library paths can be set directly via a dpdl stack option setting (see below)


### Configuration

The Dpdl runtime can be parameterized by pushing the corresponding option settings onto the Dpdl stack via the 
function **`dpdl_stack_push(..)`**. The options need to be prefixed with 'dpdl:'


For the embedding of C code the following option settings are available:


#### Option settings

**`dpdl:compile`**

Instructs the Dpdl runtime to compile in memory the embedded C code before executing it (execution Mode 2)

**`dpdl:-vv`**

prints include file list. To show also include tries use the flag '-vvv' instead

**`dpdl:-F$File`**

Adds the specified file to the compile set

Note: The unregistered version of 'DpdlEngine lite' allows this option to be used only once within a given execution section

**`dpdl:-A$Dir`**

Adds the all the files contained in the specified directory to the compile set

Note: This option is enabled only in the full registered version of 'DpdlEngine lite'

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

**`dpdl:$option`**

Any other option supported by the compiler can be passed using the prefix 'dpdl:'


**Example:**

```c
println("this Dpdl demo shows how C code can be dynamically compiled (in memory at runtime) within Dpdl")

dpdl_stack_push("dpdl:compile", "dpdl:-Dtestvar=999", "dpdl:-DtestF(a)=a+23", "dpdl:-I./DpdlLibs/C", "dpdl:-I/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include", "dpdl:-L/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/lib")

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

int dpdl_main(int param){

	printf("Dpdl embedded C Test: %d %d\n", testvar, testF(0));
	
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

The full list of option parameter settings can be inspected here:

[Dpdl_C_Compiler_reference_documentation](https://www.dpdl.io/doc/dpdl_tcc/Dpdl_C_Compiler_reference_documentation.html)

