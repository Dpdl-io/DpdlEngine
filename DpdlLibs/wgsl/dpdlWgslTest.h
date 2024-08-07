# File: wgsl/dpdlWgslTest.h
#
# Example: Dpdl sample code that makes use of the dpdl language plug-in 'Wgsl' and the native library 'dpdlgpu' to execute a compute algorithm
#			directly on GPU. The plug-in enables to execute WGSL code, which is the WebGPU shading lanuguage (https://www.w3.org/TR/WGSL/),
#			that is than translated and executed on GPU hardware.
#
#			The algorithm below implements a "Gaussian Error Linear Units" (GELUs), a high-performing neural network activation function,
#			on an array of 10000 floating point numbers. More info on GELU in this paper: https://arxiv.org/pdf/1606.08415
#			Two tensors having a one dimensional shape, input and output, are allocated and passed to the kernel that binds the data
#			to the corresponding arrays within the wgsl code. The kernel runs asynchronously from the dpdl code that waits and copies
#			the data to the output buffer when ready.
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('native')

# main
println("testing Wgsl algorithm on GPU...")

println("loading native libraries 'c' and 'dpdlgpu'...")

object libc = native.loadLib("c")

object libgpu = native.loadLib("dpdlgpu")

raise(libgpu, "Error in loading 'dpdlgpu' lib")

println("getting dpdlgpu lib version...")

string ver = libgpu.DPDLNATIVE_GPU_getVersion()

println("version: " + ver)

# we allocate a data buffer with 10000 entries
long DATA_SIZE = 10000

# indexes of the tensors and kernel created
int idx_tensor_in = 0
int idx_tensor_out = 0
int idx_kernel = 0

println("allocating input buffer...")

object input_arr = libc.malloc(DATA_SIZE * 4)
input_arr.setMemory(0L, DATA_SIZE * 4, 0x00)

object output_arr = libc.malloc(DATA_SIZE * 4)
input_arr.setMemory(0L, DATA_SIZE * 4, 0x00)

println("populating input data...")

long cnt = 0L
float f_val
for(cnt < DATA_SIZE)
	f_val = rand_f(1000)
	input_arr.setFloat(cnt, f_val);
	cnt = cnt+1
endfor

int tensor_in = DPDLNATIVE_GPU_createTensorInputS1x1(idx_tensor_in, "f32", DATA_SIZE, input_arr)
int tensor_out =  DPDLNATIVE_GPU_createTensorOutputS1x1(idx_tensor_out, "f32", DATA_SIZE)

dpdl_stack_var_put("precision", "f32")
dpdl_stack_var_put("workgroup_size", "256, 1, 1")

dpdl_stack_push("dpdl:applyvars")

>>wgsl(gelu_alg)
const SCALING_FACTOR: f32 = 0.7978845608028654; // sqrt(2.0 / Math.PI)

@group(0) @binding(0) var<storage, read_write> inp: array<{{precision}}>;
@group(0) @binding(1) var<storage, read_write> out: array<{{precision}}>;
@group(0) @binding(1) var<storage, read_write> dummy: array<{{precision}}>;

@compute @workgroup_size({{workgroup_size}})
fn main(
    @builtin(global_invocation_id) GlobalInvocationID: vec3<u32>) {
    let i: u32 = GlobalInvocationID.x;
    if (i < arrayLength(&inp)) {
        let x: f32 = inp[i];
        out[i] = select(0.5 * x * (1.0 + tanh(SCALING_FACTOR
                 * (x + .044715 * x * x * x))), x, x > 10.0);
    }
}
<<
int exit_code = dpdl_exit_code()

println("Wgsl exit code: " + exit_code)

int kernel_status = DPDLNATIVE_GPU_createKernelS1x1(idx_kernel, idx_tensor_in, idx_tensor_out, DATA_SIZE)

int kernel_dispatch = DPDLNATIVE_GPU_dispatchKernel(idx_kernel)

int wait_copy = DPDLNATIVE_GPU_waitCopyCPU(idx_kernel, idx_tensor_out, output_arr, DATA_SIZE)

println("Output: ")

float f_val_in, f_val_out
long c = 0L
for(c < DATA_SIZE)
	f_val_in = input_arr.getFloat(c);
	f_val_out = output_arr.getFloat(c);

	println(f_val_in + "=" + f_val_out)

	c = c+1
endfor

println("finished")
