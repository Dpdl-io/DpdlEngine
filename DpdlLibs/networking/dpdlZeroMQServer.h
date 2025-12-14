# File: networking/dpdlZeroMQServer.h
#
# Example: Dpdl example that implements a simple server that uses the ZeroMQ library by means of an embedded code section in java
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

int port = 5555

println("starting ZeroMQ server...")

dpdl_stack_push(port)
>>java
	public static void dpdl_main(int server_port){
		System.out.println("init server...");

		ZContext context = new ZContext();
		try {
			ZMQ.Socket socket = context.createSocket(SocketType.REP);
			socket.bind("tcp://*:" + server_port);

			while (!Thread.currentThread().isInterrupted()) {
				byte[] reply = socket.recv(0);

				System.out.println(
					"Received: [" + new String(reply, ZMQ.CHARSET) + "]"
				);

				String response = "Hello, world!";
				socket.send(response.getBytes(ZMQ.CHARSET), 0);
			}
		}catch(Exception e){
			System.out.println("Error: " + e.getMessage());
		}
	}

	int port = arg0.intValue();
	dpdl_main(port);

	return 0;
<<
int exit_code = dpdl_exit_code()

println("server exit code: " + exit_code)
