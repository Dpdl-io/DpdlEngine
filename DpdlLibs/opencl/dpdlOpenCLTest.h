# File: opencl/dpdlOpenCLTest.h
#
# Example: Dpdl sample code that makes use of the Dpdl language plug-in 'dpdlopencl' to execute embedded OCL code (OpenCL)
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('native')

# main
println("testing simple OpenGl algorithm on GPU...")

println("loading native libraries 'libc' and 'libdpdlopencl'...")

object libc = native.loadLib("c")

raise(libc, "Error in loading 'libc'")

object libgpu = native.loadLib("dpdlopencl")

raise(libgpu, "Error in loading 'libdpdlopencl'")

println("getting dpdlopencl version...")

string ver = libgpu.DPDLNATIVE_OPENCL_getVersion()

println("version: " + ver)

# we allocate a data buffer with 10000 entries, each 8 bytes of memory
long DATA_SIZE = 10000L
long byte_cnt = 8L

println("allocating input buffer...")

object input_arr1 = libc.malloc(DATA_SIZE * byte_cnt)
input_arr1.setMemory(0L, DATA_SIZE * byte_cnt, 0x00)

object input_arr2 = libc.malloc(DATA_SIZE * byte_cnt)
input_arr2.setMemory(0L, DATA_SIZE * byte_cnt, 0x00)

object output_arr = libc.malloc(DATA_SIZE * byte_cnt)
input_arr.setMemory(0L, DATA_SIZE * byte_cnt, 0x00)

println("populating some random input data...")

long cnt = 0L
double d_val
int tmp
for(cnt < DATA_SIZE)
	tmp = randInt(16, 1000)
	d_val = to_double(tmp)

	input_arr1.setDouble(cnt, d_val)
	input_arr2.setDouble(cnt, d_val+3000.0d)

	cnt = cnt+1L
endfor

# indexes of input & output vectors
int idx_vec_a = 0
int idx_vec_b = 1
int idx_vec_c = 2

int status

status = libgpu.DPDLNATIVE_OPENCL_addVec(idx_vec_a, "f64", DATA_SIZE, input_arr1)
status = libgpu.DPDLNATIVE_OPENCL_addVec(idx_vec_b, "f64", DATA_SIZE, input_arr2)
status = libgpu.DPDLNATIVE_OPENCL_addVec(idx_vec_c, "f64", DATA_SIZE, output_arr)

println("executing kernel...")

>>ocl
	#if defined(cl_khr_fp64)
	#  pragma OPENCL EXTENSION cl_khr_fp64: enable
	#elif defined(cl_amd_fp64)
	#  pragma OPENCL EXTENSION cl_amd_fp64: enable
	#else
	#  error double precision is not supported
	#endif

	kernel void dpdl_kernel(global const double *a, global const double *b, global double *c) {
		size_t gid = get_global_id(0);
		c[gid] = a[gid] + b[gid];
	};
<<

int exit_code = dpdl_exit_code()

println("embedded ocl exit code: " + exit_code)

int wait_copy = libgpu.DPDLNATIVE_OPENCL_waitReadBuffer(idx_vec_c, output_arr, DATA_SIZE)

println("OUTPUT: ")

double d_val_out
long c = 0L
for(c < DATA_SIZE)
	d_val_out = output_arr.getDouble(c)

	println("output_arr[" + c + "]=" + d_val_out)

	c = c+1L
endfor

println("finished")
