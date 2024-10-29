#
# www.dpdl.io
# (c) 2023 SEE Solutions
#
# file: test_basic/testString.h
#
#

println("basic test java String....")

object mystr = loadObj("String", "This is a test")

int len = mystr.length()

println("mystr: " + mystr + " len: " + len)

println("converting to uppercase....")

string upperstr = mystr.toUpperCase()

println("upper case: " + upperstr)

int c
for(c < 1000)
	println("msg: " + upperstr + " c: " + c)
	c=c+1
endfor
println("")

println("finished")
