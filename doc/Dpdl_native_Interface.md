# Dpdl native Interface

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		

## Dpdl native Interface


Dpdl allows to access native library functions of any given loaded native library seamlessly, in the same way as ordinary dpdl functions.

This features makes Dpdl a complete and powerful programming language to interact also with low level system components.

**Dpdl library:**

**`native`**

```python
loadLib(string lib_name) return object lib
mapLib(string lib_name, object obj) return object lib
```

Example:

```python
import('native')

object clib = loadLib("c")

clib.printf("This message comes from native print function: %s %d", "Hello, 23)
```

By loading the library 'c', Dpdl automatically selects the appropriate library, on Linux/Unix/MAC 'libc' and on Windows 'msvcrt'.

On Windows systems it's possible also to access the system library 'kernel32' and it provides COM support.


Example Dpdl code accessing the system library 'libc' functions:
```python
import('native')

object libc = native.loadLib("c")

println("testing native interface with 'libc'...")

int uid = libc.getuid()
println("uid: " + uid)

int gid = libc.getgid()
println("gid: " + gid)

string env_java = libc.getenv("JAVA_HOME")
println("env java: " + env_java)

int page_size = libc.getpagesize()
println("page_size: " + page_size)

println("setting and getting an environment variable...")

string new_env = "MY_env"

int stat = libc.setenv(new_env, "this is env MEGA", 1)
println("status: " + stat)

println("getting env variable 'MY_env'...")

string new_env_val = libc.getenv("MY_env")
println("env value: " + new_env_val)

println("testing malloc...")

object ptr = libc.malloc(1024)

ptr.setMemory(0L, 1024L, 0x00)
libc.free(ptr)

println("done")

println("testing file access...")

int fh = libc.open("./Test/TestWrite.txt", 1)

raise(fh, "Error in opening file")

string mydata_str = "this is the content MEGA I write to my file"

object sz = loadObj("size_t")
sz.setValue(24)
println("data size: " + sz)

sz = libc.write(fh, mydata_str, sz)

println("data size written: " + sz)

println("testing memory copy...")

string mymem_data = "my data string to copy: MEGA"

object char_src = libc.malloc(1024)
char_src.setString(0L, mymem_data)

println("char_src is of type: " + typeof(char_src))

object char_dest = libc.malloc(1024)
char_dest.setMemory(0L, 1024L, 0x00)

println("char_dest is of type: " + typeof(char_src))

object size = loadObj("size_t")
size.setValue(1024L)
int comp = libc.memcmp(char_src, char_dest, size)
if(comp > 0)
	println("'*char_dest' is less than char_src")
fi

object ptr_dest = loadObj("PointerByReference")
ptr_dest.setValue(char_dest)
object ptr_content = ptr_dest.getValue()

println("before copy memory is: " + ptr_content.getString(0L))

println("copying from source buffer...")

object szm = loadObj("size_t")
szm.setValue(1024L)

object p = libc.memcpy(char_dest, char_src, szm)

println("after copy memory is: " + ptr_content.getString(0L))

comp = libc.memcmp(char_src, char_dest, size)
if(comp == 0)
	println("'*char_dest' and '*char_src' are EQUAL")
fi

println("done")
```

### Configuration

#### DPDL_NATIVE_LIB_PATH

The native library to be loaded needs to be available on the default system path or it's path must be configured in the configuration file 'DpdlEngine.ini' via the 'DPDL_NATIVE_LIB_PATH' variable.

The default configuration for 'DPDL_NATIVE_LIB_PATH' is set to './lib/addon'

#### DPDL_NATIVE_CODE_PROTECTION

Dpdl provides built-in support for memory protection useful to avoid segmentation faults and unexpected crashes.

By default the protection is enabled, it can be disabled by setting the variable 'DPDL_NATIVE_CODE_PROTECTION' to 'false' in the
configuration file 'DpdlEngine.ini'


### Type mapping

The following tables lists the type mapping between C and Dpdl:

<table>
<thead><td>Dpdl type</td><td>Native type</td><td>Size</td><td>on Windows OS</td></thead>
<tr><td>char or byte</td><td>char</td><td>8-bit integer</td><td>BYTE, TCHAR</td></tr>
<tr><td>short</td><td>short</td><td>16-bit integer</td><td>WORD</td></tr>
<tr><td>char</td><td>wchar_t</td><td>16/32-bit character</td><td>TCHAR</td></tr>
<tr><td>int</td><td>int</td><td>32-bit integer</td><td>DWORD</td></tr>
<tr><td>bool</td><td>int</td><td>boolean value</td><td>BOOL</td></tr>
<tr><td>NativeLong (jna)</td><td>long</td><td>32/64-bit integer</td><td>LONG</td></tr>
<tr><td>long</td><td>long long</td><td>64-bit integer</td><td>__int64</td></tr>
<tr><td>float</td><td>float</td><td>32-bit FP</td><td></td></tr>
<tr><td>double</td><td>double</td><td>64-bit FP</td><td></td></tr>
<tr><td>string</td><td>char*</td><td>C string</td><td>LPCSTR</td></tr>
<tr><td>Pointer (jna)</td><td>void*</td><td>pointer</td><td>LPVOID, HANDLE, LP<i>XXX</i></td></tr>
</table>

Unsigned types have the same mappings as signed types

### API

Helper functions and platform specific features are available via the following API accessible with Dpdl:

[Dpdl JNA reference](https://www.dpdl.io/doc/dpdl_jna/javadoc/) 


### Note

The Dpdl native interface library is only available in the full registered version of 'DpdlEngine'.

A demo version with the 'native' library enabled can be requested for evaluation purposes by writing to: info@dpdl.io



