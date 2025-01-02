# File: java/dpdlJavaExample2.h
#
# Example: Dpdl script that makes use of an embedded java code bock to perform some dummy calculations on an array passed from Dpdl
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedded java code block...")

int myarr[300000]
int myi = 100

int c
for(c < 300000)
	myarr[c] = c
	c=c+1
endfor

dpdl_stack_push(myarr, myi)

setStartTime()

>>java

System.out.println("Parameters: ");
System.out.println("	arg0: " + arg0);
System.out.println("	arg1: " + arg1);


static int[] myCalc(int[] arr){
	int[] arr_n = new int[arr.length];
	for(int i = 0; i < arr.length-1; i++){
		arr_n[i] = (arr[i] * arr[i+1]) + 10;
	}
	return arr_n;
}


int[] res = myCalc(arg0);

for(int x = 0; x < res.length; x++){
	System.out.println("res[" + x + "]=" + res[x]);
}

return 1;
<<

int ms = getEndTime()

int exit_code = dpdl_exit_code()

println("embedded java exit code: " + exit_code + " exec time (ms): " + ms)