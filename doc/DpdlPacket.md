# Dpdl

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	


## 'DpdlPacket'

Dpdl allows to create <ins>compressed packets</ins> of data defined as **`DpdlPacket`** via a dedicated code definition.

The data in a 'DpdlPacket' is organized in chunks of <ins>**highly compressed data**</ins>, along with <ins>database indexes</ins> and code definitions.

Chunks of data contained in a 'DpdlPacket' can be <ins>allocated</ins>, <ins>executed</ins>, <ins>queried</ins> and <ins>deallocated</ins> when data is not needed anymore.

This approach enables to handle very efficiently relatively "big" amounts of data on memory scarce devices.

The performance of query execution when querying a DpdlPacket is <ins>**x25 times faster**</ins> compared to the standard record store access.


### Layout of a 'DpdlPacket'

```
		---------------------------
		| Dpdl header & code       |
		----------------------------
		| Chunk #1                 |----> allocate (de-compress, decode, execute) --> query --> deallocate
		|__________________________|          |
		| Chunk #2                 |          |
		|__________________________|     #######################
		| Chunk #3                 |     # Indexed B-Tree      #
		|__________________________|     #                     #
		| ....                     |     # DATA                #
		|__________________________|     #######################
		| Chunk #N                 |
		|__________________________|	
														
```	
										
This allows a very efficient method of accessing and searching relatively "big" amounts of data in memory scarce devices.

Dpdl code can be embedded in the DpdlPacket code definition and allows to trigger its execution on predefined callbacks.
This makes a DpdlPacket an executable packet of data.

This is an example DpdlPacket code definition (a phonebook database), which is compiled to a DpdlPacket containing all definitions and all chunks of data in a highly compressed format:

```c++
call(dpdlInterpreter)
::module dpdl_PHONEBOOK_BZ
::module_SPEC 23452
::model 836
::dpdlVersion 1.0

OPTIONS {
    TARGET = CDC & CLDC
    KVM = 1.0
    ZIP = true
    CHECKSUM = true
    SIGNATURE = true
    ENCRYPTION(RSA) = false
}

#defineDpdlEncoding UTF-8

#defineDB phone_bz | ./Test/BolzanoPhone.csv | null null

#defineSQL query_ SELECT name, phoneNR, e-mail FROM phone_bz end

#defineProtocol-cHtml phonebook_visual phone_book.html

import extern SystemData

catch DPDL_Script OnInit() {
    import("dpdllib.h") nl
    println("OnInit()") nl
}

import virtual DATA none  {
        class BolzanoPhone volatile phonebook_visual {
              DATA::string const name;
              DATA::string using phoneNR;
              DATA::string using  e-mail;
              #defineGUI Default <PhoneBook>  <Enter name and surname:>
              
              catch DPDL_Script OnDecode() {
                 import("dpdllib.h") nl
                 import("dpdlRS.h") nl
                 println("OnDecode()") nl
                 string time = getTime() nl
                 println("storing access time..." + time) nl
                 int rs_id = createRS("AccessStats", AUTHMODE_ANY, dpdlTrue, dpdlTrue) nl
                 int rec_id = addRecord(rs_id, time) nl
                 int status = closeRS(rs_id) nl
                 println("done status: " + status) nl
              }
        }
}
#defineD BolzanoPhone source phone_bz SQL query {
                CHUNK entry [6];
                struct BTree DENSE_INDEX hashing *name
                entry.content { name , phoneNR , e-mail }
                entry.name TAG(0xef) const (string) = 20;
                entry.phoneNR TAG(0xefe) (string) = 15;
                entry.e-mail TAG(0xefee) (string) = 30;
}

```

The DpdlPacket as defined above, can be allocated and queried via Dpdl API or via the equivalent Java API

