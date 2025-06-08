# Dpdl compiler documentation

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003 

## Dpdl

Dpdl provides a mechanism to compile variables and code constructs in embedded code templates at runtime.

This enables an easy and straight forward way of complementing or setting variables or code sections inside the embedded code definitions.


### Options

**`dpdl:applyvars`**

Variables pushed onto the dpdl stack via **`dpdl_stack_var_put(..)`**, **`dpdl_stack_obj_put(..)`** etc., can be referenced with **`{{var_name}}`** inside embedded code sections.

The dpdl stack configuration 'dpdl:applyvars' needs to be provided to apply the code substitution. This improves performance.

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

### API functions


**`dpdl_stack_var_put(..)`**

**`dpdl_stack_var_get(..)`**

**`dpdl_stack_obj_put(..)`**

**`dpdl_stack_obj_get(..)`**

**`dpdl_stack_var_glob_put(..)`**

**`dpdl_stack_var_glob_get(..)`**

**`dpdl_stack_obj_glob_put(..)`**

**`dpdl_stack_obj_glob_get(..)`**


