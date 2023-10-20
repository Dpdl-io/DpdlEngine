# File: dataCompress.h
#
# Example: Compress and de-compress a string of data using java.util.zip.GZIP*
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

# main
object str = loadObj("String", "my data for Dpdl")
println("string to compress: " + str)

object byte_out = loadObj("ByteArrayOutputStream")
object zip_out = loadObj("GZIPOutputStream", byte_out)

println("compressing...")
zip_out.write(str.getBytes())
zip_out.close()
println("data compressed successfully")

object compressed_str = byte_out.toString()
println("compressed string: " + compressed_str)

println("decompressing...")
object byte_in = compressed_str.getBytes()

object byte_arr_in = loadObj("ByteArrayInputStream", byte_in)
object zip_in = loadObj("GZIPInputStream", byte_arr_in)

object in_reader = loadObj("InputStreamReader", zip_in)
object buf_reader = loadObj("BufferedReader", in_reader)

string decompressed_str = ""
string line = ""
while(line != null)
	line = buf_reader.readLine()
	if(line != null)
		decompressed_str = decompressed_str + line
	fi
endwhile
println("decompressed: " + decompressed_str)
