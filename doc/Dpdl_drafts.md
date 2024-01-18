# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	
developed by
**SEE Solutions**
&copy; 2003

The following document contains planned new Dpdl features that are considered and evaluated.
These features may eventually be available in coming releases.
Suggestions and comments are very appreciated.



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
