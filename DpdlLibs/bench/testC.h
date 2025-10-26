# File: bench/testC.h
#
# Example: 
# This test Dpdl script executes an embedded 'C' code accepting parameters pushed on the dpdl_stack, and
# writes some result to the buffer variable 'dpdlbuf_*' which is than intercepted again in Dpdl
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

func myAlg(object hm_p, string param, int n)
	println("myAlg(..)")
	int hm_size = hm_p.size()
	println("hashmap size: " + hm_size)
	int hash = hash(hm_p.get("test"))
	hash = abs(hash)
	param = param + " " + hash
	
	dpdl_stack_push(buf_key, param, hm_p.get("test"), n)
	
	>>c
	#include <stdio.h>
	#include <stdlib.h>
	#include <dpdl.h>
	
	int dpdl_main(int argc, char **argv){
		printf("--------------------------------------\n");
		printf("Hello C from Dpdl!\n");
		printf("\n");
		printf("num params: %d\n", argc);
		int cnt;
	    for (cnt = 0; cnt < argc; cnt++){
	        printf("	param %d: %s\n", cnt, argv[cnt]);
	    }
	    int n;
	    char param[256];
	    sscanf(argv[0], "%s", &param);
	    sscanf(argv[2], "%d", &n);
	    char res[256];
	    int i;
	    for(i = 0; i < n; i++){
	    	sprintf(res, "%s %d",param, i); 
	    }
	    dpdl_stack_buf_put(res);
	   	printf("--------------------------------------\n");
	    return 0;
	}
	<<
	string buf = dpdl_stack_buf_get(buf_key)
	println("response buffer: " + buf)
end

# main
println("starting test C bench...")

# buffer key
string buf_key = "dpdlbuf_myalg"

object hm = new("HashMap")
hm.put("test", "sometest")

object *hm_p = &hm

string param = "MEGA"
int n = 1000
int cnt = 0

setStartTime()
while(cnt < n)
	println("counter: " + cnt)
	param = "MEGA " + cnt
	myAlg(hm, param, abs(randInt(8, 32)))
	cnt = cnt + 1
endwhile
int exec_ms = getEndTime()
println("finished in " + exec_ms + " milliseconds")
