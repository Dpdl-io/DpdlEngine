# File: testRSConcurrency.h
# Date: 03.09.2009
# Dpdl example: add records to test1 and test2 record stores and read by enumeration the records.
#				This test has been implemented to test concurrent access on record stores
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
include("dpdlMIDP.h")
func printlnScreen(string m)
     println(m+"\n")
end

func printScreen(string m)
     print(m)
end

func saveMsg(string msg_)
     int id = -1
     if(RS1 != -1)
         id = addRecord(RS1, msg_)
         printlnScreen("Msg:" + msg_ + " ID:" + id)
         printlnScreen("OutBox(1) Msg saved")
     fi
     if(RS2 != -1)
         id = addRecord(RS2, msg_)
         printlnScreen("Msg:" + msg_ + " ID:" + id)
         printlnScreen("OutBox(2) Msg saved")
     fi
end

func readMsgOutbox1()
     string msg_out = "null"
     if(RS1 != -1)
         #we send only the last in the queue for now
         int nr_rec = 0
         nr_rec = getNrRecords(RS1)
         println("nr records: " + nr_rec)
         if(nr_rec > 0)
               nr_rec = getNextRecordID(RS1)
               println("rec id: " + nr_rec)
               if nr_rec != -1
                    msg_out = getRecord(RS1, nr_rec)
               fi
               printlnScreen("Msg:" + msg_out + " ID:" + nr_rec)
               printlnScreen("in Outbox(1) available")
               deleteRecord(RS1, nr_rec)
         else
               msg_out = "null"
         fi
       #  resetEnum(RS1)
     fi
     return msg_out
end

func readMsgOutbox2()
     string msg_out = "null"
     if(RS2 != -1)
         #we send only the last in the queue for now
         int nr_rec = 0
         nr_rec = getNrRecords(RS2)
         if(nr_rec > 0)
               nr_rec = getNextRecordID(RS2)
               if nr_rec != -1
                    msg_out = getRecord(RS2, nr_rec)
               fi
               printlnScreen("Msg:" + msg_out + " ID:" + nr_rec)
               printlnScreen("in Outbox(2) available")
               deleteRecord(RS2, nr_rec)
         else
               msg_out = "null"
         fi
        # resetEnum(RS2)
     fi
     return msg_out
end

#main
println("mega")
printlnScreen("initTestRS()")
int RS1 = createRS("test1", AUTHMODE_ANY, dpdlTrue, dpdlTrue)
int RS2 = createRS("test2", AUTHMODE_ANY, dpdlTrue, dpdlTrue)
enumRecords(RS1, dpdlTrue)
enumRecords(RS2, dpdlTrue)
printlnScreen("record stores created")
int cc = 1
string m1 = dpdlNull
string m2 = dpdlNull
string str_ = dpdlNull
int nr_rec = -1
int id_rec = -1
while(dpdlTrue && (cc < 40))
    str_ = "mega"+cc
    saveMsg(str_)
    nr_rec = getNrRecords(RS1)
    id_rec = getNextRecordID(RS1)
    printlnScreen("nr_rec: " + nr_rec + "   id_rec: " + id_rec)
    sleep(20)
    cc = cc+1
endwhile
closeRS(RS1)
closeRS(RS2)

# we open again the RS 
RS1 = createRS("test1", AUTHMODE_ANY, dpdlFalse, dpdlFalse)
RS2 = createRS("test2", AUTHMODE_ANY, dpdlFalse, dpdlFalse)
enumRecords(RS1, dpdlTrue)
enumRecords(RS2, dpdlTrue)
cc = 0
while(dpdlTrue && (cc < 40))
    m1 = readMsgOutbox1()
    m2 = readMsgOutbox2()
    printlnScreen("m1: " + m1)
    printlnScreen("m2: " + m2)
    sleep(10)
    cc = cc+1
endwhile
int status = dpdlFalse
status = closeRS(RS1)
status = closeRS(RS2)
status = deleteRS("test1")
status = deleteRS("test2")
printlnScreen("finished()")
