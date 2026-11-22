# Dpdl realtime

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	




## Dpdl realtime with RTSJ

For realtime applications, Dpdl integrates also constructs and semantics to interact with the **RTSJ** (*Real-Time Specification for Java*) api to enable and handle realtime threading on systems and platforms that provide realtime capabilities.

The RTSJ (*Real-Time Specification for Java*) provides an API to create realtime threads and event handlers, for interacting with devices and native memory, to enforce resource limits and to handle POSIX signals on JVMs and systems that have realtime support.


### Example:

dpdl code that implements a dpdl **`class`** **`TestPriority`** to launch a *RealtimeThread* worker object with increased **Priority**

In this example the Worker thread executes an '*embedded code section*' in java

```python

class Worker : refObj("RealtimeThread") {

	bool stop = false

	func Worker(int priority)
		object prio_param = new("PriorityParameters", priority, null)

		super(prio_param, null)

		println("Worker init() with priority: " + priority)
	end

	func run()
		println("running some task...")

		dpdl_stack_push(stop)
		>>java
			boolean status_stop = arg0;
			for (int i = 0; i < 10000000; i++){
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
		super()
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


### The real-time functionality can be accessed:
 
- either directly using the RTSJ spec API
- via an abstraction layer available within the **`dpdl library`** *package* '**`realtime`**', which enables the handling multiple realtime threads and timer resources through a unified interface based on the RTSJ
- via the dpdl **`>>task`** feature that can be configured to use realtime threads instead of ordinary threads

When running Dpdl on a realtime system, the main internal DpdlEngine threads are also based on the RealtimeThread class and can also be controlled programmatically to a certain extend.


### Examples

### Index

[dpdl example using RTSJ API directly](#dpdl-example-using-rtsj-api-directly)

[dpdl example implementation for a reusable realtime asynchronous event handler](#dpdl-example-implementation-for-a-reusable-realtime-asynchronous-event-handler)

[dpdl example using the abstraction dpdl library package realtime](#dpdl-example-using-the-abstraction-dpdl-library-package-realtime)

[dpdl example with a dpdl task that executes as realtime thread](#dpdl-example-with-a-dpdl-task-that-executes-as-realtime-thread)


### dpdl example using RTSJ API directly

dpdl example that makes use of RTSJ API to launch a real-time worker thread to perform a task that executes and '*embedded code section*' in java

```python
println("dpdl example that launches a realtime worker thread with increased priority using the RTSJ spec library ...")

class TestPriority : refObj("RealtimeThread") {

	func TestPriority()
		super()
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
			for (int i = 0; i < 10000000; i++){
				if (status_stop){
					System.out.println("terminating...");
					return 0;
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
 
* [Index](#examples)

### dpdl example implementation for a reusable realtime asynchronous event handler
 
This Dpdl example shows the usage and the implementation of the dpdl **`class`** that represents a reusable realtime Asynchronous Event Hanlder.

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

dpdl source of the example above: [realtime/dpdlRTSJAsyncEventHandlerTest.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/realtime/dpdlRTSJAsyncEventHandlerTest.h)


#### Implementation of the dpdl class **`ReusableAEH`** included in the example above (see **`dpdlRTSJAsyncEventHandlerTest.h`**)
 
 
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
	  	  super()
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
 
* [Index](#examples)


### dpdl example using the abstraction dpdl library package **`realtime`**
 
dpdl example make use of the dpdl library package '**`realtime`**' to use the abstraction interface '**RealtimeManager**'for accessing *realtime* **Threads**, **Timers** and **Memory** via a unified interface.
 
 
 ```python
 
import('realtime')


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

 
```

#### Below the implementation of the dpdl **`class`** components: **`MyTask`**, **`MySense`** and **`MyExec`** (in example above):
 
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
			double calc = 0.0d;
			for (int i = 0; i < 1000; i++) {
				calc += Math.sqrt((double)i);
			}
			return "Result: " + calc;
		<<
		return dpdl_stack_buf_get()
	end
}

 ```
 
 * [Index](#examples)
 
 
### dpdl example with a dpdl task that executes as realtime thread
 
This example shows how the dpdl **`>>task`** feature can be configured so that it runs with a *RealtimeThread* via RTSJ

In this case the task is first initialized and subsequently started.

```python
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

raise(status, "task initialization failed")

println("task initialized with status: " + status)

object task_obj = dpdl_task_obj_get("my_task")

object prio_param = new("PriorityParameters", task_obj.getPriority()+1, null)

task_obj.startTask(prio_param)

task_obj.join()

println("task completed")

```
 
* [Index](#examples)