# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	
developed by
**SEE Solutions**
&copy; 2003

The following document contains Dpdl features that are currently in development phase and will be released soon in
coming releases




## class Type

The possibility to defined a **`class`** having member variables and functions

proposed draft:
```c++
class A {
	int x = 0
	string s = "A"
	
	func A(int id)
		x = id
	end
	
	func myFunc()
		println("an A func: " + x)
	end
}

class a = A(2)
a.myFunc()
```



## Completed integrations (already available in release)

### Function return type

The possibility to enforce a given return type in function definitions via return type specifiers 'func myfunc() $type'.

The return type specifiers are optional.

The variable type 'var' is always accepted for all return types as the values are dispatched at runtime.

#### Status: implemented and available in release

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

### 'enum' type

The possibility to define the 'enum' type

#### Status: implemented and available in release

Example:
```c
enum mykeys {
	TEST=11, DPDL, CODE=23
}

enum status {
	PENDING, DONE, ERROR, RUNNING
}

enum mykeys a

println("mykeys a: " + a)
println("TEST: " + a.TEST)
println("DPDL: " + a.DPDL)
println("CODE: " + a.CODE)

println("")

enum status s
println("status s: " + s)
println("PENDING: " + s.PENDING)
println("DONE: " + s.DONE)
println("ERROR: " + s.ERROR)
println("RUNNING: " + s.RUNNING)

```


