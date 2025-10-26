# File: testDpdlStruct.h
#
# Example: This Dpdl script shows how to use the type 'struct'
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
	string s = "A"
	object so = new("String", "my java obj A")
	myPrint(s)

	func thisAFunc()
		println("thisAFunc: " + s + " so: " + so)
		return 23
	end

}

struct B {
	int x = 2
	string s = "B"
	myPrint(s)
}

# main
println("testing struct...")
struct A a
println("a: " + a)

struct B b
println("b: " + b)

int res = a.x + b.x
println("A.x + B.x = " + res)
println("A.so:" + a.so)

println("calling A.thisAFunc()")
int x = a.thisAFunc()
println("ret val: " + x)

println("initializing an array with a struct...")
my_arr[] = array(a)
println("my_arr: " + my_arr)
int size = my_arr.size()
println("size: " + size)
my_arr[size] = array(b)
my_new_arr[] = my_arr
println("my_new_arr: " + my_new_arr)
size = my_new_arr.size()
println("size: " + size)
println("last element: " + my_new_arr[size-1])

