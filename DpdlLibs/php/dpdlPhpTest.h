# File: php/dpdlPhpTest.h
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
                 echo 'Hello from php:)' . PHP_EOL;
                 echo 'Time: ' . date('Y-m-d H:i:s') . PHP_EOL;
                 echo 'Sys info: '.php_uname();
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded php code")

println("")
println("finished")
