# File: BTObexServer.h
#
# Example: This script implements a Bluetooth Obex Server that reads messages from a record store
#		   and sends them to the discovered bluetooth devices via SMS. On J2ME devices the log is printed on a UI Form.
#		   To write messages to the record store the script importantMsgWriter.h is used.
#		   This script has been tested on MIDP CLDC 1.0 and CLDC 2.0
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
import("dpdlMIDP.h")

func printlnScreen(string m)
     if TEXT_LOG != -1
         int x =  FormAppend(TEXT_LOG, m+"\n")
     else
         println(m)
     fi
end

func printScreen(string m)
     if TEXT_LOG != -1
        int x = FormAppend(TEXT_LOG, m)
     else
         print(m)
     fi
end

func sendImportantMsg(string dev)
     int status_send = dpdlFalse
     int id = -1
     string d = dpdlNull
     string msg_to = dpdlNull
     int cnt_ = 0
     if(MSG_QUEUE_HIGH != -1)
        printlnScreen("Important Msgs -------------")
        DPDLLIB_rebuildEnum(MSG_QUEUE_HIGH)
        int nr_ = getEnumNrRecords(MSG_QUEUE_HIGH)
        printlnScreen("# Msgs in Queue HIGH: " + nr_)
            cnt_ = nr_-1
            while cnt_ < nr_
                id = getNextRecordID(MSG_QUEUE_HIGH)
                printlnScreen("next recID: " + id)
                if id != -1
                  d = getRecord(MSG_QUEUE_HIGH, id)
                  msg_to = "Notification Message: \n  "+d+"\n\n  <time sent:  " + getTime() + "  >"
                  printlnScreen("msg: " + msg_to)
                  status_send = DPDLAPI_sendObex(dev, dpdlTrue, msg_to)
                fi
                cnt_ = cnt_+1
                sleep(1000)
            endwhile
            printlnScreen("Status sending: " + status_send)
     fi
end


func run()
     #first we clear the previous log
     FormClear(TEXT_LOG)
     s1 = DPDLAPI_searchClientsOnServer()
     int status_discovery = dpdlFalse
     int service_discovery = dpdlFalse
     int counter_ = 0
     string dev = "n"
     while (status_discovery != dpdlTrue) && (service_discovery != dpdlTrue)
         status_discovery = DPDLAPI_discoveryServerFinished()
         service_discovery = DPDLAPI_serviceDiscoveryServerFinished()
         printScreen(".")
         sleep(2000)
         counter_ = counter_+1
     endwhile
     println("")
	 int dev_found = 0
     while(dev != "null")
          dev = DPDLAPI_getServerVisibleBTAddr()
          if(dev != "null")
              println("dev visible: " + dev)
			  dev_found = dev_found + 1
			  println("sending data...")
			  sendImportantMsg(dev)
          fi
     endwhile
	 if(dev_found == 0)
		println("No device found")
	 fi
     return dpdlTrue
end

#start of execution
#this will be replaced by getStaticContext("TEXT_LOG")
int TEXT_LOG = 1
int MSG_QUEUE_HIGH = 0
int s1, s2, s3, s4, s5, s6 = 0

#we set the polling and timeout values to 10*100ms, internally readClientData(..)
#runs every 100 ms for 10 times, until a data unit is buffered, usually at 1st time
setRxTimeout(10, 100)
int x = run()
