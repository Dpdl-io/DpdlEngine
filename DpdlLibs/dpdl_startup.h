# File: dpdl_startup.h
# Date: 03.09.2009
#
# Startup code for the DpdlEngine. This script is executed when the DpdlEngine starts if EXEC_STARTUP_CODE is set true
# NOTE: This file cannot be changed for the Demo and for unregistered Dpdl licenses
#
# Example: Run the script bluetoothDiscoverySave.h in a dedicated Thread
#
# (c)opyright 2003
# SEE Solutions
#
# e-mail: info@dpdl.io
#
#
include("dpdllib.h")

func printlnScreen(string m)
     println(m+"\n")
end

func printScreen(string m)
     print(m)
end

string dpdl_script = "bluetoothDiscoverySave.h"

int commThread = 0

printlnScreen("--------------------------")
printlnScreen("init() dpdl_startup.h")
printlnScreen("please wait while initializing " + dpdl_script)

int DELAY_PAUSE = 1000
int SERVER_REFRESH = 5000
int server = -1

server = createThread(commThread, dpdl_script, dpdlNormPriority, SERVER_REFRESH)

if server == dpdlTrue
    printlnScreen(dpdl_script + " inited: " + server + " Thread interval: " + SERVER_REFRESH + " ms")
else
    printlnScreen("Error in starting " + dpdl_script)
fi

printlnScreen("--------------------------")

