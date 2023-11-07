# File: dpdlJuliaExample.h
#
# Example: This Dpdl script executes a simple embedded Julia script
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Dpdl example executing embedded 'Julia'...")

>>julia
println("This comes from Julia:")
println("")

l = ["Dpdl", "supports", "Julia"]  
for i in l
    println(i)
    for j in 1:3
    	println(j) 
    end 
end 
return 1
<<

int exit_code = dpdl_exit_code()

println("embedded Julia exit code: " + exit_code)