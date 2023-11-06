# File: dpdlJuliaBufRet.h
#
# Example: This Dpdl script pushes parameters on the dpdl stack and executes an embedded Julia script that writes a calculation result
#          to the dpdl stack  which is intercepted again in Dpdl
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing 'dpdl_stack_buf_put' from julia programming language...")

dpdl_stack_push("dpdlbuf_var1")

>>julia
println("applying muladd(A, B, z) ->")
println("")

A=[1.0 2.0; 3.0 4.0]
B=[1.0 1.0; 1.0 1.0]
z=[0, 100]

println("A: ")
println(A)

println("B: ")
println(B)

println("z: ")
println(z)

result = muladd(A, B, z)

result_str = string(result)

myresult_return = "matrix muladd(A, B, z): " * result_str

write_buf = @ccall dpdl_stack_buf_put(myresult_return::Ptr{UInt8})::Int32
return 1
<<
println("")

int exit_code = dpdl_exit_code()
println("finished with exit code: " + exit_code)

string resp_buf = dpdl_stack_buf_get("dpdlbuf_var1")
println("response buffer: " + resp_buf)
