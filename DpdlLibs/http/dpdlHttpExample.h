# File: http/dpdlHttpExample.h
#
# Example: Dpdl Example that performs HTTP requests (GET, POST, PUT, etc..)
#			The post and put requests are performed towards a request/response service for testing purposes.
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

import('http')

# main
println("testing HTTP requests using 'http' library")

println("-----------------------------------------")

println("performing GET request...")

object get = http.get("https://www.dpdl.io")

println("content: " + get.text())
println("headers: " + get.headers())
println("response code: " + get.responseCode())

println("-----------------------------------------")

println("performing simple POST request...")

object post = http.post("https://httpbin.org/post")
post.param("name", "Alexis")
post.param("surname", "Kunst")
post.param("email", "alexis.kunst@seesolutions.it")

println("response: " + post.text())

println("-----------------------------------------")

println("performing json POST request...")

string myjson_str = "{ \"mystr\": \"Hello Dpdl JSON\", \"i_num\": 10 }"

object post = http.post("https://httpbin.org/post", myjson_str)
post.header("Accept", "application/json")
post.header("Content-Type", "application/json")

println("response: " + post.text())

println("-----------------------------------------")

println("performing PUT request...")

object put = http.put("https://httpbin.org/put", "This is my test content")

println("response: " + put.text())

println("-----------------------------------------")

