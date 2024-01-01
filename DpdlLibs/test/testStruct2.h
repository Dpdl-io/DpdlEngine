# File: test/testStruct.h
#
# Example: Test Dpdl script with structs
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myprint(var v)
	println("myprint()->" + v)
end

struct A {
	string id = "A"
	int x = 10
	int y = 20

	func print()
		println("---------------")
		println("id: " + id)
		println("x: " + x)
		println("y: " + y)
		println("---------------")
	end
}

struct B {
	string id = "B"
	int x = 99
	int y = 999
	struct A mya

	myprint(x + mya.x)

	func setId()
		println("setId()")
		id = "B new id"
		println("id: " + id)
		return 1
	end

	func getA()
		return mya
	end

	func print()
		println("---------------")
		println("id: " + id)
		println("x: " + x)
		println("y: " + y)
		println("---------------")
	end

}

# main
println("testStruct2...")
struct B myb
println("myb: " + myb)

println("calling func...")
myb.print()
myb.setId()
println("myb: " + myb)
println("id: " + myb.id)

object myst = myb.getA()
println("myst: " + myst + " type: " + typeof(myst))
myst.print()



