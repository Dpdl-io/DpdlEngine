# File: ruby/dpdlRubyExample.h
#
# Example: This Dpdl script shows how ruby code can be embedded within Dpdl scripts. The function containing embedded ruby is called with a Thread
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myFuncRuby(int t_id)
	println("executing embedded ruby code...")

	>>ruby
	$global_variable = 23

	$dpdl_ret = 0

	puts "Hello World from ruby inside Dpdl"

	class Class1
	   def print_global
	   	   puts "Global variable in Class1 is #$global_variable"

		   for a in 1..5000 do
			   puts "This is a TEST #{a}"
		   end
	   end
	end
	class Class2
	   def print_global
		  puts "Global variable in Class2 is #$global_variable"
	   end
	end

	class1obj = Class1.new
	class1obj.print_global
	class2obj = Class2.new
	class2obj.print_global

	$dpdl_ret = 1
	<<
	int exit_code = dpdl_exit_code()
	println("embedded ruby code exit code: " + exit_code + " in thread id: " + t_id + " cnt: " + cnt)
	cnt = cnt+1
end

# main
println("testing embedding of ruby code...")

int cnt = 0

int tId = Thread("myFuncRuby", 5000)

raise(tId, "Error in starting thread")

println("thread started with id: " + tId)
