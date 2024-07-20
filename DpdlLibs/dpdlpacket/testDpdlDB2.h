# File: dpdlpacket/testDpdlDB2.h
#
# Example: Dpdl Script implementation that shows how to access and query data stored in a Dpdl-Packet (dpdl_PHONEBOOK.dpdl)
#		   that has been encoded with dpdl_PHONEBOOK.c source
#
# 		   This implementation assumes that the provided Dpdl packet dpdl_PHONEBOOK has already been installed.
#		   If the selected chunks are not yet allocated, allocation will be done at the first run. Data can be exported
#		   to a *.csv file or to a record store if export_data = dpdlTrue
#
# (c)opyright 2003
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
import("dpdllib.h")
import("dpdlRS.h")
#import("dpdlMIDP.h")

func init()
   println("init() testDpdlDB2.h")
end

func addToCSV(string name, string phoneNR, string email)
	string entry = "" + name + ";" + phoneNR + ";" + email + ""
	if(hfile != dpdlError)
		write(hfile, entry)
		println("entry added..")
	else
		println("Error in opening file for writing")
	fi
end

func addToRecordStore(string name, string phoneNR, string email)
	object entry
	if(PTR_RS != -1)
		println("adding record to recordstore...")
		object baos = loadObj("ByteArrayOutputStream")
		object outputStream = loadObj("DataOutputStream", baos)
			
		outputStream.writeUTF(name)
		outputStream.writeUTF(phoneNR)
		outputStream.writeUTF(email)

		object byte_arr = baos.toByteArray()
			
		entry = loadObj("String", byte_arr)
		int id = DPDLLIB_addRSData(PTR_RS, entry.toString())
	else
		println("Error opening record store for writing")
	fi
end
	
func showResults()
     string name_
     string phoneNR
     string email
     int nr_res = DPDLAPI_getNrResults()
     int c = 0
     println("Results: " + nr_res + " ---->");
     if(nr_res > 0)
         # we just show one result-set in this example
         while(c < nr_res)
              name_ = DPDLAPI_getResultSet(c, "name")
              phoneNR = DPDLAPI_getResultSet(c, "phoneNR")
              email = DPDLAPI_getResultSet(c, "e-mail")
              println("                       name: " + name_)
              println("                       phone nr.: " + phoneNR)
              println("                       e-mail: " + email)
              println("-----------------------------------------")
              if(name_ != dpdlNull && export_data)
              	 addToCSV(name_, phoneNR, email)
              	 #addToRecordStore(name_, phoneNR, email)
              fi
              c=c+1
         endwhile
         println("#######################")
     else
         println("no results found")
     fi
end

# script entry point
string DPDL_PACKET_NAME = "dpdl_PHONEBOOK"
string DPDL_CHUNK_NAME = "BolzanoPhone"
string data_export_file = "./TEST/BolzanoPhone.csv"
string data_export_rs = "dpdl_PHONEBOOK"
int export_data = dpdlFalse

# for stats
int total_ms = 0
int end_ms = 0

println("starting...")
init()

println("allocating Dpdl Service...")
int status = dpdlError
println("swapping chunks..")
status = DPDLAPI_swapDpdlChunk(DPDL_PACKET_NAME, DPDL_CHUNK_NAME)
println("status: " + status)
println("finished swapping..")

string constraint_ = dpdlNull
int PTR_RS = -1

int hfile = dpdlError
if(export_data == dpdlTrue)
   hfile = open(data_export_file, "w")
   PTR_RS = DPDLLIB_openRS(data_export_rs, AUTHMODE_ANY, dpdlTrue, dpdlTrue)
fi
status = dpdlTrue
if(status == dpdlTrue)
         int c = 0
         int i = 1
         string search_key = ""
         int search_rand_int = 0
         println("running queries...")
         println("press 'q' to query from the console, else ENTER to run 48877 queries automatically")
         int console_input = dpdlFalse
         string read_console = readln()
         if(read_console == "q")
              console_input = dpdlTrue
         else
         	  println("enter a constraint base name: $basename $counter")
              constraint_ = readln()
              constraint_ = constraint_ + " "
         fi
         int count_single_query = 0
         long time_start_ms, time_end_ms, time_total_ms
         time_start_ms = currentTimeMillis()
         while(c < 48877)
              if(console_input)
                  println("enter a key to search ('q' to quit):")
                  search_key = readln()
                  if(search_key == "q")
                  	c = 48877
                  fi
                  count_single_query = count_single_query + 1
              else
              	  search_rand_int = randInt(32, 48877)
              	  search_rand_int = i #abs(search_rand_int) # i
                  println("-->   searching: "+(constraint_+search_rand_int))
                  search_key = (constraint_+search_rand_int)
              fi
              setStartTime()
              status = DPDLAPI_selectDpdlService(DPDL_PACKET_NAME, DPDL_CHUNK_NAME, search_key)
              end_ms = getEndTime()
              total_ms = total_ms + end_ms
              if(status == dpdlTrue)
              	showResults()
              else
              	println("Error in select")
              fi
              c = c+1
              i = i+1
         endwhile
         time_end_ms = currentTimeMillis()
         time_total_ms = time_end_ms - time_start_ms
         int total_records = 48877
         if(count_single_query != 0)
         	total_records = count_single_query
         fi
         int time_exec = total_ms / total_records
         println("average query execution time(ms): " + time_exec)
         println("total execution time(ms): " + time_total_ms)
fi
if(export_data == dpdlTrue)
   close(hfile)
   closeRS(PTR_RS)
fi

