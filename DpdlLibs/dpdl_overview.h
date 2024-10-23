# File: dpdl_overview.h
#
# Example: Sample dummy Dpdl script that shows most language features
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import("dpdllib.h")

func myThread_1(int t_id, string param)
	println("Hello from Dpdl Thread: " + t_id)
	println("param: " + param)
	println("time: " + getTime())
	println("---------------------------------------------------")
end

func myThread_2(int t_id)
	println("Message from Dpdl Thread: " + t_id)
end

func dpdl_thread_finalize(int t_id)
	println("Thread finalized: " + t_id)
end

func mySimpleFunc(object myobj)
	println("mySimpleFunc")
	println("myobj: " + myobj)
	myobj = myobj + " append my str mega"
	return myobj
end

func myFuncRetType() int
	println("myFuncRetType")
	return 79
end

enum status {
	INIT,
	DONE,
	OK,
	ERROR = -1
}

struct A {
	string s = "an A"
	int key = 232323
}

struct myStruct {
	int x = 10
	float f = 0.1
	double d = 0.3d
	long l = 1000L
	short sh = 10s
	byte b = 0x01
	bool bo = true
	string s = "Test my code"
	var v = "a generic var type, dispatched at runtime"
	object o = loadObj("String", "my java obj str")

	struct A mya
	enum status stat

	println("myStruct")

	func myStructCall()
		println("myStructCall: " + s)
		return 23
	end

	func getA()
		mya.s = "This is my returned struct A"
		return mya
	end
}

class MyClass {
	int id
	string msg = "I'm a dpdl class"

	struct myStruct data

	func MyClass(int nid)
		id = nid
	end

	func printMsg()
		println(msg)
		println("data: " + data)
	end

}

# main
bool startThreads = false
println("a sample program written with Dpdl (Dynamic Packet Definition Language). (c) 2003 Armin Costa...")

class MyClass myc

myc.printMsg()

string mystr = "my message: "
object mystrobj = "my dpdl object"
string msg = mySimpleFunc("my message: ")
object msg2 = mySimpleFunc(mystrobj)
println("msg: " + msg)
println("msg2: " + msg2)
println("msg2 ends with 'mega': " + msg2.endsWith("mega"))

int ii = myFuncRetType()
int *iip = &ii
println("ii: " + ii)
println("*iip: " + *iip)
ii = ii + 23
println("*iip: " + *iip)

var iiv = myFuncRetType()
println("iiv: " + iiv)

struct myStruct a
enum status st
println("myStruct a: " + a)
println("a.x: " + a.x)

println("calling struct function...")
int s_ret = a.myStructCall()
println("s_ret: " + s_ret)

println("getting inner struct of a...")
struct A ax
ax = a.getA()
println("ax: " + ax)
object myAobj = a.getA()
println("myAobj.s: " + myAobj.s)
println("myAobj.key: " + myAobj.key)

println("enum status st: " + st)
println("st.DONE: " + st.DONE)
println("st.ERROR: " + st.ERROR)

println("array allocation and access...")

myarr[] = [1, 2, 3, 4 , 5, 6]
myarr_mix[] = [1, 0.1, 23.0d, 1000L, "mega"]

myarr2[] = "1, 2, 3, 4 , 5, 6"
myarr_mix2[] = "1, 0.1, 23.0d, 0x01, 1000L, mega"

println("myarr: " + myarr)
println("myarr_mix: " + myarr_mix)
int s = myarr_mix.size()
println("size: " + s)

myarr_mix[0] = a
println("myarr_mix: " + myarr_mix)
s = myarr_mix.size()
println("size: " + s)

object myarrlist = myarr_mix.getArrObj()
println("myarrlist: " + myarrlist.toString())
println("")
println("Iterating over...")
int c = 0
int size = myarr_mix.size()
for(c < size)
	println("myarr_mix[" + c + "]=" + myarr_mix[c] + " is of type: " + typeof(myarr_mix[c]))
	c = c+1
endfor
println("")
println("Iterating over using arraylist obj...")
object iter = myarrlist.iterator()
var elem
while(iter.hasNext())
	println("myarrlist item: " + iter.next() + "")
endwhile

