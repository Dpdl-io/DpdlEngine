# File: test/testArray.h
#
# Example: Test Dpdl script with load another dpdl script as object
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myA {
	string id = "this is an A"
	int y = 23
}

# main
struct myA mya

object myload = loadCode("test/MyLC.h")
myload.myFunc("MyLC")
println("s: " + myload.s)
println("x: " + myload.x)
println("mystr: " + myload.mystr)

myload.s = "assigning a new str"
println("s: " + myload.s)

object mynewstr = new("String", "This is my NEW str")
myload.mystr = mynewstr
println("NEW mystr: " + myload.mystr)

println("printing myA a struct...")
myload.myFuncStructPrint("MyLC", mya)

int c = 0
setStartTime()
for(c < 100)
	println(myload.s + " " + c)
	c = c+1
endfor
int ms = getEndTime()
println("exec time ms: " + ms)

int status = myload.myNativeFunc("MyLC")
println("native func stauts: " + status)

mya = myload.myFuncStructMod("MyLC", mya)
println("myanew: " + mya)
println("mya.id: " + mya.id)
println("mya.y: " + mya.y)
