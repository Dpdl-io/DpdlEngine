# File: ring/dpdlRingExample.h
#
# Example: dpdl sample code with an asynchronous 'embedded code section' in Ring lang that implements a simple
#			HTTP server that serves two end-points, '/time' && '/stop'
#
#			A loop than makes 100 requests before stopping the server via the /stop end-point
#
#
# author: A.Costa
# e-mail: ac@dpdl.io
#

import('http')


println("creating a server via 'embedded code section' in ring-lang...")

>>ring(async)

	load "httplib.ring"

	? "Start the server..."

	oServer = new Server

	oServer.route(:Get,"/time",:gettime)
	oServer.route(:Get,"/stop",:stop)

	? "Listening on port 8080"

	oServer.listen("0.0.0.0", 8080)

	func gettime
		oServer.setContent("Time: " + time(), "text/plain")

	func stop
		oServer.stop()
<<

int exit_code = dpdl_exit_code()

println("server status: " + exit_code)

raise(exit_code, "Error in starting server")

object resp = null
int cnt
while(cnt < 100)
	println("getting time...")

	resp = http.get("http://localhost:8080/time")

	println("resp -> " + resp.text())

	print(".")

	sleep(3000)
	cnt=cnt+1
endwhile

println("")

println("stopping server...")

object stop = http.get("http://localhost:8080/stop")

println("content: " + stop.text())
println("headers: " + stop.headers())

println("status: " + stop.responseCode())

