# File: myModule.h
#
# Example: This Dpdl script is loaded in the script dpdl_overview.h
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
int value = 0

func myModule(int i)
	println("init myModule()")
	value = i
end

func printHello()
	println("printHello val: " + value)
end

return 1

