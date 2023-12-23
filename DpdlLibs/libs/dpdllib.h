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
# Filename: dpdllib.h
# This library provides some basic functions to allocate and search a Dpdl-Packet
#
import("dpdltypes.h")

func chunkAlloc(string pkgname, string chunk)
         int status = DPDLAPI_mallocDpdlService(pkgname)
         println("done malloc()")
         if status == dpdlTrue
              DPDLAPI_swapDpdlChunk(pkgname, chunk)
              println("chunkAlloc OK")
              return dpdlTrue
         else
              println("no need for chunk allocation, OK")
              return dpdlFalse
         fi
end

func searchData(string pkgName, string chunk, string constraint)
    int status = DPDLAPI_selectDpdlService(pkgName, chunk, constraint)
    if status == dpdlTrue
         DPDLAPI_projectData(chunk, constraint)
         if DPDLAPI_getDataState() == dpdlTrue
             println("Results ready")
             return dpdlTrue
         fi
         return dpdlFalse
    else
         println("error in quering Data")
         return dpdlFalse
    fi
end

func openLogFile(string file)
   dpdlHFILE = open(file, "w")
   return dpdlHFILE
end

func logToFile(string data)
    if dpdlHFILE == -1
       dpdlHFILE = open(file, "w")
       write(dpdlHFILE, data)
       println("data written")
    else
       write(dpdlHFILE, data)
    fi
end


#system variable definition
string DpdlLibVersion = "1.0"
int engineID = 0

#start Library execution
int dpdlHFILE = -1






