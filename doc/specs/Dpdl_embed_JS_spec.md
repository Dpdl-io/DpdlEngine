
## Dpdl language plug-in documentation for 'JavaScript'

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
		
developed by
**SEE Solutions**
&copy;





JavaScript can be embedded and executed within Dpdl code by using the keyword **`>>js`**.

Currently the following types (Modes) are supported:

1) Using the '*QuickJS*' javascript engine, ES2023 compliant (<ins>default mode</ins>)
2) Using the '*Nashorn*' javascript engine available on the Java platform -> available only on JRE version from 11 to 15
3) Using the '*V8*' javascript engine (* *available soon*)


### Mode (1) (default mode)

The 'Dpdl language plug-in' for executing JavaScript is built on the *QuickJS* JavaScript engine. It provides a powerful and complete API to interact with javascript at low level, supports most *ES2023 specification* (https://tc39.es/ecma262/2023/) including modules, asynchronous generators, proxies and BigInt.
It supports also some features of the *ES2024 specification* (https://tc39.es/ecma262/2024)

Custom native functions and objects can be implemented as shared libraries and accessed from javascript code.

You can find examples in the folder [./DpdlLibs/js/](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/js)

The libraries **`std`** and **`os`** are already imported and accessible with `std.*` and `os.*` respectively.


#### Example

```python
println("testing embedded js...")

dpdl_stack_push("my Hello Message!!!")
>>js

import { fib } from "./DpdlLibs/js/fib_module.js";

var a_message = "null";

console.log(scriptArgs)
console.log('Dpdl sends a message with QuickJS');

if(scriptArgs.length > 0){
	a_message = scriptArgs[0];
}
std.printf("Message = %s %d", a_message, 23);
console.log('');
console.log("fib(10)=", fib(10));
<<

int exit_code = dpdl_exit_code()
println("embedded js exited with exit code: " + exit_code)
```

The native Dpdl api function **`dpdl_stack_buf_put(..)`** is available to write data to the 'dpdlbuf_*' variable pushed on the dpdl stack.
See example: https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/js/dpdlJsCalcPi.h


#### Options

The following options can be passed to the 'Dpdl language plug-in for executing the *embedded code section*

##### Memory size

**`dpdl:-M`**

ex: **dpdl:-M20k** for 20 Kb (*)

##### Stack size 

**`dpdl:-S`**

ex: **dpdl:-S10k** for 10 Kb (*)

##### Include files

**`dpdl:-I`**

ex: **dpdl:-I./DpdlLibs/test/my_test_lib.js** for including a js file. Multiple 'dpdl:-I...' are allowed

##### Output file

Compile js file to bytecode 

**`dpdl:-o`**

ex: **dpdl:-o./DpdlLibs/test/my_out.bin**

###### Dump Memory stats

**`dpdl:-d`**


**(*)** suffixes: `k` (Kb) , `m` (Mb) , `g`(Gb) 


Refer to the official 'QuickJS' documentation for more info about the javascript engine used:

[official QuickJS doc](https://www.dpdl.io/doc/qjs/quickjs.html)

### Mode (2)

The '*Nashorn*' javascript engine can be activated by explicit configuration via the 'dpdlplugin:' option

```python

dpdl_stack_push("dpdlplugin:nashorn")

dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
>>js
your javascript code 
print(var1)....
<<
```

NOTE: The Dpdl embedded javascript plug-in needs specific features that must be supported by the java JRE/JDK implementation.
	  Not all java virtual machines support these features. In future releases the V8 JavaScript engine will be supported.


#### Passing data to the embedded javascript

Variables can be passed to the embedded javascript by pushing them onto the Dpdl stack with the api function **`dpdl_stack_push(..)`**

Example that passes an integer variable and an array to the embedded js code:

```python
int val = 23
arr[] = [1, 2, 3, 4]

dpdl_stack_push(val, arr)
>>js
	var sa;
	var arr;
	var v;
	if(scriptArgs.length > 1){
		v = scriptArgs[0];
		arr = scriptArgs[1];
		std.printf("val=%d\n", v);
		console.log(arr);
	}else{
		sa = "";
	}
	for(let i = 0; i < arr.length; i++) {
		std.printf("arr[%d]=%d\n", i, arr[i]);
	}
<<
int exit_code = dpdl_exit_code()
println("Dpdl js exited with exit code: " + exit_code)
```