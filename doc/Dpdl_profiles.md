# Dpdl

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	



## 'DpdlEngine' Profiles

The *DpdlEngine* can be run in different configurations (**Profiles**) and Setups, depending on which is the target platform and which is the usage domain. This affects also the overall size (footprint) of the application.

The *DpdlEngine* setup may optionally also include some *Dpdl language plug-ins* to enable to execute '**embedded code sections**' for example in other programming languages. The *Dpdl language plug-ins* can be included or excluded, even on-the-fly, via a simple configuration.

A typical setup of Dpdl might be the '*DpdlEngine*' plus some of the available *Dpdl language plug-ins* to execute '*embedded code sections*' like for example in: **C**, **Java**, **Python** and **JavaScript*** etc..

Also the type and number of *Dpdl language plug-ins* included can vary.

### Profiles available:

- **Compact**
- **Full**

### 'Compact' profile

This profile is targeted specifically for <ins>small</ins> *Embedded Systems*.

It contains a subset of built-in dpdl functions and modules.

The functionalities to <ins>create</ins> DpdlPackets are not included here.

Also the *Dpdl language plug-ins* eventually included in this type of setup are <ins>specifically targeted for small *Embedded Systems*</ins>.

**Total size** of the '*DpdlEngine*' for this profile is: <ins>**`80 Kb`** or even less</ins>


#### Example setup of DpdlEngine 'Compact' with included <ins>lightweight</ins> version of *Dpdl language plug-ins*

The *Dpdl language plug-ins* included in this type of setup are also <ins>specifically targeted for small *Embedded Systems*</ins>. 

In this example there are 3 <ins>*Dpdl language plug-ins* **included**</ins>, for:

- **C** (*interpreted & compiled*)
- **MicroPython**
- **Micro JavaScript** (*ES5*)

**TOTAL size** of this profile, '*DpdlEngine*' <ins>including</ins> *Dpdl language plug-ins*: **`686 Kb`** 

| Platform | Component | Size |
| ---  | --- | --- | 
|Linux x86_64 |	| **Total size:** **`686 Kb`** |
|	| **DpdlEngine core** (*Compact*) | 80 Kb |
|	| *Dpdl language plug-in* for **C** (interpreted & compiled)  | 284 Kb |
|	| *Dpdl language plug-in* for **MicroPython**  | 170 Kb |
|	| *Dpdl language plug-in* for **Micro JavaScript** (*ES5*) | 152 Kb |

**Note:** also <ins>other Dpdl language plug-ins might be added</ins> if needed


### 'Full' profile

This profile is targeted to medium size *Embedded Systems*, and everything above (desktop, server, etc..)

It contains the full set of built-in dpdl functions and modules. It includes also the full functionalities to <ins>create</ins>, <ins>handle</ins> and <ins>query</ins> '**DpdlPackets**'

The extended version of *Dpdl language plug-ins* are usually included in this kind of profile. 

**Total size** of the '*DpdlEngine*' for this profile is: <ins>**`372 Kb`**</ins>


#### Example setup of DpdlEngine 'Full' with included <ins>extended</ins> version of *Dpdl language plug-ins*

In this example there are 3 <ins>*Dpdl language plug-ins* **included**</ins>, in its <ins>Extended version</ins>, for:

- **C** (*interpreted & compiled*)
- **Python**
- **JavaScript** (*ES2025*)


| Platform | Component | Size |
| ---  | --- | --- | 
|Linux x86_64 |	| **Total size:** 5,1 Mb |
|	| **DpdlEngine core** (*Full*) | 372 Kb |
|	| *Dpdl language plug-in* for **C** (interpreted & compiled)  | 284 Kb |
|	| *Dpdl language plug-in* for **Python**  | 2551 Kb |
|	| *Dpdl language plug-in* for **JavaScript** (*ES2025*) | 1924 Kb |

**Note:** also <ins>other Dpdl language plug-ins might be added</ins> if needed


