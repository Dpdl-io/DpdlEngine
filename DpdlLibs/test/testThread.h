# File: test/testThread.h
#
# Example: Test Dpdl script for threads
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

int id = Thread("myThreadFunc1", 3000, 4, "my thread param")

raise(id, "Error in starting thread")

println("thread starting with id: " + id)

sleep(1000)

println("starting thread 2...")

id = Thread("myThreadFunc2", 4000, -1, "my thread param")

raise(id, "Error in starting thread")

println("thread starting with id: " + id)
