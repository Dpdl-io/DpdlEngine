# Dpdl

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

developed by
**SEE Solutions**
&copy;	


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

### Custom operations

Dpdl provides a mechanism to intercept and re-define customizable behaviors for dpdl language operations so that they can be manipulated at runtime.

Possible operations are:

- **`get`**
- **`set`**
- **`has`**
- **`apply`**
- **`call`**
- **`construct`** 

The following example shows how member variable access behavior on a type **`class`** can be customized via custom handlers.

At the first invocation of the 'printit(..)' function, the constant value 23 is returned.
After the setting of the member variable 'hash', the computed hash of the string is returned.

**Example:**

```python

func handlerGet(object target, object name, ... )
	if(name == "hash")
		object ret = Reflect.get(target, name)
		if(ret != null && ((typeof(ret)=="int") && ret != 0))
			return ret
		else
			return 23
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
		hash = super.hashCode()
	end

	func printit()
		super.toString()
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



