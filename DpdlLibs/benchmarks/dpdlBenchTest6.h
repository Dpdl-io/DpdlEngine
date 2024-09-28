# File: benchmarks/dpdlBenchTest6.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple benchmark that makes use of 'class'
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


class A {
	string id = "A"
	object myvec = vec()

	func getId() string
		return id
	end

	func addItem(object o)
		myvec.addElement(o)
	end

	func printValues()
		object iter = myvec.iterator()
		while(iter.hasNext())
			println("item=" + iter.next())
		endwhile
		println("")
	end
}


class B {
	string id = "B"
	object so = loadObj("String", id)
	object values = arr(1.0, 2, 3, 4, 5, 6.3d, 7s, 8, 9L, "x", "y", "z", so)

	func getId() string
		return id
	end

	func printValues()
	 	int size = values.size()
		int i
		for(i < size)
			var elem = values.get(i)
			println("i=" + elem + " is of type:: " + typeof(elem))
			i=i+1
		endfor
		println("")
	end
}

# main
println("testing 'class'...")

class A mya
class B myb

println("mya id: " + mya.getId())
println("myb id: " + myb.getId())

println("populating mya vector...")

setStartTime()

int i
for(i < 100000)
	mya.addItem(i)
	i=i+1
endfor


println("mya values:")
mya.printValues()

println("myb values:")
myb.printValues()

int ms = getEndTime()

println("exec time (ms) " + ms)

