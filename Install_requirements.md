Dpdl - Dynamic Packet Definition Language

			    www.dpdl.io


provided by
SEE Solutions


# System requirements

'DpdlEngine lite' V1.0 is available for Free, with some limitations/restrictions (see section below),
under the license agreement included (see LICENSE.txt).

The 'DpdlEngine lite' release requires a compatible Java Virtual Machine (JRE) >= version 1.6 specification to run.

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

### Dpdl embedded language plug-ins Add-ons:

Additional Dpdl language plug-in add-ons can be downloaded or updated by downloading and extracting the following zip archive in the
'./lib/' folder .

https://www.dpdl.io/downloads/Dpdl_language_plugins.zip


### Embedded languages - compatibility matrix

(X + version) **currently supported**

(*) **available soon**

| Platform |Embedded C |Python |Julia |OCaml |Lua |ROOT C/C++ |go |ch C/C+ |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux x86_64 |X|X v3.2|X v1.9.3|X v4.01|X v5.4|X v6.28|*|*|
| Mac OS X (arm64) |X|X v3.12|X v1.9.3|X v4.01|X v5.4|X v6.28|*|*|
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X v4.01|X v5.4|*|*|*|
| Windows64|X|*|*|X v4.01|*|*|*|*|


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

## Embedded 'Julia' code

For the embedding of 'Julia' code the following paths (symbolic links) must be set in the folder './dpdl_env_paths':

JULIA_DEPOT_PATH = path to the 'Julia' package folder
JULIA_LIBS_PATH = path to the 'Julia' lib folder

eg. symbolic links in the folder './dpdl_env_paths/'
```
JULIA_DEPOT_PATH -> /Users/arcosta/APP/devel/julia-1.9.3/usr/share/julia_depot
JULIA_LIBS_PATH -> /Users/arcosta/APP/devel/julia-1.9.3/usr/lib
```

NOTE: The native Dpdl library 'dpdljulia' needs to be downloaded and deployed separately (see Downloads section in README.md)

## Embedded 'ROOT C/C++' code

For the embedding of 'ROOT' code the following path (symbolic links) must be set in the folder './dpdl_env_paths':

ROOT_LIB_PATH = path to the 'ROOT' lib folder

eg. symbolic links in the folder './dpdl_env_paths/'
```
ROOT_LIB_PATH -> /Users/arcosta/APP/devel/ROOT_Devel/lib
```
NOTE: The native Dpdl library 'dpdlroot' needs to be downloaded and deployed separately (see Downloads section in README.md)

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
The script simply accesses a html website at www.dpdl.io for validation (NO data is collected or stored, it's a simple get html).
	  
The validation script can be inspected here: 
[./DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h](https://github.com/SEESolutions-it/DpdlEngine/blob/main/DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h)

* The DpdlEngine parameters and configuration file 'DpdlEngine.ini' can be customized only in the registered version
	
* The class definition file (classes.txt), used for dynamic loading and resolving of library classes via loadObj(..) and getClass(..) methods can be edited only in the registered version of Dpdl.
	
* The execution of Dpdl scripts is limited to 500 lines of code. Embedded C code, Python and OCaml is limited to 100 lines of code (per section)
	
* The Dpdl scripting API function 'systemExec' is available only in the registered version of Dpdl
	
* The interface API to develop custom API extensions (DpdlExtension) is available only in the registered version of Dpdl
	
* The compilation/encoding of DpdlPackets via Dpdl code definition files (ex. dpdl_PHONEBOOK.c) is available only in the registered version of Dpdl
	
* The Dpdl java API is available only in the registered Dpdl version (but Dpdl scripting API is fully available)

* The 'Thread(..)' API function is available only in the registered version of Dpdl (use createThread(..) instead, it provides similar functionality)

* Native 'dpdlpython' api for embedding python within Dpdl scripts is not available on Windows OS 

* Dpdl scripts included with 'include(...)' supports execution of embedded code only in the registered version of Dpdl

**NOTE:** The native Dpdl library for embedded C support within Dpdl scripts is currently available for MacOS, Linux x86_64, Windows 64-bit and Raspberry Pi. 
More builds will follow. Eventually it might be necessary to recompile it for some versions of the platform.
Contact us if this is the case.







