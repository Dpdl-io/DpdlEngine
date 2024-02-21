# File: python/dpdlEmbedPython2.h
#
# Example: This example shows how to embed and execute python code with a main() function within Dpdl
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#


# main
println("testing embedding python code")

dpdl_stack_push("var1", "var2", "var3")  # currently arguments are not intercepted in python main function, will be fixed in next release
>>python
import sys

def runMyFunc():


	languages = ['Dpdl', 'C', 'Python', 'OCaml']
	
	# run a loop for each item of the list
	for language in languages:
	    print(language)
	    
def main():
	print("my python code...")
	args = sys.argv[1:]
	if len(args) > 0:
		print(args[1])

	runMyFunc()
	
if __name__ == "__main__":
    main()
<<
int exit_code = dpdl_exit_code()

println("ebedded python exit code: " + exit_code)
