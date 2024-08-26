# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	
developed by
**SEE Solutions**
&copy; 2003

The following document contains proposals for new Dpdl features that are considered and in development.

These features may eventually be available in coming releases.

Suggestions and comments are very appreciated.


## class Type compilation to java bytecode

Provide a native Dpdl function 'genObjByteCode(...)' that allows to compile a defined dpdl class into native java bytecode.

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

class A a(1)
a.myFunc()

# now we generate java byte code from the defined dpdl class and obtain an object (like a java object loaded via 'loadObj(...)' )

object bcA = genObjByteCode(A)

...
```
