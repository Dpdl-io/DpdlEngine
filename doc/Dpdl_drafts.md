# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	


The following document contains Dpdl features that are currently in development phase and will be released soon in
coming releases


## Function return type

The possibility to enforce a given return type in function definitions via return type specifiers.

The return type specifiers are optional.

The variable type 'var' is always accepted for all return types as the values are dispatched at runtime.


Example:
```c
func testFuncRetInt() int
	println("testFuncRetInt")
	return 23
end

int y = testFuncRetInt()
var yv = testFuncRetInt()
println("y: " + y)
println("yv: " + yv)
```





