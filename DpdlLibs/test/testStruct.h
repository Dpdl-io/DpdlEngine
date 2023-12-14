# File: test/testStruct.h
#
# Example: Test Dpdl script with structs
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

func myPrint(string str)
	println("myPrint: " + str)
end

struct B {
	int x = 10
	int y = 20
	string s = "B"
	arr[] = "a,b,c,d"
	object so = loadObj("String", "my java obj " + s)

	object vec = loadObj("Vector")
	object hashmap = loadObj("HashMap")

	myPrint(s)

	println(arr[0])
	println(arr[1])
	println(arr[2])
	println(arr[3])

	vec.add(arr[0])
	vec.add(arr[1])
	vec.add(arr[2])
	vec.add(arr[3])

	hashmap.put("1", arr[0])
	hashmap.put("2", arr[1])
	hashmap.put("3", arr[2])
	hashmap.put("4", arr[3])

	func thisBFunc()
		println("thisBFunc: " + s + " so: " + so)
	end

	func aGeneralFunc()
		println("aGeneralFunc: " + s)
	end

	func printHashMap()
		println("hashmap: ")
		raise(hashmap, "hashmap is null")

		object keys = hashmap.entrySet()
		object iter = keys.iterator()
		object entry
		string key, value
		while(iter.hasNext())
			entry = iter.next()
			key = entry.getKey()
			value = entry.getValue()
			println("key=" + key + " value=" + value)
		endwhile
	end

	func printVector()
		println("vector: ")
		raise(vec, "vec is null")

		object enum__ = vec.elements()
		while(enum__.hasMoreElements())
			println("" + enum__.nextElement())
		endwhile
	end
}

struct A {
	int x = 1
	int y = 2
	string s = "A"
	object so = loadObj("String", "my java obj " + s)
	struct B bs

	myPrint(s)
	println(bs)

	func thisAFunc()
		println("thisAFunc: " + s + " so: " + so)
		return 23
	end

	func aGeneralFunc()
		println("aGeneralFunc: " + s)
	end
}

func retStruct(var i, var j)
	println(i.s + " " + i + " | type: " + typeof(i))
	println(j.s + " " + j + " | type: " + typeof(j))
	struct A ret
	ret.x = i.x + j.x
	ret.y = i.y + j.y
	ret.s = i.s + j.s
	ret.so = i.so + " * " + j.so

	return ret
end

func passStruct(struct i)
	println("passed struct: " + i)
end

# main
println("testing struct...")

println("allocating some struct...")
struct A a
struct B b

println("a: " + a)
println("b: " + b)
println("inner struct of a: " + a.bs)

println("changing values of b...")
b.x = 100
b.y = 200
println("a: " + a)
println("b: " + b)

println("summing x y s values of a and b...")
var sum = retStruct(a, b)
println("returned type: " + typeof(sum))
println("sum: " + sum)

println("passing struct to function...")
passStruct(sum)

println("calling different name functions...")
a.thisAFunc()
b.thisBFunc()

println("calling same name functions...")
a.aGeneralFunc()
b.aGeneralFunc()

println("print vector of b...")
b.printVector()
prntln("print hashmap of b...")
b.printHashMap()


println("testing for...")
a.x = 6
a.y = 6
int cnt = 0
for(cnt < 5)
	println(a)
	a.x = a.x + cnt^16
	a.y = a.y + cnt^16
	cnt = cnt + 1
endfor
