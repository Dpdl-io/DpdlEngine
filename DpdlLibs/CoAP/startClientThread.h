# File: startClientThread.h
#
# Example: This script executes the dpdlCoAPClient2.h CoAP client in a dedicated thread
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
include("dpdllib.h")

#main
println("starting CoAP client thread...")
int status = createThread(0, "CoAP/dpdlCoAPClient2.h", dpdlMinPriority, 3000)
println("started: " + status)
