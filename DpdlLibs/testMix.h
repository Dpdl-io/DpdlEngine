include("testMixInc.h")

func mySubC()
	>>c
	#include <stdio.h>
	
	printf("Hello Sub C\n");
	<<
end

func myC(int x)
	println(x)
	
	>>c
	#include <stdio.h>
	
	printf("Hello from C\n");
	<<
	mySubC()
	
	println("--------------------------------")
end

func myPy(int x)
	println(x)
	
	>>python
	print("Hello from Python\n")
	<<
	
	println("--------------------------------")
end

func myLua(int x)
	println(x)
	
	>>lua
	io.write("Hello from Lua")
	print()
	<<
	
	println("--------------------------------")
end

func myJulia(int x)
	println(x)
	
	>>julia
	println("Hello from Lua")
	println("")
	l = ["Dpdl", "supports", "Julia"]  
	for i in l
    	println(i)
	end 
	return 1
	<<
	
	println("--------------------------------")
end

func myRoot(int x)
	println(x)
	
	>>root
	printf("Hello from ROOT\n");
	printf("\n");

	auto r  = new TRandom();	
	double x, y, z, P = 6.;
	int np = 4;
	
	for (int N=0; N<np; N++) {
		x = 2*P*(r->Rndm(N))-P;
		y = 2*P*(r->Rndm(N))-P;
		z = (sin(x)/x)*(sin(y)/y)+0.2;
		printf("x=%lf y=%lf z=%lf \n", x, y, z);
	}
	<<
	
	println("--------------------------------")
end

# main
int nr_iter = 40

println("testing include...")
testInc()

println("embedding C...")
int c = 0
while(c < nr_iter)
	myC(c)
	c = c+1
endwhile	

println("embedding Python...")
c = 0
while(c < nr_iter)
	myPy(c)
	c = c+1
endwhile

println("embedding Lua...")
c = 0
while(c < nr_iter)
	myLua(c)
	c = c+1
endwhile

println("embedding Julia...")
c = 0
while(c < nr_iter)
	myJulia(c)
	c = c+1
endwhile

println("embedding ROOT...")
c = 0
while(c < nr_iter)
	myRoot(c)
	c = c+1
endwhile

return 1