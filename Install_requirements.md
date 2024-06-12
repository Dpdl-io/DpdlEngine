# Dpdl - System requirements

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

			    www.dpdl.io


developed by
**SEE Solutions**
&copy; 2003


'DpdlEngine lite' V1.0 is available as Free Trial Shareware, with some limitations/restrictions (see [Download.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Download.md) doc),
under the license agreement included in this distribution (see LICENSE.txt).

The full registered version of DpdlEngine can be requested via the order request form:
[ORDER Full Version](https://www.dpdl.io/index_order.html)


## Note

The DpdlEngine documentation is located in the 'doc' folder, OR ideally more up to date, on the GitHub repository:

[Dpdl.io GitHub](https://github.com/Dpdl-io/DpdlEngine)

As DpdlEngine is in a fast development cycle and new features and fixes may be available from time to time (see [Changes.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Changes.md) doc)

By filing the following form you'll get a permanent download link.
[Direct DOWNLOAD request link](https://www.dpdl.io/download_request.htm)


### Important notice: 

It's important to verify the integrity of the 'DpdlEngine lite' release zip file you downloaded or received the package () via third parties:

The distributed package (DpdlEngine_V1.0_release.zip) <ins>**MUST**</ins> in any case match the <ins>SHA(256) checksum</ins> as reported on this site: 
					
			https://www.dpdl.io/DemoDpdl_validator.html
			

## System requirements

Although Dpdl is compatible also with previews versions of Java and virtual machines, this release of 'DpdlEngine lite' requires a 
compatible Java Virtual Machine (JRE) version  >= 'Java 17'  to run.

If your requirements are to run 'DpdlEngine lite' on an older version of java JRE, just drop an e-mail to: info@dpdl.io 

There are many java virtual machines available, the official Java JRE from Oracle can be downloaded from 
www.java.com or www.oracle.com website:

https://www.java.com/en/download/manual.jsp

Some Dpdl API functions (ex. embedded C code and other embedded languages) make use of the Dpdl native API library 'dpdlnativeapi'.
The Dpdl native API library is platform dependent and is currently available for the following platforms (see also compatibility matrix below):

* MacOS 13.4 (aarch64)
* Linux x86_64 (x84 64bit)
* Raspberry PI (armv7)
* Windows 64-bit (Intel)
	
The native libraries are located in the corresponding platform/architecture folder under './lib/native/' in the corresponding platform folder.

The native libraries <ins>can be compiled for additional platforms by us</ins> on your request by writing to info@dpdl.io

You may delete unused libraries for platforms that you are not interested in (e.g. ./lib/native/$someplatform )

To enable the <ins>USE of the **JavaFX library**</ins>, it's necessary to set the environment variable **`JAVAFX_PATH`** with the full path to the
JavaFX libraries on your system:

eg.
```
export JAVAFX_PATH=/Users/arcosta/APP/devel/javafx-sdk-21.0.1/lib
```

NOTE: On Windows OS use the appropriate 'javafx' startup script to run DpdlEngine


### Embedded languages - compatibility matrix

(X + version) **Supported**

(*) **available soon**

| Platform |Embedded ANSI C |Python |Julia |Js |Clojure |Lua |ROOT C++ |Ruby |Java |SQL |OCaml |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Linux x86_64 |X|X v3.2|X v1.9.3|X|X v1.12.0|X v5.4|X v6.28|*|X|X|X v4.01|
| Mac OS X (aarch64) |X|X v3.12|X v1.9.3|X|X v1.12.0|X v5.4|X v6.28|X 3.2.2|X|X|X v4.01|
| Raspberry PI 3 (armv7) | X|X v3.2|X v1.9.3|X|X v1.12.0|X v5.4|*|*|X|X|X v4.01|
| Windows64|X|*|*|X|X v1.12.0|*|*|*|X|X|X v4.01|


Note: The Free trial shareware version of 'DpdlEngine lite' includes a subset of the Dpdl language plug-ins (see 'DpdlEngine.ini' section [DpdlCustom]) .

If your're interested in testing a specific Dpdl language plug-in please feel free to contact us,
we'll be happy to satisfy your specific needs: info@dpdl.io


### Embedded C code

The C code embedded within Dpdl can be executed in 2 modes:

1) Interpreted (minimal subset of C90)
2) Compiled in memory at runtime and executed (full ANSI C99 compilant)

Mode 2) can be activated by pushing the optino 'dpdl:compile' on the dpdl stack before embedding the code

