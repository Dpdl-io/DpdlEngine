# File: realtime/dpdlRTSJDpdlRealtimeManager.h
#
# Example: This dpdl class makes makes use of the dpdl 'realtime' library package to invoke a 'RealtimeManager' abstraction class
#
# author: A.Costa
# e-mail: ac@dpdl.io
#

import('realtime')


class MyTask : refObj("DpdlRunnable"){

	func run()
		println("some heartbeat at: " + sys.currentTimeMillis())
	end
}

class MySense : refObj("DpdlRunnable"){

	func run()
		println("executing a task with some embedded java code...")
		>>java
			while (!Thread.currentThread().isInterrupted()) {
				try {
					// Read some sensor data here
					Thread.sleep(50L);
				} catch (InterruptedException e) {
					break;
				}
			}
			return 1;
		<<
		int exit_code = dpdl_exit_code()

		println("task exit code: " + exit_code)
	end
}


class MyExec : refObj("DpdlSupplier"){

	func get()
		>>java
			double calc = 0.0d;
			for (int i = 0; i < 1000; i++) {
				calc += Math.sqrt((double)i);
			}
			return "Result: " + calc;
		<<
		return dpdl_stack_buf_get()
	end
}



println("testing the dpdl API class RealtimeManager within dpdl 'realtime' library package, to launch various kind of Executors with real-time threads via RTSJ api ...")

object sys = getObj("System")

object rtmgr = realtime.getRealtimeManager()

object prio_level = rtmgr.PriorityLevel

println("")

println("INIT the Executors...")

class MyTask1 task1()

class MySense sensor1()

class MySense sensor2()

class MyExec mycalc()

println("")

long time_start = sys.currentTimeMillis()

println("1) EXECUTING a scheduled task...")

object mytask = rtmgr.schedulePeriodicTask("My heartbeat", 100,  0, task1)

string mytask_id = rtmgr.getTimerId(mytask)

println("timer task started with id: " + mytask_id)


println("2) CREATING a RealtimeThread ...")

object mythread1 = rtmgr.createRealtimeThread("SensorReader1", rtmgr.getPriorityValue(prio_level.MEDIUM), sensor1)

string mythread1_id = rtmgr.getThreadId(mythread1)

println("RT thread created with id: " + mythread1_id)


println("3) CREATING a RealtimeThread with No Heap access...")

object mythread2 = rtmgr.createNoHeapRealtimeThread("SensorReader2", rtmgr.getPriorityValue(prio_level.HIGH), sensor2)

string mythread2_id = rtmgr.getThreadId(mythread2)

println("RT thread created with id: " + mythread2_id)


println("changing PRIORITY of SensorReader1...")

int curr_prio = rtmgr.getThreadPriority(mythread1_id)

rtmgr.setThreadPriority(mythread1_id, curr_prio+3)


println("4) EXECUTING some computation in scoped Memory")

object result = rtmgr.executeInLTMemory(1024L * 1024L, mycalc)

println("result: " + result)

println("completed")

long end_time = sys.currentTimeMillis()

println("TOTAL EXEC Time (ms): " + (end_time - start_time))

println("")

println("Shutting Down and Cleaning Up...")

rtmgr.shutdown()

println("finished")

