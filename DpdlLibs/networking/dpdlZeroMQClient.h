# File: networking/dpdlZeroMQClient.h
#
# Example: Dpdl examle that implements a simple ZeroMQ client to send a loop of messages to a zeromq server bv means of
#			an 'embedded code section' in java
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

int port = 5555

println("starting ZeroMQ client...")

dpdl_stack_push(port)
>>java
    public static void dpdl_main(int server_port){
		ZContext context = new ZContext();
        try {
            System.out.println("Connecting to hello zeromq server");

            ZMQ.Socket socket = context.createSocket(SocketType.REQ);
            socket.connect("tcp://localhost:" + server_port);

            for (int requestNbr = 0; requestNbr != 10; requestNbr++) {
                String request = "Hello";
                System.out.println("sending msg " + requestNbr);
                socket.send(request.getBytes(ZMQ.CHARSET), 0);

                byte[] reply = socket.recv(0);
                System.out.println(
                    "Received " + new String(reply, ZMQ.CHARSET) + " " +
                    requestNbr
                );
            }
        }catch(Exception e){
        	System.out.println("Error in starting client: " + e.getMessage());
        }
    }

	int port = arg0.intValue();
	dpdl_main(port);

	return 0;
<<
int exit_code = dpdl_exit_code()

println("client exit code: " + exit_code)
