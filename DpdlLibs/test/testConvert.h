# File: test/testConvert.h
#
# Example: Sample Dpdl script that converts types
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing convert types...")

int i = 1000
float f = 999.3
double d = 2000000.5d

int fint = to_int(f)
int dint = to_int(d)
println("fi: " + fint)
println("di: " + dint)

float ifloat = to_float(i)
float dfloat = to_float(d)
println("ifloat: " + ifloat)
println("dfloat: " + dfloat)

double idouble = to_double(i)
double fdouble = to_double(f)
println("idouble: " + idouble)
println("fdouble: " + fdouble)

string sint = "1000"
string sfloat = "0.23"
string sdouble = "99999999.9"

int si = convert("int", sint)
float sf = convert("float", sfloat)
double sd = convert("double", sdouble)

println("si: " + si)
println("sf: " + sf)
println("sd: " + sd)

println("finished")

