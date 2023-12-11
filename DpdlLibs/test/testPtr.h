# File: test/testPtr.h
#
# Example: Test Dpdl script for pointers
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

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
	println("str: " + str)
	println("x: " + *i_p)
end

# main

println("testing pointers...")

string s = "my test message"
int i = 23

myFunc(&s, &i)

string *s_p = &s
int *i_p = &i

myFuncPtr(&s, i_p)
