
# Dpdl embedded languages

				www.dpdl.io
		

		
## Supported embedded programming languages

Multiple programming languages can be embedded directly within Dpdl scripts by using the keyword '**>>...**', for example: **>>python**

The execution of embedded programming languages is driven by the Dpdl runtime through a configurable dedicated native interface with a plug-in configurable
option. See **[DpdlCustom]** tag in 'DpdlEngine.ini' configuration file.

Currently Dpdl supports the embedding of the following languages:

* Embedded C (minimal subset of C90)
* Python
* Julia
* JavaScript
* OCaml
* Lua
* ROOT C++

### Embedded C (minimal subset of C90)

#### keyword >>c

```
>>c
	your C code
<<
```

The embedded C code may, or may not include a 'main(..)' function. 
If the main function is defined, parameters which are pushed to the Dpdl stack via the 'dpdl_stack_push(..)' function
are passed as parameters to the main function in the C code.

#### Example without C main(..):
```python
println("my Dpdl script embeds some C code")

>>c
#include <stdio.h>

printf("Hello C from Dpdl\n");
<<
```

#### Example with C main(..) -> function accepting parameters, and writing a result to the Dpdl stack:

```python
println("my Dpdl script embeds some C code")

dpdl_stack_push("dpdlbuf_myresult", "param1", "param 2", 23)
>>c
#include <stdio.h>
#include <dpdl.h>

int main(int argc, char **argv){
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


#### documentation

[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)


### Python

#### keyword >>python

```
>>python
	your Python code
<<
```

### Julia

Julia is a powerful high performance computing programming language with many scientific library packages.

https://julialang.org/

#### keyword >>julia

```python
>>julia
your Julia code
<<
```

NOTE: The native Dpdl library 'dpdljulia' is not included in the 'DpdlEngine lite' release, and needs to be downloaded and
      deployed separately (see Downloads section)


### Embedding of 'JavaScript'

JavaScript is the ideal programming language for web applications as it's supported by all popular web browsers.

JavaScript code can be embedded within Dpdl via the keyword '**>>js**'

#### keyword >>js

```python

dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
dpdl_stack_var_put("var1", "This variable comes from Dpdl (var1)")
>>js
your javascript code 
print(var1)....
<<
```
NOTE: The Dpdl embedded javascript plug-in needs specific features that must be supported by the java JRE/JDK implementation.
	  Not all java virtual machines support these features.

### OCaml

#### keyword >>ocaml

```
>>ocaml
	your OCaml code
<<
```


### Lua

#### keyword >>lua

```
>>lua
	your Lua code
<<
```

The embedded 'Lua' code may or may not include a 'main(..)' function.
If the 'main(..)' function is defined, parameters which are pushed to the Dpdl stack via the 'dpdl_stack_push(..)' function
are passed as parameters to the main function in the Lua code via a table type.

#### Example without main(..):

```python
println("my Dpdl script embeds some Lua script...")

>>lua
io.write("TEST ")
print()
<<
```

#### Example with main(..):

The parameters pushed on the Dpdl stack are passed to the Lua 'main(..)' function as table.
The main function returns also a table which is buffered info the stack variable defined 'dpdlbuf_var1'

```python
println("my Dpdl script embeds some Lua script...")

dpdl_stack_push("dpdlbuf_var1", "name", "Alexis", "surname", "Kunst")

>>lua
function paramLen(T)
  local count = 0
  for _ in pairs(T) do count = count + 1 end
  return count
end

function dpdl_main(params)
	local num_params = paramLen(params)
	io.write("dpdl_main call with number of params: ")
	io.write(num_params)
	print()
	print("executing my embedded algorithm...")
	print("")
	print("returning param values in 'uppercase'")
	local tab_out = {numfields=1}
	for k,v in pairs(params) do
		tab_out.numfields = tab_out.numfields + 1
		tab_out[tostring(k)] = string.upper(tostring(v))
	end
	tab_out.numfields = tostring(tab_out.numfields)
	return tab_out
end
<<
int exit_code = dpdl_exit_code()

println("embedded Lua exit code: " + exit_code)

string resp_buf = dpdl_stack_buf_get("dpdlbuf_var1")

println("Lua response buffer: ")
println(resp_buf)
```


### ROOT Data Analysis Framework (C++)


https://root.cern/gallery/

The ROOT toolkit provides full featured APIs for Data visualization, modeling, statistics and many other.

ROOT C++ code can be embedded within Dpdl with the keyword '**>>root**'

NOTE: The native Dpdl library 'dpdlroot' is not included in the 'DpdlEngine lite' release, and needs to be downloaded and deployed separately (see Downloads section)

#### keyword >>root

```
>>root
	your ROOT C++ code
<<
```


