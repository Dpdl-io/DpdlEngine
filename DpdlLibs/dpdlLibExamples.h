# File: dpdlLibExamples.h
#
# Example: Various examples using Dpdl scripting. The single examples can be run individually via tagged execution by providing
#			the appropriate @TAG (i.e @TEST1, etc...)
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
import("dpdllib.h")
import("dpdlRS.h")
import("dpdlBT.h")

# Examples using Dpdl scripting, you can execute the individual tests by providing the appropriate @TAG (ex. @TEST1 etc.)

#@TEST1
println("TEST 1 #######################################")
# reading file
string fname_r = "./Test/TestRead.txt"
println("reading from a file ...")
string content = ""
string str_in = ""
int fh = open(fname_r, "r")
while(str_in != dpdlNull)
	str_in = read(fh)
	if(str_in != dpdlNull)
	    content = content + str_in
	fi
endwhile
close(fh)
println("content: " + content)
sleep(2000)
println("")

#@TEST2
println("TEST 2 #######################################")
# writing file
println("writing to a file ...")
string fname_w = "./Test/TestWrite.txt"
string str_out = "This is a Test"
int fh2 = open(fname_w, "w")
write(fh2, str_out)
close(fh2)
sleep(2000)
println("")

#@TEST3
println("TEST 3 #######################################")
# array allocation
println("allocating and adding elements to dynamic vector array ...")
allocMemArray(0, 10)
allocMemArray(1, 10)
int c = 0
while(c < 15)
	putMemArrayInt(0, c)
	putMemArrayStr(1, "test " + c)
	c = c + 1
endwhile
c = 0
int val = -1
string val_str = dpdlNull
while(c < getMemArraySize(0))
	val = getMemArrayInt(0, c)
	val_str = getMemArrayStr(1, c)
	println("value: " + val + " str: " + val_str)
	c = c + 1
endwhile
println("")
println("native arraylist extension")

myarraylist[0] = 1
myarraylist[1] = 2
myarraylist[2] = "mega"
temparr[0] = "tie"
temparr[1] = "uzz"
newarr[] = "100 200 300 400 mega"

myarraylist[3] = myarraylist[0] 
int sum__ = myarraylist[0] + myarraylist[1]
string mymega = myarraylist[2]
println("myarraylist: " + myarraylist)
println("size: " + myarraylist.size())
println("sum: " + sum__)
println("str: " + mymega)
myarraylist = temparr
println("new myarraylist: " + myarraylist)
println("")
arr[0] = 1
arr[1] = "mega"
println("arr list: " + arr)
# get ArrayList obj
object arr_obj = arr.getArrObj()
bool isincluded = arr_obj.contains("mega")
println("the list cointains \"mega\": " + isincluded)
println("removing \"mega\"...")
arr_obj.remove(1)
println("the new list: " + arr)
sleep(2000)
println("")

#@TEST4
println("TEST 4 #######################################")
# Time
println("get time ...")
println(getTime())
setStartTime()
sleep(1000)
int ms = getEndTime()
println("time elapsed in ms: " + ms)
sleep(2000)
println("")

#@TEST5
println("TEST 5 #######################################")
# String operations
string str = "Hello World from Dpdl"
println("performing string operations on string: " + str)
int len = strlen(str)
println("len: " + len)
string substr = substring(str, 0, 5)
println("substring: " + substr)
println("hash: " + hash(str))
if(endsWith(str, "Dpdl") == dpdlTrue)
	println("string ends with Dpdl")
fi
println("replacing 'World' with 'Space' in string...");
string str_replaced =  replace(str, "World", "Space")
println("New string is: " + str_replaced)
sleep(2000)
println("")

#@TEST6
println("TEST 6 #######################################")
# Random Number generation
println("generating random numbers ...")
int c2 = 0
int rand = -1
while(c2 < 10)
	rand = randInt(32, 100)
	println("random nr: " + abs(rand))
	c2 = c2 + 1
endwhile
sleep(2000)
println("")

#@TEST7
println("TEST 7 #######################################")
# Inline script execution
println("Executing inline dpdl script...")
int status_execscript = DPDLAPI_execScript("println(\"Hello\")")  
sleep(2000)
println("")

#@TEST8
println("TEST 8 #######################################")
# System exec operations
println("executing system function 'echo test' ...")
int status = systemExec("echo test", dpdlTrue, dpdlTrue)
println("status: " + status)
sleep(2000)
println("")

#@TEST9
println("TEST 9 #######################################")
# XML xpath query
println("query xml document via xpath...")
string result = DPDLAPI_processXPath("./Test/xpath_test.xml", "/Users/User/Name")
int nr_results = DPDLAPI_getXPathNrResults()
println("nr results: " + nr_results)
println("result: ")
println(result)
println("getting last entry ...")
string entry = DPDLAPI_getXPathResult(nr_results - 1)
println("entry: " + entry)
sleep(2000)
println("")

