# File: test/testXML.h
#
# Example: Sample Dpdl script that parses an XML file with an xml pull parser
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing xml pull parser...")

string fname_r = "./Test/test_address.xml"

println("reading xml file ...")
string xml_content = ""
string str_in = ""
int fh = open(fname_r, "r")
while(str_in != "null")
	str_in = read(fh)
	if(str_in != "null")
		xml_content = xml_content + str_in
	fi
endwhile
close(fh)
println("done")

println("creating xml pull parser instance...")

object factory = getClass("XmlPullParserFactory")
object XmlPullParser = getClass("XmlPullParser")

object xml_factory = factory.create()

raise(xml_factory, "Error in creating XmlPullParserFactory")

bool nsa = true
xml_factory.setNamespaceAware(nsa)

object xpp = xml_factory.newPullParser()

println("done")

println("parsing xml...")

object str_reader = loadObj("StringReader", xml_content)
xpp.setInput(str_reader)

int eventType = xpp.getEventType()
while (eventType != XmlPullParser.END_DOCUMENT)
	if(eventType == XmlPullParser.START_DOCUMENT)
		println("Start document")
	elseif(eventType == XmlPullParser.END_DOCUMENT)
		println("End document")
	elseif(eventType == XmlPullParser.START_TAG)
		println("Start tag -> " + xpp.getName())
	elseif(eventType == XmlPullParser.END_TAG)
		println("End tag -> " + xpp.getName())
	elseif(eventType == XmlPullParser.TEXT)
		println("Text: " + xpp.getText())
	fi
	eventType = xpp.next()
endwhile

println("finished")
