# File: test/testArrayType.h
#
# Example: Test Dpdl script with primitive type arrays
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing primitive type arrays...")

println("testing 'int' array type:")

int myarri[6]

myarri[0] = 23
myarri[1] = 34
myarri[2] = 45

println("myarri: " + myarri + " is of type: " + typeof(myarri))

println("myarri[0]=" + myarri[0])
println("myarri[1]=" + myarri[1])
println("myarri[2]=" + myarri[2])

int myarrii[] = {233, 344, 455}

println("myarrii: " + myarrii + " is of type: " + typeof(myarrii))

println("myarrii[0]=" + myarrii[0])
println("myarrii[1]=" + myarrii[1])
println("myarrii[2]=" + myarrii[2])


println("")
println("testing 'float' array type:")

float myarrf[6]

myarrf1[0] = 0.1
myarrf[1] = 0.2
myarrf[2] = 0.3

println("myarrf: " + myarrf + " is of type: " + typeof(myarrf))

println("myarrf[0]=" + myarrf[0])
println("myarrf[1]=" + myarrf[1])
println("myarrf[2]=" + myarrf[2])

float myarrfi[] = {3.0, 6.0, 9.0}


println("myarrfi: " + myarrfi + " is of type: " + typeof(myarrfi))

println("myarrfi[0]=" + myarrfi[0])
println("myarrfi[1]=" + myarrfi[1])
println("myarrfi[2]=" + myarrfi[2])


println("")
println("testing 'byte' array type:")

byte myarrb[6]

myarrb[0] = 3B
myarrb[1] = 6B
myarrb[2] = 9B

println("myarrb: " + myarrb + " is of type: " + typeof(myarrb))

println("myarrb[0]=" + myarrb[0])
println("myarrb[1]=" + myarrb[1])
println("myarrb[2]=" + myarrb[2])

byte myarrbi[] = {0x03B, 0x06B, 0x09B}

println("myarrbi: " + myarrbi + " is of type: " + typeof(myarrbi))

println("myarrbi[0]=" + myarrbi[0])
println("myarrbi[1]=" + myarrbi[1])
println("myarrbi[2]=" + myarrbi[2])



