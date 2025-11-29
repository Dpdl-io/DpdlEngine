# File: test/testUnion2.h
#
# Example: Dpdl code that converts a dpdl type 'union' to the corresponding native C/C++ 'union' type which
#			can be passed to native library functions
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

union myU1 {
	int x, y, z
}

union myU2 : myU1 {
	int r
	int i
	char a, b, c
	int x = 5555
}

println("testing union type...")

union myU1 u1

u1.x = 888

println("u1: " + u1)

union myU2 u2

u2.a = 'A'

println("u2: " + u2)


println("generating a compatible C/C++ structure that can be passed to native library functions...")

object u2C = genObjCodeC(u2)

println("u2C: " + u2C + " is of type: " + typeof(u2C))

println("u2C.x: " + u2C.x)

println("this union: " + u2C + " can now be passed to a native function by reference or by value")
