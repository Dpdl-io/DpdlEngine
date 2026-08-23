# Dpdl realtime

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	




## Dpdl realtime capabilities by using the RTSJ spec

For realtime applications Dpdl integrates also constructs and semantics to interact with APIs based on the RTSJ (*Real-Time Specification for Java*) specification to handle realtime threading on systems and platforms with real-time capabilities.

The RTSJ (*Real-Time Specification for Java*) provides an API to create realtime threads and event handlers, for interacting with devices and native memory, to enforce resource limits and to handle POSIX signals.

When running Dpdl on a realtime system, the main internal DpdlEngine threads are also based on the RealtimeThread class and can be controlled programmatically.

The realtime functions can be accessed:
 
- either directly using the RTSJ spec API
- or accessed via an abstraction layer available within the Dpdl package '**`realtime`**'. It enables to handle multiple realtime thread and timer resources thought a unified interface based on RTSJ spec


### dpdl example using RTSJ API directly

dpdl example that makes use of RTSJ API to launch a real-time worker thread to perform a task that executes and '*embedded code section*' in java

 ```python
 
class Worker : refObj("RealtimeThread") {

	bool stop = false

	func Worker(int priority)
		object prio_param = new("PriorityParameters", priority, null)

		super(prio_param)

		println("Worker init() with priority: " + priority)
	end

	func run()
		println("running task...")
		
		dpdl_stack_push(stop)
		>>java
			boolean status_stop = arg0;
			for (int i = 0; i < 100000000; i++){
				if (status_stop){
					return;
				}
			}
			System.out.println("Worker task completed");
			return 1;
		<<
		int exit_code = dpdl_exit_code()

		println("task exit code: " + exit_code)

	end

	func quit()
		stop = true
	end

}

class TestPriority : refObj("RealtimeThread") {

	func TestPriority()
		println("TestPriority init()")
	end

	func run()
		object worker = new(Woker, this.getPriority() + 1)

		worker.start()

		sleep(500)

		worker.quit()

		worker.join()

	end

}


println("dpdl example that launches a realtime worker thread via the RTSJ spec library ...")

class TestPriority test_prio()

test_prio.start()

test_prio.join()

println("finished")
 
 ```
 
 ### dpdl example using the dpdl 'realtime' package abstraction based on RTSJ
 
dpdl example using the 'RealtimeManager' abstraction interface available with the dpdl package '**`realtime`**' for accessing realtime Threads, Timers and Memory.
 
 ```python
 
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
					Thread.sleep(50);
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
			double calc = 0;
			for (int i = 0; i < 1000; i++) {
				calc += Math.sqrt(i);
			}
			return "Result: " + calc;
		<<
	end
}


println("testing Dpdl API real-time threads via RTSJ spec ....")

object sys = getObj("System")

object rtmgr = realtime.getRealtimeManager()

object prio_level = rtmgr.PriorityLevel

println("1) executing a scheduled task...")

class MyTask1 task1()

object mytask = rtmgr.schedulePeriodicTask("My heartbeat", 100,  0, task1)

string mytask_id = rtmgr.getTimerId(mytask)

println("timer task started with id: " + mytask_id)


println("2) creating a RealtimeThread ...")

class MySense sensor1()

object mythread1 = rtmgr.createRealtimeThread("SensorReader1", rtmgr.getPriorityValue(prio_level.MEDIUM), sensor1)

string mythread1_id = rtmgr.getThreadId(mythread1)

println("RT thread created with id: " + mythread1_id)



println("3) creating a RealtimeThread with No Heap access...")

class MySense sensor2()

object mythread2 = rtmgr.createNoHeapRealtimeThread("SensorReader2", rtmgr.getPriorityValue(prio_level.HIGH), sensor2)

string mythread2_id = rtmgr.getThreadId(mythread2)

println("RT thread created with id: " + mythread2_id)


println("changing priority of SensorReader1...")

int curr_prio = rtmgr.getThreadPriority(mythread1_id)

rtmgr.setThreadPriority(mythread1_id, curr_prio+3)


println("4) executing some computation in scoped memory")

class MyExec mycalc()

object result = rtmgr.executeInLTMemory(1024L * 1024L, mycalc)

println("result: " + result)

println("completed")


println("shutting down and cleaning up...")

rtmgr.shutdown()

println("finished")

 
 ```
 
 