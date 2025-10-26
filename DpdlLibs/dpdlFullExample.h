# File: dpdlFullExample.h
#
# Example Dpdl script: embedding C and Python within Dpdl
#
# Author: A.C
# e-mail: ac@dpdl.io
#
#
# 

func printMap(object m)
	string res = ""
	string elem = ""
	object en = m.elements()
	while(en.hasMoreElements())
		elem = en.nextElement()
		res = res + elem + " "
	endwhile
	return res
end


# main
println("Dpdl embedded C and Python example")
println("")
object my_java_obj = new("String", "This is a test to access java API via Dpdl, every java class or library can be accessed in this way")
println(my_java_obj)
println("")
println("let's start...")
println("")
# we allocate a java object java.lang.Hashtable
object table = new("Hashtable")
table.put("dpdl", "Dpdl")
table.put("embed", "executes")
table.put("c", "C")
table.put("python", "Python")
table.put("ocaml", "OCaml")

println("Dpdl supports the following programming languages:")
string supported = printMap(table)
println(supported)
println("")
println("")

println("choose your preferred programming language:")
string input = readln()
println("")
println("checking if Dpdl supports it....")
bool b_isavail = table.contains(input)
println("Dpdl supports it: " + b_isavail)
println("")
println("")
println("lets code in Python...")

>>python
languages = ['Dpdl', 'C', 'Python', 'OCaml']

for language in languages:
	print(language)
<<

# again Dpdl
int exit_code = dpdl_exit_code()
println("")
println("embedded python exit code: " + exit_code)
println("")
println("-------------------------------------------------")
println("Do you want to execute the embedded 'C' code? type 'yes' if you want to execute it, 'no' otherwise:")
string confirm = readln()
if(confirm == "yes")

println("now we have an algorithm is C....")
string my_params = "test Dpdl with C"
double d1 = 23.0d
float f1 = 11.0
int x = 10

# we push the parameters on the dpdl stack so we can access them in C, we also push a 'dpdlbuf_*' variable so we can write to it in C, and retrieve it later from Dpdl
dpdl_stack_push("dpdlbuf_myresult", my_params, d1, f1, x)

>>c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dpdl.h>

int myAlgorithm(char *param, double d, float f, int n, int *a) {
    int i;

    printf("n = %d\n", n);
    for(i=0; i<n; i++){
       printf("%s | d=%lf f=%f a[%d] = %d\n", param, d, f, i, a[i]);
       a[i] = i + 100;
    }
    return 23;
}

int dpdl_main(int argc, char **argv){
	printf("Hello C from Dpdl!\n");
	printf("\n");
	printf("num params: %d\n", argc);
	int cnt;
    for (cnt = 0; cnt < argc; cnt++){
        printf("	param %d: %s\n", cnt, argv[cnt]);
    }
    
   	char my_params[256];
   	double d1;
   	float f1;
   	int x;
   	sscanf(argv[0], "%s", &my_params);
   	sscanf(argv[1], "%lf", &d1);
   	sscanf(argv[2], "%f", &f1);
   	sscanf(argv[3], "%d", &x);
   	
   	int mynum[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   	int alg_res = myAlgorithm(&my_params, d1, f1, x, &mynum);
   	
   	char buf_str[80];
   	sprintf(buf_str, "my algorithm result = %d", alg_res);
	dpdl_stack_buf_put(buf_str);
    return 0;
}
<<
# again Dpdl
exit_code = dpdl_exit_code()
string my_c_algorithm = dpdl_stack_buf_get("dpdlbuf_myresult")
println("Result from C alg: " + my_c_algorithm)

else
	println("check or edit the code if you want, and than execute")
fi

return 1