my_new_arr[] = array(a)
println("my_new_arr: " + my_new_arr)
println("------------------------")
println("Supported types:")

string mys = "my string"
int i = 3
float f = 0.1
double d = 0.2d
long l = 1000000L
short sh = 10s
byte c = 0x02
char ch = 'a'
object stro = "a Test str"

bool b = true
struct myStruct aa
object myo = loadObj("String", "my java object")
var v = "my var"
var v2 = 10

println("mys=" + mys + " type=" + typeof(mys))
println("i=" + i + " type=" + typeof(i))
println("f=" + f + " type=" + typeof(f))
println("d=" + d + " type=" + typeof(d))
println("l=" + l + " type=" + typeof(l))
println("sh=" + sh + " type=" + typeof(sh))
println("c=" + c + " type=" + typeof(c))
println("ch=" + ch + " type=" + typeof(ch))
println("stro=" + stro + " type=" + typeof(stro))
println("b=" + b + " type=" + typeof(b))
println("aa=" + aa + " type=" + typeof(aa))
println("myo=" + myo + " type=" + typeof(myo))
println("v=" + v + " type=" + typeof(v))


println("the variable 'v' is of type: " + typeof(v))
println("the variable 'v2' is of type: " + typeof(v2))
println("the variable 'i' is of type: " + typeof(i))

println("------------------------")

# use of a java.lang.String
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

	int dpdl_main(int argc, char **argv){
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

println("")
println("Now we embed some native java code...")

string str = "this is my str parameter"
int i = 100
float f = 0.2
double d = 9999.9d

dpdl_stack_push(str, "./Test/TestRead.txt", i, f, d)

>>java

System.out.println("Parameters: ");
System.out.println("	arg0: " + arg0);
System.out.println("	arg1: " + arg1);
System.out.println("	arg2: " + arg2);
System.out.println("	arg3: " + arg3);
System.out.println("	arg4: " + arg3);

static void myMethod1(){
	System.out.println("myMethod1: " + 1);
}

myMethod1();
myMethod2();

static void myMethod2(){
	System.out.println("method2: " + 2);
}

for(int x = 0; x < 3; x++){
	System.out.println("x: " + x);
}

File myfile = new File(arg1);

StringBuilder stringBuilder = new StringBuilder();

try{
	BufferedReader reader = new BufferedReader(new FileReader(myfile));

	String line = null;
	while ((line = reader.readLine()) != null) {
		stringBuilder.append(line);
	}
}catch(Exception e){
	System.out.println("Error in reading file");
}

System.out.println("myfile content: " + stringBuilder.toString());

return 1;
<<

int exit_code = dpdl_exit_code()
println("embedded java exit code: " + exit_code)

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
println("Executing Thread process: " + mythread_process + "  nr. iterations: " + nr_iterations)
int status_t = DPDLAPI_createThread(thread_instance, mythread_process, 1, ms_interval, nr_iterations)
while(DPDLAPI_threadRunning(thread_instance) == dpdlTrue)
	println(".")
	sleep(1000)
endwhile
println("finished")
println("")
println("------------------------")

if(startThreads)
	println("starting Dpdl threads....")
	int tIdx1 = Thread("myThread_1", 3000, 5, "passing some param")
	if(tIdx1 != -1)
		println("Thread started with id: " + tIdx1)
	else
		println("Thread error")
	fi
	sleep(2000)
	int tIdx2 = Thread("myThread_2", 3000, 3)
	if(tIdx2 != -1)
		println("Thread started with id: " + tIdx2)
	else
		println("Thread error")
	fi
else
	println("startThreads is: " + startThreads)
fi
println("done")

struct myA {
	string id = "this is an A"
	int y = 23
}

struct myA mya

object myload = loadCode("test/MyLC.h")
myload.myFunc("MyLC")

println("s: " + myload.s)
println("x: " + myload.x)
println("mystr: " + myload.mystr)

mya = myload.myFuncStructMod("MyLC", mya)
println("myanew: " + mya)
println("mya.id: " + mya.id)
println("mya.y: " + mya.y)

println("-------------------------------------")
int myx = 6
int myy = 3
println("this is also possible: ${ println(\"res=\" + (myload.x + mya.y))}")
