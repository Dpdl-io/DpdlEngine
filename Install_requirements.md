Dpdl - Dynamic Packet Definition Language

			    www.dpdl.io


provided by
SEE Solutions


# System requirements

'DpdlEngine lite' V1.0 is available for Free, with some limitations/restrictions (see section below),
under the license agreement included (see LICENSE.txt).

The 'DpdlEngine lite' release requires a compatible Java Virtual Machine (JRE) >= version 1.5 specification to run.

There are many java virtual machines available, the official Java JRE from Oracle can be downloaded from 
www.java.com or www.oracle.com website:

https://www.java.com/en/download/manual.jsp

Some Dpdl API functions (ex. embedded C code) make use of the Dpdl native API library (dpdlnativeapi).
The Dpdl native API library is platform dependent and is available for the following platforms:

	* MacOS 13.4 (arm)
	* Linux x86_64 (x84 64bit)
	* Raspberry PI (armv7)
	* Windows 64-bit (Intel)
	
The native libraries are located in the corresponding platform/architecture folder under './lib/native/' in the corresponding platform folder.

The library can be compiled for additional platforms by us on your request by writing to info@dpdl.io

You may delete the libraries for platforms that you do not use (e.g. ./lib/native/someplatform )

## Embedded 'Python' code

### Supported platforms

Currently the 'DpdlEngine lite' release includes the native Python library '**libdpdlpython**' for **MacOS (arm64)**, **Linux (x86_64)** and Raspberry PI 3 (armv7l)

	* on **Linux:** Python version 3.2m (gcc version 4.4.7)
	* on **MacOS:** Python version 3.12 (Apple clang version 14.0.3)
	* on **Raspberry PI 3**: Python version 3.2m (gcc version 4.4.11)
	* Windows version will follow soon in the coming release
	
	
Support for more platforms will be released soon. MicroPython will also be available as option.

**Note:** The environment variable 'PYTHONHOME' and 'PYTHONPATH' need to be setted correctly for finding the python libraries
```
export PYTHONHOME=/your_path/to/python/install_dir/
export PYTHONPATH=/your_path/to/python/install_dir/
``` 

## Embedded 'OCaml' code

The embedding of OCaml code is still experimental, but works.

See the official OCaml-java documentation at http://www.ocamljava.org/documentation/
	
Eventually you may update the 'ocamlrun-scripting.jar' in the ./lib folder with the newest release downloaded 
directly from ocamljava.org
	

# How to run

To start the DpdlClient console application simply run the following command:

```
java -jar DpdlEngine_V1.0_release.jar
```

Or execute the following scripts:

On Linux/MacOS/Unix
```
sh runDpdlClient.sh
```

On Windows
```
runDpdlClient.bat
```

NOTE: <ins>If a newer version of Java has been installed</ins>, use the following startup script (due to novel java module handling, This will
be fixed in the next release):
```
sh run_DpdlClient_java20.sh
```


# Bluetooth stack compatibility

To use the Dpdl bluetooth API a compatible bluetooth stack needs to be available on the operating system.

Currently the available bluetooth implementation (JSR-82 ) interfaces with the following BT stacks:
	
	* Linux BlueZ
	* Mac OS X
	* WIDCOMM
	* BlueSoleil
	* Microsoft Bluetooth stack found in Windows XP SP2 or Windows Vista
	* WIDCOMM and Microsoft Bluetooth stack on Windows Mobile.
	* J2ME
	* JavaME


## Linux BlueZ

Ensure the BlueZ library 'libbluetooth.so' is available on the path, eventually create a symbolic link (from libbluetooth.so.*)


# Embedded OCaml code

The embedded OCaml code (via >>ocaml keyword) is executed by the Dpdl runtime through the ocamljava library (http://www.ocamljava.org/) and
requires the following jar library located in the lib folder (./lib): 'ocamlrun-scripting.jar' 

If the 'compile' option has been set (OCaml code is compiled at runtime to improve speed), also the 'ocamljava.jar'
needs to be present in the lib folder.


# 'DpdlEngine lite' release limitations/restrictions (compared to registered version)

	
The 'DpdlEngine lite' release software package is available for Free and has the following limitations/restrictions:

* At startup, the DpdlEngine requires the execution of a validation script.
The script simply accesses a html website at www.seesolutions.it for validation (NO data is collected or stored, it's a simple get html).
	  
The validation script can be inspected here: 
[./DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h)

* The DpdlEngine parameters and configuration file 'DpdlEngine.ini' can be customized only in the registered version
	
* The class definition file (classes.txt), used for dynamic loading and resolving of library classes via loadObj(..) and getClass(..) methods can be edited only in the registered version of Dpdl.
	
* The execution of Dpdl scripts is limited to 500 lines of code. Embedded C code, Python and OCaml is limited to 100 lines of code (per section)
	
* The Dpdl scripting API function 'systemExec' is available only in the registered version of Dpdl
	
* The interface API to develop custom API extensions (DpdlExtension) is available only in the registered version of Dpdl
	
* The compilation/encoding of DpdlPackets via Dpdl code definition files (ex. dpdl_PHONEBOOK.c) is available only in the registered version of Dpdl
	
* The Dpdl java API is available only in the registered Dpdl version (but Dpdl scripting API is fully available)

* DPDLAPI_*XPath* methods are implemented only in the registered version of Dpdl

* The 'Thread(..)' API function is available only in the registered version of Dpdl (use createThread(..) instead, it provides similar functionality)








