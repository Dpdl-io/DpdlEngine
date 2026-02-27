# DpdlVM

![Dpdl](https://www.dpdl.io/images/dpdl-io_blue_small.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy;	



## Description


The 'DpdlVM' is a dedicated code virtual machine for executing Dpdl code on constrained systems where no JVM (OpenJDK, Oracle, or similar) is available. This is typically the case on very limited memory footprint systems like small Embedded platforms, System on Chip (SoC) and Microcontrollers (MCUs).

The DpdlVM can be very compact (between 60 Kb and 437 Kb), depending on the type of setup and configuration.

The actual DpdlVM size depends also on the type of 'Dpdl language plug-ins' that are actually included, for eventually supporting 'embedded code sections' (optional) 

The 'Dpdl language plug-ins' may or may not be included, or just 1 of the available Dpdl language plug-ins may be included for example.

The typical setup for Dpdl running on constrained systems is a DpdlVM that includes one or more of the following 'Dpdl language plug-ins' that allow to execute the following 'embedded code sections'.

'**Dpdl language plug-ins**' currently available on the **DpdlVM**:

- C
- MicroPython
- JavaScript

As example, the size of the DpdlVM that includes the Dpdl langage plug-in for executing C 'embedded code sections' (interpreted & compiled) is only **`298 Kb`** in Total, packed in a single executable (also romizable)


**Example:** dpdl code with an 'embedded code section' in C (compiled)

```python
println("Dpdl example with embedded C code section...")

dpdl_stack_push("dpdl:compile")

>>c
	#include <stdio.h>
	#include <time.h>

	int dpdl_main(int argc, char **argv){
		printf("Hello from Dpdl embedded C example\n");
		printf("\n");
		time_t start;
		time_t end;
	    time(&start);
	    int c;
		for(c = 0; c < 100000; c++){
			printf("iter %d \n", c);
		}

		time(&end);
		printf("\n");
		double exec_time = difftime(end, start);
		printf("Exec time: %lf \n", exec_time);

	    return 0;
	}
<<

int exit_code = dpdl_exit_code()

println("embedded C exit code: " + exit_code)
```



