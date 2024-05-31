# File: test/testGenObjCode.h
#
# Example: Dpdl example that uses the API function 'genObjCode' to convert/compile a 'struct' into a native java bytecode object.
#			The resulting object can be accessed in the same way as an ordinary object.
#
#			The first declaration of embedded java code (>>java) is also compiled into the resulting object
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct A {
	string id = "myid"
	int account = 23
	double myd = 999.9d
	float myf = 1.9
	long myl = 10000000L
	short mys = 100s
	byte myb = 0x01
	char mych = 'A'
	bool mybool = true
	object myobj = null

	>>java
	public int myNativeJavaFunc(int val){
		System.out.println("myNativeJavaFunc()");
		for(int i = 0; i < 10; i++){
			System.out.println("iter: " + i + " val: " + (val+i));
		}
		return (val+3);
	}
	<<

	func testFunc()
		println("testFunc()")

		>>java
			System.out.println("This message comes from java");
			return 1;
		<<
	end

	func testN()
		println("testN()")

		>>c
		#include <stdio.h>

		printf("This message comes from C\n");

		return 0;
		<<
	end

}

# main
println("testing 'genObjCode'...")

struct A a
a.testFunc()
a.testN()

object myAobj = genObjCode(a)

println("myAobj: " + myAobj)

println("myAobj.id: " + myAobj.id)
println("myAobj.account: " + myAobj.account)

println("calling native java bytecode method...")

int res = myAobj.myNativeJavaFunc(23)

println("res: " + res)

println("finished")
