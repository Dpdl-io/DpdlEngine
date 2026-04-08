# File: simple/dpdlFibonacci.h
#
# Example: a simple Fibonacci series calculation via recursion
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


int N = 20


func fib(int n) int
	if(n <= 1)
		return n
	fi

	return fib(n - 1) + fib(n - 2)
end


int i
for(i < N)
	println("fib($i) = " + fib(i))
	i=i+1
endfor

println("finished")

