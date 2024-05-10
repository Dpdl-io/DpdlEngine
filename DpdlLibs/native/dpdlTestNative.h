# File: native/dpdlTestNative.h
#
# Example: Dpdl sample code that loads and calls native library (libc) functions
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

