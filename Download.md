# Dpdl Download

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	



## Licensing

Dpdl is a proprietary software developed by SEE Solutions.

The 'DpdlEngine' is available as a standalone software package/library in two distinct release distributions:

- **DpdlEngine lite**
- **DpdlEngine pro**


## 'DpdlEngine lite'

The demo release of 'DpdlEngine lite' is available for evaluation as Demo trial Shareware with some limitations/restrictions  and requires a valid License Key.


#### Download 'DpdlEngine lite'

The 'DpdlEngine lite' Demo release (v1.0) can be requested, with some limitations/restrictions, via the www.dpdl.io download request form:

[DOWNLOAD request](https://www.dpdl.io/download_request.htm)

Documentation and Updates are regularly available on the official DpdlEngine GitHub repository:
[DpdlEngine GitHub](https://github.com/Dpdl-io/DpdlEngine)

At request, the full registered version can be activated by acquiring a personal license with corresponding activation key with a fixed, one time pricing model. 

Suggestion, feature wish list and contributions to enhance Dpdl are very welcome and can be submitted on the discussion section on GitHub:
[Dpdl discussion](https://github.com/Dpdl-io/DpdlEngine/discussions)


## 'DpdlEngine pro'

The 'DpdlEngine pro' release is supplied tailored to specific customer requirements in terms of licensing model and release package.

In particular also platform specific targets can be defined (e.g run on Java 1.4, JavaME etc..) to meet at best the customer requirements at full extend.

The available Dpdl language plug-ins can also be requested along with its full source code disclosure for applying customizations or develop further extensions.

We strongly believe that requirements and business strategies can be worked out together with our clients.

The <ins>'DpdlEngine pro'</ins> software is licensed on custom licensing models depending on the type of use and application domain.

Feel free to get a non binding quotation by writing to info@dpdl.io


## Pricing

### How much does a registered 'DpdlEngine lite' cost?

The 'DpdlEngine lite' release license is granted on the basis of a fixed, one-time pricing model.

| License type | number activation keys | Price (tax excl.) |
| ------------ | ---------------------- | ----------------- |
| individual   | 1 | 90 $ |
| ------------ | ---------------------- | ----------------- |
| Small team   | 5 | 360 $ |
| ------------ | ---------------------- | ----------------- |
| Medium team  | 10 | 720 $ |


#### Additional Subscriptions

| Type | Description | Price (tax excl.) |
| ------------ | ---------------------- | ----------------- |
| Support   | 1 year support for 5 hours | 300 $ |
| ------------ | ---------------------- | ----------------- |
| Customizations  | customizations/feature request  | 120 $ / hourly |
| ------------ | ---------------------- | ----------------- |
| Extra plugin  | extra embedded language plugin | 70 $ |


### What does the free trial 'DpdlEngine lite' release provide?

The 'DpdlEngine lite' release is available for Free to try with some limitations/restrictions (see section below),
and can be used to exploit the features of Dpdl and to develop and distribute small applications
or utility tools.


'DpdlEgine lite' includes:

* The 'DpdlClient' console application that allows to execute a set of commands for interacting with the core DpdlEngine
	  
* Dpdl scripting engine with Dpdl API libraries.

* Support for the following embeddable languages: Embedded C (interpreted and compiled), JavaScript, Java
	
* Example Dpdl scripts (located in the folder and './DpdlLibs/' and './DpdlPackets/' )
	
* Example DpdlPacket (dpdl_PHONEBOOK.dpdl) with corresponding Dpdl code definition file
	

## How to order a registered  'DpdlEngine lite' release license?

To buy a registered 'DpdlEngine lite' license with no limitations/restrictions, regular updates and support,
please submit your request via the following order request form, you will be contacted promptly: 

[Request Form](https://www.dpdl.io/index_order.html)

Or simply write an e-mail to info@dpdl.io



## 'DpdlEngine lite' Demo free trial shareware release limitations/restrictions

	
The 'DpdlEngine lite' Demo release software package is available for Free to try and has the following limitations/restrictions
compared to the full registered version:

* At startup, the 'DpdlEngine lite' Demo requires internet connectivity for the execution of a validation script.
The script simply accesses a html website at https://www.dpdl.io for validation (NO data is collected or stored, it's a simple get html).
-> startup is therefore also <ins>slower in demo version</ins> due to validation, compared to full registered version.
	  
The validation script can be inspected here: 
[./DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/DemoDpdl_validator/validateDpdlDemo.h)

* The DpdlEngine parameters and configuration file 'DpdlEngine.ini' can be customized only in the full registered version
	
* Further API's can be added only in the full registered version of 'DpdlEngine'
	
* The execution of Dpdl scripts is limited to 500 lines of code, embedded language code (C, JavaScript, Java) is limited to 100 lines of code per section.
	
* The Dpdl scripting API function 'systemExec' is available only in the registered version of Dpdl
	
* The interface API to develop custom API extensions (DpdlExtension) is available only in the full registered version of Dpdl.
	
* The compilation/encoding of DpdlPackets via Dpdl code definition files (ex. dpdl_PHONEBOOK.c) is available only in the registered version of Dpdl
	
* The Dpdl java API is available only in the registered Dpdl version (but Dpdl scripting API is fully available)

* The 'Thread(..)' and createThread(..) API functions allow only a limited number of threads to be allocated (max 3 Threads allowed, further allocations will than rotate an override previews thread allocations)

* Native 'dpdlpython' api for embedding python within Dpdl scripts is not available on Windows OS

* On Windows OS the native Dpdl API function 'dpdl_stack_buf_put(..)' is not available when option 'dpdl:compile' or 'dpdl:C99' is activated

* The option 'dpdl:compile' used to <ins>compile</ins> embedded ANSI C code in memory at runtime can be used only 500 times in the unregistered version of Dpdl

* The option 'dpdl:-F' (to add files to be compiled) used along with the option 'dpdl:compile' can be used only once in the unregistered version of Dpdl

* The option 'dpdl:-A' (to add files to be compiled) used along with the option 'dpdl:compile' is enabled only in the registered version (Note: it will throw and execption in the Demo version)

* Multi-line embedded structured text, data and code resources are supported only in the full registered version of 'DpdlEngine lite'.

* The 'DpdlNerdAI' (DAN) Dpdl language plug-in requires a password '123456' at each generation in the unregistered version of DpdlEngine. The max. size of 'dpdlnerdai_buf' is 500

* The Demo release of 'DpdlEngine lite' has as slower startup due to security checks, compared to the full registered version of 'DpdlEngine lite'

* The 'loadLib' and 'mapLib' functions of the 'native' Dpdl library are available only in the full registered version of Dpdl

* Multi-line resources 'res' and asynchronous 'task' are available only in the full registered version of DpdlEngine



**NOTE:** The native Dpdl library for embedded C support within Dpdl scripts is currently available for MacOS, Linux x86_64, Windows 64-bit and Raspberry Pi. 

More builds will follow. Eventually it might be necessary to recompile it for some versions of the platform.
Contact us if this is the case, we're pleased to satisfy you request





