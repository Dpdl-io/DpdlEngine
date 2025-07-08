# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	
developed by
**SEE Solutions**
&copy; 2003

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

## Compile Dpdl code sections to java bytecode


This is a proposal draft for enabling Dpdl code sections to be compiled to java bytecode at runtime.

The purpose of this feature is to improve performance critical code sections

The meta instruction **`[bytecode]`** signalizes the beginning of Dpdl to bytecode compilation, until the first empty code line is found.

**Example:**

```python
println("testing Dpdl java bytecode compilation at runtime...")

[bytecode]
int arr_i[1000000]
int i
for(i < 1000000)
	arr_i[i] = (arr_i[i] * 2) / 3
	println("arr_i[i]=" + arr_i[i])
endfor

println("this line is executed again as ordinary Dpdl")
```

## Custom language operations

This proposal draft is intended to provide a way to intercept and redefine customizable behaviors for dpdl language operations that can be manipulated at runtime. Possible operations are: **`get`** **`set`** **`has`** **`apply`** **`call`** **`construct`** 

The following example shows how member variable access behavior can be customized via custom handlers. At the first invocation of the 'printit(..)' function, the constant value 23 is returned. After the setting of the member variable 'hash', the computed hash of the string is returned.

**Example:**

```python

func handlerGet(object target, object name, ... )
	if(name == "hash")
		object ret = Reflect.get(target, name)
		if(ret != null && ((typeof(ret)=="int") && ret != 0))
			return ret
		else
			23
		fi
	else
		return 23
	fi
end


class MyStr : refObj("String") {

	int hash = 0

	func MyStr(string s)
		super(s)
	end

	func setHash()
		hash = this.hashCode()
	end

	func printit()
		this.toString()
		println("hash code: " + hash)
	end

}


println("this example shows how dpdl language operations can be intercepted and redefined...")

println('TEST')

class MyStr mys("this is a test")

mys.proxy("get", handlerGet)

mys.printit()

mys.setHash()

mys.printit()
```


