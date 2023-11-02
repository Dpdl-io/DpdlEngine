# File: testRaiseException.h
#
# Example: This example shows the use of 'raise(..)' to handle exceptions
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

println("testing str raise(..)")
println("")

string s1 = "nul(l)"
raise(s1, "s1 is null")

println("testing int raise")
int i = 1
raise(i, "i == -1")

println("testing bool raise")
bool b = true
raise(b, "b == false")

println("testing object raise")
object o = loadObj("String", "test")
raise(o, "o == null")

println("testing bool expression raise")
raise(o =! null, "o =! null")

dpdl_print_exception_table()

println("done")