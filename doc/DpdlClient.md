# Dpdl

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## DpdlClient

The 'DpdlClient' is a console application that allows to execute certain functionalities of Dpdl via a command line.
The same functionalities can be accessed also programmatically via the Dpdl API.


The following commands are currently available:
```
 -l  List DpdlPackets installed
 -i  Install DpdlPacket
 -d  Uninstall DpdlPacket
 -la List DpdlPackets allocated
 -a  Allocate DpdlPacket
 -da Deallocate DpdlPacket
 -qp Query DpdlPacket (needs to be allocated first)
 -c Create DpdlPacket
 -libs  List Dpdl libraries
 -slib  Show library
 -api   List Dpdl API functions
 -exec  Type && Execute a Dpdl script, between <script>...  </script>
 -load  Load && Execute a Dpdl script file (relative path to./DpdlLibs/ eg. arraylistExample.h)
 -bench  Run a query benchmark test (on DpdlPacket dpdl_PHONEBOOK)
 -lc List the classes of a given java jar file
 -h  Help
 -q  quit
```

To run to DpdlClient console application you need Java JRE >= 1.5 and run the following command:
```
java -jar DpdlEngine_V1.0_release.jar
```

To execute a Dpdl code directly use the '-load' parameter at DpdlEngine startup:
```
java -jar DpdlEngine_V1.0_release.jar -load yourScript.h
```

If you need to run the DpdlClient on the latest version of Java, use the following command and add the modules you want to access via Dpdl code:

```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED -cp ./lib/mjcoap.jar -jar DpdlEngine_V1.0_release.jar
```


## Run Dpdl scripts


You can execute Dpdl code in the following ways:

1) Programmatically by using the Dpdl API
2) Load and execute the Dpdl script file with the '-load' command
3) Load and execute the Dpdl script file with the '-load' command at DpdlClient startup
4) Input the script directly in the DpdlClient command console by using the '-exec' command ( with closing </script> tag)


### 1) Programmatically by using the Dpdl API


```python
int status = DPDLAPI_execCode("sample.h", null)
```

You can also embed the code directly in Dpdl

```
int status = DPDLAPI_execScript("println(\"Hello from Dpdl\")", null)
```

### 2) Load and execute the Dpdl scripts with the '-load' command:

```
-load
enter the Dpdl script file to execute:
arraylistExample.h
```

### 3) Load and execute the Dpdl scripts with the '-load' command at DpdlClient startup:

example:
```
java -jar DpdlEngine_V1.0_release.jar -load yourScript.h
```

Note: see also 'run_SampleApp_java17.sh'


### 4) Input the Dpdl script directly in the DpdlClient command console by using '-exec' command:

```python
-exec
<script>
string str = "this is a test"
println(str)
</script>
```




