# File: dpdlCodeExecExample.h
#
# Example: Inline Dpdl script execution using a dedicated DpdlEngine instance
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
println("-------------------------------")
# native DpdlEngine API calls
println("testing native DpdlEngine API calls")
object display = new("dpdl.dpdlUI.Display")
object dpdl_engine = new("dpdl.dpdlDpdlEngine.DpdlEngine", display)
println("DpdlEngine loaded...")
dpdl_engine.DPDLAPI_initDpdlScripting()
object mySubscript = new("String", "println(\"Hello\")")
object script_vec = new("Vector")
script_vec.add(mySubscript)
dpdl_engine.DPDLAPI_execDpdlCode(script_vec)
println("done")
println("")
