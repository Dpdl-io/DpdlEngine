# File: xml/dpdlXMLQuery.h
#
# Example: Sample Dpdl script that performs XPath queries on an xml document
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#


string result = DPDLAPI_processXPath("./Test/xpath_test.xml", "/Users/User/Name")

result_arr[] = result

if(result_arr.size() > 0)
	println("result_arr[0]=" + result_arr[0])
fi

int nr_results = DPDLAPI_getXPathNrResults()

println("nr results: " + nr_results)

println("getting last entry ...")

string entry = DPDLAPI_getXPathResult(nr_results - 1)
println("entry: " + entry)



