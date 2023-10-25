# File: dpdlPointers.h
#
# Example: This Dpdl script shows how to use pointers and references
#
# Author: AC
# e-mail: info@dpdl.io
#
#

# function with pointers
func myFuncPtr(object *testp, string *sp, int *xp)
	*sp = *testp + " " + *sp + " " + "TIE"
	*xp = 369
end

func printVarAndPtr()
	println("test_obj: " + test_obj)
	println("s: " + s)
	println("x: " + x)
	println("testp: " + *testp)
	println("sp: " + *sp)
	println("xp: " + *xp)
	println("")
end

# main
println("testing pointers...")
println("")

# variables
object test_obj = loadObj("String", "MEGA")
string s = "mega"
int x = 10
int z = 3

# pointers
object *testp = &test_obj
int *xp = &x
string *sp = &s

printVarAndPtr()

println("changing vars....")
s = "metatie"
x = 100

printVarAndPtr()


println("call myFuncPtr(..)")
println("")
myFuncPtr(testp, sp, xp)
println("Value changed: " + *sp)
println("Value changed: " + *xp)

float f = 1.0
double d = 2.0d
object str = loadObj("String", "TestPtr")

println("assign pointers...")
println("")
float *fp = &f
double *dp = &d
object *str_p = &str

println("*fp: " + *fp)
println("*dp:" + *dp)
println("*str_p: " + *str_p)

println("done")