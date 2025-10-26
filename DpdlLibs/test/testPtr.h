# File: test/testPtr.h
#
# Example: Test Dpdl script with pointers
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct myStruct {
	int x = 23
	int y = 999
	string s = ""
}

func myFunc(string str, int x)
	println("myFunc()")
	println("")
	println("str: " + str)
	println("x: " + x)
	string *str_p = str
	int *x_p = x
	println("str_p: " + *str_p)
	println("x_p: " + *x_p)
	println("---------------------------")
end

func myFuncPtr(string str, int *i_p)
	println("myFuncPtr()")
	println("")
	string *str2_p = str
	println("str: " + str)
 	println("*str_p: " + *str2_p)
	println("x: " + *i_p)
end

func printStr(object *pstr)
	println("printStr *pstr: " + *pstr)
end

func printMap(object m)
	object keyset = m.keySet()
	object iter = keyset.iterator()
	object key, val
	while(iter.hasNext())
		key = iter.next()
		val = m.get(key)
		println("key: " + key + " val: " + val)
	endwhile
end

func printMapPtr(object *pmap)
	println("printMapPtr()")
	object keyset = *pmap.keySet()
	object iter = keyset.iterator()
	object key, val
	while(iter.hasNext())
		key = iter.next()
		val = *pmap.get(key)
		println("key: " + key + " val: " + val)
	endwhile
end

# main

println("testing pointers...")

string s = "my test message 1"
int i = 23

myFunc(&s, &i)

string *s_p = &s
int *i_p = &i
s = "my test message 2"

myFuncPtr(&s, i_p)

println("testing struct pointers...")
struct myStruct a
println(a)

a.s = "MEGA"
println(a)

struct myStruct *ap
*ap = &a
println(*ap)
a.s = "MEGATIE"
println(*ap)
var *avp = &a
println("*avp: " + *avp)
a.s = "MEGATIE var pointer to struct"
println("*avp: " + *avp)

println("testing object pointers...")

object str = new("String", "Test")
object *pstr = &str
println("str: " + str)
println("pstr: " + *pstr)

str = new("String", "Test2")

println("pstr: " + *pstr)
printStr(*pstr)


string sub = "t2"
string *psub = &sub
bool b = str.endsWith(*psub)
println("b: " + b)

b = *pstr.endsWith("t2")
println("b: " + b)

bool b2 = *pstr.endsWith(*psub)
println("b2: " + b2)

sub = "t_mod"
b2 = *pstr.endsWith(*psub)
println("test b2: " + b2)

println("######################################")

object map = new("HashMap")
map.put(1, "test1")
map.put(2, "test2")
map.put(3, "test3")

println("print HashMap...")
printMap(map)

map.put(4, "test4")

object *pmap = &map
printMapPtr(*pmap)


