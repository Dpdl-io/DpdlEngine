# File: gpu/dpdlTritonExample.h
#
# Example: Sample dpdl code that executes a 'Trion' python-based compute kernel that runs on GPU
#			The kernel performs an addition of two tensors
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#

println("executing a compute kernel with Triton on GPU...")

object tensors = getObj("Tensors")

int tns_size = 98432

object tns_x = tensors.random(tns_size, 1)

object tns_y = tensors.random(tns_size, 1)

dpdl_stack_push(tns_size, tns_x, tns_y)

>>triton(my_compute)
	import torch

	import triton
	import triton.language as tl


	DEVICE = triton.runtime.driver.active.get_active_torch_device()

	@triton.jit
	def add(x_ptr, y_ptr, output_ptr, n_elements, BLOCK_SIZE: tl.constexpr):

		pid = tl.program_id(axis=0)

		block_start = pid * BLOCK_SIZE
		offsets = block_start + tl.arange(0, BLOCK_SIZE)

		mask = offsets < n_elements

		x = tl.load(x_ptr + offsets, mask=mask)
		y = tl.load(y_ptr + offsets, mask=mask)

		output = x + y

		tl.store(output_ptr + offsets, output, mask=mask)


	def dpdl_kernel(size, x: torch.Tensor, y: torch.Tensor):

	    output = torch.empty_like(x)

	    assert x.device == DEVICE and y.device == DEVICE and output.device == DEVICE

	    n_elements = output.numel()

	    grid = lambda meta: (triton.cdiv(n_elements, meta['BLOCK_SIZE']), )

	    add[grid](x, y, output, n_elements, BLOCK_SIZE=1024)

	    return output


<<
int exit_code = dpdl_exit_code()

println("exit_code: " + exit_code)

raise(exit_code, "Error in executing Triton kernel")

object output = dpdl_stack_obj_get(my_compute)

println("output: ")

println(output)


