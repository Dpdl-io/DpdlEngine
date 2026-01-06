# File: janet/dpdlJanetTest.h
#
# Example:
#		Dpdl test example that executes an 'embedded code section' in Janet lang
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing embedded janet code...")

>>janet
	(print `hello, world!`)
<<

int exit_code = dpdl_exit_code()

println("embedded janet exit code: " + exit_code)
