# File: app/dummy/dpdl_sample_inc.h
#
# Example: Small sample Dpdl dummy app to test some features
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

include("lib/myapplib.h")

func dpdl_sample_thread(string param)
	println("dpdl_sample_thread()")
	println("param: " + param)
end

func myThreadFunc(int t_id)
    appRunning = true
	mydata.id = 23
	int randi = randInt(16, 100)
	mydata.data = "some data:" + abs(randi)  + " from thread id: " + t_id
	mydata.len = strlen(mydata.data)
end

func dpdl_thread_finalize(int t_id)
	println("thread terminated with id: " + t_id)
	appRunning = false
end

func start()
	if(startThread == true)
		tIdx = Thread("myThreadFunc", 2000, 5)

		raise(tIdx, "Error in starting thread")

		println("thread started with id: " + tIdx)
	fi
end

func isRunning()
	return appRunning
end

func setID()
	ID = "mega"
end

func getID()
	return ID
end

# main
bool appRunning = false
int tIdx = -1
bool startThread = true
string ID = "nullmega"

struct Data mydata

return 1
