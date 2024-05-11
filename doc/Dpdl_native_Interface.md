# Dpdl native Interface

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		

## Dpdl native Interface


Dpdl allows to access native library functions of any given loaded native library seamlessly, in the same way as ordinary dpdl functions.

This features makes Dpdl a complete and powerful programming language to develop also low level system components.

By loading 'c' (see example below), Dpdl automatically selects the appropriate library, on Linux/Unix/MAC 'libc' and on Windows 'msvcrt'.

On Windows systems it's possible also to access the system library 'kernel32' and it provides COM support.

Example Dpdl code accessing the system library 'libc' functions:
```python
import('native')

object libc = native.loadLib("c")

# main
println("testing native interface with 'libc'...")
println("")

int uid = libc.getuid()
println("uid: " + uid)

int gid = libc.getgid()
println("gid: " + gid)

string env_java = libc.getenv("JAVA_HOME")
println("env java: " + env_java)

println("setting and getting an environment variable...")

string new_env = "MY_env"
int stat = libc.setenv(new_env, "this is env MEGA", 1)
println("status: " + stat)

println("getting env variable 'MY_env'...")
string new_env_val = libc.getenv("MY_env")
println("env value: " + new_env_val)

int page_size = libc.getpagesize()
println("page_size: " + page_size)


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

println("done")
```

The native library to be loaded needs to be available on the default system path or it's path must be configured in the configuration file 'DpdlEngine.ini' via the 'DPDL_NATIVE_LIB_PATH' variable.

The default configuration for 'DPDL_NATIVE_LIB_PATH' is set to './lib/addon'


NOTE: The 'DpdlEngine lite' demo/shareware release allows to access only a limite number of functions.

The full registered version of 'DpdlEngine' has almost complete support for the native C library interface







