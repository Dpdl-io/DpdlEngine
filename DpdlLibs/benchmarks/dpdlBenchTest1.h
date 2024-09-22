# File: benchmarks/dpdlBenchTest1.h
#
# (c)opyright 2023 SEE Solutions
#
# Example: Simple benchmark to measure the execution speed of Dpdl function calls with access to JRE objects
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

struct MyS {
	long id
	int x, y
	int nr
	string desc
}

# main
println("performing simple benchmark on accessing Dpdl functions and JRE objects")

println("testing stack() and struct...")

println("pushing data onto the stack...")

object mys = stack()

int c = 0
while(c <= 10000)
	mys.push("item"+c)
	c=c+1
endwhile

println("popping data from the stack...")

var elem = "null"
while(elem != null)
	elem = mys.pop()
	if(elem != null)
		println("elem: " + elem)
		println("--------------------------")
	fi
endwhile

println("pushing a data struct onto the stack...")

struct MyS st
st.id = 9999999L
st.x = randInt(400)
st.y = randInt(400)
st.nr = c
st.desc = "my st->" + c

mys.push(cast(st))

println("popping data struct from the stack...")

object ste = mys.pop()

if(typeof(ste) == "struct:MyS")
	println("st.id: " + st.id)
	println("st.x: " + st.x)
	println("st.y: " + st.y)
	println("st.desc: " + st.desc)
	println("st.nr: " + st.nr)
else
	println("unknown type")
fi

println("")
println("testing access to jre objects...")

object myhash = loadObj("Hashtable")

myhash.put("Dpdl", "1")
myhash.put("Java", "2")
myhash.put("C", "3")

println("myhash has size: " + myhash.size())

bool isAvail = myhash.containsKey("Dpdl")

println("myhash contains 'Dpdl': " + isAvail)

println("")
println("testing map()...")

object mymap = map()

mymap.put(1, "a")
mymap.put(2, "b")
mymap.put(3, "c")

println("mymap: " + mymap)

string elem2 = mymap.get(2)

println("2nd element: " + elem2)

mymap.clear()

println("populating mymap...")

string item
int cnt = 1

for(cnt <= 10000)
	item="data_"+cnt
	mymap.put(cnt, item)
	cnt=cnt+1
endfor

println("iterating over mymap via an iterator...")

setStartTime()

object keys = mymap.keySet()
object iter = keys.iterator()

object key, val
while(iter.hasNext())
	key = iter.next()
	val = mymap.get(key)
	println("" + key + "=" + val)
endwhile

int ms = getEndTime()

println("")
println("exec time Result (ms): " + ms)
println("")

println("finished!")

