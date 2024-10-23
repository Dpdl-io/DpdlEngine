# File: app/dummy/dpdl_sample_inc.h
#
# Example: Small sample Dpdl dummy app to test some features
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

include("lib/myapplib.h")

enum Status {
	IDLE‚
	INIT,
	RUNNING=3,
	DONE=4,
	EXIT,
	ERROR=-1
}

struct App {
	string name = "MyApp"
	int id = 1
	int serial = 222
	int currentStatus = 0

	func getName()
		return name
	end
}

func myNativeFunc(string datastr, int val)
	println("myNativeFunc...")

	dpdl_stack_push("dpdlbuf_myalg", datastr, val)

	>>c
	#include <stdio.h>
	#include <time.h>
	#include <dpdl.h>

	int dpdl_main(int argc, char **argv){
		printf("Hello Dpdl C function\n");
		printf("\n");
		int start; // use time_t when compile option is set
		int end; // use time_t when compile option is set
		time(&start);
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
		for (cnt = 0; cnt < argc; cnt++){
			printf("	param %d: %s\n", cnt, argv[cnt]);
		}
		int n;
		char param[256];
		sscanf(argv[0], "%s", &param);
		sscanf(argv[1], "%d", &n);
		char res[256];
		int i;
		for(i = 0; i < n; i++){
			printf("Test %s %d \n", param, i);
		}
		time(&end);
		printf("\n");
		double exec_time = difftime(end, start);
		//printf("Exec time: %f \n", exec_time);
		sprintf(res, "My algorithm execution time native C code: %f ms", exec_time);
		dpdl_stack_buf_put(res);
		printf("done\n");
		return 0;
	}
	<<
	int exit_code = dpdl_exit_code()
	string buf_ret
	if(exit_code != -1)
		buf_ret = dpdl_stack_buf_get("dpdlbuf_myalg")
	fi
	printl("BUF: " + buf_ret)
	return buf_ret
end

func myAppInit() int
	println("myAppInit")
	return 23
end

func getAppName()
	return myapp.name
end

func fillDataMap()
	object hm = loadObj("HashMap")

	string val
	int c = 0
	for(c < 10)
		val = "this is myvalue:" + c
		hm.put(c, val)
		c = c+1
	endfor
	return hm
end

func getDataNew()
	struct Data d
	d.id = 23
	d.data = "mydata new"
	d.len = strlen(d.data)
	return d
end

func getData()
	return threadCode.mydata
end

func getDataMap()
	return datamap
end

func getApp()
	return myapp
end

func isRunning()
	bool brun = threadCode.isRunning("dpdl_sample_thread")
	return brun
end


enum Status appstatus
struct App myapp

println("app_inc loaded")
printVersion()
println("adding data map...")
object datamap = fillDataMap()
println("myapp.currentStatus=" + myapp.currentStatus)

println("starting thread...")
object threadCode= loadCode("app/dummy/dpdl_sample_thread.h", "myparam")
threadCode.ID = "New process " + getTime()
println("Now ID : " + threadCode.ID)
threadCode.start("dpdl_sample_thread")

sleep(2000)
println("")


