# File: umka/dpdlUmkaTest.h
#
# Example:
#		Dpdl test example that executes an 'embedded code section' in Umka lang
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing embedded Umka...")

dpdl_stack_push("param1", "param2")
>>umka
fn dpdl_main() {
	printf("Hello from Umka in Dpdl\n")
}
<<
int exit_code = dpdl_exit_code()

println("umka exit code: " + exit_code)
