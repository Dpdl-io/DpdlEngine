# File: test/testClassSub2.h
#
# Example: Example Dpdl code that highlights Inheritance and Polymorphism of the type 'class'. It also shows
#			how embedded code sections in various programming languages can be embedded directly within Dpdl,
#			in this example java and C code
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct property {
	int max_weight_gr
	float max_height_m
	string desc = null
}

class Animal {
	int id
	string name
	struct property info = {100000, 2.5,.}

	func Animal(int id_)
		id = id_
		name = "No name"

		println("new Animal() with id: " + id + " info: " + info)
	end

	func Animal(int id_, string name_)
		id = id_
		name = name_

		println("new Animal with id: " + id + " and name: " + name + " - info: " + info)
	end

	func print()
		println("This is an Animal")
	end

	func makeSound()
		println("kind of animal is not defined")
	end

	func getHashMap()
		object h_map = loadObj("HashMap")

		info_arr[] = array(info)
		int i = 0
		for(i < info_arr.size())
			h_map.put(i, info_arr[i])
			i=i+1
		endfor

		return h_map
	end
}

class Dog : Animal {

	func Dog(int id_, string name_)
		super(id_, name_)

		info.max_weight_gr = 8000
		info.max_height_m = 0.5
		info.desc = "this breed is Shitzu"

		println("new Dog() with id: " + id + " and name: " + name + " - info: " + info)
	end

	func print()
		println("This is a Dog with name: " + name)
	end

	func makeSound()
		println("WOOF WOOF")
	end

	func makeSound(int times) int
		int ret_val

		dpdl_stack_push(times)

		>>java
			int iter = arg0.intValue();
			for(int i = 0; i < iter; i++){
				System.out.println("WOOF");
			}
			return 1;
		<<
		ret_val = dpdl_exit_code()

		return ret_val
	end

}

class Cat : Animal {

	func Cat(int id_, string name_)
		super(id_, name_)

		info.max_weight_gr = 1000
		info.max_height_m = 0.25
		info.desc = "thie breed is Siamese"

		println("new Cat() with id: " + id + " and name: " + name + " - info: " + info)
	end

	func print()
		println("This is a Cat with name: " + name)
	end

	func makeSound()
		println("MIAUU MIAUU")
	end

	func makeSound(int beep) int
		int ret_val

		dpdl_stack_obj_put("iter", beep)

		dpdl_stack_push("dpdl:applyvars")
		>>c
			#include <stdio.h>
			#include <unistd.h>

			// we output the character to ring 'bell' in the console
			for(int i = 0; i < {{iter}}; i++){
				putchar('\a');
			}
			return 23;
		<<
		ret_val = dpdl_exit_code()

		return ret_val
	end

}

println("testing class type Inheritance and Polymorphism...")
println("")

class Animal ani(1)

ani.print()
ani.makeSound()

println("")

class Dog mydog(2, "Rosa")

mydog.print()
mydog.makeSound()
int sd = mydog.makeSound(10)

object map_dog = mydog.getHashMap()
println("map dog: " + map_dog)

println("")

class Cat mycat(3, "Minni")

mycat.print()
mycat.makeSound()
int sc = mycat.makeSound(3)

object map_cat = mycat.getHashMap()
println("map cat: " + map_cat)

println("")
println("finished")
