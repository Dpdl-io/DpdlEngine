# DpdlVM

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	



## Description


The '**DpdlVM**' is a dedicated compact code virtual machine that enables to execute dpdl code on constrained systems where no JVM (OpenJDK, Oracle, or similar) is available.

This is typically the case on very limited memory footprint systems like small Embedded System platforms, System on Chip (SoC) and Microcontrollers (MCUs).

The **DpdlVM** can be very compact (between 60 Kb and 437 Kb), depending on the type of configuration Profile and Setup.

The actual size of the DpdlVM executable depends also on the number and type of '*Dpdl language plug-ins*' that are actually included, for eventually executing 'embedded code sections' in other programming languages (optional).

The '*Dpdl language plug-ins*' may, or may not be included, or just 1 of the available Dpdl language plug-ins may be included for example.

The typical setup for Dpdl running on constrained systems, is a DpdlVM that includes one or more of the following '*Dpdl language plug-ins*' that allow to execute the following 'embedded code sections'.

### '**Dpdl language plug-ins**' currently available on the **DpdlVM**:

- C (interpreted & compiled)
- MicroPython
- Micro JavaScript ( *ES5* )
- Lightweight Ruby ( mruby )

**Example:**

The size of the '**DpdlVM**' that includes the *Dpdl language plug-in* for executing C 'embedded code sections' (interpreted & compiled) is only **`298 Kb`** in Total, packed as a single executable (also romizable).

When executing C code in *interpreted* mode (**Mode 1**), <ins>all libraries and include files listed here in</ins> [Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md) are already included in the DpdlVM executable.


### Example dpdl code with '*embedded code section*' in C

Simple dpdl example code with an '*embedded code section*' in C (*compiled* **Mode 2**), that runs on the DpdlVM

```python

class A {
	int id
	string desc

	func A(int id_, string desc_)
		id = id_
		desc = desc_
	end

	func getId() int
		return id
	end

	func getDesc() string
		return desc
	end
}

class B : A {

	object data = null

	func B(int id_, string desc_, object data_)
		super(id_, desc_)
		data = data_
	end

	func getData()
		return data
	end
}


println("dpdl example..")

object map = new("HashMap")

map.put(1, "my data 1")
map.put(2, "my data 2")
map.put(3, "my data 3")

class B ab(23, "a sample test description", map)

println("ab: " + ab)

println("id: " + ab.getId() + " desc: " + ab.getDesc() + " data: " + ab.getData())

int i
for(i < 10000)
	println("This is printed from Dpdl:" + i)
	i=i+1
endfor

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
		for(c = 0; c < 1000000; c++){
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

### Example dpdl code with '*embedded code section*' in Ruby (mruby)

Example dpdl code running on DpdlVM on a ESP32 MCU to blink a LED via an '*embedded code section*' in Ruby (mruby).

```ruby
println("blinking a led on ESP32 MCU via 'mruby' ...")

int i
for(i < 1000)
	println("iter $i")
	i=i+1
endfor

>>mruby(async)
	led = ESP32::GPIO_NUM_2
	ESP32::GPIO::pinMode(led, ESP32::GPIO::OUTPUT)

	loop {
	  ESP32::GPIO::digitalWrite(led, ESP32::GPIO::HIGH)
	  ESP32::System.delay(1000)
	  ESP32::GPIO::digitalWrite(led, ESP32::GPIO::LOW)
	  ESP32::System.delay(1000)
	}
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing ESP32 led blinking code")

while(true)
	print(".")
	sleep(3000)
endwhile
```

The **mruby** *gem* lib used here within the ruby code is: [mruby-esp32-gpio](https://github.com/mruby-esp32/mruby-esp32-gpio)

