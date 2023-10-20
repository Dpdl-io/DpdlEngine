# Dpdl Lib V1.0     
#
# (c)opyright 2003
# SEE Solutions
#
# info@dpdl.io
#
#
# This library is implemented with Dpdl scripting and comes with the standard core DpdlEngine.
# It contains system abstraction functions and internal variables.
#
# Filename: dpdltypes.h
# This module implements functions and variables to access arrays and threads
#
func allocArr(int pos, int minSize)
     return allocMemArray(pos, minSize)
end

func sizeArr(int pos)
     return getMemArraySize(pos)
end

#return int element index
func putArrInt(int pos, int val)
     return putMemArrayInt(pos,  val)
end

#return int element value
func getArrInt(int pos, int index)
     return getMemArrayInt(pos, index)
end

#return int element index
func putArrStr(int pos,  string val)
     return putMemArrayStr(pos,  val)
end

#return string element value
func getArrStr(int pos, int index)
     return getMemArrayStr(pos, index)
end

func setLock()
    dpdlLOCK = 1
end

func releaseLock()
    dpdlLOCK = 0
end

func getLock()
     return dpdlLOCK
end

func releaseLock()
    dpdlLOCK = 0
end


func createThread(int instance, string script_file, int priority, int milliseconds)
    return DPDLAPI_createThread(instance, script_file, priority, milliseconds)
end


func deleteThread(int id)
       return DPDLAPI_deleteThread(id)
end


#start of execution, LOCK is unused at beginning
int dpdlLOCK = 0
int dpdlthreadCount = 0
int dpdlTrue = 1
int dpdlFalse = 0
string dpdlNull = "null"
int dpdlNotFound = -2
int dpdlError = -1

#Thread variables
int dpdlMinPriority = 1
int dpdlMaxPriority = 10
int dpdlNormPriority = 5



