# File: recordStoreExample.h
#
# Example: create, populate and iterate a record store
# Note: a shortcuts of the functions are available in dpdlRS.h
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
include("dpdllib.h")
include("dpdlBT.h")
include("dpdlRS.h")

func saveData(string data)
     if(PTR_RS != -1)
         int id = DPDLLIB_addRSData(PTR_RS, data)
         println("rec ID:" + id)
         println("data: " + data)
     fi
end


# main
string my_record_store_name = "MyRecordStore"
int nr_records = 10
int c = 0

println("opening RecordStore: " + my_record_store_name)
int PTR_RS = DPDLLIB_openRS(my_record_store_name, AUTHMODE_ANY, dpdlTrue, dpdlTrue)
DPDLLIB_enumRecords(PTR_RS, dpdlTrue)
println("--------------------------------")
println("adding data...")
while(c < nr_records)
	saveData("data=" + c)
	c = c + 1
endwhile
println("--------------------------------")
int nr_elements_rs  =  DPDLLIB_getNumRecords(PTR_RS)
println("nr. of records in recordstore: "+ nr_elements_rs)
closeRS(PTR_RS)
println("--------------------------------")
int rec_id = 1
string record_data = ""
println("showing data in recordstore...")
PTR_RS = DPDLLIB_openRS(my_record_store_name, AUTHMODE_ANY, dpdlTrue, dpdlTrue)
DPDLLIB_enumRecords(PTR_RS, dpdlTrue)
DPDLLIB_rebuildEnum(PTR_RS)
while(rec_id != -1)
	rec_id = DPDLLIB_getNextRecordID(PTR_RS)
	println("fetching next record id: " + rec_id)
	record_data = DPDLLIB_getRSData(PTR_RS, rec_id)
	println("rec_id: " + rec_id + " record_data: " + record_data)
endwhile
closeRS(PTR_RS)
println("--------------------------------")
println("done")
