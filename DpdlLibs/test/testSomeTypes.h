# File: test/testSomeTypes.h
#
# Example: Sample Dpdl script with 'char'
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myData {
	int x = 23
	string id = "my id 888"
	char c = '$'

	func print()
		println("c: " + c)
	end

	func append(char v)
		string s1 = "" + c + "_" + v
		println("s1: " + s1)
	end
}

struct myDataNum {
	short s1n = 23s
	short s2n = 11s
	short s3n = 9s

	func printNum(short xyz)
		println("s1n: " + s1n + " s2n: " + s2n + " s3n: " + s3n)
		println("xyz: " + xyz)
	end
}

func myfunc(char ch) char
	println("myfunc")
	println("my character: " + ch + " is of type: " + typeof(ch))

	char ret = 'Y'
	return ret
end

func myfunc2(short val) short
	println("myfunc2 val: " + val)
	short mys_val = 23s
	return mys_val
end


# main
println("testing types...")

char c = 'a'
println("my char: " + c)

object str = new("String", "Dpdl_o")
println("str: " + str)

char c_old = 'o'
char c_new = 'N'
object new_str = str.replace(c_old, c_new)
println("new_str: " + new_str)

char c1, c2

println("c1: " + c1)
println("c2: " + c2)

c1 = 'a'
c2 = 'b'

println("c1: " + c1)
println("c2: " + c2)

char myx = 'X'
char my_c_ret = myfunc(myx)
println("my_c_ret: " + my_c_ret)

struct myData d
println("d: " + d)
d.print()
d.append('z')

char mc = 'p'
arr[] = ["mega", 1, 0.1, 0x03B, mc]
println("arr: " + arr)
println("arr[4]: " + arr[4])

char nc = 'b'

object char_class = getObj("Character")
int nc_val = char_class.getNumericValue(nc)

println("nc: " + nc)
println("nc_val: " + nc_val)

short s = 100s

println("s: " + s + " is of type: " + typeof(s))

short mys = myfunc2(s)
println("mys: " + mys)

short s1 = 20s
short s2 = 10s
short sres = s1 + s2
println("+ sres: " + sres)

sres = s1 - s2
println("- sres: " + sres)

sres = s1 * s2
println("* sres: " + sres)

sres = s1 / s2
println("/ sres: " + sres)

object so = new("Short", "10")
println("so: " + so)

struct myDataNum num
println("num: " + num)

short ss = 111s
println("ss: " + ss)

short *pss = &ss

println("pss: " + *pss)

println("changing...")

ss = 1111s

println("pss: " + *pss)

double res_pow = s1^s2
println("res pow: " + res_pow + " type: " + typeof(res_pow))

float f1 = 0.3
float f2 = 0.6
double res_f = f1^f2
println("res_f: " + res_f)

object res_of = f1^f2
println("res_of: " + res_of + " type: " + typeof(res_of))

int myi = 99999
object myio = myi
println("myio: " + myio + " type: " + typeof(myio))

int new_i = myi * myio
println("new_i: " + new_i)

