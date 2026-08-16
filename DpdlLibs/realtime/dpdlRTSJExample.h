# File: realtime/dpdlRTSJExample.h
#
# Example: Dpdl example that launches a realtime worker thread via the RTSJ spec library.
#			The main worker thread function makes use of an 'embedded code section' in java to perform the actual task
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#


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
