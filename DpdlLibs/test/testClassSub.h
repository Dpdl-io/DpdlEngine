# File: test/testClassSub.h
#
# Example: Sample Dpdl code to test derived 'class' type inheritance
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


class A {
	int id = -1

	func A(int id_)
		id = id_
	end

	func setId(int id_)
		id = id_
	end

	func getId() int
		return id
	end

	func print()
		println("the id of this class is: " + id)
	end

	func printMe()
		println("ME: -> A")
	end
}

class B : A {
	string desc = "this is derived class from A"

	func B(int id_)
		super(id_)
	end

	func setDesc(string d)
		desc = d
	end

	func getDesc() string
		return desc
	end

	func printMe()
		println("ME: -> B")
	end

	func printMeAgain()
		println("ME AGAIN: -> B")
	end
}

class C : B {
	int id = 369
	string desc = "this is a class derived from B"

	func C(int id_)
		super(id_)
	end

	func print()
		id = 23
		println("the id of this class is: " + id)
	end

	func printMeAgain()
		println("ME AGAIN: -> C")
	end

}


# main
println("testing inheritance and polymorphism on type 'class'")
println("")

class A a(123)
class B b(456)
class C c(789)

println("A :")
println("a.id -> " + a.id)
println("")

println("B :")
println("b.id -> " + b.id)
b.setId(888)
println("b.id -> " + b.id)
b.print()
b.printMe()
println("")

println("C :")
println("c.id -> " + c.id)
c.setId(888)
println("c.id -> " + c.id)
c.print()
c.printMe()
c.printMeAgain()
println("")
