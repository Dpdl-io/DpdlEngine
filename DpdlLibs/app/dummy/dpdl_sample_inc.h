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

struct Data {
	int id
	int len
	string data
}

func myThreadFunc(int t_id)
    appRunning = true
	println("myThreadFunc with id: " + t_id)
	println("myapp.currentStatus=" + myapp.currentStatus)
	myapp.currentStatus = myapp.currentStatus+1

	mydata.id = myapp.currentStatus
	mydata.data = "some data: " + randInt(16, 100)
	mydata.len = strlen(mydata.data)

end

func dpdl_thread_finalize(int t_id)
	println("thread terminated with id: " + t_id)
	appRunning = false
end

func myNativeFunc(string datastr, int val)
	println("myNativeFunc...")

	dpdl_stack_push("dpdlbuf_myalg", datastr, val)

	>>c
	#include <stdio.h>
	#include <time.h>
	#include <dpdl.h>

	int main(int argc, char **argv){
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

func myAppInit()
	println("myAppInit")
	return 23
end

func getAppName()
	return myapp.name
end

func getDataNew()
	struct Data d
	d.id = 23
	d.data = "mydata new"
	d.len = strlen(d.data)
	return d
end

func getData()
	return mydata
end

func getApp()
	return myapp
end


enum Status appstatus
struct App myapp
struct Data mydata

bool appRunning = false
println("app_inc loaded")
printVersion()
println("myapp.currentStatus=" + myapp.currentStatus)

println("starting thread...")

int tIdx = Thread("myThreadFunc", 2000, 3)

raise(tIdx, "Error in starting thread")

println("thread starting with id: " + tIdx)


