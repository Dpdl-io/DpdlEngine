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

raise(exit_code, "task did not start correctly")

object task_id = dpdl_task_pop_id()

println("task id: " + task_id)

int c = 0
for(c < 5)
	print("#")
	c=c+1
	sleep(1000)
endfor

object task_obj = dpdl_task_obj_get(task_id)

task_obj.sleep(20000L)

println("finished")
