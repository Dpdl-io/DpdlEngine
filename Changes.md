
# DpdlEngine V1.0 improvements

## New 

* The native Dpdl library for Python 'dpdlpython' is now available  in the 'DpdlEngine lite' release (for Mac OS X arm64, Linux x86_64 and Raspberry PI 3 armv7)
* 'lua' scripts can now be embedded in Dpdl scripts via the '**>>lua**' keyword (the plugin is available as separate download and requires update of 'DpdlEngine.ini' config file
* Lua Dpdl native library is now included in DpdlEngine lite release

Download link:

https://www.dpdl.io/downloads/369/DpdlEngine_V1.0_release.zip


## Fixes

* Fixed bug resulted from integration of pointers/references
* 02.11.2023 Fixed bug for Python identification 

## Work in progress

* 'dpdlpython' library for Windows64
* Test python 'Tensorflow lite' and define needed interfaces
* Adaptions to run 'DpdlEngine lite' on the full featured miniJVM developed by digitalgust (https://github.com/digitalgust/miniJVM)


## Planned

The following programming language plug-ins will be developed:

* Implement language plug-in to enable the embedding of 'go' programming language -> keyword '**>>go**'
* Implement language plug-in for 'Ch' embedded C/C++ interpreter from softintegration.com (requires separate commercial license from softintegration) -> keyword '**>>ch**'