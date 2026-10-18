# File: realtime/dpdlRTSJAsyncEventHandler.h
#
# Example: This dpdl code implements a reusable realtime AsyncEventHandler class that enables to handle
#			different logic implementations
#
#			for usage see example: ./realtime/dpdlRTSJAsyncEventHandlerTest.h
#
#			Example ported to dpdl from the Book: Realtime Java Platform Programming 2nd edition
#
#
# author: A.Costa
# e-mail: ac@dpdl.io
#


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
