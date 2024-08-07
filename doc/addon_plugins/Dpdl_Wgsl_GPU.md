# Dpdl Wgsl GPU

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io
				

developed by
**SEE Solutions**
&copy; 2003
		

## Dpdl 'Wgsl' plug-in (on GPU)

The dedicated dpdl language plug-in 'Wgsl' can execute WGSL (WebGPU Shading Language) compute code, which is executed on GPU and complies to the [WebGPU](https://www.w3.org/TR/webgpu/) specification, directly embedded within Dpdl code.

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
```


