#
# www.dpdl.io
# (c) 2023 SEE Solutions
#
# file: test_basic/testC.h
#
#

println("basic test embedded C (interpreted)...")
println("")

>>c
	#include <stdio.h>

	int x = 23;
	char *msg = "message from C";

	for(int i = 0; i < 1000; i++){
		printf("i=%d -> msg: %s val: %d\n", i, msg, x);
	}
<<
int exit_code = dpdl_exit_code()

println("")
println("embedded C exit code: " + exit_code)

println("finished")
