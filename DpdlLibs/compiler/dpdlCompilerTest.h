# File: compiler/dpdlCompilerTest.h
#
# Example: Dpdl example that makes use of the lib 'compiler' to compile an external java source unit and access
#			it as a dpdl object.
#
#			There are 2 distinct java classes (class 'A' that extends class 'B'), in java source form, located in a configurable folder.
#			Here are the java files: https://github.com/Dpdl-io/DpdlEngine/tree/main/Test/MyCode_dir
#
#			Class 'A' is compiled (along with B), loaded and accessed as a dpdl object
#
#
# author: A.Costa
# e-mail: ac@dpdl.io
#


import('compiler')

println("testing the lib 'compiler'...")

object cls = compiler.compileUnitJava("mypkga.A")

println("cls: " + cls + " is of type: " + typeof(cls))

int val = cls.testIt(888, "MEGA")

println("val: " + val)

println("finished")

