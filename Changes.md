
# DpdlEngine V1.0 improvements

## New 

* The native Dpdl library for Python 'dpdlpython' is now available  in the 'DpdlEngine lite' release (for Mac OS X arm64, Linux x86_64 and Raspberry PI 3 armv7)
* 'lua' scripts can now be embedded in Dpdl scripts via the '**>>lua**' keyword
* Lua Dpdl native library is now included in DpdlEngine lite release, but currently combining Python and Lua does not work due --> will be fixed soon
* It's now possible to launch a Dpdl script via the '-load' parameter at DpdlEngine startup (eg: java -jar DpdlEngine_V1.0_release.jar -load arraylistExample.h)
* Added message parameter to function raise(object condition, string msg)
* 'Julia' script can now be embedded in Dpdl scripts via the '**>>julia**' keyword --> Dpdl library 'dpdljulia' needs to be downloaded and deployed separately (see Download section in README.md)
* 'ROOT' C++ code can now be embedded in Dpdl scripts via the '**>>root**' keyword --> Dpdl library 'dpdlroot' needs to be downloaded and deployed separately (see Download sectio in README.md)
* JavaScript can now be embedded in Dpdl scripts via the '**>>js**' keyword
* (12.11.2023) Embedded ANSI C code can now be compiled dynamically on-the-fly in memory at runtime for faster execution (see option '**dpdl:compile**') --> available within the next days

* NEW (15.11.2023) The embedded C code compile option 'dpdl:compile' is now available in the 'DpdlEngine lite' release download
  currently platforms supported: MAC OSX (arm64) Linux (x86_64), Raspberry (armv7)
  Support for Windows64 will be released soon

## Fixes

* Fixed bug resulted from integration of pointers/references
* 02.11.2023 Fixed bug for Python indentation 


## Work in progress

* 'dpdlpython' library for Windows64
* Test python 'Tensorflow lite' and define needed interfaces
* Adaptions to run 'DpdlEngine lite' on the full featured miniJVM developed by digitalgust (https://github.com/digitalgust/miniJVM)


## Planned

The following programming language plug-ins will be developed:

* Implement language plug-in to enable the embedding of 'ruby' programming language -> keyword '**>>ruby**'
* Implement language plug-in to enable the embedding of 'go' programming language -> keyword '**>>go**'

