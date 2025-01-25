# File: test/testStruct3.h
#
# Example: Test Dpdl script with structs that make use of inheritance
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myA {
	int id
	string desc

	func printBase()
		println("some base info")
	end

	func printIt()
		println("myA -> id: " + id + " desc: " + desc)
	end
}

struct myB : myA {
	int x = 3
	int y = 4
	int z = 9

	func printIt()
		println("myB -> id: " + id + " desc: " + desc)
	end
}


# main

println("testing struct type with inheritance...")
println("")

struct myB b

println("b: " + b)
b.printBase()
b.printIt()

b.id = 888
b.desc = "my description Test"

println("b: " + b)

b.printIt()

println("b.x: " + b.x)
println("b.y: " + b.y)

println("---------------------")

struct myB b1 = {23, 69, 85}

# here we initialize only y

struct myB b2 = {.,6,.}

println("b1: " + b1)
println("b2: " + b2)
