# File: slang/dpdlSlangExample.h
#
# Example: This dpdl example makes use of an 'embedded code section' in Slang Shading Language code
#			that compiles a compute shader to SPRIV and executes it
#
# author: A.Costa
# e-mail: ac@dpdl.io
#

import('native')
import('shader')


println("testing a shader with slang...")

long DATA_SIZE = 1000000L
long byte_cnt = 4L

object libc = native.loadLib("c")

object buf0 = libc.malloc(DATA_SIZE * byte_cnt)
buf0.setMemory(0L, DATA_SIZE * byte_cnt, 0x00B)

object buf1 = libc.malloc(DATA_SIZE * byte_cnt)
buf1.setMemory(0L, DATA_SIZE * byte_cnt, 0x00B)

object res = libc.malloc(DATA_SIZE * byte_cnt)
res.setMemory(0L, DATA_SIZE * byte_cnt, 0x00B)

int s1 = shader.DPDLNATIVE_addBuffer(0, "f32", DATA_SIZE, buf0)

int s2 = shader.DPDLNATIVE_addBuffer(1, "f32", DATA_SIZE, buf1)

int s3 = shader.DPDLNATIVE_addBuffer(2, "f32", DATA_SIZE, res)

int status = s1 & s2 & s3

raise(status, "Error allocating buffers")

println("populating input buffers...")

long cnt = 0L
float f_val
int tmp
for(cnt < DATA_SIZE)
	tmp = randInt(16, 1000)
	f_val = to_float(tmp)

	buf0.setFloat(cnt, f_val)

	buf1.setFloat(cnt, f_val * 2.0f)

	cnt = cnt+1L
endfor

println("compiling and executing compute shader...")

>>slang
	StructuredBuffer<float> buffer0;
	StructuredBuffer<float> buffer1;
	RWStructuredBuffer<float> result;

	[shader("compute")]
	[numthreads(1,1,1)]
	void dpdl_main(uint3 threadId : SV_DispatchThreadID){
		uint index = threadId.x;
		result[index] = buffer0[index] + buffer1[index];
	}
<<
int exit_code = dpdl_exit_code()

println("embedded shader exit code: " + exit_code)

raise(exit_code, "Error in executing compute shader")

println("RESULT:")

float f_val
long c = 0L
for(c < DATA_SIZE)
	f_val = res.getFloat(c)
	print(f_val + " ")
	c = c+1L
endfor

println("finished")
