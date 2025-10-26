# File: test/testClassConstructor.h
#
# Example: Sample Dpdl script that shows how to initialize a 'class' type with constructor, and without constructor
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


class A {

	int id
	string str
	object obj = null

	func A(int id_, string str_, object obj_)
		id = id_
		str = str_
		obj = obj_
	end

	func print()
		println("id: " + id)
		println("str: " + str)
		println("obj: " + obj)
	end
}

# main

println("testing class constructor...")
println("")

println("initialization with constructor:")

object so = new("String", "MEGA")

class A mya(23, "a Test is this", so)

println("mya.id: " + mya.id)
println("mya.str: " + mya.str)
println("mya.obj: " + mya.obj)

println("")
println("initialization without constructor:")

class A ana

ana.print()


