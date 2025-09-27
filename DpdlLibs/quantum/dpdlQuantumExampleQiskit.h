# File: quantum/dpdlQuantumExampleQiskit.h
#
# Example: Dpdl example that generates a quantum circuit via embedded python code that uses the Qiskit quantum computing libraries.
#			The quantum circuit created is an entangled Bell pair (Bell state) with 2 qubits and 2 bits.
#           An ascii representation of the created circuit is returned as result on the dpdl stack
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#


println("generating a Bell pair quantum circuit...")

dpdl_stack_push("dpdbuf_circuit")

>>python
from qiskit import QuantumCircuit

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)

qc.measure([0, 1], [0, 1])

dpdl_stack_buf_put(qc)

<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in generating quantum circuit")

object qc = dpdl_stack_obj_get("dpdbuf_circuit")

println("generated quantum circuit: " + qc)

println("finished")
