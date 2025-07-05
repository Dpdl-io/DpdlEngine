/**
 file: test_dpdl_code_exec2.c

 This example C program shows how to execute embedded Dpdl code within a C program.

 Author: ac@dpdl.io
  
*/
#include <stdio.h>
#include "dpdl.h"


char *dpdl_src_code =   ""
                        "int c = 0      \n"
                        "for(c < 1000)  \n"
                        "       println('This is Dpdl from C=' + c)     \n"
                        "       c=c+1\n \n"
                        "endfor \n";


int main(int argc, char **argv){

	printf("executing Dpdl code from C...\n");

	int ret = dpdl_exec_code(dpdl_src_code);

	printf("ret: %d\n", ret);

	return 0;
}
