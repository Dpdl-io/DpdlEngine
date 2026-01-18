# File: agent/testAgent.h
#
# Example: Dpdl code that implements two independent Agents that exchange messages in a cyclic way
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#


println("starting main agent management platform...")

object agent_mgt = new("DpdlAgentManagementPlatform")

println("version: " + agent_mgt.getVersion())

raise(agent_mgt, "Error in starting dpdl agent management platform...")

println("starting agent1...")

dpdl_stack_push("dpdlstack:myagent_config", "dpdlagent:-code java -container -host localhost -port 1049")

>>agent(myagent1)
	protected void setup() {
		System.out.println("Agent #1  " + this.getLocalName() + " is ready");

		        addBehaviour(new CyclicBehaviour(this) {

		            public void action() {
		                ACLMessage msg = receive();
		                if (msg != null) {
		                	System.out.println("message received: " + msg.getContent());

		                    ACLMessage reply = msg.createReply();
		                    reply.addReceiver(new AID("myagent2", AID.ISLOCALNAME));
		                    reply.setPerformative(ACLMessage.INFORM);
		                    try {
		                        String replyStr= "HELLO TEST from myagent1";
		                        System.out.println("sending reply: " + replyStr);
		                        reply.setContent(replyStr);
		                    } catch (Exception e) {
		                        throw new RuntimeException(e);
		                    }

		                    send(reply);

		                    try {
		                        Thread.sleep(5000);
		                    } catch (InterruptedException e) {
		                        e.printStackTrace();
		                    }
		                } else {
		                    block();
		                }
		            }
		        });
	}

<<

object myagent1_obj = dpdl_agent_get("myagent1")

println("Agent #1 GUID is: " + myagent1_obj.getName())
println("")

println("starting agent2...")

dpdl_stack_push("dpdlstack:myagent_config")

>>agent(myagent2)
	protected void setup() {
        System.out.println("Agent #2" + getLocalName() + " is ready");
        addBehaviour(new CyclicBehaviour(this) {
            String reply = "null";
            public void action() {

                ACLMessage msg = new ACLMessage(ACLMessage.INFORM);
                if(reply != null) {
                    try {
                        reply = "Hello MEGA TEST from myagent2";
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                    msg.setContent(reply);
                    System.out.println("Agent #2 Sending reply: " + reply);
                } else {
                    try {
                        msg.setContent("MEGA TEST :)");
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                }

                msg.addReceiver(new AID("myagent1", AID.ISLOCALNAME));

                send(msg);

                ACLMessage replyACL = receive();
                System.out.println("Agent #2 received reply: " + replyACL);
                if (replyACL != null) {
                	System.out.println("Agent #2 received reply: " + replyACL.getContent());
                    reply = replyACL.getContent();

                } else {
                    block();
                }

                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
	}

<<

object myagent2_obj = dpdl_agent_get("myagent2")

println("Agent #2 GUID is: " + myagent2_obj.getName())
println("")

println("both agents are running...")

while(true)
	print(".")
	sleep(5000)
endwhile
