# Dpdl

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## 'DpdlPacket'

Dpdl allows to create compressed packets of data **`DpdlPacket`** via a dedicated code definition.
The data in a DpdlPacket is organized in chunks of highly compressed data, along with database indexes and code definitions.

Data chunks of a DpdlPacket can be allocated, queried and deallocated when not needed anymore.

The speedup is x25 when querying a DpdlPacket compared to the standard record store access.

### Layout of a DpdlPacket

```
		---------------------------
		| Dpdl header & code		|								#######################
		--------------------------	-								# Indexed B-Tree    	#
		| Chunk #1                 |----> allocate (de-compress)	-->	#					#
		|__________________________|								# DATA				#
		| Chunk #2                 |								#######################
		|__________________________|
		| Chunk #3                 |
		|__________________________|
		| ....                     |
		|__________________________|
		| Chunk #N                 |
		|__________________________|	
														
```											
This allows a very efficient method of accessing and searching big amounts of data in memory constrained devices.

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
int status = DPDLAPI_swapDpdlChunk("dpdl_PHONEBOOK_BZ", "BolzanoPhone")
if(status == dpdlTrue)
	status = DPDLAPI_selectDpdlService("dpdl_PHONEBOOK_BZ",, "BolzanoPhone", "armin 369")
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

	execute the command -load and enter the query console example script:
	
	```
	-load
	enter the Dpdl script name to execute:
	testDpdlDB2.h
	```
	
	
	The script allows to perform either a single query, or n sequential or random queries, and measures the execution
	time for searching and accessing data:
	
		1) To perform a single query (press 'q')
		
		2) To execute sequential or random queries, for each of the data entries (press ENTER)
		   and than enter '**armin**' as constraint base name, which is part of the key of each data entry:
		   i.e. "armin 1, armin 2, ..."
		   
		   For random vs. sequential queries comment or uncomment the following line of code in the script
		   -> i #abs(search_rand_int) 
		
