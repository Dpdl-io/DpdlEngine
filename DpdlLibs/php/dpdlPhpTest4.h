# File: php/dpdlPhpTest4.h
#
# Example: Dpdl Example with embedded PHP code to read a CSV file, count the number of fields in each line and print the values.
#			The file to be parsed is pushed onto the dpdl stack, and a record containing the nr. of records parsed is returned
#			via a dpdl stack buffer
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#


# main
println("testing embedded php code execution...")
println("")

dpdl_stack_push("dpdlbuf_d1", "Test/stockdata.csv")

>>php
	$row = 1;
	$rec_nr = 0;
	if( count($argv) > 0 ){
		$file = $argv[0];
	}else{
		die("Error no input file provided");
	 }
	if (($handle = fopen($file, "r")) !== FALSE) {
		while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
			$num = count($data);
			echo "$num fields in line $row:\n";
			$row++;
			for ($c=0; $c < $num; $c++) {
				echo $data[$c] . "\n";
			}
		}
		fclose($handle);
		$rec_nr = $row;
	}else{
		die("IO error while opening CSV file: $file");
	}

	dpdl_stack_buf_put("nr. of records parsed is " . $rec_nr);
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded php code")

string result = dpdl_stack_buf_get("dpdlbuf_d1")

println("")
println("result: " + result)
println("")
println("finished")
