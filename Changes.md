
<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

developed by
**SEE Solutions**
&copy;

# DpdlEngine V1.0 features/changes/fixes


## New features

* NEW Support for in-code Asynchronous Multi-Agent development

* NEW Dpdl language plug-in for 'Scheme' is now available

* NEW Dpdl language plug-in for 'Modelica' is now available. Modelica is programming language to model cyber-physical systems and components.


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

* Dpdl language plug-in to enable the embedding of 'Dart' programming language code -> keyword '**>>dart**'
* Dpdl language plug-in to enable the embedding of 'octave' programming language code -> keyword '**>>octave**'
* Dpdl language plug-in to enable the embedding of 'go' programming language code -> keyword '**>>go**'

