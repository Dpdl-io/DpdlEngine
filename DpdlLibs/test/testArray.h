# File: test/testArray.h
#
# Example: Test Dpdl script with primitive and dynamic arrays
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
println("testing arrays..")
println("")

println("primitive array test:")

int myarri[6]
float myarrf[6]

int inp[] = {3, 6, 9}
float inp2[] = {3.0, 6.0, 9.0}

myarri[0] = inp[0]
myarri[1] = inp[1]
myarri[2] = inp[2]

myarrf[0] = inp2[0]
myarrf[1] = inp2[1]
myarrf[2] = inp2[2]
myarrf[3] = 999.9
myarrf[4] = 1000.9
myarrf[5] = 2000.9

int c
for(c < 6)
	println("myarri[" + c + "]=" + myarri[c])
	println("myarrf[" + c + "]=" + myarrf[c])
	c=c+1
endfor


println("dynamic array test:")
println("")

struct A a

testarr[] = "1, 2, 3, 4"
testarr[0] = a
println("testarr: " + testarr)
subarr[] = array(testarr[0])
println("subarr: " + subarr)

object arrobj = testarr.getArrObj()

object it = arrobj.iterator()

while(it.hasNext())
	println("elem: " + it.next())
endwhile

println("----------------------------")

object subarrobj = subarr.getArrObj()
object its = subarrobj.iterator()
while(its.hasNext())
	println("elem: " + its.next())
endwhile

arr_new[] = array("test")
println("arr_new: " + arr_new)

arr_new2[] = array(subarr)
println("arr_new2: " + arr_new2)
testProc()

println("----------------------------")

testarr2[] = [1, 0.3, 23.0d, 1000L, 0x09B, "mega"]
println("testarr2: " + testarr2)

object arrobj2 = testarr2.getArrObj()

object it2 = arrobj2.iterator()

while(it2.hasNext())
	println("elem2: " + it2.next())
endwhile

