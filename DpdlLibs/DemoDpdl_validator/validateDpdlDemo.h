# File: validateDpdlDemo.h
#
# NOTE: Do not edit or delete this file, it's required to keep the Dpdl DEMO release active
#
# This scripts serves as a validator for the DEMO release of Dpdl. It simply accesses a web page of
# SEE Solutions at the following url: https://www.dpdl.io
# 
# contact: info@dpdl.io
#

# main
string URL_to_validate = "https://www.dpdl.io/DemoDpdl_validator.html"

object url = loadObj("URL", URL_to_validate)
object url_connection = url.openConnection()
object url_in = url_connection.getInputStream()
if(url_in == null)
	println("exiting...")
	exit(-1)
fi
object url_in_read = loadObj("InputStreamReader", url_in)
if(url_in_read == null)
	println("exiting...")
	exit(-1)
fi
object buf_read = loadObj("BufferedReader", url_in_read)
object buf_str = loadObj("String", "")

string web_content = ""
while(buf_str != null)
	buf_str = buf_read.readLine()
	if(buf_str != null)
		web_content = web_content + buf_str.toString()
	fi
endwhile

object check_url = loadObj("String", web_content)
bool check_ok = check_url.contains("Dpdl (Dynamic Packet Definition Language) Demo validator 260a5348b14")
println("DEMO validation: " + check_ok)
if(check_ok == false)
	println("exiting...")
	exit(-1)
fi

