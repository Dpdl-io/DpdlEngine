# File: native/dpdlTestNative.h
#
# Example: Dpdl sample code that loads and calls functions from a native library (libc)
#			By loading 'c' Dpdl automatically selects the appropriate lib, on Linux/Unix/MAC 'libc' and on Windows 'msvcrt'
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

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

int page_size = libc.getpagesize()
println("page_size: " + page_size)

println("")
println("setting and getting an environment variable...")

string new_env = "MY_env"

int stat = libc.setenv(new_env, "this is env MEGA", 1)
println("status: " + stat)

println("getting env variable 'MY_env'...")

string new_env_val = libc.getenv("MY_env")
println("env value: " + new_env_val)
println("")

println("testing malloc...")

object ptr = libc.malloc(1024)

ptr.setMemory(0L, 1024L, 0x00B)
libc.free(ptr)

println("done")
println("")

println("testing file access...")

object fcntl = getObj("Fcntl")

int fh = libc.open("./Test/TestWrite.txt", fcntl.O_RDWR)

raise(fh, "Error in opening file")

string mydata_str = "this is the content MEGA I write to my file"

object ptrstr = libc.malloc(1024)
ptrstr.setString(0L, mydata_str, "utf-8")

object sz = new("size_t")
sz.setValue(strlen(mydata_str))
println("data size: " + sz)

sz = libc.write(fh, ptrstr, sz)

println("data size written: " + sz)
println("")

println("testing memory copy...")

string mymem_data = "my data string to copy: MEGA"

object char_src = libc.malloc(1024)
char_src.setString(0L, mymem_data)

println("char_src is of type: " + typeof(char_src))

object char_dest = libc.malloc(1024)
char_dest.setMemory(0L, 1024L, 0x00B)

println("char_dest is of type: " + typeof(char_src))

object size = new("size_t")
size.setValue(1024L)
int comp = libc.memcmp(char_src, char_dest, size)
if(comp > 0)
	println("'*char_dest' is less than *char_src")
fi

object ptr_dest = new("PointerByReference")
ptr_dest.setValue(char_dest)
object ptr_content = ptr_dest.getValue()

println("before copy memory is: " + ptr_content.getString(0L))

println("copying from source buffer...")

object szm = new("size_t")
szm.setValue(1024L)

object p = libc.memcpy(char_dest, char_src, szm)

println("after copy memory is: " + ptr_content.getString(0L))

comp = libc.memcmp(char_src, char_dest, size)
if(comp == 0)
	println("'*char_dest' and '*char_src' now are EQUAL")
fi

println("")
println("done")

