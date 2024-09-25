# File: benchmarks/testString.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple test that loads and accesses a jre 'String' class
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing access to jre String class...")

object mystr = loadObj("String", "This is a test")

int len = mystr.length()

println("mystr: " + mystr + " len: " + len)

println("converting to uppercase....")

string upperstr = mystr.toUpperCase()

println("upper case: " + upperstr)

setStartTime()

int c
for(c < 1000000)
	println("msg: " + upperstr + " c: " + c)
	c=c+1
endfor

int ms = getEndTime()

println("")
println("exec time (ms): " + ms)
println("")

println("finished")
