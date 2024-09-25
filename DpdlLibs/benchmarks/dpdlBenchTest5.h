# File: benchmarks/dpdlBenchTest5.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple test that executes some 'task' asynchronously
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("executing asynchronous 'task'....")

>>task
	println("Task 1:")
	int c
	while(c < 10)
		print(".")
		sleep(2000)
		c=c+1
	endwhile
	println("Task 1 finished")
<<

int exit_code = dpdl_exit_code()

println("task started with exit code: " + exit_code)

raise(exit_code, "task did not start correctly")

object task1_id = dpdl_task_pop_id()

object task1_obj = dpdl_task_obj_get(task_id)

>>task
	println("Task 2:")
	int c
	while(c < 20)
		print("#")
		sleep(2000)
		c=c+1
	endwhile
	println("Task 2 finished")
<<

exit_code = dpdl_exit_code()

println("task started with exit code: " + exit_code)

raise(exit_code, "task did not start correctly")

object task2_id = dpdl_task_pop_id()

object task2_obj = dpdl_task_obj_get(task2_id)

task2_obj.sleep(20000L)

println("finished")
