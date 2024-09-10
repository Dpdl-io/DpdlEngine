# File: test/testTask.h
#
# Example: Example Dpdl script that make use of an asynchronous 'task'
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main

println("testing Dpdl tasks...")

>>task
	println("this is a dpdl Task that runs asynchronously")

	int c = 0
	while(c < 10)
		print(".")
		c=c+1
		sleep(2000)
	endwhile

	println("task finished")
<<

int exit_code = dpdl_exit_code()

println("task started with exit code: " + exit_code)

int c = 0
for(c < 10)
	print("#")
	c=c+1
	sleep(2000)
endfor

println("finished")
