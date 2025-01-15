
![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

developed by
**SEE Solutions**
&copy; 2003

# DpdlEngine V1.0 features/changes/fixes


## New features

* NEW Dpdl language plugin for 'Perl' is now available

* Inheritance and Polymorphism for type 'class' and 'struct'

* Dpdl language plug-in for 'MicroPython' is now available

* Asynchronous Tasks can now be executed via the keyword **`>>task`** containing embedded Dpdl code sections 

* Dpdl now supports also the type 'class'

* Dpdl language plug-in for 'Groovy' is now available

* Dpdl language plug-in 'Wgsl' that allows to scale computations on GPU's by using WGSL code (WebGPU Shading Language)

* Dpdl Wasm runtime plug-in for compiling and accessing 'Wasm' module functions from 'dpdl' and from embedded code

* Multi-line structured text, data and code resources are supported


## Adaption

* Entry point for embedded C code, in interpreted as well as in compiled mode, is now unified as 'dpdl_main(....)'


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

