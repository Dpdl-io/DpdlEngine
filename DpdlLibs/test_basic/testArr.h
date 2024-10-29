#
# www.dpdl.io
# (c) 2023 SEE Solutions
#
# file: test_basic/testArr.h
#
#

println("basic test array...")

myarr[] = [1, 2, 3, 4, 5, 6, "a", "b", "c", "d", "e", "f", 0.3, 1.369, 2.48]

println("myarr: ")
int c
for(c < myarr.size())
	println("myarr[" + c + "]=" + myarr[c] + " is of type: " + typeof(myarr[c]))
	c=c+1
endfor
println("")

println("finished")
