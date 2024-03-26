# File: sql/dpdlSqlExample.h
#
# Example: This Dpdl script executes an embedded sql statement on a provided database and retrieves and prints out the resultset
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing 'sql' queries with Dpdl...")

dpdl_stack_var_put("db_url", "jdbc:postgresql://127.0.0.1:5432/mytestdb")
dpdl_stack_var_put("db_user", "testuser")
dpdl_stack_var_put("db_pass", "189923")

dpdl_stack_push("dpdlbuf_res")

>>sql
	SELECT id, name, surname, email from mytable
<<

object result = dpdl_stack_obj_get("dpdlbuf_res")

raise(result, "Error: dpdl stack buffer is null")

int rs_size = result.size()

object id, name, surname, email

int c = 0
object entry
for(c < rs_size)
	println("-----------------------------------")
	entry = result.get(c)
	id = entry.get(0)
	name = entry.get(1)
	surname = entry.get(2)
	email = entry.get(3)

	println("id: " + id)
	println("name: " + name)
	println("surname: " + surname)
	println("e-mail: " + email)

	println("-----------------------------------")

	c=c+1

endfor

println("finished")

