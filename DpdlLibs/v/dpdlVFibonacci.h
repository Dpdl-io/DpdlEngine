# File: v/dpdlVFibonacci.h
#
# Example: Dpdl sample code that embeds and executes a 'V' code block to calculates the fibonacci sequence
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("calculating the fibonacci sequence with embedded V code..."

println("please enter the sequence rank number: ")

string number = readln()

dpdl_stack_var_push("", number)

>>v
const args = arguments()

fn dpdl_main() {

	if args.len != 2 {
		println('missing param')
		return
	}

	stop := args[1].int()

	if stop > 92 {
		println('rank must <= 92')
		return
	}

	mut a := i64(0)
	mut b := i64(0)
	mut c := i64(1)
	println(a + b + c)
	for _ in 0 .. stop {

		a = b
		b = c

		c = a + b

		println(c)
	}
}
<<
int exit_code = dpdl_exit_code()

println("embedded v exit code: " + exit_code)
