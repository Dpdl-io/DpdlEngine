# File: test/testStruct4.h
#
# Example: Test dpdl code with 'struct' type that make use of inheritance and a type definition
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


println("example with 'struct' type")

struct Coords {
	int x
	int y
	float z
}

typedef struct MyStruct : Coords {
	string id
	string data
} Point;


object point = new Point{"someID", "some Data"}

point.x = 100
point.y = 200
point.z = -23.3f

println("my Point: " + point)


println("and still also in this way...)

struct MyStruct myst = {"myID", "some data", ., ., .}

myst.x = 10
myst.y = 20
myst.z = 23.3f

println("myst: " + myst)
