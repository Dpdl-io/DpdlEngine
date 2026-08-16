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

The RTSJ provides an API to create realtime threads and event handlers, for interacting with devices and native memory, enforcing resource limits and handle POSIX signals.

When running Dpdl on a realtime system, the main interal DpdlEngine threads are also based on the RealtimeThread class and can be controlled programmatically.


**Example:**

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