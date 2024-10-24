
![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

developed by
**SEE Solutions**
&copy; 2003

# DpdlEngine V1.0 features/changes/fixes

## New features

* NEW Asynchronous Tasks can now be executed via the keyword **`>>task`** containing embedded Dpdl code sections 

* Dpdl now supports also the type 'class'

* Dpdl language plug-in for 'Groovy' is now available

* Dpdl language plug-in 'Wgsl' that allows to scale computations on GPU's by using WGSL code (WebGPU Shading Language)

* Dpdl Wasm runtime plug-in for compiling and accessing 'Wasm' module functions from 'dpdl' and from embedded code

* Multi-line structured text, data and code resources are supported


## Adaption

* Entry point for embedded C code, in interpreted as well as in compiled mode, is unified as 'dpdl_main(....)'


## Fixes

* 15.09.2024 Fix minor memory management issue when using 'DPDLAPI_createThread(...)'
* 01.09.2024 Fix small bug related to formatting
* 07.06.2024 Fixed bug related to enum type when field values were explicitly assigned and accessed without enum reference. Now works as espected in all cases
* 22.05.2024 The power operator ^ now returns always a 'double' value
* 07.01.2024 Fixed some duplicate entries in the class definition file
* 13.12.2023 Fixed issue in nested 'struct' type
* 09.12.2023 Fixed bug for 'long' definition inside functions
* 02.11.2023 Fixed bug for Python indentation
* Fixed bug resulted from integration of pointers/references


## Known Issues

* The Dpdl language plugin for 'OCaml' is working on Java JRE versions 1.7 and 1.8. On newer versions of java an
update of '.lib/ocamlrun-scripting.jar' and './lib/ocamljava.jar' might be required (available from http://www.ocamljava.org)


## Work in progress

* compile 'dpdlpython' library for Windows64


## Planned

### Features

* Dpdl backend compiler based on LLVM for generating native machine code for most target platform architectures


### Dpdl language plug-ins

The following programming language plug-ins will be developed:

* Implement language plug-in to enable the embedding of 'octave' programming language -> keyword '**>>octave**'
* Implement language plug-in to enable the embedding of 'go' programming language -> keyword '**>>go**'

