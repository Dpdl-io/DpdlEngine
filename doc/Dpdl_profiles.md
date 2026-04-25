# Dpdl

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

developed by
**SEE Solutions**
&copy;	



## 'DpdlEngine' Profiles

The *DpdlEngine* can be run in different configurations (Profiles) and Setups, depending on which is the target platform and which is the usage domain. This affects also the overall size (footprint) of the application.

The *DpdlEngine* setup may also include some *Dpdl language plug-ins* to enable to execute '**embedded code sections**' in other programming languages.

*Dpdl language plug-ins* are an **optional** component, they can be included or excluded, even on-the-fly, via a simple configuration.

A typical setup of Dpdl might be the 'DpdlEngine' plus some of the available *Dpdl language plug-ins* to execute 'embedded code sections' like for example in: *C, Java, Python and JavaScript* etc..

Also the type and number of *Dpdl language plug-ins* included can vary.

### Profiles available

* **`Compact`** : **DpdlEngine** <ins>**Compact**</ins> profile: **`80 Kb`**</ins> or less

* **`Full`** : **DpdlEngine** <ins>**Full**</ins> profile (includes 'DpdlPacket' database support and rich set of built-in functions): **`372 Kb`**


### Compact

Contains a usage profile that enables to execute dpdl code. The functionalities to create and handle '**DpdlPacket**' are included.


#### DpdlEngine 'Compact' with included lightweight version of *Dpdl language plug-ins* for *C, MicroPython and Micro JavaScript*: TOTAL size **`686 Kb`**

The *Dpdl language plug-ins* included in this type of setup are targeted for Embedded Systems.

Also <ins>other Dpdl language plug-ins can be added</ins> of course.

| Platform |Dpdl core Basic |C (interpreted/compiled)| MicroPython | Micro JavaScript (*ES5*) | **TOTAL size** |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 | 80 Kb | 284 Kb | 170 Kb | 152 Kb | 686 Kb|


#### DpdlEngine 'Compact' with included extended version of *Dpdl language plug-ins*

The *Dpdl language plug-ins* included in this type of setup are based on the complete version.

Also <ins>other Dpdl language plug-ins can be added</ins> of course.

| Platform |Dpdl core Basic |C (interpreted/compiled)| Python | JavaScript (*ES2023*)| **TOTAL size** |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 | 80 Kb | 284 Kb | 2551 Kb | 1924 Kb | 4,8 Mb|


### Full

Contains a usage profile that enables to execute dpdl code including a feature rich sets of built-in functions. 

This profile includes also all functionalities required to create, handle and query '**DpdlPacket**'.

#### DpdlEngine 'Full' with included extended version of *Dpdl language plug-ins*

| Platform |Dpdl core Full |C (interpreted/compiled)| Python | JavaScript (*ES2023*) | **TOTAL size** |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 | 372 Kb | 284 Kb | 2551 Kb |  1924 Kb | 5,1 MB|


