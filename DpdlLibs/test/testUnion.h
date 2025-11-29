# File: test/testUnion.h
#
# Example: Dpdl code that makes use of the dpdl type 'union'
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myS {
	int id
	string desc
}

union myU {
	float u, w
}

union myData {
	int x, y
	float z
	struct myS s
}

union myData data

data.x = 100

println("data: " + data)