```python
println("swapping data chunk..."

int status = DPDLAPI_swapDpdlChunk("dpdl_PHONEBOOK_BZ", "BolzanoPhone")

if(status == dpdlTrue)
	println("performing query ...")
	
	status = DPDLAPI_selectDpdlService("dpdl_PHONEBOOK_BZ", "BolzanoPhone", "armin 3692323")
	
	if(status)
		string name
		string phoneNR
		string email
	     int nr_res = DPDLAPI_getNrResults()
	     int c = 0
	     println("Results: " + nr_res + " ---->");
	     if(nr_res > 0)
	         while(c < nr_res)
	              name = DPDLAPI_getResultSet(c, "name")
	              phoneNR = DPDLAPI_getResultSet(c, "phoneNR")
	              email = DPDLAPI_getResultSet(c, "e-mail")
	              println("                       name: " + name)
	              println("                       phone nr.: " + phoneNR)
	              println("                       e-mail: " + email)
	              println("-----------------------------------------")
	              c=c+1
	         endwhile
	         println("#######################")
	     else
	         println("no results found")
	     fi
	else
		println("Error in query")
	fi
fi

```

The first time a DpdlPacket is allocated (swapped), data is decompressed in a temporary storage. This process takes some time for the 1st allocation,
but is immediate for subsequent allocations, as long as the DpdlPacket is not explicitly deallocated.

### Data Types

A DpdlPacket chunk allocation supports the following types:

```c++
int
string
char
double
float
long
byte
Image
class
xml
dpdlpacket
```

## DpdlPacket example (installation, allocation and query)

The Demo release of Dpdl includes an encoded DpdlPacket (dpdl_PHONEBOOK.dpdl) that has 48877 data entries (name, phoneNR, e-email).

The packet is approximately 1,2 MB in size and has been encoded with the following Dpdl source script (dpdl_PHONEBOOK.c):


To run the example

1. start the DpdlClient by executing the following script:

on Linux/MacOS
```
./run_DpdlClient.sh
```

on Windows
```
./run_DpdlClient.bat
```

2. install the DpdlPacket (dpdl_PHONEBOOK.dpdl) which is located in the folder ./DpdlServices/data/

	execute the command -i and enter the packet name: 
	
	```
	-i
	enter the DpdlPacket to install:
	dpdl_PHONEBOOK
	```
	


3. allocate the DpdlPacket and the corresponding data chunk:

	execute the command -a and enter the packet name and data chunk name to allocate:
	
	```
	-a
	enter the DpdlPacket to allocate ($dpdl_packet:$chunk_name:)
	dpdl_PHONEBOOK:BolzanoPhone
	```
	
	The DpdlPacket will be de-compressed and allocated ready to query. The 1st time a packet is allocated it takes 
	some time, subsequent allocations are immediate

	
4. run the query console example script
	
	The example dpdl script to perform the queries is [dpdlpacket/testDpdlDB2.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/dpdlpacket/testDpdlDB2.h)
	
	To run the dpdl script execute the command -load command in the console and enter the query console example script:
	
	```
	-load
	enter the Dpdl script name to execute:
	dpdlpacket/testDpdlDB2.h
	```
	
	The dpdl script will print this, where you can choose a test method:
	
	The script allows to perform either a single query, or n sequential or random queries, and measures the execution
	time for searching and accessing data:
	
		1) To perform a single query (press 'q')
		
		2) To execute sequential or random queries, for each of the data entries (press ENTER)
		   and than enter '**armin**' as constraint base name, which is part of the key of each data entry:
		   i.e. "armin 1, armin 2, ..."
		   
		   For random vs. sequential queries comment or uncomment the following line of code in the script
		   -> i #abs(search_rand_int) 
		

		
The 'DpdlPacket' database technology in Dpdl has been developed since year 2003, when the first java applications where developed for mobile devices.

It started with a BsC thesis by A.C:

[Advanced database techniques in Dpdl : dynamic packet definition language ; a portable data protocol for small embedded systems](https://unibz.primo.exlibrisgroup.com/permalink/39UBZ_INST/hl3dt9/alma9928450240001241)

