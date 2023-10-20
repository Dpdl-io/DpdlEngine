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
object display = loadObj("dpdl.dpdlUI.Display")
object dpdl_engine = loadObj("dpdl.dpdlDpdlEngine.DpdlEngine", display)
println("DpdlEngine loaded...")
dpdl_engine.DPDLAPI_initDpdlScripting()
object mySubscript = loadObj("String", "println(\"Hello\")")
object script_vec = loadObj("Vector")
script_vec.add(mySubscript)
dpdl_engine.DPDLAPI_execDpdlCode(script_vec)
println("done")
println("")
