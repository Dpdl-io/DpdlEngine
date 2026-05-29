# Dpdl drafts - in development phase

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



## Dpdl Interfaces

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

	func A(int id_)
		id = id_
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

## JIT compiled dpdl code sections

Although some JVM implementation like Oracle, OpenJDK, etc.. have effective Just-in-Time (JIT) compilation technology in place, this is not available on many other
JVM implementations.

This is a proposal draft for enabling dpdl code sections to be JIT compiled at runtime <ins>before execution</ins>.

The purpose of this feature is only to improve performance of critical code sections that perform calculations, it is not intended to be used on a wider scale.

The meta instruction **`[jit]`** signalizes the beginning of dpdl which should be JIT compiled before execution, until the first empty code line is found.

**Example:**

```python
println("testing Dpdl java bytecode generation ...")

[jit]
int arr_i[1000000]
int i
for(i < 1000000)
	arr_i[i] = (arr_i[i] * 2) / 3
	println("arr_i[i]=" + arr_i[i])
endfor

println("this line is executed again as ordinary Dpdl")
```

