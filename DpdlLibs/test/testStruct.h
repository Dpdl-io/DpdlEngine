# File: test/testStruct.h
#
# Example: Test Dpdl script for structs
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myPrint(string str)
	println("myPrint: " + str)
end

struct A {
	int x = 1
	int y = 2
	string s = "A"
	object so = loadObj("String", "my java obj A")
	myPrint(s)

	func thisAFunc()
		println("thisAFunc: " + s + " so: " + so)
		return 23
	end
}

func retStruct(var i, var j)
	println("i: " + i + " type: " + typeof(i))
	println("j: " + j + " type: " + typeof(j))
	println("summing...")
	struct A ret
	ret.x = i.x + j.x
	ret.y = i.y + j.y
	ret.s = i.s + j.s
	ret.so = i.so + " * " + j.so

	return ret
end

func passStruct(struct i)
	println("passed struct: " + i)
end

# main
println("testing struct...")

struct A a
println("a: " + a)
struct A b
println("b: " + b)
b.x = 10
b.y = 20

println("a: " + a)
println("b: " + b)
var sum = retStruct(a, b)
println("sum: " + sum)
passStruct(sum)

