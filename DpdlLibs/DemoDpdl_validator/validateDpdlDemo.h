# File: validateDpdlDemo.h
#
# NOTE: Do not edit or delete this file, it is required to validate the 'DpdlEngine lite' DEMO release
#
# This scripts serves as a validator for the DpdlEngine lite release of Dpdl. It simply accesses a web page of
# SEE Solutions at the following url: https://www.dpdl.io
# 
# contact: info@dpdl.io
#

import('http')

# main
string URL_to_validate = "https://www.dpdl.io/DemoDpdl_validator.html"

object get = http.get(URL_to_validate)

object response_code = get.responseCode()
object headers = get.headers()
string web_content = get.text()

if(response_code == 200)
	object check_url = new("String", web_content)

	bool check_ok = check_url.contains("Dpdl (Dynamic Packet Definition Language) Demo validator 260a5348b")

	println("DEMO validation: " + check_ok)

	if(check_ok == false)
		println("This version of Dpdl has been deprecated. Please download the latest release.")
		println("exiting...")
		exit(-1)
	else
		println("")
		int idx_s = check_url.indexOf("<msg>")
		int idx_e = check_url.indexOf("</msg>")
		idx_s = idx_s + 5
		if(idx_e > idx_s)
			string msg = check_url.substring(idx_s, idx_e)
			println("Notice: " + msg)
			println("")
		fi
	fi
else
	println("Notice: The dpdl.io web-site needs to be accessible for running the Demo version: " + URL_to_validate)
	exit(-1)
fi

return 1
