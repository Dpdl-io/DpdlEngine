# File: dpdlLuaBufRet.h
#
# Example: 
# This Dpdl script executes an embedded C++ code section
#			
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main

println("test embedded C++...")

>>cpp
int np = 1000000;
for (int N=0; N<np; N++) {
	printf("Test: %d\n", N);
}
<<

int exit_code = dpdl_exit_code()

println("embedded ROOT exit code: " + exit_code)