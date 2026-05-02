
## Dpdl language plug-in specification for 'Java'

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io
		
developed by
**SEE Solutions**
&copy;



'Java' code can be embedded and executed within Dpdl by using the keyword **`>>java`**

**example:**

```python
println("testing embedded java code block...")

int myarr[300000]
int myi = 100

int c
for(c < 300000)
	myarr[c] = c
	c=c+1
endfor

dpdl_stack_push("dpdlbuf_test", myarr, myi)

setStartTime()

>>java
	System.out.println("Parameters: ");
	System.out.println("	arg0: " + arg0);
	System.out.println("	arg1: " + arg1);
	
	
	static int[] myCalc(int[] arr){
		int[] arr_n = new int[arr.length];
		for(int i = 0; i < arr.length-1; i++){
			arr_n[i] = (arr[i] * arr[i+1]) + 10;
		}
		return arr_n;
	}
	
	
	int[] res = myCalc(arg0);
	
	long sum = 0;
	for(int x = 0; x < res.length; x++){
		System.out.println("res[" + x + "]=" + res[x]);
		sum += res[x];
	}
	
	return "Some test data to write back-> " + sum;
<<

int ms = getEndTime()

int exit_code = dpdl_exit_code()

println("embedded java exit code: " + exit_code + " exec time (ms): " + ms)

string ret_buf = dpdl_stack_buf_get("dpdlbuf_test")

println("result buffer: " + ret_buf)
```

### Calling 'embedded code section' java methods

For '*embedded code section*s' in Java, it's possible to to call the contained java methods methods from dpdl by getting the related object from the stack:

```python
println("dpdl example with an 'embedded code section' in java...")

string str = "this is my str parameter"
int i = 100
float f = 0.2
double d = 9999.9d

dpdl_stack_push(str, "./Test/TestRead.txt", i, f, d)

>>java(my_code_obj)

	System.out.println("Parameters: ");
	System.out.println("	arg0: " + arg0);
	System.out.println("	arg1: " + arg1);
	System.out.println("	arg2: " + arg2);
	System.out.println("	arg3: " + arg3);
	System.out.println("	arg4: " + arg4);

	println("call some methods...")

	myMethod1(arg2);
	myMethod2(arg0, arg2);

	static void myMethod1(int c){
		System.out.println("call myMethod1: " + c);
		System.out.println("	arg1: " + arg1);
		System.out.println("	arg3: " + arg3);

	}

	static void myMethod2(string val, int c){
		System.out.println("call method2: " + val + " " + 2);
		System.out.println("	arg3: " + arg3);
		System.out.println("	arg4: " + arg4);
	}

<<
int exit_code = dpdl_exit_code()

println("embedded java exit code: " + exit_code)

println("we can than also get the code obj and call directly the methods...")

object my_code_obj = dpdl_stack_obj_get("my_code_obj")

my_code_obj.myMethod1(888)

my_code_obj.myMethod2("this is my val", 23)

println("finished")
```

### Requirements

The *Dpdl language plug-in* by default uses the *Janino* library. It requires java 1.7+ or later to run.


#### Compatibility matrix

|Java version |JRE version |Release Date |Status |
| --- | --- | --- | --- |
|7 |jdk1.7.0_21 (32 bit) |2011-07-28 |passed |
|8 |adopt_openjdk-8.0.292.10-hotspot |? 	|passed |
|11 |adopt_openjdk-11.0.11.9-hotspot |? |passed |
|17 	|adopt_openjdk-17.0.1+12 |? 	|passed |


###

The embedded java code must return a value, either of type 'int', 'String' or any other 'Object'

Parameters that are pushed onto the dpdl stack are accessible in the embedded java code via the variable names 'args0, args1, ....argsN'

The following imports are predefined as default, so that embedded code can be access the classes directly:

- java.io.*
- java.util.*
- java.time.*
- java.sql.*

Further default imports can be defined in the 'DpdlEngine.ini' configuration

### Supported java language properties

All the language features listed below are supported, even in case *DpdlEngine* itself runs in an older JRE version

#### Java 1.4 language features:

