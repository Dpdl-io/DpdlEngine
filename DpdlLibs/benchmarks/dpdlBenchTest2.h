# File: benchmarks/dpdlBenchTest2.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple benchmark to measure the execution speed of different embedded code sections including:
#			- Dpdl
#			- Java
#			- C (interpreted Mode)
#			- C (compiled Mode)
#			- JavaScript
#			- Clojure
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("performing simple benchmark with dpdl code and embedded code sections in java, C and Clojure")

println("starting...")

println("1) Simple loop with Dpdl...")

int i = 0
int val
string tag = "Dpdl"

setStartTime()

for(i < 1000000)
	val=i * 2
	println(tag + " -> i: " + i + " val: " + val)
	i=i+1
endfor

int ms1 = getEndTime()

println("exec time (ms): " + ms1)


println("2) Simple loop with embedded Java code...")


setStartTime()

>>java
	public static void myloop(){
		int val = 0;
		String tag = "Java code";
		for(int i = 0; i < 1000000; i++){
			val=i * 2;
			System.out.println(tag + " -> i: " + i + " val: " + val);
		}
	}

	myloop();

    return 1;
<<
int ms2 = getEndTime()

println("exec time (ms): " + ms2)


println("3) Simple loop with embedded interpreted C code...")


setStartTime()

>>c
	#include <stdio.h>

	int val;
 	char *tag = "C interpreted code";
	for(int i = 0; i < 1000000; i++){
		val=i * 2;
		printf("%s  -> i: %d  val: %d\n", tag, i, val);
	}
	return 0;
<<
int ms3 = getEndTime()

println("exec time (ms): " + ms3)


println("4) Simple loop with embedded compiled C code...")


dpdl_stack_push("dpdl:compile")

setStartTime()

>>c
 	#include <stdio.h>

	int dpdl_main(int argc, char **argv){
		int val;
		char *tag = "C compiled code";
		for(int i = 0; i < 1000000; i++){
			val=i * 2;
			printf("%s -> i: %d  val: %d\n", tag, i, val);
		}
		return 0;
	}
<<
int ms4 = getEndTime()

println("5) Simple loop with embedded javascript code...")

setStartTime()

>>js
"use strict";

function myloop() {
	var tag = 'JavaScript code';
	var nr_iter = 1000000;
	var val;
	var i;
	for(i = 0; i < nr_iter; i++){
		val=i * 2;
		std.printf("%s -> i: %d val: %d\n", tag, i, val);
	}
	console.log('');

}

myloop();
<<
int ms5 = getEndTime()

println("6) Simple loop with embedded Clojure code...")

setStartTime()

dpdl_stack_var_put("arg1", "test1")
dpdl_stack_var_put("arg2", "test2")
>>clj
(ns dpdl)
	(defn dpdl_main[^objects param]
		(println (str "Hello Clojure from Dpdl!:)"))
		(def tag "Clojure code")

		(dotimes [i 1000000]
		  (let [val (* i 2)]
		    (println (str tag " -> i: " i " val: " val))))
		(int 1)
	)
<<

int ms6 = getEndTime()

println("exec time (ms): " + ms5)

println("---------------------------------------------------------------------------")
println("execution time Results:")
println("")
println("pure Dpdl (ms): " + ms1)
println("embedded Java code (ms): " + ms2)
println("embedded C code interpreted (ms): " + ms3)
println("embedded C code compiled (ms): " + ms4)
println("embedded JavaScript code (ms): " + ms5)
println("embedded Cloujure code (ms): " + ms6)
println("")
println("finished")
