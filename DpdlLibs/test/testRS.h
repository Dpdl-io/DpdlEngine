# File: test/testRS.h
#
# Example: Test Dpdl script that uses build-in Record Stores.
#		   This script in uses the 'dpdlRS.h' lib to abstract the Dpdl api, you may use the DPDLAPI_* functions directly
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

import("dpdllib.h")
import("dpdlRS.h")

# main
println("testing record store..")

println("creating a record store...")

int rs_id = createRS("myrecords", AUTHMODE_ANY, dpdlTrue, dpdlTrue)

raise(rs_id, "Error: unable to create record store")

println("record store created with id: " + rs_id)

int rec_id
string data
int cnt = 0
while(cnt < 10)
	data = "my test data " + cnt

	rec_id = addRecord(rs_id, data)

	raise(rec_id, "Error in adding record")

	println("record added with id: " + rec_id)

	cnt = cnt+1
endwhile

println("reading data from record store...")

enumRecords(rs_id, dpdlTrue)


while(rec_id != -1)
	rec_id = getNextRecordID(rs_id)
	if(rec_id != -1)
		println("getting record with id: " + rec_id)
		data = getRecord(rs_id, rec_id)
		println("rec_id: " + rec_id + " data: " + data)
	fi
endwhile

println("closing record store...")

closeRS(rs_id)

println("done")
