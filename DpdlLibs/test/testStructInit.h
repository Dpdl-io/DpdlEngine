# File: test/testStructInit.h
#
# Example: Sample Dpdl script that shows how to initialize 'struct' member variables upon declaration
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct InA {
	int val
}

struct A {
	int id
	float x, y
	string str
	object data
	struct InA ia
}

object d = new("String", "some test data")

struct InA myina
myina.val = 888

# initialize with given values

struct A mya = {23, 0.3, 0.6, "Test", d, myina}

println("mya: " + mya)
println("")

println("finished")
