# File: groovy/dpdlGroovyExample.h
#
# Example: Dpdl script that embeds and executes a dummy 'Groovy' code block
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


# main
println("testing dpdl embedded 'groovy' code...")

string var1 = "this is a sample string parameter"
int var2 = 23

dpdl_stack_var_put("myvar1", var1)
dpdl_stack_obj_put("myvar2", var2)

>>groovy

class Parent {
   def fName
   def lName
   def listOfChildren = []
}

class Child {
   def propertyOne
   def propertyTwo
}

def dpdl_main(Object[] args, Object var_map){

   println("dpdl stack variable map: " + var_map.toString())

   def p = new Parent();
   def cOne = new Child();
   def cTwo = new Child();

   p.fName ="Armin"
   p.lName ="Costa"

   cOne.propertyOne = "Alexis"
   cOne.propertyTwo = "b"

   cTwo.propertyOne = "Billy"
   cTwo.propertyTwo = "d"

   p.listOfChildren.add(cOne)
   p.listOfChildren.add(cTwo)

   println("First name: " + p.fName)
   println("Last name: " + p.lName)

   println("Children: ")
   p.listOfChildren.each{ foo->
       println(foo.propertyOne)
   }

   println "done"

   return (Object)new Integer(1);
}

<<
int exit_code = dpdl_exit_code()

println("embedded groovy exit code: " + exit_code)
