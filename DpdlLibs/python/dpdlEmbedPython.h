# File: python/dpdlEmbedPython.h
#
# Example: This example shows how to embed and execute python code within Dpdl
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#


# main
println("testing embedding python code")
println("")

>>python
languages = ['Dpdl', 'C', 'Python', 'OCaml']

for language in languages:
	print(language)
<<
println("")

int exit_code = dpdl_exit_code()

println("ebedded python exit code: " + exit_code)
