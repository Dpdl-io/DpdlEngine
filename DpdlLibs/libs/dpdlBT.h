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
# Filename: dpdlBT.h
# This library provides functions for accessing Bluetooth (JSR 82)
#


# the function allows customization of read- and write-out operations, speed vs. accurancy
func setRxTimeout(int timeout_read, int time_slice)
     TIMEOUT_READ = timeout_read
     TIMESLICE = time_slice
end

func sendClientData(int device, string data)
      return DPDLAPI_sendClientData(device, data)
end

func readClientData(int device)
      string data = "null"
      int cnt = 1
      while data == "null"
         data = DPDLAPI_readClientData(device)
         sleep(TIMESLICE)
         cnt = cnt + 1
         if (cnt == TIMEOUT_READ)
             data = BT_TIMEOUT
         fi
      endwhile
      return data
end

func clearClientTXBuffer(int device)
     DPDLAPI_clearClientTX(device)
end

func clearClientRXBuffer(int device)
       DPDLAPI_clearClientRX(device)
end

func sendServerData(string data)
      return DPDLAPI_sendServerData(data)
end

func readServerData()
      string data = "null"
      int cnt = 1
      while data == "null"
         data = DPDLAPI_readServerData()
         sleep(TIMESLICE)
         cnt = cnt + 1
         if (cnt == TIMEOUT_READ)
             data = BT_TIMEOUT
         fi
      endwhile
      return data
end

func clearServerTXBuffer()
    return DPDLAPI_clearServerTX()
end


#BT API defines
int BT_LIAC_MODE = 10390272
int BT_GIAC_MODE = 10390323

#vars
int BT_SERVER_MODE = 9999

# config
# we set the time out of read() requests to 1000 milliseconds
string BT_TIMEOUT = "BT_TIMEOUT"
int TIMEOUT_READ = 50

# time slice in ms
int TIMESLICE = 20
