# File: test/testTypeDef.h
#
# Example: Sample Dpdl code that make use of 'typedef' specifier
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

typedef byte i8
typedef int i32
typedef float f32


func myTest(i8 val, i32 x, i32 y, f32 z) float
	float ret = to_float(x * y)

	ret = ret+z

	return ret
end


# main

i8 myval = 0x03B
i32 myx = 100
i32 myy = 200

f32 myz = 0.23

println("myval: " + myval)
println("myx: " + myx)
println("myy: " + myy)

println("calling function...")

float res = myTest(myval, myx, myy, myz)

println("res: " + res)
