# Dpdl proposal drafts

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

	
by
**SEE Solutions**
&copy;

The following document contains proposals for new Dpdl features that are considered and in development.

These features may eventually be available in coming releases.

Suggestions and comments are very appreciated.


## dpdl-lang

### Interfaces

Proposal for supporting Interfaces.

An Interface describes a list of functions that a class, which inherits from the interface, must implement.

```python

interface IA {
	func foo()
	func bar() void
	func foo_bar() int
}


class A : IA {

	int id

	func A(int id)
		this.id = id
	end

	func foo()
		println("foo()")
	end

	func bar() void
		println("bar()")
	end

	func foo_bar() int
		println("A->foo_bar()")

		return id
	end
}

class B : A {

	func B()
		super(888)
	end
	
	func foo_bar() int
		println("B->foo_bar()")

		return 369
	end
}


println("testing interfaces...")

class A mya(999)

mya.foo()
mya.bar()

println("mya->" + mya.foo_bar())

class B myb

myb.foo()
myb.bar()

println("myb->" + myb.foo_bar())
```

