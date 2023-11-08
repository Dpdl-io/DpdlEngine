# File: dpdlRootSaveImg.h
#
# Example: 
# This Dpdl script executes an embedded 'ROOT' C/C++ script that opens an existing PNG image and saves it to a JPG format
#			
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main

println("test embedded ROOT C/C++...")

>>root
   TImage *img = TImage::Open("./Test/Dpdl.png");
   if (!img) {
      printf("Error: Could not open image\n");
      return;
   }
 
   img->WriteImage("./Test/Dpdl.jpg");
<<

int exit_code = dpdl_exit_code()

println("embedded ROOT exit code: " + exit_code)