- **package** declaration, **import** declaration
- **class** declaration
- **interface** declaration
- Inheritance (**extends** and **implements**)
- Static member type declaration
- Inner (non-static member, local, anonymous) class declaration
-- Class initializer, instance initializer
- Field declaration, method declaration
- Local variable declaration
- Class variable initializer, instance variable initializer
- Block statement (**{...}**)
- **if ... else** statement
- Basic **for** statement
- **while** statement
- **do ... while** statement
- **try ... catch ... finally** statement
- **throw** statement
- **return** statement
- **break** statement
- **continue** statement
- **switch** statement
- **synchronized** statement
- All primitive types (**boolean, char, byte, short, int, long, float, double**)
- Assignment operator **=**
- Compound assignment operators **+=, -=, *=, /=, &=, |=, ^=, %=, <<=, >>=, >>>=**
- Conditional operators **? ... :, &&, ||**
- Boolean logical operators **&, ^, |**
- Integer bitwise operators **&, ^, |**
- Numeric operators ***, /, %, +, -, <<, >>, >>>**
- String concatenation operator **+**
- Operators **++** and **--**
- Type comparison operator **instanceof**
- Unary operators **+, -, ~, !**
- Parenthesized expression
- Field access (like **System.out**)
- Superclass member access (**super.meth(), super.field**)
- **this** (reference to current instance)
- Alternate constructor invocation (**this(a, b, c);**)
- Superclass constructor invocation (**super(a, b, c);**)
- Method invocation (**System.out.println("Hello")**)
- Class instance creation (**new Foo()**)
- Primitive array creation (**new int[10][5][]**)
- Class or interface array creation (**new Foo[10][5][]**)
- Array access (**args[0]**)
- Local variable access
- Integer literal (decimal, hex and octal)
- Floating-point literal (decimal)
- Boolean, character, string literal
- **null** literal
- Numeric conversions: Unary, binary, widening, narrowing
- Reference conversions: Widening, Narrowing
- Assignment conversion
- String conversion (for string concatenation)
- Cast
- Constant expression
- Block scope, method scope, class scope, global scope
- **throws** clause
- Array initializer (**String[] a = { "x", "y", "z" };**)
- Primitive class literals (**int.class**)
- Non-primitive class literals (**String.class**)
- References between uncompiled compilation units
- Line number tables ("**-g:lines**")
- Source file information ("**-g:source**")
- Locale Handling of **@deprecated** doc comment tag
- Accessibility checking (**public, protected, private**, default)
- Checking of "definite assignment"
- Methods that compile to more than 32 KB
- **assert** (partially implemented - assertions are always enabled, as if the JVM was started with the "-ea" command line option)
- **StringBuilder** class used for string concatenation

#### Java 5 language features:

- Declaration of parameterized types
- Type arguments (e.g. **List<String>**): Are parsed, but otherwise ignored. The most significant restriction that follows is that you must cast return values from method invocations, e.g. "**(String) myMap.get(key)**"
- Enhanced **for** statement
- Autoboxing and unboxing
- **enum** declaration
- **enum switch** statement
- Annotation type declaration (including method default values)
- Variable arity methods (a.k.a. "varargs")
- Static imports (single and on-demand; fields, types and methods)
- Annotations
- Covariant return types
- **@Override** annotation
- Hexadecimal floating point literals
    
#### Java 7 language features:

- Binary integer literal (JLS7 3.10.1)
- Underscores in numeric literals (JLS7 3.10.1)
- String **switch** statement (JLS7 14.11)
- **try**-with-resources statement (JLS7 14.20.3)
- **catch**ing and rethrowing multiple exception types: Partially implemented; parsed and unparsed, but not compilable
- Type interference for generic instance creation (a.k.a. the "diamond operator") (JLS11 15.9.1)
    
#### Java 8 language features:

- Lambda expressions: Partially implemented; parsed and unparsed, but not compilable
- Method references: Partially implemented; parsed and unparsed, but not compilable
- Default methods
- Static interface methods

#### Java 9 language features:

- Private interface method
- Enhanced **try**-with-resources statement, allowing **VariableAccesses** as resources (JLS9 14.20.3)
- Modules: Partially implemented; modular compilation units are parsed and unparsed, but not compilable

#### Java 10 language features:

- Local variable type inference: Partially implemented; parsed and unparsed, but not compilable
    
#### Java 11 language features:

- Lambda parameter type inference: Partially implemented; parsed and unparsed, but not compilable
   
#### Java 15 language features:

- Text blocks

