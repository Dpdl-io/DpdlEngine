# File: test/testCodeExec.h
#
# Example: Dpdl script that executes structured code resources
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("test executing code resources...")
println("")

>>res(my_content)

	This is some strcuctured content
				:)
			   MEGA

		 {{my_custom_msg}}

<<

dpdl_stack_var_put("my_custom_msg", "Dpdl has been developed by A.Costa")

object content = dpdl_res_obj_get("my_content")

println("some content:")
println(content)

println("creating code resources...")
println("")

>>res(java_method_printA)

static void printA(){
	System.out.println("printA: " + 888);
}

printA();

<<

>>res(dpdl_struct_printS)
struct S {
	int x = 23
	int y = 888
	string str = "S"
	object so = new("String", "This is a test")

	func print()
		println("S:")
		println("x=" + x + " y=" + y + " str=" + str + " so=" + so)
	end
}

struct S mys
mys.print()

<<

println("executing java code resource...")
println("")

object printA = dpdl_res_obj_get("java_method_printA")

dpdl_stack_var_put("code_java_printA", printA.toString())

dpdl_stack_push("dpdl:applyvars")
>>java

{{code_java_printA}}

<<
int exit_code = dpdl_exit_code()

println("embedded java exit code: " + exit_code)

println("executing dpdl code resource...")

object code = dpdl_res_obj_get("dpdl_struct_printS")

string code_str = code.toString()

int status_exec = DPDLAPI_execCode(code_str)

println("status exec: " + status_exec)