#@TEST10
println("TEST 10 #######################################")
# Bluetooth device discovery
println("BT device discovery inited")
int x = DPDLAPI_createObexServer(BT_GIAC_MODE)
println("discovering BT devices...")
     int s1 = DPDLAPI_searchClientsOnServer()
     int status_discovery = dpdlFalse
     int service_discovery = dpdlFalse
     int counter = 0
     if(s1 == dpdlTrue)
	     while (status_discovery != 1) && (service_discovery != 1)
	         status_discovery = DPDLAPI_discoveryServerFinished()
	         service_discovery = DPDLAPI_serviceDiscoveryServerFinished()
	         print(".")
	         counter = counter+1
	         sleep(1000)
	     endwhile
     else
     	println("No working Bluetooth stack found")
     fi
	 string dev = "n"
	 int dev_found = 0
     while(dev != "null")
          dev = DPDLAPI_getServerVisibleBTAddr()
          if(dev != "null")
              println("dev visible: " + dev)
			  dev_found = dev_found + 1
          fi
     endwhile
sleep(2000)
println("")

#@TEST11
println("TEST 11 #######################################")
# Write and Read data to Recordstore
string my_record_store_name = "MyRecordStore"
int nr_records = 10
int cnt = 0

println("opening RecordStore: " + my_record_store_name)
int PTR_RS = DPDLLIB_openRS(my_record_store_name, AUTHMODE_ANY, dpdlTrue, dpdlTrue)
DPDLLIB_enumRecords(PTR_RS, dpdlTrue)
println("--------------------------------")
println("adding data...")
string data = "null"
int id2 = -1
while(cnt < nr_records)
	data = "data=" + c
	if(PTR_RS != -1)
    	id2 = DPDLLIB_addRSData(PTR_RS, data)
    	println("rec ID:" + id2)
     	println("data: " + data)
     fi
	cnt = cnt + 1
endwhile
println("--------------------------------")
int nr_elements_rs  =  DPDLLIB_getNumRecords(PTR_RS)
println("nr. of records in recordstore: "+ nr_elements_rs)
closeRS(PTR_RS)
println("--------------------------------")
int rec_id = 1
string record_data = ""
println("showing data in recordstore...")
PTR_RS = DPDLLIB_openRS(my_record_store_name, AUTHMODE_ANY, dpdlTrue, dpdlTrue)
DPDLLIB_enumRecords(PTR_RS, dpdlTrue)
DPDLLIB_rebuildEnum(PTR_RS)
while(rec_id != -1)
	rec_id = DPDLLIB_getNextRecordID(PTR_RS)
	println("fetching next record id: " + rec_id)
	record_data = DPDLLIB_getRSData(PTR_RS, rec_id)
	println("rec_id: " + rec_id + " record_data: " + record_data)
endwhile
closeRS(PTR_RS)
println("--------------------------------")
println("done")

#@TEST12
println("TEST 12 #######################################")
# setup and access virtual Filesystem

println("creating virtual Dpdl filesystem...")
int fs_id = DPDLLIB_createFS("MyFileSystem")
println("filesystem created with id: " + fs_id)

string dir_name = "app"
println("creating directory: " + dir_name)
status = DPDLLIB_mkdirFS(fs_id, dir_name)
println("status: " + status)

string file_name = "myTestFile.txt"
println("creating file " + file_name + " ...")
int f_h = DPDLLIB_mkfileFS(fs_id, "/" + dir_name, file_name)
println("file created with id: " + f_h)

string data_fs = "Hello Dpdl filesystem"
println("writing data to file...")
status = DPDLLIB_writeFS(fs_id, f_h, data_fs)
println("status: " + status)

println("reading data from file...")
data = DPDLLIB_readFS(fs_id, f_h)
println("data: " + data)

println("printing directory tree...")
status = DPDLLIB_printdirFS(fs_id)
println("status: " + status)

println("unmounting filesystem...")
status = DPDLLIB_unmountFS(fs_id)
println("status: " + status)
println("")

#@TEST13
println("TEST 13 #######################################")
# loadObj(..) & getClass(..) methods to load dynamically java library classes and objects
println("testing getClass() method invocation on java.lang.System")
println("")
object sys, out, out2
sys=getClass("System")
out=sys.out
out2=out

out.println("Hello World Dpdl ")
out2.println("Hello World Dpdl Reflection 2")
println("")
println("-------------------------------")
# put and get on HashMap
println("testing put(..) and get() method invocation on java.util.HashMap")
println("")
object map, s
map=loadObj("HashMap")
map.put("1","Dpdl")
map.put("2","Packet")
map.put("3","Definition")
map.put("4","Language")

s=map.get("1")
out.println(s)
s=map.get("4")
out.println(s)
println("")
println("-------------------------------")
# test Vector enumeration
println("testing Enumeration on java.util.Vector")
println("")
object vec = loadObj("Vector")
vec.add("one")
vec.add("two")
vec.add("three")
object iter = vec.elements()
println("vec:")
while(iter.hasMoreElements())
    println("	" + iter.nextElement())
