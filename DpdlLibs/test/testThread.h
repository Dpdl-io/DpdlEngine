# File: test/testThread.h
#
# Example: Test Dpdl script with threads that execute a specified function
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myThreadFunc1(int t_id, string param)
	println("message from thread id: " + t_id)
	println("param: " + param)
end

func myThreadFunc2(int t_id, string param)
	println("message from thread id: " + t_id)
	println("param: " + param)
end

func dpdl_thread_finalize(int id)
	println("finalized Thread id: " + id)
end

# main
println("testing threads...")

println("starting thread 1...")

int t_id1 = Thread("myThreadFunc1", 3000, 4, "my thread param")

raise(t_id1, "Error in starting thread")

println("thread starting with id: " + t_id1)

sleep(1000)

println("starting thread 2...")

int t_id2 = Thread("myThreadFunc2", 4000, -1, "my thread param")

raise(t_id2, "Error in starting thread")

println("thread starting with id: " + t_id2)

sleep(4000)

println("setting thread priority....")

int set_prio = setThreadPriority(t_id2, 10)

println("set priority status: " + set_prio)
