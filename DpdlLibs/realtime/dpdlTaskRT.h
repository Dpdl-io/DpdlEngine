# File: realtime/dpdlTaskRT.h
#
# Example: dpdl example that makes use of a dpdl 'task' with realtime threading
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#


println("creating and executing a dpdl task with realtime mode...")

println("creating task...")

dpdl_stack_push(realtime, start=false)

>>task(my_task)
	println("executing task...")

	int c = 0
	while(c < 1000)
		print(".")
		c=c+1
		sleep(2000)
	endwhile

	println("task finished")
<<

object status = dpdl_task_status_get("my_task")

raise(status, "task have not correctly initialized")

println("task initialized with status: " + status)

object task_obj = dpdl_task_obj_get("my_task")

object prio_param = new("PriorityParameters", task_obj.getPriority()+1, null)

task_obj.startTask(prio_param)

task_obj.join()

println("task completed")

