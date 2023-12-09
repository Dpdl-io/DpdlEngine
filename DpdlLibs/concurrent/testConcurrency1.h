# File: concurrent/testConcurrency1.h
#
# Example: This Dpdl script launches threads with defined intervals and nr. of iterations on functions
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myThreadFunc1(int t_id, string t_param)
	println("Hello from thread id: " + t_id)
	println("param: " + t_param)
end

func myThreadFunc2(int t_id)
	println("Hello from thread id: " + t_id)
end

func myThreadFunc3(int t_id)
	println("Hello from thread id: " + t_id)
end

# this function is called whenever a thread terminates
func thread_finalize(int id)
	println("finalized Thread id: " + id)
end

func myThreadFunc4()
	int n = 6
	double x = 10.0d
	string a = "test"

	dpdl_stack_push(n, x, a)
	>>c
	#include <stdio.h>

	int main(int argc, char **argv){
		printf("Hello from thread 4\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
		for (cnt = 0; cnt < argc; cnt++){
			printf("	param %d: %s\n", cnt, argv[cnt]);
		}
		return 0;
	}
	<<
end

println("starting a Dpdl threads...")
println("")
println("starting thread 1...")
int tId1 = Thread("myThreadFunc1", 2000, 3, "my added param")
if(tId1 != -1)
	println("Thread started with id: " + tId1)
else
	println("Error in starting thread")
fi

# we make a pause to guarantee not lock conditions
sleep(3000)
println("starting thread 2...")
int tId2 = Thread("myThreadFunc2", 3000, 3)
if(tId2 != -1)
	println("Thread started with id: " + tId2)
else
	println("Error in starting thread")
fi

sleep(3000)
println("starting thread 3...")
int tId3= Thread("myThreadFunc3", 4000, 3)
if(tId3 != -1)
	println("Thread started with id: " + tId3)
else
	println("Error in starting thread")
fi
println("done")
