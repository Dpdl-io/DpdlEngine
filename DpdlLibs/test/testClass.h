# File: test/testClass.h
#
# Example: Sample Dpdl script with 'class' type
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myStruct {
	string s_id = "mystruct"
	int val = 23
}

class BaseA {
	string id = "baseA"

	func printBase()
		println("my base A")
	end

	func setId(string newid)
		id = newid
	end
}

class A {
	int id = 1
	string s = "A"

	struct myStruct data

	func A(int x)
		id = x
	end

	func myFunc()
		println("an A class function with id: " + id)
		println("data: " + data)
	end
}


# main
println("testing class...")


string tmp = "mega"

class A a
class BaseA base

println("base: " + base)

base.setId("new baseA")

println("base: " + base)

println("calling class functions...")

a.myFunc()
base.printBase()

println("testing class pointers...")

object myobjA = a

object *myobjA_p = &a

println("myobjA: " + myobjA)

println("myobjA_p: " + *myobjA_p)

class A aa

a = base

println("a: " + a)

class A newa
newa.s = "a new S"

a = newa

println("myobjA_p: " + *myobjA_p)

class A newa_n

newa_n.myFunc()

var *newa_n_p = &newa_n

println("*newa_n_p.s: " + *newa_n_p)

println("finished!")
