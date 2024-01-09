# File: dpdlJuliaMaldelbrot.h
#
# Example: This Dpdl script implements a console version of the Mandelbrot set fractal with embedded Julia code
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Mandelbrot set fractal implemented using embedded Julia code...")

>>julia
function mandelbrot(a)
    z = 0
    for i=1:50
        z = z^2 + a
    end
    return z
end

for y=1.0:-0.05:-1.0
    for x=-2.0:0.0315:0.5
        abs(mandelbrot(complex(x, y))) < 2 ? print("*") : print(" ")
    end
    println()
end
<<
int exit_code = dpdl_exit_code()
println("Dpdl julia exit code: " + exit_code)
