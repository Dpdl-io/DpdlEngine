
![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

# DpdlEngine V1.0 improvements/changes/fixes

## New 

* NEW (13.12.2023) Added cache for faster loading of java classes

* NEW (09.12.2023) variable 'var' type is supported + function 'typeof(..)' can be used to query the type of a given variable
* NEW (28.11.2023) The data type 'struct' is supported
* NEW (23.11.2023) The native function Thread(..) is now enabled in the 'DpdlEngine lite' release but allows an allocation of only max 3 threads (for unlimited thread allocation the registered version is required)
* NEW (15.11.2023) The embedded C code compile option 'dpdl:compile' is now available in the 'DpdlEngine lite' release download
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

* 13.12.2023 Fixed issue in nested 'struct' type
* 09.12.2023 Fixed bug for 'long' definition inside functions
* 02.11.2023 Fixed bug for Python indentation
* Fixed bug resulted from integration of pointers/references




## Work in progress

* Adaptions to run 'DpdlEngine lite' on the full featured miniJVM developed by digitalgust (https://github.com/digitalgust/miniJVM)
* compile 'dpdlpython' library for Windows64


## Planned

### Features

* Dpdl compiler for generating native machine code 


### Dpdl language plugins

The following programming language plug-ins will be developed:

* Implement language plug-in to enable the embedding of 'ruby' programming language -> keyword '**>>ruby**'
* Implement language plug-in to enable the embedding of 'go' programming language -> keyword '**>>go**'

