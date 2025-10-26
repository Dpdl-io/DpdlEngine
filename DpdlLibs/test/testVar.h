# File: test/testVar.h
#
# Example: Test Dpdl script with variables
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct aStr {
	string ct = "this is a struct"
	int val = 999
}

func testFuncRetStr() string
	return "mystr"
end

func testFuncRetInt() int
	return 23
end

func testFuncRetFloat() float
	return 0.22
end

func testFuncRetDouble() double
	return 232323.0d
end

func testFuncRetLong() long
	return 1000000000000L
end

func testFuncRetObj() object
	object stro = new("String", "myteststr")
	return stro
end

func testFuncRetVar()
	var tmpv = convert("float", 10) + 0.2
	return tmpv
end

func testFuncRetStruct()
	struct aStr tmpstr
	return tmpstr
end

println("testing variable and function return types")
println("")

println("testing string...")

string s = testFuncRetStr()
object os = testFuncRetStr()
var vs = testFuncRetStr()
println("s: " + s)
println("o: " + os)
println("vs: " + vs + " type: " + typeof(vs))
var sd = cast(s)
println("sd: " + sd + " type: " + typeof(sd))
println("")

println("testing int...")

int i = testFuncRetInt()
object oi = testFuncRetInt()
var vi = testFuncRetInt()
println("i: " + i)
println("oi: " + oi)
println("vi: " + vi + " type: " + typeof(vi))
println("")

println("testing float...")

float f = testFuncRetFloat()
var vf = testFuncRetFloat()
object of = testFuncRetFloat()
println("f: " + f)
println("of: " + of)
println("vf: " + vf + " type: " + typeof(vf))
println("")

println("testing double...")

double d = testFuncRetDouble()
var vd = testFuncRetDouble()
object od = testFuncRetDouble()
println("d: " + d)
println("od: " + od)
println("vd: " + vd + " type: " + typeof(vd))
println("")

println("testing long...")

long l = testFuncRetLong()
object ol = testFuncRetLong()
var vl = testFuncRetLong()
println("l: " + l)
println("ol: " + ol)
println("vl: " + vl + " type: " + typeof(vl))
println("")

println("testing object...")

object oss = testFuncRetObj()
var vos = testFuncRetObj()
println("os: " + oss + " type: " + typeof(oss))
println("vos: " + vos + " type: " + typeof(vos))
println("")

println("testing var...")

object ov = testFuncRetVar()
var vov = testFuncRetVar()
println("ov: " + ov + " type: " + typeof(ov))
println("vov: " + vov + " type: " + typeof(vov))
println("")

println("testing struct...")

struct aStr u
u = testFuncRetStruct()
object ou = testFuncRetStruct()
var vu = testFuncRetStruct()
println("u: " + u + " type-> " + typeof(u))
println("ou: " + ou + " type-> " + typeof(ou))
println("vu: " + vu + " type-> " + typeof(vu))
println("")
