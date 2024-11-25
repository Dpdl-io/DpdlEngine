# File: micropython/dpdlMicroPythonTest.h
#
# Example: This example shows how to embed and execute micropython code within Dpdl. MicroPython is a lightweight
#			Python 3 implementation for embedded-systems
#
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

# main
println("testing embedded micropython code...")

>>mpython
for i in range(10000):
	print('iter {:08}'.format(i))

try:
	1//0
except Exception as er:
	print('caught exception', repr(er))

address_book = {'Costa A.':'2604 Crosswind Drive','Alexis B.':'1301 Hillview Drive','Billy I.':'3236 Goldleaf Lane'}

print("'ACosta' address: " + address_book['Costa A.'])

import gc
print('run GC collect')
gc.collect()

print('finish')

<<
int exit_code = dpdl_exit_code()

println("exit code: " + exit_code)