The Dpdl native API library 'dpdlnativeapi' provides also a <ins>Security check</ins> to guarantee that the library have not been compromised.
Therefore the embedded C code execution cannot be mangled internally and guarantees the correct execution of C code.
In the case the library is updated, the corresponding verification checksums needs to be adjusted in 'DpdlEngine.ini" config.


### Embedded 'Python' code

#### Supported platforms (Python)

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

### Embedded 'Julia' code

For the embedding of 'Julia' code the following paths (symbolic links) must be set in the folder './dpdl_env_paths':

JULIA_DEPOT_PATH = path to the 'Julia' package folder
JULIA_LIBS_PATH = path to the 'Julia' lib folder

eg. symbolic links in the folder './dpdl_env_paths/'
```
JULIA_DEPOT_PATH -> /Users/arcosta/APP/devel/julia-1.9.3/usr/share/julia_depot
JULIA_LIBS_PATH -> /Users/arcosta/APP/devel/julia-1.9.3/usr/lib
```

NOTE: The native Dpdl library 'dpdljulia' needs to be downloaded and deployed separately (see Downloads section in README.md)

### Embedded 'ROOT C++' code

For the embedding of 'ROOT' code the following path (symbolic links) must be set in the folder './dpdl_env_paths':

ROOT_LIB_PATH = path to the 'ROOT' lib folder

eg. symbolic links in the folder './dpdl_env_paths/'
```
ROOT_LIB_PATH -> /Users/arcosta/APP/devel/ROOT_Devel/lib
```

NOTE: The native Dpdl library 'dpdlroot' needs to be downloaded and deployed separately (see Downloads section in README.md)


### Embedded 'OCaml' code (experimental)

The embedded OCaml code (via >>ocaml keyword) is executed by the Dpdl runtime through the ocamljava library (http://www.ocamljava.org/) and
requires the following jar library located in the lib folder (./lib): 'ocamlrun-scripting.jar'.
Java version 1.7 or later is needed for this plugin. 

Eventually you may update the 'ocamlrun-scripting.jar' in the ./lib folder with the newest release downloaded 
directly from ocamljava.org

If the 'dpdl:compile' option has been set (OCaml code is compiled at runtime to improve speed), also the 'ocamljava.jar'
needs to be present in the lib folder.

See the official OCaml-java documentation at http://www.ocamljava.org/documentation/


### Dpdl embedded language plug-in Add-ons:

Additional Dpdl language plug-in add-ons can be downloaded or updated by downloading and extracting the following zip archive in the
'./lib/' folder .

https://www.dpdl.io/downloads/Dpdl_language_plugins.zip


## How to run DpdlEngine

To start the DpdlClient console application simply run the following command:

```
java -jar DpdlEngine_V1.0_release.jar [-load $dpdl_script.h]
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
sh run_DpdlClient_java17.sh
```
On newer versions of the Java Virtual Machine from Oracle, if you want to access specific modules of JRE you may need to enable them with the '--add-opens' option in the DpdlEngine startup script.


## Bluetooth stack compatibility

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


### Linux BlueZ

Ensure the BlueZ library 'libbluetooth.so' is available on the path.
Eventually you might neet to create a symbolic link to a specific version of the library (eg. libbluetooth.so -> libbluetooth.so.$version)



## Limitations/restrictions of the Demo/shareware unregistered version of 'DpdlEngine lite'


see [Download.md](https://github.com/Dpdl-io/DpdlEngine/blob/main/Download.md) document


