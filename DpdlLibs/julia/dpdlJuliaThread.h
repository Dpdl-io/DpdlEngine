# File: dpdlJuliaThread.h
#
# Example: This Dpdl script executes an embedded Julia script that creates threads and calls a native Dpdl API function
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing thread from julia...")

>>julia
func(i) = ccall(:dpdl_sqrt_c_func, Float64, (Int32,), i)
println(Threads.threadpoolsize())
use(i) = println("[J $(Threads.threadid())] i = $(i) -> $(func(i))")
Threads.@threads for i in 1:5 use(i) end
return 1
<<

int exit_code = dpdl_exit_code()

println("finished with exit code: " + exit_code)