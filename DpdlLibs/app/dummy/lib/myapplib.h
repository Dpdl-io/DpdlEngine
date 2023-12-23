# File: app/dummy/lib/myapplib.h
#
# Example: Small sample Dpdl dummy app to test some features
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

string version__ = "2.0"

func printVersion()
	println("myapplib version: " + version__)
end

# main
println("myapplib init()")
