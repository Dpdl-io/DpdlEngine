# File: benchmarks/dpdlBenchTest3.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple benchmark to measure the execution speed of 'struct' function calls (with embedded Java code),
#			compiled and executed with java bytecode
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


struct MyStruct {
	string id
	int nr = 10
	int x
	int y

	func print()
		println("id: " + id +  " x: " + x + " y: ")
	end

	func setXY(int x_, int y_)
		x = x_
		y = y_
	end

	>>java
	public long iterate(int nr){
		long start, end;

		start = System.currentTimeMillis();

		for(int i = 0; i < nr; i++){
			System.out.println("i: " + i + " id: " + id + " x: " + x + " y: " + y);
		}

		end = System.currentTimeMillis();

		return (end-start);
	}

	public void setId(String id){
		this.id = id;
	}

	public String getId(){
		return this.id;
	}

	public void setXYj(int x, int y){
		this.x = x;
		this.y = y;
	}
	<<
}

# main
println("performing simple benchmark on 'struct' java function calls compiled and executed with java bytecode")

struct MyStruct mys
mys.setXY(10, 20)

println("mys: " + mys)

object myso = genObjCode(mys)

myso.setId("Test 1")
long t1 = myso.iterate(100000)

myso.setId("Test 2")
myso.setXYj(30, 40)
long t2 = myso.iterate(1000000)

println("")
println("execution time Results:")

println("t1 (ms): " + t1)
println("t2 (ms): " + t2)

println("")
println("finished")
