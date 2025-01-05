# File: php/dpdlPhpTest2.h
#
# Example: Dpdl Example with embedded PHP code
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#


# main
println("testing embedded php code execution...")
println("")

>>php
	class MyPhpClass
	{
		public $var1 = 'value 1';
		public $var2 = 'value 2';
		public $var3 = 'value 3';

		protected $protected = 'protected var';
		private   $private   = 'private var';

		function iterateVisible() {
		   echo "MyClass::iterateVisible:\n";
		   foreach($this as $key => $value) {
			   print "$key => $value\n";
		   }
		}
	}

	$class = new MyPhpClass();

	foreach($class as $key => $value) {
		print "$key => $value\n";
	}
	echo "\n";


	$class->iterateVisible();
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded php code")

println("")
println("finished")
