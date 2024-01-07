# File: test/testStruct2.h
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
	myarr[] = [1, 2, 3, 4]

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
	struct A mya2

	myprint(x + mya.x)

	func setId()
		println("setId()")
		id = "B new id"
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

	func reassign()
		mya.x = 1000
		mya.y = 2000
		mya2.x = 1
		mya2.y = 2
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

println("####################")

println("myb.mya: " + myb.mya)
println("myb.mya2: " + myb.mya2)
println("reassing....")
myb.reassign()
println("myb.mya: " + myb.mya)
println("myb.mya2: " + myb.mya2)

struct B *ptrb
*ptrb = &myb
println("*ptrb: " + *ptrb)
myb.x = 999999999
println("*ptrb: " + *ptrb)







