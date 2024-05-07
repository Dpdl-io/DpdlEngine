# File: test/testChar.h
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

func myfunc(char ch) char
	println("myfunc")
	println("my character: " + ch + " is of type: " + typeof(ch))

	char ret = 'Y'
	return ret
end


# main
println("testing types...")

char c = 'a'
println("my char: " + c)

object str = loadObj("String", "Dpdl_o")
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
arr[] = ["mega", 1, 0.1, 0x03, mc]
println("arr: " + arr)
println("arr[4]: " + arr[4])

char nc = 'b'

object char_class = getClass("Character")
int nc_val = char_class.getNumericValue(nc)

println("nc: " + nc)
println("nc_val: " + nc_val)

