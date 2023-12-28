# File: app/dummy/dpdl_sample.h
#
# Example: Small sample Dpdl dummy app to test some features
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

include("dpdl_sample_inc.h")
import("dpdllib.h")

struct myStruct {
	int x = 23
}

struct App {
	int val = 999
}

struct myStruct st
struct App a

println("DpdlLib version: " + DpdlLibVersion)
println("app starting...")
println("st.x : " + st.x)
println("app.val: " + a.val)

int status = myAppInit()

raise(status, "Error in starting application")

object app = getApp()
println("app name: " + app.name)
println("app name get: " + app.getName())
println("app id: " + app.id)
println("app serial: " + app.serial)

object d = getDataNew()
println("d: " + d)
println("d.id: " + d.id)
println("d.data: " + d.data)
println("d.len: " + d.len)

println("calling function with native C function...")
enum Status status
int curr = status.RUNNING
println("current status: " + curr)

string res = myNativeFunc(d.data, 500000)
curr = status.DONE

println("current status: " + curr)
println("result: " + res)

println("done")
sleep(2000)

object myd
int cnt = 0
while(isRunning())
	myd = getData()
	if(myd != null)
		println("Data myd: " + myd)
		println("myd.id: " + myd.id)
		println("myd.data: " + myd.data)
		println("myd.len: " + myd.len)
	fi
	if((cnt % 30) == 0)
		println("running garbage collector...")
		gc()
	else
		println("waiting from main App thread to complete...")
	fi
	cnt = cnt+1
	sleep(1000)
	println("--------------------------------------------------------------")
endwhile

println("getting data map...")

object dm = getDataMap()

raise(dm, "data map is null")

println("iterating over hashmap elements...")

object es = dm.entrySet()
object iter = es.iterator()
object ep
while(iter.hasNext())
	ep = iter.next()
	println("key=" + ep.getKey() + " value=" + ep.getValue())
endwhile

println("finished")

