# File: importantMsgWriter.h
#
# Example: This script can be used to input and store messages to be sent by the BTObexServer.h script.
#		   The messages are store in the record store BTObexServer_MSGQueue
#
# (c)opyright 2009
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
import("dpdlMIDP.h")

func saveMsg(string m)
    if(MSG_RS != -1)
         int idx = addRecord(MSG_RS, m)
         println("msg saved: " + m)
    fi
end

func startWriter()
   string msgz = dpdlNull
   while(running)
        println("enter a msg to broadcast (q == quit):")
        msgz = readln()
        if(msgz == "q")
           running = dpdlFalse
        else
            saveMsg(msgz)
        fi
        println("")
   endwhile
end

#entry point
int MSG_RS = 0
int running = dpdlTrue
startWriter()

