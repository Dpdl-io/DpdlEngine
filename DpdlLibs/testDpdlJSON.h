# File: json/testDpdlJSON.h
#
# Example: Parse JSON and access different data types
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('io')

# main
string json_file = "./Test/test.json"

println("reading json from file: " + json_file)

string content = io.readStr(json_file)

raise(content, "Error in reading json file")

println("content: " + content)
println("")
println("allocating DpdlJson...")
object dpdl_json = getClass("DpdlJson")
object json_content = loadObj("String", content)

println("parsing json...")
object json = dpdl_json.parseObj(json_content)

println("get from json:")
println("--------------")
string str = json.getString("mystr")
println("str: " + str)

object num = json.getNum("number")
println("num: " + num)

object big_int = json.getNum("big_int")
println("big_int: " + big_int)

object big_dec = json.getNum("big_dec")
println("big_dec: " + big_dec)

object lon = json.getNum("num_long")
println("long: " + lon)

bool b_true = json.getBool("bool_t")
println("b_true: " + b_true)

bool b_false = json.getBool("bool_f")
println("b_false: " + b_false)

object json_arr = json.getArr("arr")
string str_0 = json_arr.getString(0)
println("str_0: " + str_0)

object json_obj = json_arr.getObj(1)
object value = json_obj.getNum("value")
println("value: " + value)

bool b_5 = json_arr.getBool(5)
println("b_5: " + b_5)

bool b_6 = json_arr.getBool(6)
println("b_6: " + b_6)

object obj = json.getObj("obj")
string str_name = obj.getString("name")
println("name: " + str_name)
