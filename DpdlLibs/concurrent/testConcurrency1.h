# File: concurrent/testConcurrency1.h
#
# Example: This Dpdl script launches threads with defined intervals and nr. of iterations on functions
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myThreadFunc1()
	println("Hello from thread 1")
end

func myThreadFunc2()
	println("Hello from thread 2")
end

func myThreadFunc3()
	>>lua
	io.write("Hello from thread 3\n")
	print()
	<<
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
int tId1 = Thread("myThreadFunc1", 2000)
if(tId1 != -1)
	println("Thread started with id: " + tId1)
else
	println("Error in starting thread")
fi
println("starting thread 2...")
int tId2 = Thread("myThreadFunc2", 7000, 8)
if(tId2 != -1)
	println("Thread started with id: " + tId2)
else
	println("Error in starting thread")
fi
println("starting thread 3...")
int tId3= Thread("myThreadFunc3", 10000, 3)
if(tId3 != -1)
	println("Thread started with id: " + tId3)
else
	println("Error in starting thread")
fi
println("done")
