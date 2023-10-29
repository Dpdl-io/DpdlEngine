# File: dpdlLuaMain.h
#
# Example: This Dpdl script executes an embedded 'lua' script, dpdl_main(..) as entry point with a parameter table from variables pushed onto the dpdl stack
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedding lua....")


dpdl_stack_push("name", "Alexis", "surname", "Kunst")

>>lua
function doSomeAlg()
	local home_dir = os.getenv("HOME")
	print("user home: ", home_dir)
	
	local x = os.clock()
	    local s = 0
	    for i=1,100 do 
	    	s = s + i
	    	io.write(".")
	    end
	    print("")
	    print(string.format("elapsed time: %.2f\n", os.clock() - x))
end

function paramLen(T)
  local count = 0
  for _ in pairs(T) do count = count + 1 end
  return count
end

function dpdl_main(params)
	local num_params = paramLen(params)
	io.write("dpdl_main call with number of params: ")
	io.write(num_params)
	print()
	print("executing my embedded algorithm...")
	print("")
	doSomeAlg()
	print()
	print("converting param values in 'uppercase'")
	for k,v in pairs(params) do
		print(string.upper(v))
	end
end
<<

int exit_code = dpdl_exit_code()

println("embedded lua exit code: " + exit_code)


