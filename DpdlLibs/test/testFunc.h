# File: test/testFunc.h
#
# Example: Test Dpdl script with functions
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myA {
	int x = 23
}

func myFunc(string s, var v, int i, float f, double d, long l, byte b, bool bo, object o, struct sa)
	println("s: " + s)
	println("v: " + v)
	println("i: " + i)
	println("f: " + f)
	println("d: " + d)
	println("l: " + l)
	println("b: " + b)
	println("bo: " + bo)
	println("o: " + o.toString())
	println("sa: " + sa)
	println("---------------------------")
end

func myFuncPtr(string *ps, var *v, int *i, float *f, double *d, long l, byte *b, bool bo, object *po, var *pa)
	println("*s: " + *ps)
	println("*pv: " + *pv)
	println("*pi: " + *pi)
	println("*pf: " + *pf)
	println("*pd: " + *pd)
	println("l: " + l)
	println("*pb: " + *pb)
	println("bo: " + bo)
	println("*po: " + *po)
	println("*pa: " + *pa + " type: " + typeof(*pa))
	println("---------------------------")
end

func myFuncVar(var a, var b, var c)
	println("a:" + a + " type: " + typeof(a))
	println("")
	println("b:" + a + " type: " + typeof(b))
	println("")
	println("c:" + c + " type: " + typeof(c))
	println("")
end


# main
println("testing func...")

string s = "test"
int i = 1
float f = 0.1
double d = 1.0d
long l = 10L
byte b = 0x01B
bool bo = true
var v = "This is a var"
object strobj = new("String", "my string obj")
struct myA a

println("calling function myFunc(..)...")

myFunc(s, v, i, f, d, l, b, bo, strobj, a)

println("direct parameters myFunc(..)...")

myFunc("test2", "This is a var2", 1, 0.1, 1.0d, 10L, 0x01B, true, strobj, a)

println("testing pointers...")

string *ps = &s
int *pi = &i
float *pf = &f
double *pd = &d
byte *pb = &b
var *pv = &v
object *po = &strobj
var *pa = &a

println("*ps: " + *ps)
println("*pi: " + *pi)
println("*pf: " + *pf)
println("*pd: " + *pd)
println("*pb: " + *pb)
println("*pv: " + *pv)
println("*po: " + *po)

println("calling function myFuncPtr(..)")

myFuncPtr(ps, pv, pi, pf, pd, 10L, pb, true, *po, *pa)

println("calling myFuncStruct(..)")
struct myA st
int cv = 11
struct myA st2
st2.x = 24

myFuncVar(st, cv, st2)

var av = "TEST"
var *pav = &av
println("*pav: " + *pav)
av = "MEGATEST"
println("*pav: " + *pav)

