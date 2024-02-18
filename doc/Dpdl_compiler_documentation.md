# Dpdl compiler documentation


## Dpdl compiler C (TCC)


C code embedded within Dpdl scripts can be dynamically compiled in memory at runtime (see execution Mode 2)

The C compiler used and executed in form of a Dpdl language plugin is Fabric Bellard's TCC.

### Compiler options

The Dpdl runtime can be parameterized by pushing the corresponding option settings onto the Dpdl stack via the 
function **`dpdl_stack_push(..)`**. The options need to be prefixed with 'dpdl:'

For the embedding of C code the following option settings are available.


#### Option settings

**`dpdl:compile`**

Instructs the Dpdl runtime to compile in memory the embedded C code before executing it (execution Mode 2)

**`dpdl:-I$Path`**

Adds the specified include path reachable by the compiler

**`dpdl:-L$Path`**

Adds the specified library path reachable by the compiler and linker

**`dpdl:-l$lib`**

Adds the specified library for the linker

**`dpdl:-D$sym[=val]`**

Defines the preprocessor symbol '$sym' and optionally an associated value. If 'val' in not defined, it defaults to 1.

Function like macros can also be defined, e.g **`dpdl:-DF(a)=a+1`**

**`dpdl:$option**

Any other option supported by the compiler can be passed using the prefix 'dpdl:'







