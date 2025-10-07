# File: sql/dpdlSqlExampleJson.h
#
# Example: This Dpdl script executes an embedded 'sql' statement on a provided database, retrieves and prints out the resultset.
#			Encodes the result set into a json string, than decodes the json string to an object and accesses the named values
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('json')

# main
println("testing 'sql' queries and json encoding/decoding with Dpdl...")

dpdl_stack_var_put("db_url", "jdbc:postgresql://127.0.0.1:5432/mytestdb")
dpdl_stack_var_put("db_user", "testuser")
dpdl_stack_var_put("db_pass", "189923")
dpdl_stack_var_put("db_data_mode", "map")

dpdl_stack_var_put("id", "23")

dpdl_stack_push("dpdlbuf_res")

>>sql
	SELECT id, name, surname, email from mytable where id={{id}}
<<

object result = dpdl_stack_obj_get("dpdlbuf_res")

raise(result, "Error: dpdl stack buffer is null")

println("type of result: " + typeof(result))

int rs_size = result.size()

println("nr. or results: " + rs_size)

println("iterating over result set...")

object id, name, surname, email

int c = 0
object entry_map
for(c < rs_size)
	println("-----------------------------------")
	entry_map = result.get(c)

	id = entry_map.get("id")
	name = entry_map.get("name")
	surname = entry_map.get("surname")
	email = entry_map.get("email")

	println("id: " + id)
	println("name: " + name)
	println("surname: " + surname)
	println("e-mail: " + email)

	println("-----------------------------------")

	c=c+1

endfor

println("encoding result to json format...")

object json_str = json.encode(result)

println("json str: " + json_str)

println("")

println("decoding json to obj...")

object dpdl_json = getObj("DpdlJson")

object json_obj = dpdl_json.parse(json_str)

object json_elem = json_obj.getObj(0)

object json_elem_id = json_elem.getNum("id")
object json_elem_name = json_elem.getString("name")
object json_elem_surname = json_elem.getString("surname")
object json_elem_email = json_elem.getString("email")

println("id: " + json_elem_id)
println("name: " + json_elem_name)
println("surname: " + json_elem_surname)
println("e-mail: " + json_elem_email)

println("")

println("finished")

