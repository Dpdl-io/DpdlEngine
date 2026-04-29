
## Dpdl language plug-in documentation for 'C' code

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
		
developed by
**SEE Solutions**
&copy;



The dpdl '*embedded code secitons*' in C code can be executed in 2 different modes, either **`interpreted`** or **`compiled`**.

Both execution modes have some characteristics that may fit better in one case or the other.

The code is executed via a native Dpdl plug-in library that has relatively small footprint (278 Kb) and therefore is applicable also on small embedded systems.

## Modes of execution

C code can be executed in 2 different modes:

* **`interpreted`** C code (**Mode **1) --> <ins>minimal subset of C90</ins>

* **`compiled`** C code (**Mode 2**) --> compiled in memory at runtime, <ins>ANSI C99</ins>


### Mode 1 (interpreted)

When executing C code with **`interpreted** mode, the Dpdl runtime already <ins>includes a basic set of **C libraries** and **include header files**<ins> and language constructs to execute the code.

Custom libraries and functions can be integrated and linked via a straight forward implementation approach.

#### Features

- No compile time overhead, although may be a bit slower than compiled code

- minimal, but includes a basic set of C libraries and header files (*stdlib*), POSIX compliant

- Possibility to integrate custom functions

- C code may or may not have an 

#### Minimal embedded C library (*stdlib*) documentation (for Mode 1)**

[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)

* The embedded C code for mode (1) may, or may not include a 'dpdl_main(..)' function. If the main function is defined, parameters that are pushed onto the dpdl stack via the 'dpdl_stack_push(..)' function are passed as parameters to the dpdl_main(...) entry function in the C code


#### Example execution Mode (1) without dpdl_main(..) function entry point

```python
println("my Dpdl script embeds some C code")

>>c
#include <stdio.h>

printf("Hello C from Dpdl\n");
<<
```


#### Example execution Mode (1) with dpdl_main(..) function entry point

```python
println("my Dpdl script embeds some C code")

dpdl_stack_push("param1", "param 2", 23)

>>c(dpdlbuf_myresult)
	#include <stdio.h>
	#include <dpdl.h>
	
	int dpdl_main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    dpdl_stack_buf_put("my result from C");
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("finished executing embedded C code: " + exit_code)

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")

println("response buffer: " + buf)
```


### Mode 2 (compiled)

When executing C code in **`compiled**` mode, the code is effectively compiled in memory at runtime (very FAST!!), enabling maximum execution performance gain.

This mode can be activated via the dpdl stack parameter **`dpdl:compile`**.

This operation mode supports *ANSI C* (*ISO C99* standard) and many *GNUC extensions* including in-line assembly on x86 systems.

The 'dpdl:compile' option is available for the following platforms: **Linux (x86_64) MacOS (arm64), Raspberry (armv7l), Windows 64**.

The embedded C compiler included is self-relying and includes assembler and linker.

The required header files and libraries are by default searched in predefined platform default paths (i.e. /usr/local ), but custom paths can also be supplied as option parameters.

The *DpdlEngine* distribution by default includes also a basic set of include headers files and libraries that are located in the platform specific folder './lib/native/$platform/include' on which the *DpdlEngine* is currently running. 

Additional library dependencies can be added via the options settings 'dpdl:-I' and 'dpdl:-L'.

* The embedded C code for mode (2) needs to contain a function entry point '**dpdl_main(..)**' which serves as entry point for the execution

* parameters which are pushed onto the dpdl stack via the 'dpdl_stack_push(..)' function are than passed as parameters to the dpdl_main(...) entry function defined in the C code


#### Example execution Mode (2) with dpdl_main(..) function entry point

```python
# main
println("this Dpdl example shows how C code can be dynamically compiled (in memory at runtime) and executed on Dpdl")

# we instuct the Dpdl runtime to compile the C code
dpdl_stack_push("dpdl:compile", "dpdl:-I./DpdlLibs/C", "var1")

>>c(dpdlbuf_myresult)
	
	#include <stdio.h>
	
	extern void dpdl_stack_buf_put(char *buf);
		
	static inline void * my_memcpy(void * to, const void * from, size_t n){
	
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
		//my_memcpy(&str_dest, str_src, strlen(str_src));
		//printf("copied str: %s\n", str_dest);
		dpdl_stack_buf_put(str_src);
		return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("embedded C compiled and run with exit code: " + exit_code)

string buf = dpdl_stack_buf_get("dpdlbuf_myresult")

println("result: " + buf)
```

Note: in-line assembly is available only on i386 and X86_64 platforms, but it compiles also on others like Arm, etc..

# Documentation

## C libraries included (interpreted Mode 1)

When C code is executed in **`interpreted`** mode, all *stdlib* libraries and include files are already available in the dpdl runtime and can just be used.

This is the documentation of the C library available when executing embedded C code with <ins>interpreted</ins> **Mode (1)**:

[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)


## embedded C compiler (compiled Mode 2)

### Library and include paths

Even though the embedded C compiler comes with a minimal set of header files located in '**./lib/native/$platform/include**', by default it searches for 'include' and 'lib' files in the following paths:

**Linux/Unix:**

```
/usr/include
/usr/lib
```

**MacOS:**

example:

```
/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/include/
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib/
```

**Windows:**

```
MinGW or equivalent installation 'include' and 'lib' folders
```

Additional include and library paths can be set directly via dpdl stack option settings (see below)


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


