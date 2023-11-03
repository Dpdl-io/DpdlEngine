
# Dpdl embedded languages

				www.dpdl.io
		

		
## Supported embedded programming languages

Multiple programming languages can be embedded directly within Dpdl scripts by using the keyword '**>>...**', for example: **>>python**

The execution of embedded programming languages is driven by the Dpdl runtime through a configurable dedicated native interface with a plug-in configurable
option. See **[DpdlCustom]** tag in 'DpdlEngine.ini' configuration file.

### Embedded C (minimal subset of C90)

#### keyword >>c

```
>>c
	your C code
<<
```

The C code may, or may not include a 'main(..)' function. 
If the main function is defined, parameters which are pushed to the Dpdl stack via the 'dpdl_stack_push(..)' function
are passed as parameters to the main function in the C code.

Example without C main(..):
```python
println("my Dpdl script embeds some C code")

>>c
#include <stdio.h>

printf("Hello C from Dpdl\n");
<<

```

Example with C main(..) function accepting parameters, and writing a result to the Dpdl stack:
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


### ROOT Data Analysis Framework (C/C++)

An open-source data analysis framework used by high energy physics and others

https://root.cern/gallery/

The ROOT toolkit provides full featured APIs for Data visualization, modeling, statistics

#### keyword >>root

```
>>root
	your ROOT C/C++ code
<<
```


