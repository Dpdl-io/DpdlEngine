# File: native/dpdlNativeExample.h
#
# Example: Dpdl sample code that loads a native library (libc) and calls some functions
#
#			This code allocates memory via the native function 'malloc' , opens a file in read-write mode, write some values
#			to the allocated buffer and writes the buffer to the file.
#			The file is than re-opened in read only mode and the values are readed back and printed out.
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('native')

# main
println("Dpdl sample code that uses native function calls to 'libc'")

println("loading 'libc' library...")

object clib = native.loadLib("c")

raise(clib, "Error in loading library")

println("getting uid...")

int uid = clib.getuid()
println("uid: " + uid)

println("opening file in RW mode for writing...")

object fcntl = getObj("Fcntl")

int fh = clib.open("./Test/TestWriteNative.txt", fcntl.O_RDWR)

raise(fh, "Error in opening file")

println("writing values...")

int i = 3
double d = 999.5d
float f = 23.0
long l = 10000000L

char ch1 = 'X'
char ch2 = 'D'
char ch3 = 'P'
char ch4 = 'D'
char ch5 = 'L'
char ch6 = 'X'
char ch7 = '\0'

object size = loadObj("size_t")
size.setValue(4096L)

long size_l = size.longValue()

object memory = clib.malloc(4096)
memory.setMemory(0L, 4096L, 0x00B)

println("memory: " + typeof(memory))

object bytebuf = memory.getByteBuffer(0L, size_l)

bytebuf.putInt(i)
bytebuf.putDouble(d)
bytebuf.putFloat(f)
bytebuf.putLong(l)

bytebuf.putChar(ch1)
bytebuf.putChar(ch2)
bytebuf.putChar(ch3)
bytebuf.putChar(ch4)
bytebuf.putChar(ch5)
bytebuf.putChar(ch6)
bytebuf.putChar(ch7)

object sz = clib.write(fh, memory, size)

println("nr of bytes written: " + sz)

clib.close(fh)

println("reading from file...")

fh = clib.open("./Test/TestWriteNative.txt", fcntl.O_RDONLY)

memory.setMemory(0L, 4096L, 0x00B)

object szr = clib.read(fh, memory, size)

println("nr of bytes read: " + szr)

object bufread = memory.getByteBuffer(0L, size_l)

object ri = bufread.getInt()
object rd = bufread.getDouble()
object rf = bufread.getFloat()
object rl = bufread.getLong()

object rch1 = bufread.getChar()
object rch2 = bufread.getChar()
object rch3 = bufread.getChar()
object rch4 = bufread.getChar()
object rch5 = bufread.getChar()
object rch6 = bufread.getChar()

println("values from file: ")
println("")
println("ri: " + ri)
println("rd: " + rd)
println("rf: " + rf)
println("rl: " + rl)

println("rch1: " + rch1)
println("rch2: " + rch2)
println("rch3: " + rch3)
println("rch4: " + rch4)
println("rch5: " + rch5)
println("rch6: " + rch6)

clib.close(fh)

println("")
println("finished")
