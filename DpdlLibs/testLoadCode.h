# File: testLoadCode.h
#
# Example: This example shows how to load a Dpdl script object via loadCode(..) and call one of its functions
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

# main
println("test loadCode(..) with dpdl script LoadCodeFunc.h")

object mycode = loadCode("LoadCodeFunc.h", "myparam")

string mystr1 = "Test"
object mystr2 = new("String", "MEGA")

mycode.testFunc("LoadCodeFunc", mystr1, mystr2)

println("done")
