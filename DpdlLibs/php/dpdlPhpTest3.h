# File: php/dpdlPhpTest3.h
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
	function encode_ip($dotquad_ip)
	{
		$ip_sep = explode('.', $dotquad_ip);
		return sprintf('%02x%02x%02x%02x', $ip_sep[0], $ip_sep[1], $ip_sep[2], $ip_sep[3]);
	}

	function decode_ip($int_ip)
	{
		$hexipbang = explode('.', chunk_split($int_ip, 2, '.'));
		return hexdec($hexipbang[0]). '.' . hexdec($hexipbang[1]) . '.' . hexdec($hexipbang[2]) . '.' . hexdec($hexipbang[3]);
	}
	echo "IP Encoding\n";
	$localhost = encode_ip('127.0.0.1');
	echo "127.0.0.1 ==> $localhost\n";
	$router = encode_ip('192.168.2.1');
	echo "192.168.2.1 ==> $router\n";
	echo "IP Decoding\n";
	echo "$localhost ==> ",decode_ip($localhost).PHP_EOL;
	echo "$router ==> ",decode_ip($router).PHP_EOL;
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded php code")

println("")
println("finished")
