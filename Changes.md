
![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

developed by
**SEE Solutions**
&copy; 2003

# DpdlEngine V1.0 features/changes/fixes


## New features

* NEW Dpdl language plug-in for 'V' is now available

* Dpdl language plug-in for 'OCL' (OpenCL) is now available

* Dpdl language plug-in for 'Perl' is now available

* Inheritance and Polymorphism for type 'class' and 'struct'

* Dpdl language plug-in for 'MicroPython' is now available


## Adaption

* Entry point for embedded C code, in interpreted as well as in compiled mode, is now unified as 'dpdl_main(....)'


## Known Issues

* The Dpdl language plugin for 'OCaml' is working on Java JRE versions 1.7 and 1.8. On newer versions of java an
update of OCaml libraries might be required.


## Work in progress

* compile 'dpdlpython' library for Windows64


## Planned

### Features

* Dpdl backend compiler based on LLVM for generating native machine code for most target platform architectures
* Development of a dedicated **Dpdl language plug-in** for enabling QUANTUM computing via OpenQASM 2.0 (circuit description language)


### Dpdl language plug-ins

The following programming language plug-ins will be developed:

* Implement language plug-in to enable the embedding of 'octave' programming language -> keyword '**>>octave**'
* Implement language plug-in to enable the embedding of 'go' programming language -> keyword '**>>go**'

