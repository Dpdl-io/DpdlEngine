# File: test/testStructThread.h
#
# Example: Test Dpdl script with structs
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myStruct {
	int x = 10
	float f = 0.1
	double d = 0.3d
	long l = 1000L
	byte b = 0x01B
	string s = "Test"
	arr[] = "1, 2, 3, 4, 5"
}

func myThread()
	println("a.x: " + a.x)
	println("a.f: " + a.f)
	println("a.d: " + a.d)
	println("a.l: " + a.l)
	println("a.b: " + a.b)
	println("a.s: " + a.s)

	a.x = a.x + 1
	a.f = a.f + 0.1
	a.d = a.d + 10.0d
	a.l = a.l + 5L
	a.s = "Test thread " + a.x

	println("------------------------")
end

# main
println("This is a test for structs with Threads")

struct myStruct a

int tId = Thread("myThread", 1000)

raise(tId, "Error in starting thread")

println("thread started successfully")

