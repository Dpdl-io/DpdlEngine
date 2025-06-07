# Dpdl compiler documentation

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


