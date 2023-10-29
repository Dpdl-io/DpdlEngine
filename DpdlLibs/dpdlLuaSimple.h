# File: dpdlLuaSimple.h
#
# Example: 
# This Dpdl script executes an embedded 'lua' script
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedding lua....")

>>lua
io.write("TEST ")
print()
<<

int exit_code = dpdl_exit_code()

println("embedded lua exit code: " + exit_code)


