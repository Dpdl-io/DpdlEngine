
![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

developed by
**SEE Solutions**
&copy; 2003

# DpdlEngine V1.0 improvements/changes/fixes

## New 

* NEW (01.06.2024) Added support for converting/compiling Dpdl objects such as 'struct' to native java bytecode objects that can be accessed and handled in the same way as ordinary objects -> this feature will be available in the coming 'DpdlEngine lite' release

* (25.05.2024) Added native data function types **`vec(...)`** **`map(...)`** **`list(...)`** **`stack()`**

* (20.05.2024) Added support for type 'short'
* (11.05.2024) Dpdl now enables to load and access native libraries (libc, msvcrt, etc..) directly via a unified interface
					and call functions from Dpdl in the same way -> This feature is available for releases requested via the 							'Download form' (see [Download.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Download.md)
* (05.05.2024) Added 'char' type for better integration
* (17.07.2024) Dpdl language plug-in 'DpdlAINerd' for generative code is now available in 'DpdlEngine lite' release
					Documenation and examples will be available soon
* (01.04.2024) The JavaFX library is now available also in the 'DpdlEngine lite' release
* (01.04.2024) The Dpdl import library 'http' has been improved with more functions (POST, PUT, etc..)
* (24.03.2024) Dpdl language plugin for SQL is available in the 'DpdlEngine lite' release
* (16.03.2024) Dpdl embedded language plugin form Clojure has been developed and has been included in the latest 'DpdlEngine lite' release
* (18.02.2024) Dpdl embedded language plugin for 'Java' code blocks is available
* (04.02.2024) Dpdl embedded language plugin for 'Ruby' has been implemented and will be included in the coming releases of 'DpdlEngine lite'
* (30.01.2024) String can now contain expressions within the keyword '${..}' that are evaluated when variables are initialized eg. string mystr = "result: ${a + b}" 
* (20.01.2024) Added JavaFX classes to Dpdl class definition file and created Dpdl example app that uses JavaFX to render UI elements via FXML
* (13.01.2024) Added basic 'http' and 'json' import libraries.
* (02.23.2023) JavaScript can now be executed also via the 'QuickJS' javascript engine (ES2020 spec) by using the keyword '>>qjs'
* (27.12.2023) 'import' statement for libraries
* (19.12.2023) 	Function return type definitions added. Type 'enum' is supported. Function 'convert(..)' added
* (14.12.2023) 'for' statement is available i a first draft, it will be worked out further
* (13.12.2023) Added cache for faster loading of java classes
* (09.12.2023) variable 'var' type is supported + function 'typeof(..)' can be used to query the type of a given variable
* (28.11.2023) The data type 'struct' is supported
* (23.11.2023) The native function Thread(..) is now enabled in the 'DpdlEngine lite' release but allows an allocation of only max 3 threads (for unlimited thread allocation the registered version is required)
* (15.11.2023) The embedded C code compile option 'dpdl:compile' is now available in the 'DpdlEngine lite' release download
  currently platforms supported: MAC OSX (arm64) Linux (x86_64), Raspberry (armv7)
  Support for Windows64 will be released soon
* (12.11.2023) Embedded ANSI C code can now be compiled dynamically on-the-fly in memory at runtime for faster execution (see option '**dpdl:compile**') --> available within the next days
* JavaScript can now be embedded in Dpdl scripts via the '**>>js**' keyword
* 'ROOT' C++ code can now be embedded in Dpdl scripts via the '**>>root**' keyword --> Dpdl library 'dpdlroot' needs to be downloaded and deployed separately (see Download sectio in README.md)  
* 'Julia' script can now be embedded in Dpdl scripts via the '**>>julia**' keyword --> Dpdl library 'dpdljulia' needs to be downloaded and deployed separately (see Download section in README.md)
* Added message parameter to function raise(object condition, string msg)
* It's now possible to launch a Dpdl script via the '-load' parameter at DpdlEngine startup (eg: java -jar DpdlEngine_V1.0_release.jar -load arraylistExample.h)
* Lua Dpdl native library is now included in DpdlEngine lite release, but currently combining Python and Lua does not work due --> will be fixed soon
* 'lua' scripts can now be embedded in Dpdl scripts via the '**>>lua**' keyword
* The native Dpdl library for Python 'dpdlpython' is now available  in the 'DpdlEngine lite' release (for Mac OS X arm64, Linux x86_64 and Raspberry PI 3 armv7)

## Fixes

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

* Dpdl compiler for generating native machine code 



### Dpdl language plugins

The following programming language plug-ins will be developed:

* Implement language plug-in to enable the embedding of 'octave' programming language -> keyword '**>>octave**'
* Implement language plug-in to enable the embedding of 'go' programming language -> keyword '**>>go**'

