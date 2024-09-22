# File: benchmarks/dpdlBenchTest4.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple benchmark to measure the execution speed of embedded javascript executed within a dedicated dpdl thread
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myProc(int t_id, string param)
	println("Thread running with id: " + t_id)

	dpdl_stack_push("dpdlbuf_var1", param)

	setStartTime()

	>>qjs
	"use strict";

	function myloop(p) {
		console.log('embedded javascript...');
		var result = "This is my Result=";
		if(p.length > 0){
			std.printf("parameter: %s\n", p[0]);
			result = result.concat(p[0]);
		}
		console.log('');
		var nr_iter = 10000;
		var res;
		var i;
		for(i = 0; i < nr_iter; i++){
			std.printf("i=%d msg=%s\n", i, args[0]);
			if(i == nr_iter-1){
				res = std.sprintf("%s : %d", result, i);
			}
		}
		console.log('');

	    dpdl_stack_buf_put(res);
	}

	var args;
	if (typeof scriptArgs != "undefined") {
	    args = scriptArgs;
	} else if (typeof arguments != "undefined") {
	    args = arguments;
	} else {
	    args=[1000];
	}

	myloop(args);
	<<
	int ms = getEndTime()

	int exit_code = dpdl_exit_code()

	println("embedded js exit code: " + exit_code + " iteration: " + iteration)

	string res_buf = dpdl_stack_buf_get("dpdlbuf_var1")

	println("")
	println("Result: ")
	println(res_buf)
	println("")
	println("exec time (ms): " + ms)

	iteration=iteration+1
end

# main
println("testing threads...")

int iteration = 1

int t_id1 = Thread("myProc", 2000, 4, "my thread param")

raise(t_id1, "Error in starting thread")

println("thread started successfully")


