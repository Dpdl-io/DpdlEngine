# File: test/testClass2.h
#
# Example: dpdl code that make use of 'class' types
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


struct myStruct {
	string desc
	int val
}


class A {
	string id = "baseA"

	int arr_i[2000]
	float arr_f[2000]

	func A()
		println("an obj A()")
	end

	func A(string id)
		println("an obj A(string)")
		this.id = id
	end

	func printId()
		println("my base id is: " + id)
	end

	func setId(string newid)
		id = newid
	end

	func init()
		println("init()")
		int i
		for(i < 2000)
			arr_i[i] = i
			arr_f[i] = to_float(i)
			i=i+1
		endfor
	end

	func printArr()
		int i
		for(i < 2000)
			println("arr_i[$i]=" + arr_i[i])
			println("arr_f[$i]=" + arr_f[i])
			i=i+1
		endfor
	end

}

class B extends A {

	int uuid

	struct myStruct data = {"desc B", 23}

	func B(int uuid_)
		super("mysubB")
		this.uuid = uuid
	end

	func myFunc()
		println("an B class function with id: " + id + " and uuid: " + uuid)
		println("data: " + data)
	end
}



println("example dpdl code that makes use of 'class' type ...")

class A ana()

println("ana: " + ana)

ana.init()
ana.printArr()

class B ab(888)

println("ab: " + ab)

ab.myFunc()
ab.printId()

println("ab.id: " + ab.id)
println("ab.uuid: " + ab.uuid)
println("ab.data: " + ab.data)

