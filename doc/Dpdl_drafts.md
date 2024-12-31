# Dpdl drafts - in development phase

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

	
developed by
**SEE Solutions**
&copy; 2003

The following document contains proposals for new Dpdl features that are considered and in development.

These features may eventually be available in coming releases.

Suggestions and comments are very appreciated.



## Compile Dpdl code sections to java bytecode


This is a proposal draft for enabling Dpdl code sections to be compiled to java bytecode at runtime.

The purpose of this feature is to improve performance critical code sections

The meta instruction **`[bytecode]`** signalizes the beginning of Dpdl to bytecode compilation, untile the first empty code line.

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


