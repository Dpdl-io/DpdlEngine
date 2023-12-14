# File: test/testArray.h
#
# Example: Test Dpdl script with arrays
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct A {
	string s = "A"
	int x = 10
	var v = 1.0
}

func testProc()
	arr[] = "a, b, c, d"
	println("testProc->arr: " + arr)
end

# main
struct A a

testarr[] = "1, 2, 3, 4"
testarr[0] = a
println("testarr: " + testarr)
subarr[] = array(testarr[0])
println("subarr: " + subarr)

object arrobj = testarr.getObj()

object it = arrobj.iterator()

while(it.hasNext())
	println("elem: " + it.next())
endwhile

println("----------------------------")

object subarrobj = subarr.getObj()
object it2 = subarrobj.iterator()
while(it2.hasNext())
	println("elem: " + it2.next())
endwhile

arr_new[] = array("test")
println("arr_new: " + arr_new)

arr_new2[] = array(subarr)
println("arr_new2: " + arr_new2)
testProc()


