# Dpdl - GPU compute

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		
 

Dpdl enables to execute compute intensive algorithms directly on GPGPUs or GPUs.

This can be performed via embedded code sections implemented directly in OCL (OpenCL) or Wgsl (Web GPU Shading Language) code.

The following **Dpdl language plug-ins** that enable GPU compute are currently available:

	- Dpdl language plugin 'opencl'
	- Dpdl language plugin 'wgsl'


## Dpdl language plugin 'opencl'

This dedicated Dpdl language plug-in for 'OpenCL' can execute OCL (**OpenCL Compute Language**) compute code, which can be executed directly on GPGPUs, GPU's and even on multiple ordinary CPUs.

**Exmample:**

```python
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

```

## Dpdl language plugin 'Wgsl'

This dedicated dpdl language plug-in for 'Wgsl' can execute WGSL (**WebGPU Shading Language**) compute code, which is executed on GPUs and complies to the [WebGPU](https://www.w3.org/TR/webgpu/) specification, directly embedded within Dpdl code.

The WGSL language can be used to programmatically execute workloads of graphic compute pipelines as well as compute algorithms directly on GPUs and GPGPU's

The 'Wgsl' dpdl language plug-in supports all major GPU platforms such as Nvidia, Intel, AMD, and others. The WGSL code embedded with this plug-in can run on a wide variety of laptops, workstations, mobile devices and any hardware with Vulkan, Metal, or DirectX support.


**Example:**

```python
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
long DATA_SIZE = 10000L
long byte_cnt = 4L

# indexes of the tensors & kernel created
int idx_tensor_in = 1
int idx_tensor_out = 1
int idx_kernel = 1

println("allocating input buffer...")

object input_arr = libc.malloc(DATA_SIZE * byte_cnt)
input_arr.setMemory(0L, DATA_SIZE * byte_cnt, 0x00B)

object output_arr = libc.malloc(DATA_SIZE * byte_cnt)
input_arr.setMemory(0L, DATA_SIZE * byte_cnt, 0x00B)

println("populating input data...")

long cnt = 0L
float f_val
int tmp
for(cnt < DATA_SIZE)
	tmp = randInt(16, 1000)
	f_val = to_float(tmp)

	input_arr.setFloat(cnt, f_val)

	cnt = cnt+1L
endfor

int status_in = libgpu.DPDLNATIVE_GPU_createTensorInputS1x1(idx_tensor_in, "f32", DATA_SIZE, input_arr)
int status_out =  libgpu.DPDLNATIVE_GPU_createTensorOutputS1x1(idx_tensor_out, "f32", DATA_SIZE)


dpdl_stack_var_put("precision", "f32")
dpdl_stack_var_put("workgroup_size", "256, 1, 1")

dpdl_stack_push("dpdl:applyvars")

>>wgsl
const SCALE_FACTOR: f32 = 0.7978845608028654; // sqrt(2.0 / Math.PI)

@group(0) @binding(0) var<storage, read_write> inp: array<{{precision}}>;
@group(0) @binding(1) var<storage, read_write> out: array<{{precision}}>;

@compute @workgroup_size({{workgroup_size}})
fn main(
    @builtin(global_invocation_id) GlobalInvocationID: vec3<u32>) {
    let i: u32 = GlobalInvocationID.x;
    if (i < arrayLength(&inp)) {
        let x: f32 = inp[i];
        out[i] = select(0.5 * x * (1.0 + tanh(SCALE_FACTOR
                 * (x + .044715 * x * x * x))), x, x > 10.0);
    }
}
<<
int exit_code = dpdl_exit_code()

println("Wgsl exit code: " + exit_code)

int status_kernel = libgpu.DPDLNATIVE_GPU_createKernelS1x1(idx_kernel, idx_tensor_in, idx_tensor_out, DATA_SIZE)

int status_dispatch = libgpu.DPDLNATIVE_GPU_dispatchKernel(idx_kernel)

int wait_copy = libgpu.DPDLNATIVE_GPU_waitCopyCPU(idx_kernel, idx_tensor_out, output_arr, DATA_SIZE)

println("OUTPUT: ")

float f_val_in, f_val_out
long c = 0L
for(c < DATA_SIZE)
	f_val_in = input_arr.getFloat(c)
	f_val_out = output_arr.getFloat(c)

	println(f_val_in + "=" + f_val_out)

	c = c+1L
endfor

println("finished")

```


