# Dpdl realtime

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	




## Dpdl realtime capabilities by using the RTSJ specification

For realtime applications Dpdl integrates also constructs and semantics to interact with APIs based on the RTSJ (*Real-Time Specification for Java*) specification to handle realtime threading on systems and platforms with real-time capabilities.

The RTSJ (*Real-Time Specification for Java*) provides an API to create realtime threads and event handlers, for interacting with devices and native memory, to enforce resource limits and to handle POSIX signals.

When running Dpdl on a realtime system, the main internal DpdlEngine threads are also based on the RealtimeThread class and can be controlled programmatically.

The realtime functions can be accessed:
 
- either directly using the RTSJ spec API
- or accessed via an abstraction layer available within the dpdl library package '**`realtime`**' --> enables to handle multiple realtime threads and timer resources thought a unified interface based on the RTSJ api.

### Examples:

[dpdl example using RTSJ API directly](#dpdl-example-using-rtsj-api-directly)

[dpdl example for a reusable realtime asynchronous event handler implementation](#dpdl-example-for-a-reusable-realtime-asynchronous-event-handler-implementation)

[dpdl example using the dpdl realtime abstraction library](#dpdl-example-using-the-dpdl-realtime-abstraction-library)

### dpdl example using RTSJ API directly

dpdl example that makes use of RTSJ API to launch a real-time worker thread to perform a task that executes and '*embedded code section*' in java

```python
println("dpdl example that launches a realtime worker thread with increased priority using the RTSJ spec library ...")

class TestPriority : refObj("RealtimeThread") {

	func TestPriority()
		println("TestPriority init()")
	end

	func run()
		object worker = new(Worker, this.getPriority() + 1)

		worker.start()

		sleep(500)

		worker.quit()

		worker.join()

	end

}

class TestPriority test_prio()

test_prio.start()

test_prio.join()

println("finished")
```

#### Implementation of the dpdl **`class`** '**Worker**' (for example above 'TestPriority'):

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
 
 ```
 
* [Examples](#examples)

### dpdl example for a reusable realtime asynchronous event handler implementation
 
This Dpdl example shows the usage and the implementation of the dpdl **`class`** -> a reusable realtime asynchronous event hanlder

Example ported to dpdl from the Book: *Realtime Java Platform Programming 2nd edition*

```python

include("dpdlRTSJAsyncEventHandler.h")


class MyLogic : refObj("DpdlRunnable"){

	func MyLogic()
		println("logic init()")
	end
	
	func run()
		println("Tick logic")
	end
}

class MySubLogic : MyLogic {

	func MySubLogic()
		super()
	end

	func run()
		println("Tock Tock logic")
	end
}


println("testing a reusable real-time Asynchronous Event Handler class implementation...")

println("instantiate the two logics...")

class MyLogic step1()

class MySubLogic step2()

println("instantiate the ReusableAEH class...")

ReusableAEH aeh = new ReusableAEH()

object interval = new("RelativeTime", 1000L, 0)

object timer = new("PeriodicTimer", null, interval, aeh)

println("setting logic for step 1...")

aeh.setLogic(step1)

timer.start()

sleep(10000)

println("done")

println("setting logic for step 2...")

aeh.setLogic(step2)

sleep(10000)

println("removing handler...")

timer.removeHandler(aeh)

println("done")

println("exiting...")

exit(0)


```

dpdl source: [realtime/dpdlRTSJAsyncEventHandlerTest.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/realtime/dpdlRTSJAsyncEventHandlerTest.h)
 
#### Implementation of the dpdl class **`ReusableAEH`** defined in the usage example above (**`dpdlRTSJAsyncEventHandlerTest.h`**)
 
 
 ```python
 
 
class ReusableAEH : refObj("AsyncEventHandler" {
	
	  object<ReusableAEH> next = null
	
	  object<Runnable> logic = null
	
	  func ReusableAEH()
	  	  super()
	  end
	
	  func ReusableAEH(bool nonHeap)
	  	  super(nonHeap)
	  end
	
	  func ReusableAEH(bool nonHeap, object<Runnable> logic)
	  	  super(nonHeap)
		  setLogic(logic)
	  end
	
	  func ReusableAEH(object<Runnable> logic)
		  setLogic(logic)
	  end
	
	  func ReusableAEH(object<SchedulingParameters> scheduling,
			  object<ReleaseParameters> release,
			  object<MemoryParameters> memory,
			  object<MemoryArea> area,
			  object<ProcessingGroupParameters> group,
			  bool nonHeap,
			  object<Runnable> logic)
	
	  	  super(scheduling, release, memory, area, group, nonHeap, logic)
		  setLogic(logic)
	  end
	
	  func ReusableAEH(object<SchedulingParameters> scheduling,
			  object<ReleaseParameters> release,
			  object<MemoryParameters> memory,
			  object<MemoryArea> area,
			  object<ProcessingGroupParameters> group,
			  bool nonHeap)
	
	  	  super(scheduling, release, memory, area, group, nonHeap, null)
	  end
	
	  func ReusableAEH(object<SchedulingParameters> scheduling,
			  object<ReleaseParameters> release,
			  object<MemoryParameters> memory,
			  object<MemoryArea> area,
			  object<ProcessingGroupParameter> group)
	
		  super(scheduling, release, memory, area, group, null)
	  end
	
	  func ReusableAEH(object<SchedulingParameters> scheduling,
			  object<ReleaseParameter> release,
			  object<MemoryParameters> memory,
			  object<MemoryArea> area,
			  object<ProcessingGroupParameters> group,
			  object<Runnable> logic)
	
	    	super(scheduling, release, memory, area, group, logic)
	    	setLogic(logic)
	  end
	
	  func setLogic(object<Runnable> logic) void
	  	  this.logic = logic
	  end
	
	  func handleAsyncEvent() void
	  	  if(logic != null)
	  		  logic.run()
		  fi
	  end
	
	}
	 
 ```
 
 dpdl source: [realtime/dpdlRTSJAsyncEventHandler.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/realtime/dpdlRTSJAsyncEventHandler.h)
 
* [Examples](#examples)


### dpdl example using the dpdl realtime abstraction library
 
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
		return dpdl_stack_buf_get()
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
 
 * [Examples](#examples)