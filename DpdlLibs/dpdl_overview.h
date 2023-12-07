# File: dpdl_overview.h
#
# Example: Sample Dpdl script
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
include("dpdllib.h")

func myThreadHello()
	println("Hello from Dpdl Thread")
end

func myThreadMessage()
	println("Message from Dpdl Thread")
end

# this function is called whenever a thread terminates
func thread_finalize(int id)
	println("Thread finalized: " + id)
end

struct myStruct {
	int x = 10
	float f = 0.1
	double d = 0.3d
	long l = 1000L
	byte b = 0x01
	string s = "Test struct"

	println("myStruct")

	func myStructCall()
		println("myStructCall: " + s)
		return 23
	end
}

# main
println("a sample dummy Dpdl script...")

string mystr = "my string"
object myobj = "my dpdl object"
struct myStruct a
println("calling struct fuction...")
int s_ret = a.myStructCall()
println("s_ret: " + s_ret)


myarr[] = "1, 2, 3, 4 , 5, 6"
myarr_mix[] = "1, test, 0x01, 0.1"

println("array: " + myarr_mix)
int s = myarr_mix.size()
println("size: " + s)

myarr_mix[0] = a
println("array: " + myarr_mix)
s = myarr_mix.size()
println("size: " + s)

object myarrlist = myarr_mix.getObj()
println("arrlist: " + myarrlist.toString())
println("------------------------")
println("Supported types:")

string mys = "my string"
int i = 3
float f = 0.1
double d = 0.2d
long l = 1000000L
byte c = 0x02
bool b = true
struct myStruct aa
object myo = loadObj("String", "my java object")
var v = "my var"

println("mys(string)=" + mys)
println("i(int)=" + i)
println("f(float)=" + f)
println("d(double)=" + d)
println("l(long)=" + l)
println("c(byte)=" + c)
println("b(bool)=" + b)
println("aa(struct)=" + aa)
println("myo(object)=" + myo)
println("v(var)=" + v)
println("------------------------")

# use of java.lang.String java class
object mystr2 = loadObj("String", "my Dpdl java String obj")
println("mystr2: " + mystr2)
bool isIn = mystr2.contains("Dpdl")
println("mystr2 contains 'Dpdl': " + isIn)
println("------------------------")

# use of a java.util.Clanendar
object calendar = getClass("Calendar")
object cal_inst = calendar.getInstance()
int day_ = cal_inst.get(calendar.DAY_OF_MONTH)
int month_ = cal_inst.get(calendar.MONTH)
int year_ = cal_inst.get(calendar.YEAR)
string mydate = day_ + "-" + month_ + "-" + year_
println("date: " + mydate)
println("------------------------")

# use a java.util.HashMap
object myhm = loadObj("HashMap")
myhm.put("my", 1)
myhm.put("Dpdl", 2)
myhm.put("java", 3)
myhm.put("hashmap", 4)
println("hashmap: " + myhm.toString())
println("------------------------")

# load a Dpdl script object
object mycode = loadCode("myModule.h", 1000)
mycode.printHello("myModule")
println("------------------------")

# embed C code
println("my embedded C code...")
dpdl_stack_push("dpdlbuf_var1", i, d, mystr)
>>c
	#include <stdio.h>
	#include <dpdl.h>

	int main(int argc, char **argv){
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
		for (cnt = 0; cnt < argc; cnt++){
			printf("	param %d: %s\n", cnt, argv[cnt]);
		}
		dpdl_stack_buf_put("myresult");
		return 0;
	}
<<
int exit_code = dpdl_exit_code()
println("embedded C exit code: " + exit_code)
string res = dpdl_stack_buf_get("dpdlbuf_var1")
println("result: " + res)
println("------------------------")

# embed python code
println("my embedded Python code")
>>python
languages = ['Dpdl', 'C', 'C++', 'Python', 'Julia', 'JavaScript', 'Lua', 'OCaml']

for language in languages:
	print(language)
<<
exit_code = dpdl_exit_code()
println("embedded Python exit code: " + exit_code)
println("------------------------")

prointln("...")
println("embed many other languages...")
println("...")
println("------------------------")

println("starting a dedicated script instance thread...")
int thread_instance = 0
string mythread_process = "myThreadProcess.h"
int ms_interval = 2000
int nr_iterations = 3
println("Executing a Thread process: " + mythread_process + " for " + nr_iterations + " iterations")
int status_t = DPDLAPI_createThread(thread_instance, mythread_process, dpdlMinPriority, ms_interval, nr_iterations)
while(DPDLAPI_threadRunning(thread_instance) == dpdlTrue)
	println(".")
	sleep(1000)
endwhile
println("finished")
println("")
println("------------------------")

println("starting Dpdl threads....")
int tIdx1 = Thread("myThreadHello", 2000, 5)
if(tIdx1 != -1)
	println("Thread started with id: " + tIdx1)
else
	println("Thread error")
fi
int tIdx2 = Thread("myThreadMessage", 3000, 3)
if(tIdx2 != -1)
	println("Thread started with id: " + tIdx2)
else
	println("Thread error")
fi
println("done")


