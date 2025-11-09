# File: dpdlJsExample.h
#
# Example:
# This Dpdl script executes an embedded 'js' javascript, variables are pushed to the dpdl stack and intercepted in the javascript code
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("test embedding javascript ...")

dpdl_stack_push("dpdlplugin:nashorn");

dpdl_stack_var_put("var1", "MEGA")
dpdl_stack_var_put("var2", "MEGA")

>>js
    print("Hello javascript from Dpdl: ");
    print("")
    print("var1: " + var1);
    print("var2: " + var2);
    print("The number PI is equal to: " + java.lang.Math.PI);
    print("")
    var importFile = new JavaImporter(java.util);  
    var a = new importFile.ArrayList();  
    a.add(12);  
    a.add(20);  
    print(a);  
    print(a.getClass());          
<<

int exit_code = dpdl_exit_code()

println("embedded js exit code: " + exit_code)