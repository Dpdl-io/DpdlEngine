# File: downloadWebURL.h
#
# Example: Download the html of a web URL and save the content to a file
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
object url = loadObj("URL", "https://www.dpdl.io")

object url_connection = url.openConnection()
raise(url_connection, "Error in opening connection")

object url_in = url_connection.getInputStream()
object url_in_read = loadObj("InputStreamReader", url_in)
raise(url_in_read, "Error in opening input stream")

object buf_read = loadObj("BufferedReader", url_in_read)
object buf_str = loadObj("String", "")
string web_content = ""
while(buf_str != null)
	buf_str = buf_read.readLine()
	if(buf_str != null)
		web_content = web_content + buf_str.toString()
	fi
endwhile

println(web_content)

string myfile = "./Test/web_content.txt"
println("writing file: " + myfile)
object file_writer = loadObj("FileWriter", myfile)
file_writer.write(web_content)
file_writer.flush()
file_writer.close()
