# File: test/testConcurrentEmbeddedCode.h
#
# Example: Sample Dpdl script that executed concurrently 2 dpdl scripts with embedded C code
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

import("dpdllib.h")

# main
println("testing concurrent embedded code...")

int tIdx0 = createThread(0, "C/dpdlSampleC.h", dpdlNormPriority, 2000)
int tIdx1 = createThread(1, "C/dpdlSampleC.h", dpdlNormPriority, 2000)

println("threads running...")

