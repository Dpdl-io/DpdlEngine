# File: dpdlJuliaPlot.h
#
# Example: This Dpdl script executes an embedded Julia script that plots data using the 'Plots' package
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main

println("Testing Plot data with Julia programming language...")

>>julia
using Plots

x = range(0, 10, length=100)
y1 = sin.(x)
y2 = cos.(x)
p = plot(x, [y1 y2])
savefig(p, "./Test/myplot.pdf") 

dispose_status = @ccall dpdl_julia_dispose()::Int32
return 1
<<

int exit_code = dpdl_exit_code()
println("finished with exit code: " + exit_code)
