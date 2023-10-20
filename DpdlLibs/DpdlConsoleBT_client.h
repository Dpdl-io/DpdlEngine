# File: DpdlConsoleBT_client.h
# Date: 21.07.2007
# Dpdl example: This script implements a bluetooth client console that connects to a bluetooth server and
#				accepts commands that are executed, i.e. executes a piece of Dpdl code.
#				On J2ME devices the console log and status is printed on a UI Form canvas
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
include("dpdlMIDP.h")
include("DPDLProt.h")

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


func startConsoleSession()
         string cmd = "null"
         while(cmd != dpdl_end_cmd)
             printScreen(".")
             cmd = readClientData(client)
             #we poll continuously for input commands from the server
             if(cmd == BT_TIMEOUT)
                 cmd = "null"
             else
                 if(cmd == dpdl_exec_cmd)
                      string script = readClientData(client)
                      if(script != "null" && script != BT_TIMEOUT)
                           printlnScreen(dpdl_exec_cmd)
                           printlnScreen("Script: ")
                           printlnScreen(script)
                           return DPDLAPI_execScript(script)
                      else
                           printlnScreen("no script received: BT_TIMEOUT")
                      fi
                 else if(cmd == dpdl_save_cmd)
                      printlnScreen(dpdl_save_cmd)
                 else
                      printlnScreen("no valid cmd")
                 fi
             fi
             sleep(100)
         endwhile
         return false
end


func run()
     #first we clear the previous log
     FormClear(TEXT_LOG)
     string rx = "null"
     string tx = "null"
     printlnScreen("Sending Session request...")
     tx = dpdl_console_cmd
     int x = sendClientData(client, tx)
     if(x == dpdlTrue)
         rx = readClientData(client)
         while(rx == "null")
             rx = readClientData(client)
             #we force data transfer as this script runs 1 time, no threading
             if(rx == BT_TIMEOUT)
                 rx = "null"
             fi
             sleep(100)
         endwhile
         printlnScreen("tx: " + tx)
         printlnScreen("rx: " + rx)
     else
         printlnScreen("no connection available")
         clearClientTXBuffer(client)
     fi
     if (rx != "null") && (rx != BT_TIMEOUT)
          if(rx == dpdl_ok_cmd)
                setStartTime()
                int s_runtime = startConsoleSession()
                int t_ms = getEndTime()
                printlnScreen("total processing time: " + t_ms + " ms")
                printlnScreen("clearing TX && RX Buffers")
                clearClientTXBuffer(client)
                clearClientRXBuffer(client)
                if(s_runtime == dpdlTrue)
                         printlnScreen("Session terminated successfully OK")
                else
                         printlnScreen("Runtime Error")
                         return dpdlFalse
                fi
                return dpdlTrue
          fi
     else
          printlnScreen("no answer")
     fi
     return dpdlTrue
end


#main
	 
     #client ->loaded statically at index 0, see DpdlConsoleBT_client.h_static
     int client = 0
     
     #TEXT_LOG ->loaded statically at index 0, see DpdlConsoleBT_client.h_static
     int TEXT_LOG = 0
     
     #we set the polling and timeout values to 10*100ms, internally readClientData(..)
     #runs every 100 ms for 10 times, until a data unit is buffered, usually at 1st time
     setRxTimeout(10, 100)
     int x__ = run()
