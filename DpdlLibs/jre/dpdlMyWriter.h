# File: jre/dpdlMyWriter.h
#
# Example: Dpdl example that implements an efficient function to write buffered data to files.
#			The dpdl class is derived from a 'BufferedWriter' java JRE object
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


class MyWriter : refObj("BufferedWriter") {

	object header = new("String", "some data init head str")

	object file_writer = null

	func MyWriter(string file_n, int off)

		file_writer = new("FileWriter", file_n)

		raise(file_writer, "could not open file: " + file_n)

		super(file_writer)

		println("new MyWriter()-> file:" + file_n + " offset:" + off)

	end

	func init()
		println("type of super class is: " + typeof(super))

		super.write(header, 0, header.length())

		println("started")
	end

	func writeStr(string data, int nr)
		int i
		for(i < nr)
			super.write(data, 0, strlen(data))

			print(".")

			i=i+1
		endfor
		println("")

		super.newLine()
		super.flush()
	end

	func close()
		super.close()
	end
}

println("testing my buffered file writer...")

class MyWriter myw("./Test/mydata2.txt", 0)

myw.init()

myw.writeStr("data 1", 1000)
myw.writeStr("data 2", 2000)
myw.writeStr("data 3", 2000)

myw.close()

println("finished")

