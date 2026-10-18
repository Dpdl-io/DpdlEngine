# File: realtime/dpdlRTSJAsyncEventHandlerTest.h
#
# Example: Dpdl example that uses the reusable dpdl class 'ReusableAEH' (a reusable realtime Asyncronous Event Handler),
#			to implement two dedicated logic events
#
#			see ReusableAEH class: ./realtime/dpdlRTSJAsyncEventHandler.h
#
#			Example ported to dpdl from the Book: Realtime Java Platform Programming 2nd edition
#
#
# author: A.Costa
# e-mail: ac@dpdl.io
#

include("dpdlRTSJAsyncEventHandler.h")


class MyLogic : refObj("DpdlRunnable"){

	func MyLogic()
		super()
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

