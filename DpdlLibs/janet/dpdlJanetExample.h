# File: janet/dpdlJanetExample.h
#
# Example:
#		Dpdl example that executes an 'embedded code section' in Janet lang that implements a Chat-Server
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing embedded janet code...")

>>janet
	(def conmap @{})
	
	(defn broadcast [em msg]
	  (eachk par conmap
	         (if (not= par em)
	           (if-let [tar (get conmap par)]
	             (net/write tar (string/format "[%s]:%s" em msg))))))
	
	(defn handler
	  [connection]
	  (print "connection: " connection)
	  (net/write connection "Whats your name?\n")
	  (def name (string/trim (string (ev/read connection 100))))
	  (print name " connected")
	  (if (get conmap name)
	    (do
	      (net/write connection "Name already taken!")
	      (:close connection))
	    (do
	      (put conmap name connection)
	      (net/write connection (string/format "Welcome %s\n" name))
	      (defer (do
	               (put conmap name nil)
	               (:close connection))
	        (while (def msg (ev/read connection 100))
	          (broadcast name (string msg)))
	        (print name " disconnected")))))
	
	(defn dpdl_main [& args]
	  (printf "STARTING SERVER...")
	  (flush)
	  (def my-server (net/listen "127.0.0.1" "8000"))
	  (forever
	   (def connection (net/accept my-server))
	   (ev/call handler connection)))
<<

int exit_code = dpdl_exit_code()

println("embedded janet exit code: " + exit_code)
