
# Dpdl language plug-in documentation for 'Java'

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

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


### Requirements

This Dpdl language plug-in is built upon the *Janino* library to compile code blocks.

It requires java 1.7 or later.

#### Compatibility matrix

|Java version |JRE version |Release Date |Status |
| --- | --- | --- | --- |
|7 |jdk1.7.0_21 (32 bit) |2011-07-28 |passed |
|8 |adopt_openjdk-8.0.292.10-hotspot |? 	|passed |
|11 |adopt_openjdk-11.0.11.9-hotspot |? |passed |
|17 	|adopt_openjdk-17.0.1+12 |? 	|passed |


### Supported java language properties

Note: All the language features below are supported, even if *DpdlEngine* itself runs in an older JRE version

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

