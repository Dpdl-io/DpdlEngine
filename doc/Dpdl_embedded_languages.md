
# Dpdl embedded languages

				www.dpdl.io
		

		
## Supported embedded programming languages

Multiple programming languages can be embedded directly within Dpdl scripts by using the keyword '**>>...**', for example: **>>python**

The execution of embedded programming languages is driven by the Dpdl runtime through a configurable dedicated native interface with a plug-in configurable
option. See **[DpdlCustom]** tag in 'DpdlEngine.ini' configuration file.

### Embedded C (minimal subset of C90)

#### keyword >>c

```
>>c
	your C code
<<
```

#### documentation

[Dpdl_embedded_C_libs.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/doc/Dpdl_embedded_C_libs.md)


### Python

#### keyword >>python

```
>>python
	your Python code
<<
```

### OCaml

#### keyword >>ocaml

```
>>ocaml
	your OCaml code
<<
```

### Lua

#### keyword >>lua

```
>>lua
	your Lua code
<<
```

### ROOT Data Analysis Framework (C/C++)

An open-source data analysis framework used by high energy physics and others

https://root.cern/gallery/

The ROOT toolkit provides full featured APIs for Data visualization, modeling, statistics

#### keyword >>root

```
>>root
	your ROOT C/C++ code
<<
```


