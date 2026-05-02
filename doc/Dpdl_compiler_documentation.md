# Dpdl compiler documentation

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 

## Dpdl

Dpdl provides a mechanism to compile variables and code constructs in embedded code section templates at runtime.

This enables an easy and straight forward way of complementing or setting variables or code sections inside the embedded code definitions.


### Options

**`dpdl:applyvars`**

Variables pushed onto the dpdl stack via **`dpdl_stack_var_put(..)`**, **`dpdl_stack_obj_put(..)`** etc., can be referenced with **`{{var_name}}`** inside embedded code sections.

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
	
	return 1;
<<

int exit_code = dpdl_exit_code()

println("embedded code exit code: " + exit_code)
```

To improve performance, the dpdl stack configuration '**dpdl:applyvars**' needs to be provided to apply the code substitution.

But there is also an option settings in the 'DpdlEngine.ini' configuration file, that allows to set the option per default in every execution flow:

```
...
DPDL_COMPILER_APPLYVARS = true
...
```

**example:** an 'embedded code section' in ruby

```python
println("embedding some ruby code...")

int x = 23

dpdl_stack_obj_put("my_int", x)

>>ruby
	number = {{my_int}}
	
	(1..15).each {
		|n| puts "I have #{number} tasks, currently running task: #{n}"
	}
<<
int exit_code = dpdl_exit_code()

println("embedded code exit code: " + exit_code)
```



### API functions


**`dpdl_stack_var_put(..)`**

**`dpdl_stack_var_get(..)`**

**`dpdl_stack_obj_put(..)`**

**`dpdl_stack_obj_get(..)`**

**`dpdl_stack_var_glob_put(..)`**

**`dpdl_stack_var_glob_get(..)`**

**`dpdl_stack_obj_glob_put(..)`**

**`dpdl_stack_obj_glob_get(..)`**


