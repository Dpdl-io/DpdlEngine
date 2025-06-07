
# Dpdl language plug-in documentation

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
		
developed by
**SEE Solutions**
&copy; 2003





The embedded 'Lua' code may or may not include a 'main(..)' function.
If the 'main(..)' function is defined, parameters which are pushed to the Dpdl stack via the 'dpdl_stack_push(..)' function
are passed as parameters to the main function in the Lua code via a table type.


#### Example without main(..):

```python
println("my Dpdl script embeds some Lua script...")

>>lua
io.write("TEST ")
print()
<<
```

#### Example with main(..):

The parameters pushed on the Dpdl stack are passed to the Lua 'main(..)' function as table.
The main function returns also a table which is buffered info the stack variable defined 'dpdlbuf_var1'

```python
println("my Dpdl script embeds some Lua script...")

dpdl_stack_push("dpdlbuf_var1", "name", "Alexis", "surname", "Kunst")

>>lua
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
	print("returning param values in 'uppercase'")
	local tab_out = {numfields=1}
	for k,v in pairs(params) do
		tab_out.numfields = tab_out.numfields + 1
		tab_out[tostring(k)] = string.upper(tostring(v))
	end
	tab_out.numfields = tostring(tab_out.numfields)
	return tab_out
end
<<
int exit_code = dpdl_exit_code()

println("embedded Lua exit code: " + exit_code)

string resp_buf = dpdl_stack_buf_get("dpdlbuf_var1")

println("Lua response buffer: ")
println(resp_buf)
```