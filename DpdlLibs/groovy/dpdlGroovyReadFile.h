# File: groovy/dpdlGroovyReadFile.h
#
# Example: Dpdl script that embeds and executes a 'Groovy' code block that reads a file provided as parameter on the dpdl stack,
#			and prints each line to the console
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("reading a file line by line using embedded 'Groovy' code...")

dpdl_stack_push("./Test/see_solutions.html")
>>groovy

def dpdl_main(Object[] param, Object var_map){
	String myfile = (String)param[0];
	new File(myfile).eachLine { line ->
	  println line
	}
	return 1;
}

<<
int exit_code = dpdl_exit_code()

println("embedded groovy exit code: " + exit_code)
