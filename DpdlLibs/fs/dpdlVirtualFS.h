# File: fs/dpdlVirtualFS.h
#
# Example: Dpdl script that shows how to read and write data to the virtual record store filesystem
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
string fs_name = "TestDpdlVirtualFS"
string dir_name = "app"
string base_file_name = "myTestFile"
string file_name
int nr_entries = 10

println("creating virtual record store filesystem: " + fs_name)

int fs_id = DPDLLIB_createFS(fs_name)

raise(fs_id, "Error in creating filesystem")

println("filesystem created with id: " + fs_id)

int status = -1

println("creating directory: " + dir_name)

status = DPDLLIB_mkdirFS(fs_id, dir_name)

raise(status, "Error in creating directory")

println("status: " + status)

println("writing data to file...")

string mydata = "Hello Dpdl filesystem"
int f_h = -1
int c = 0
for(c < nr_entries)
	file_name = base_file_name + "_" + c + ".txt"

	println("creating file " + file_name + " ...")

	f_h = DPDLLIB_mkfileFS(fs_id, "/" + dir_name, file_name)

	println("file created with id: " + f_h)

	println("writing data to file...")

	status = DPDLLIB_writeFS(fs_id, f_h, mydata + " " + c)

	println("status: " + status)
	c = c+1
endfor

println("reading data from file...")
string data
c = 0
for(c < nr_entries)
	data = DPDLLIB_readFS(fs_id, c)
	println("read data: " + data)
	c = c+1
endfor

println("printing filesystem directory tree...")

status = DPDLLIB_printdirFS(fs_id)

println("status: " + status)

println("unmounting filesystem...")

status = DPDLLIB_unmountFS(fs_id)

raise(status , "Error in unmounting filesystem")

println("status: " + status)
println("")
println("finished")

