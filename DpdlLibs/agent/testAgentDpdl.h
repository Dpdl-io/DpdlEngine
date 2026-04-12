# File: agent/testAgentDpdl.h
#
# Example: Dpdl code that implements two independent Agents (via dpdl code) that exchange messages in a cyclic way
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#


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

println("both agents are now running...")

while(true)
	print(".")
	sleep(5000)
endwhile
