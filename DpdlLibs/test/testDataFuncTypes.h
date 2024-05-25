# File: test/testDataFuncTypes.h
#
# Example: Sample Dpdl script that uses vec(...), map(...), list(...) and stack(...) data function objects
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing data function types...")

println("")
println("testing vec(...)")

object data = vec("a", "b", "c", "d", "e", "f")

object myvec = vec(1, 2, 3, 4, 5, data)

println("myvec: " + myvec + " type: " + typeof(myvec))

println("myvec: " + myvec)

object first_e = myvec.elementAt(0)

println("first element: " + first_e)

println("adding element...")
myvec.add("Test")

object last_e = myvec.lastElement()

println("last element: " + last_e)


println("------------------------------------------------------------------")
println("testing map(...)")

object mymap = map("a:3", "b:6", "c:9")

println("mymap: " + mymap + " type: " + typeof(mymap))

println("contains key 'b': " + mymap.containsKey("b"))
println("contains value '9': " + mymap.containsValue("9"))

println("contains value 'not_avail': " + mymap.containsValue("not_avail"))

object entry_set = mymap.entrySet()
object iter = entry_set.iterator()
object entry
string key, val

for(iter.hasNext())
	entry = iter.next()
	key = entry.getKey()
	val = entry.getValue()
	println("key: " + key + " val: " + val)
endfor

println("------------------------------------------------------------------")
println("testing list(...)")

object mylist = list("A", "Costa", 1, 0.3, 999.9d, 10000L)

println("mylist: " + mylist + " type: " + typeof(mylist))

mylist.add(2, "Software Engineer")

object elem1 = mylist.get(0)
object elem2 = mylist.get(1)
object elem3 = mylist.get(2)
object elem4 = mylist.get(3)
object elem5 = mylist.get(4)
object elem6 = mylist.get(5)
object elem7 = mylist.get(6)

println("elem1: " + elem1 + " type: " + typeof(elem1))
println("elem2: " + elem2 + " type: " + typeof(elem2))
println("elem3: " + elem3 + " type: " + typeof(elem3))
println("elem4: " + elem4 + " type: " + typeof(elem4))
println("elem5: " + elem5 + " type: " + typeof(elem5))
println("elem6: " + elem6 + " type: " + typeof(elem6))
println("elem7: " + elem7 + " type: " + typeof(elem7))

println("removing first element...")

mylist.removeFirst()

elem1 = mylist.get(0)

println("elem1: " + elem1)

println("------------------------------------------------------------------")
println("testing stack(...)")

object mystack = stack()

mystack.push(1)
mystack.push("a")
mystack.push("b")
mystack.push(2)

object lastelem = mystack.peek()
println("last element: " + lastelem)

lastelem = mystack.pop()
println("last element removed: " + lastelem)

object lastelem = mystack.pop()
println("last element: " + lastelem)

int idx = mystack.search("a")
println("value 'a' is at index: " + idx)



