# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	
developed by
**SEE Solutions**
&copy; 2003

The following document contains proposals for new Dpdl features that are considered and in development.

These features may eventually be available in coming releases.

Suggestions and comments are very appreciated.


## Inheritance and Polymorphism for type 'class'

Enable inheritance and runtime polymorphism for the type 'class' via the definition **`class name : subclass`**
and the keyword **`override`** for function overloading.

**Example:**
```python
class A {
	int id = -1

	func A(int id_)
		id = id_
	end

	func setId(int id_)
		id = id_
	end

	func getId() int
		return id
	end

	func print()
		println("the id of this class is: " + id)
	end
}

class B : A {
	string desc = "this is derived class from A"

	func setDesc(string d)
		desc = d
	end

	func getDesc() string
		return desc
	end
}

class C : B {
	int id = 369
	string desc = "this is a class derived from B"

	override func print()
		id = 23
		println("the id of this class is: " + id)
	end
}

# main
println("testing inheritance and polymorphism on type class")

class A a(123)
class B b(456)
class C c(789)

println("A :")
println("a.id -> " + a.id)
println("")

println("B :")
println("b.id -> " + b.id)
b.setId(888)
println("b.id -> " + b.id)
b.print()
println("")

println("C :")
println("c.id -> " + c.id)
c.setId(888)
println("c.id -> " + c.id)
c.print()
println("")

```

## Compilation of type 'class' to java bytecode

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
