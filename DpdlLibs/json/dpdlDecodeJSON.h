# File: json/dpdlDecodeJSON.h
#
# Example: Sample Dpdl script that decodes a json file into a struct
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

import('io')
import('json')

struct myJsonData {
	string mystr
	int i_num
	float f_num
	double d_num
	bool b_val
}

# main
println("decoding json to struct....")

string json_file = "./Test/test2.json"

println("reading json from file: " + json_file)

string content = io.readStr(json_file)

raise(content, "Error in reading json file")

struct myJsonData data

data = json.decode(content, data)

raise(data, "Error in decoding json")

println("data.mystr: " + data.mystr)
println("data.i_num: " + data.i_num)
println("data.f_num: " + data.f_num)
println("data.d_num: " + data.d_num)
println("data.b_val: " + data.b_val)

println("type of mystr is: " + typeof(data.mystr))
println("type of i_num is: " + typeof(data.i_num))
println("type of f_num is: " + typeof(data.f_num))
println("type of d_num is: " + typeof(data.d_num))
println("type of b_val is: " + typeof(data.b_val))
