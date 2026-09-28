# File: test/testEmbeddedCodeSections.h
#
# Example: sample dpdl code that makes use of various 'embedded code sections' in different programming languages
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("with dpdl you can embed and execute code sections in different programming languages, simultaneously and of multiple types...")

println("at its native speed :)")


setStartTime()

println("embedding some C code (interpreted)...")

>>c
	#include <stdio.h>

	float x = 23.0;
	char *m = "this message is printed in C";

	for(int i = 0; i < 1000; i++){
		float val = x + ((float)i/1000.0f);

		printf("msg: %s %d %lf\n", m, i, val);
	}
	return 1;
<<

int exit_code = dpdl_exit_code()

println("embedded C (interpreted) exit code: " + exit_code)

println("embedding some C code (compiled)...")

dpdl_stack_push("dpdl:compile")

>>c(mycode)
	#include <stdio.h>
	#include <time.h>

	extern void dpdl_stack_buf_put(char *buf);

	int dpdl_main(int argc, char **argv){
		printf("test C native...\n");
		printf("\n");
		time_t start;
		time_t end;
		time(&start);
		int c;
		for(c = 0; c < 500000; c++){
			printf("iter %d \n", c);
		}
		time(&end);
		printf("\n");

		double exec_time = difftime(end, start);
		printf("Exec time: %lf \n", exec_time);

		char buf[256];
		sprintf(buf, "my result is %lf", exec_time);

		dpdl_stack_buf_put(buf);

		return 1;
	}
<<

int exit_code = dpdl_exit_code()

println("embedded C (compiled) exit code: " + exit_code)

string my_result = dpdl_stack_buf_get("mycode")

println("my result: " + my_result)

println("embedding some JavaScript code...")

dpdl_stack_push("my Hello Message!!!")

>>js
	import { fib } from "./DpdlLibs/js/fib_module.js";

	var a_message = "null";

	if(scriptArgs.length > 0){
		a_message = scriptArgs[0];
	}
	std.printf("Message = %s %d", a_message, 23);
	console.log('');
	console.log('this fibonacci calculation is perfomed in javascript');
	console.log("fib(10)=", fib(10));

<<

println("testing embedded Clojure...")

dpdl_stack_var_put("arg1", "test1")
dpdl_stack_var_put("arg2", "test2")

>>clj
	(ns dpdl)
		(defn make-adder [x]
		  (let [y x]
			(fn [z] (+ y z))))

		(def add2 (make-adder 2))

		;; a comment entry point
		(defn dpdl_main[^objects param]
				(println (str "Hello Clojure from Dpdl!:) 1st param: " (first param) " res:" (add2 2)))
				(int 1)
		)
<<

exit_code = dpdl_exit_code()

println("embedded clojure exit code: " + exit_code)

println("you can embed many other languages too...we list them with via embedded Python code:")

>>python
languages = ['C', 'C++', 'Python', 'JavaScript', 'Julia', 'Lua', 'Ruby', 'Java', 'PHP', 'Perl', 'Groovy', 'Clojure', 'Modelica']

for language in languages:
	print(language)
<<

int ms = getEndTime()

exit_code = dpdl_exit_code()

println("embedded python exit code: " + exit_code)
println("")

println("all sections executed in time (ms): " + ms)

