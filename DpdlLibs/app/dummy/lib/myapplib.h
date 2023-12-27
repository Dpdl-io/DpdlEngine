# File: app/dummy/lib/myapplib.h
#
# Example: Small sample Dpdl dummy app to test some features
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct Data {
	int id
	int len
	string data
}

func printVersion()
	println("myapplib version: " + version__)
end

# main
string version__ = "2.0"
println("myapplib init()")
