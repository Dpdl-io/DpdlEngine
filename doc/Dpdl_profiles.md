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

- **Compact**
- **Full**

#### Compact

This profile is targeted specifically for <ins>small</ins> *Embedded Systems*.

It contains a subset of built-in dpdl functions and modules.

The functionalities for creation of DpdlPackets is not included here.

Also the *Dpdl language plug-ins* eventually included in this type of setup are specifically targeted for small *Embedded Systems*.

**Total size** of the '*DpdlEngine*' for this profile is: **`80 Kb`** or even less


##### Example setup of DpdlEngine 'Compact' with included lightweight version of *Dpdl language plug-ins*

The *Dpdl language plug-ins* included in this type of setup are also specifically targeted for small *Embedded Systems*. 

There are 3 *Dpdl language plug-ins* included here in this example, for:
- **C** (*interpreted & compiled*)
- **MicroPython**
- **Micro JavaScript** (*ES5*)

**TOTAL size:** **`686 Kb`**

| Platform |Dpdl core Basic |C (interpreted/compiled)| MicroPython | Micro JavaScript (*ES5*) | **TOTAL size** |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 | 80 Kb | 284 Kb | 170 Kb | 152 Kb | 686 Kb|

Note: also <ins>other Dpdl language plug-ins might be added</ins> if needed


#### Full

This profile is targeted to medium size *Embedded Systems*, and everything above (desktop, server, etc..)

It contains the full set of built-in dpdl functions and modules. It includes also the full functionalities required to create, handle and query '**DpdlPacket**'

The extended version of *Dpdl language plug-ins* are usually included in this kind of profile. 

**Total size** of the '*DpdlEngine*' for this profile is: **`372 Kb`**


##### Example setup of DpdlEngine 'Full' with included extended version of *Dpdl language plug-ins*

There are 3 *Dpdl language plug-ins* included here in this example, for:
- **C** (*interpreted & compiled*)
- **MicroPython**
- **Micro JavaScript** (*ES5*)

| Platform |Dpdl core Full |C (interpreted/compiled)| Python | JavaScript (*ES2023*) | **TOTAL size** |
| ---  | --- | --- | --- | --- | --- |
| Linux x86_64 | 372 Kb | 284 Kb | 2551 Kb |  1924 Kb | 5,1 MB|

Note: also <ins>other Dpdl language plug-ins might be added</ins> if needed
