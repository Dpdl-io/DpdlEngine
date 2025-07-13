# Dpdl

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## Dpdl Meta programming

The dpdl API provides functions to enable dynamic code generation and transformation at runtime and compile-time


### Code injection

dpdl code can be injected at runtime into the following dpdl types: **`class`** **`struct`** via the functions 'inject(..)' and 'eject(..)'


**Example:**

```python
class A {
	string tag = "empty"
}


class A ana

string my_newcode = "'"
		func printit()
			int i
			for(i < 23)
				println('Hello from injected code: ' + i)
			endfor
		end
		"'"

int fid = ana.inject(my_newcode)

# use it
ana.printit()

ana.eject(fid)

ana.printit()
# function will not be found

```

