## DpdlAgent

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

developed by
**SEE Solutions**
&copy;	


### DpdlAgent specification

The *DpdlEngine* has built-in support for **Agent** technology that enables to implement Distributed Mobile Agents (*DpdlAgent*) execution flows.

The '**DpdlAgent** component provides an agent development framework for building distributed and mobile multi-agent systems. It fully adheres to IEEE FIPA (*Foundation for Intelligent Physical Agents*) specifications, ensuring standardized, interoperable agent communication and coordination.

The platform components supports agent mobility, allowing agents to be dynamically created, suspended, and migrated across heterogeneous hosts at runtime without OS dependency. System configuration and supervision can be handled programmatically or through a remote management GUI, enabling flexible and scalable deployment.

It implements the complete FIPA communication model, including ACL messaging, interaction protocols, content languages, ontologies, and adaptive transport mechanisms. Communication is asynchronous and queue-based, providing efficient, flexible message handling suited to dynamic and mobile agent environments.


### Platform features

- Distributed, FIPA-compliant agent platform with built-in AMP (Agent Management Platform) and DF (Directory Facility) services

- Remote Management UI for managing agents and containers

- Tools for debugging and developing multi-agent applications

- Support for agent mobility, including state and (when needed) code transfer

- Parallel and concurrent agent behaviors with non-preemptive scheduling

- Multiple, federated Directory Facilitators for multi-domain applications

- Efficient ACL message transport (object-based internally, FIPA-compliant across platforms)

- Built-in FIPA interaction protocols, naming service, and automatic agent registration

- Extensible content languages, ontologies, and in-process API for external applications


### Example

Two 'agents' that communicate with a *Cyclic* behaviour.

#### Implementation using **dpdl** code

This is the implementation of the two agents by using <ins>**dpdl**</ins> code

```python


println("starting main agent management platform...")

object agent_mgt = new("DpdlAgentManagementPlatform")

println("version: " + agent_mgt.getVersion())

raise(agent_mgt, "Error in starting dpdl agent management platform...")

dpdl_stack_push("dpdlstack:myagent_config", "dpdlagent:-code dpdl -container -host localhost -port 1099")

println("starting agent1...")

>>agent(myagent1)

	class MyCyclicBehaviour : refObj("CyclicBehaviour") {

		func MyCyclicBehaviour(object agent)
			super(agent)
		end

		func action()

			object AID = getObj("AID")
			object ACLMessage = getObj("ACLMessage")

			object msg = receive()

			if (msg != null)
				println("message received: " + msg.getContent())

				object reply = msg.createReply()

				reply.addReceiver(new("AID", "myagent2", AID.ISLOCALNAME))

				reply.setPerformative(ACLMessage.INFORM)

					object curr_date = new("Date")

					string replyStr= "HELLO TEST from myagent1 " + curr_date.toString()
					println("sending reply: " + replyStr)

					reply.setContent(replyStr)

				send(reply)

				sleep(5000)

			else
				block()
			fi

		end

	}

	func setup()
		println("Agent #1  " + this.getLocalName() + " is ready")

		class MyCyclicBehaviour behaviour(this)

		addBehaviour(behaviour)
	end

<<

object myagent1_obj = dpdl_agent_obj_get("myagent1")

println("Agent #1 GUID is: " + myagent1_obj.getName())
println("")

println("ensure the agent is active...")

myagent1_obj.doActivate()

println("starting agent2...")

dpdl_stack_push("dpdlstack:myagent_config")

>>agent(myagent2)

	class MyCyclicBehaviour : refObj("CyclicBehaviour") {

		string reply = null

		func CyclicBehaviour(object agent)
			super(agent)
		end

		func action()

			object AID = getObj("AID")
			object ACLMessage = getObj("ACLMessage")

			object msg = new("ACLMessage", ACLMessage.INFORM)

			if(reply != null)
				object curr_date = new("Date")
				reply = "Hello MEGA TEST from myagent2 " + curr_date.toString()

				msg.setContent(reply)
				println("Agent #2 Sending reply: " + reply);
			else
				msg.setContent("MEGA TEST :)")
			fi

			msg.addReceiver(new("AID", "myagent1", AID.ISLOCALNAME))

			send(msg)

			object replyACL = receive()
			println("Agent #2 received reply: " + replyACL)

			if (replyACL != null)
				println("Agent #2 received reply: " + replyACL.getContent())
				reply = replyACL.getContent()

			else
				block()
			fi

			sleep(5000)

			DpdlAgentCode.execCode("println('MEGA!!!:D from Agent #2')")

		end
	}

	func setup()
		println("Agent #2  " + this.getLocalName() + " is ready")

		class MyCyclicBehaviour behaviour(this)

		addBehaviour(behaviour)
	end
<<

object myagent2_obj = dpdl_agent_obj_get("myagent2")

raise(myagent2_obj, "Error in creating agent")

println("Agent #2 GUID is: " + myagent2_obj.getName() + " of type: " + typeof(myagent2_obj))

println("ensure the agent is active...")

myagent2_obj.doActivate()


println("")

println("both agents are running...")

while(true)
	print(".")
	sleep(5000)
endwhile

```

The same implementation as above, implemented using <ins>**java**</ins> language, here the example:


### Implementation using embedded **java** code

```python

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

println("ensure the agent is active...")

myagent1_obj.doActivate()

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

println("ensure the agent is active...")

myagent2_obj.doActivate()

println("both agents are now running and can be controlled individually and via the DpdlAgentManagementPlatform object functions")

while(true)
	print(".")
	sleep(5000)
endwhile

```


