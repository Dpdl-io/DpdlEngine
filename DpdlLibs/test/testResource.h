# File: test/testResource.h
#
# Example: Test Dpdl script with embedded multi-line structured text resources
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing access to embedded multi-line resources...")

>>res(my_html)
<html>
<body>
<p>Hello World from Dpdl</p>
</body>
</html>
<<

object resid = dpdl_res_pop_id()

println("resource id: " + resid)

object myhtml = dpdl_res_obj_get(resid)

println("myhtml: ")

println(myhtml)


>>res
	This is a no name res
			:)
<<

object resid2 = dpdl_res_pop_id()

object myres = dpdl_res_obj_get(resid2)

println("myres: ")
println(myres)


object myoldres = dpdl_res_obj_get("my_html")

println("myoldres:")

println(myoldres)

println("finished")