endwhile
println("")
println("-------------------------------")
# test Collection on array
println("testing Collection min value on on array[]")
println("")
arr[] = "1 23 44 66 79 99 100"
println("finding the min value of arr: " + arr)
object arr_list = arr.getArrObj()
object collections = getClass("Collections")
object min_value = collections.min(arr_list)
println("min value: " + min_value)
println("-------------------------------")
# write to file using FileWriter
println("testing write(..) method invocation on java.io.FileWriter")
println("")
string myfile = "./Test/MyFile.txt"
println("writing file: " + myfile)
object file_writer = loadObj("FileWriter", myfile)
file_writer.write("write with FileWriter class\n")
file_writer.flush()
file_writer.close()
println("done")
println("")
println("-------------------------------")
# get Date and converto to string
println("testing toString() method invocation on java.util.Date")
println("")
object date = loadObj("Date")
string date_str = date.toString()
println("date: " + date_str)
println("")
date_str = "12/08/2023"
println("converting date: " + date_str + " to other format")
object date_format = loadObj("SimpleDateFormat", "dd/MM/yy")
object date_ = date_format.parse(date_str)
object date_format_dest = loadObj("SimpleDateFormat", "MM-dd-yyyy hh:mm:ss")
date_str = date_format_dest.format(date_)
println("converted date: " + date_str)
println("")
println("adding n days to current date")
object calendar = getClass("Calendar")
object cal_inst = calendar.getInstance()
int day_ = cal_inst.get(calendar.DATE)
int month_ = cal_inst.get(calendar.MONTH)
int year_ = cal_inst.get(calendar.YEAR)
println("" + day_ + "-" + month_ + "-" + year_ + "")
println("adding 1 day..")
cal_inst.add(calendar.DATE, 1)
day_ = cal_inst.get(calendar.DATE)
month_ = cal_inst.get(calendar.MONTH)
year_ = cal_inst.get(calendar.YEAR)
println("" + day_ + "-" + month_ + "-" + year_ + "")
println("")
println("-------------------------------")
# use Math 
println("testing sin(..) and cos(..) method invocation on java.lang.Math")
println("")
object math = getClass("Math")
double d1 = 2.8d
double d1_sin = math.sin(d1)
double d1_cos = math.cos(d1)
println("d1: " + d1)
println("sin d1: " + d1_sin)
println("cos d1: " + d1_cos)
println("")
println("-------------------------------")
# get Web content via URL 
println("testing get web content via java.net.URL")
println("")
object url = loadObj("URL", "http://www.dpdl.io")
object url_connection = url.openConnection()
object url_in = url_connection.getInputStream()
object url_in_read = loadObj("InputStreamReader", url_in)
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
println("")
println("-------------------------------")
# Tokenize a String using StringTokenizer 
println("testing java.lang.StringTokenizer")
println("")
string myStr = "Dpdl is a compact framework"
println("tokenizing string: " + myStr)
object str_tok = loadObj("StringTokenizer", myStr)
while(str_tok.hasMoreElements())
	println("token: " + str_tok.nextElement())
endwhile
println("")
println("-------------------------------")
# regex using java.util.regex
println("testing regex on java.util.regex")
println("")
string search_str = "Dpdl"
string full_str = "asdfDpdlasdfDpdlasdf"
println("searching \"" + search_str + "\" in: " + full_str)
object pattern = getClass("Pattern")
object pattern_str = pattern.compile(search_str)
object matcher = pattern_str.matcher(full_str)
int start_, end_
while(matcher.find())
	start_ = matcher.start()
	end_ = matcher.end()
	println("found at start: " + start_ + " end: " + end_)
endwhile
println("done")
println("")

#@TEST14
println("TEST 14 #######################################")
# Thread execution of Dpdl script
int thread_instance = 0
string mythread_process = "myThreadProcess.h"
int ms_interval = 1000
int nr_iterations = 5
println("Executing a Thread process: " + mythread_process + " for " + nr_iterations + " iterations")
int res = DPDLAPI_createThread(thread_instance, mythread_process, dpdlMinPriority, ms_interval, nr_iterations)
while(DPDLAPI_threadRunning(thread_instance) == dpdlTrue)
	println(".")
	sleep(1000)
endwhile
println("finished")
println("")
println("-------------------------------")

#@TEST15
println("TEST 15 #######################################")
println("Executing embedded C code")
int n = 6
double xc = 10.0d
string a = "test"

dpdl_stack_push(n, xc, a)

>>c
	#include <stdio.h>
	#include <dpdl.h>
	
	int dpdl_main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    return 0;
	}
<<
int exit_code = dpdl_exit_code()

println("ebedded C exit code: " + exit_code)
println("done")
println("")
println("-------------------------------")

#@TEST16
println("TEST 16 #######################################")
println("testing embedding python code")
println("")

>>python
languages = ['Dpdl', 'C', 'Python', 'OCaml']

for language in languages:
	print(language)
<<
println("")

int exit_code_py = dpdl_exit_code()

println("ebedded python exit code: " + exit_code_py)
println("finished")
println("")
println("-------------------------------")

