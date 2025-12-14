# File: networking/dpdlZeroMQClient2.h
#
# Example: Dpdl examle that implements a simple ZeroMQ client to send a loop of messages to a zeromq server bv means of an
#			an 'embedded code section' in C
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

dpdl_stack_push("dpdlstack:myconfig", "dpdl:compile", "dpdl:-L/opt/homebrew/Cellar/zeromq/4.3.5_2/lib", "dpdl:-I/opt/homebrew/Cellar/zeromq/4.3.5_2/include", "dpdl:-lzmq")

println("starting ZeroMQ client...")

int port = 5555

dpdl_stack_push("dpdlstack:myconfig", port)
>>c
	#include <zmq.h>
	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>

	int dpdl_main(int argc, char **argv){
		if(argc < 1){
			printf("missing port number\n");
			return -1;
		}else{
			int port_num = atoi(argv[0]);

			printf ("Connecting to hello zeromq server at port: %d\n", port_num);

			void *context = zmq_ctx_new ();
			void *requester = zmq_socket (context, ZMQ_REQ);
			zmq_connect (requester, "tcp://localhost:5555");

			int request_nbr;
			for (request_nbr = 0; request_nbr != 10; request_nbr++) {
				char buffer [10];
				printf ("Sending msg %d...\n", request_nbr);
				zmq_send (requester, "Hello", 5, 0);
				zmq_recv (requester, buffer, 10, 0);
				printf ("Received World %d\n", request_nbr);
			}
			zmq_close (requester);
			zmq_ctx_destroy (context);
			return 0;
		}
	}
<<
int exit_code = dpdl_exit_code()

println("client exit code: " + exit_code)
