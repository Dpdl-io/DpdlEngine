# File: test_perf/dpdlTestPerf.h
#
# Example: This simple test serves as a basic benchmark for performance metrics
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

class TestPerf {

	func TestPerf()
		println("init")
	end

	func myIteration(int nr)
		int i, val
		for(i < nr)
			val = val+i
			println("iter: " + i + " val: " + val)
			i=i+1
		endfor
	end

}

class TestPerf perf

int nr_iter = 1000000

object sys = getObj("System")

long ms_s = sys.currentTimeMillis()

perf.myIteration(nr_iter)

long ms_e = sys.currentTimeMillis()

println("exec time (ms): " + (ms_e-ms_s))
