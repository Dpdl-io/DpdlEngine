## DpdlAgents

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

developed by
**SEE Solutions**
&copy;	


### DpdlAgents specification

Dpdl has built-in support for **Agents** technology that enables to implement Distributed Mobile Agents execution flows.

The '**DpdlAgent** component includes a complete agent development framework based on jade for building distributed and Mobile multi-Agent systems.

It fully adheres to **IEEE FIPA** (*Foundation for Intelligent Physical Agents*) specifications, ensuring standardized, inter-operable agent communication and coordination, including ACL messaging, interaction protocols, content languages, ontologies, and adaptive transport mechanisms. 
Communication is asynchronous and queue-based, providing efficient, flexible message handling suited to dynamic and mobile agent environments.

The agent platform components support also agent mobility, allowing agents to be dynamically created, suspended, and migrated across heterogeneous hosts at runtime without OS dependency. System configuration and supervision can be handled programmatically or through a remote management UI, enabling flexible and scalable deployment.


### Platform features

- Distributed, FIPA-compliant agent platform with built-in AMP (**Agent Management Platform**) and DF (**Directory Facility**) services

- Remote **Management UI** for managing agents and containers

- Tools for debugging and developing multi-Agent applications

- Support for <ins>agent mobility</ins>, including state and (when needed) code transfer

-  <ins>Parallel</ins> and <ins>concurrent</ins> agent behaviors with non-preemptive scheduling

- Multiple, federated Directory Facilitators for multi-domain applications

- Efficient ACL message transport (object-based internally, FIPA-compliant across platforms)

- Built-in **FIPA interaction protocols**, naming service, and automatic agent registration

- Extensible content languages, <ins>ontologies</ins>, and <ins>in-process API for external applications</ins>


## Index

* [Examples](#examples)
* [API](#api)


### Examples

Two '**agents**' that communicate via *FIPA* compliant protocols and ontologies.


#### Example 'Agents' implementation using pure **dpdl** code

This is a simple implementation of the two agents using pure <ins>**dpdl**</ins> code, that exchange asynchronous messages with a *Cyclic* behaviour.

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

The same implementation as above, but implemented using embedded <ins>**java**</ins> code can be found here: [agent/dpdlAgent.h](https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/agent/dpdlAgent.h) 


### Example 'Agents' implementation using embedded '**java**' code within dpdl

This is a more articulated example, where two agents implemented with dpdl embedded java code, exchange serialized java objects. 
Note that in this case the ACLMessage language is set to be 'JavaSerialization'

```python

println("starting dpdl agent management platform to run two agents that exchange serialized java objects, using embedded java code...")

object agent_mgt = new("DpdlAgentManagementPlatform")

raise(agent_mgt, "Error in starting agent management platform...")

println("version: " + agent_mgt.getVersion())

dpdl_stack_push("dpdlstack:myagent_config", "dpdlagent:-code java -container -host localhost -port 1049")

println("starting object writer agent...")

>>agent(writeragent)

	public class Person implements java.io.Serializable {

		String name;
		String surname;
		Date   birthdate;
		int    age;

		Person(String n, String s, Date d, int a) {
			name = n;
			surname = s;
			birthdate = d;
			age = a;
		}

		public String toString() {
			return(name + " " + surname + " birthday: " + birthdate.toString() + " age = " + age);
		}
	}

	protected void setup() {

		  AID reader = new AID();
		  DFAgentDescription dfd = new DFAgentDescription();
		  ServiceDescription sd = new ServiceDescription();
		  sd.setType("Obj_Read_Agent");
		  dfd.addServices(sd);

		  try {
			while (true) {
			  System.out.println(getLocalName()+ " waiting for an Obj_Read_Agent to register via AP");
			  SearchConstraints c = new SearchConstraints();
			  c.setMaxDepth(new Long(3));
			  DFAgentDescription[] result = DFService.search(this, dfd, c);
			  if ((result != null) && (result.length > 0)) {
				dfd = result[0];
				reader = dfd.getName();
				break;
			  }
			  Thread.sleep(10000);
			}
		  } catch (Exception fe) {
			  fe.printStackTrace();
			  System.err.println(getLocalName()+" search with AP resulted in exception: " + fe.getMessage());
			  doDelete();
		  }

		  System.out.println(getLocalName() + " agent sends ACLMessages with content as serialized Java Object");

		   try {
			  ACLMessage msg = new ACLMessage(ACLMessage.INFORM);

			  msg.addReceiver(reader);

			  Person p = new Person("Armin", "Costa", new Date(), 1);
			  msg.setContentObject(p);
			  msg.setLanguage("JavaSerialization");
			  send(msg);
			  System.out.println(getLocalName()+" sent 1st msg "+msg);

			  msg.setDefaultEnvelope();
			  msg.getEnvelope().setAclRepresentation(FIPANames.ACLCodec.BITEFFICIENT);
			  send(msg);
			  System.out.println(getLocalName() + " sent 1st msg with bit-efficient aclCodec " + msg);

			  msg.getEnvelope().setAclRepresentation(FIPANames.ACLCodec.XML);
			  send(msg);
			  System.out.println(getLocalName() + " sent 1st msg with xml aclCodec " + msg);

			  p = new Person("Alexis", "Kunst", new Date(), 2);
			  msg.setContent(p.toString());
			  msg.setLanguage("JavaLanguage");
			  msg.setDefaultEnvelope();
			  send(msg);
			  System.out.println(getLocalName() + " sent 2nd msg " + msg);

			  msg.getEnvelope().setAclRepresentation(FIPANames.ACLCodec.BITEFFICIENT);
			  send(msg);
			  System.out.println(getLocalName( ) + " sent 2nd msg with bit-efficient aclCodec " + msg);

			  msg.getEnvelope().setAclRepresentation(FIPANames.ACLCodec.XML);
			  send(msg);
			  System.out.println(getLocalName() + " sent 2nd msg with xml aclCodec " + msg);
		  } catch (IOException e) {
			  e.printStackTrace();
		  }
		  doDelete();
	}

<<

object wagent = dpdl_agent_get("writeragent")

raise(wagent, "Error in creating agent")

#println("Writer Agent GUID is: " + wagent.getName())
println("")

println("starting object reader agent...")

>>agent(readeragent)

	public class Person implements java.io.Serializable {

		String name;
		String surname;
		Date   birthdate;
		int    age;

		Person(String n, String s, Date d, int a) {
			name = n;
			surname = s;
			birthdate = d;
			age = a;
		}

		public String toString() {
			return(name + " " + surname + " birthday: " + birthdate.toString() + " age = " + age);
		}
	}

	protected void setup() {

	  DFAgentDescription dfd = new DFAgentDescription();
	  ServiceDescription sd = new ServiceDescription();
	  sd.setType("Obj_Read_Agent");
	  sd.setName(getName());
	  sd.setOwnership("ExampleAgents");
	  dfd.addServices(sd);
	  dfd.setName(getAID());
	  dfd.addOntologies("Test_Example");

	  try {
		DFService.register(this,dfd);
	  } catch (FIPAException e) {
		System.err.println(getLocalName() + " registration with AP resulted in exception: " + e.getMessage());
		doDelete();
	  }

	  System.out.println(getLocalName() + " successful with AP");

	  while (true) {
		try {
		  System.out.println(getLocalName() + " is waiting for message");
		  ACLMessage msg = blockingReceive();
		  System.out.println(getLocalName() + " rx msg" + msg);

		  if ("JavaSerialization".equals(msg.getLanguage())) {
			  Person p = (Person)msg.getContentObject();
			  System.out.println(getLocalName() + " read Java Object " + p.getClass().getName() + p.toString());
		  }else{
			  System.out.println(getLocalName() + " read Java String " + msg.getContent());
		  }

		} catch(UnreadableException e3){
			  System.err.println(getLocalName()+ " catched exception " + e3.getMessage());
		}
	  }
	}

	public void takeDown() {
		try {
		  DFService.deregister(this);
		}
		catch (FIPAException e) {
		  System.err.println(getLocalName()+" de-registration with AP resulted in exception: "+e.getMessage());
		}
	}
<<

object ragent = dpdl_agent_get("readeragent")

raise(ragent, "Error in creating agent")

println("Reader Agent GUID is: " + ragent.getName())
println("")

println("both agents are now running and can be controlled individually and via the DpdlAgentManagementPlatform object functions,")
println("or controlled and inspected via dedicated Agent Platform UI")

while(true)
	print(".")
	sleep(5000)
endwhile

```

More examples will follow soon...


### API

### object classes

* [Agent](#agent)
* [Behaviour](#behaviour)
* [Types of behaviours](#types-of-behaviours)


#### Agent

```python
addBehaviour(object Behaviour)

doActivate()
 
blockingReceive() return object ACLMessage

blockingReceive(long milli_sec) return object ACLMessage

blockingReceive(object MessageTemplate) return object ACLMessage

blockingReceive(object MessageTemplate, long milli_sec) return object ACLMessage

changeStateTo(object LifeCycle) void
 
doClone(object Location, string new_name)

doDelete()

doMove(object Location)
 
doSuspend()

doWait()

doWait(long millis)

doWake()

getAgentState() return object AgentState

getAID() return object AID

getAID(string name) return object AID
 
getArguments() return object[]

getExecutedBehavioursCnt() 

getBootProperties() return object Properties

getContentManager() return object ContentManager

getCurQueueSize() return int size

getDefaultDF() return object AID

getExecutedBehavioursCnt()  return long count

getLocalName() return string local_name

getName() return string name

getPostedMessagesCnt() return int count

getProperty(string key, string aDefault) string prop

getQueueSize() return int size

getReceivedMessagesCnt() return long count

getSentMessagesCnt() return long count

here() return object Location

isAlive() return bool status

isRestarting() return bool status

postMessage(object ACLMessage) void
 	
putBack(object ACLMessage)

putO2AObject(object obj, bool blocking)

receive() return object ACLMessage

receive(object MessageTemplate) return object ACLMessage

receive(object MessageTemplate, int max) return object ACLMessage

registerO2AInterface(object classInterface, T impl) void

removeBehaviour(object Behaviour)

restoreBufferedState()

restoreFields(object InputStream)

send(object ACLMessage)

setEnabledO2ACommunication(bool enabled, int queue_size)

setGenerateBehaviourEvents(bool b)

setGenerateMessageEvents(bool b)

setO2AManager(object Behaviour)

setQueueSize(int new_size)

setup()

takeDown()

write(object OutputStream)

send(object ACLMessage)

setEnabledO2ACommunication(bool enabled, int queue_size)

setGenerateBehaviourEvents(bool b)

setGenerateMessageEvents(bool b)

setO2AManager(object Behaviour)

setQueueSize(int new_size)

setup()

takeDown()

write(object OutputStream)

```


#### Behaviour

```python
action()

block()

block(long milli_sec)

done() return bool

getAgent() return object Agent

getBehaviourName() return string name

getDataStore() return object DataStore

getParent() return object CompositeBehaviour

isRunnable() return bool status

onEnd() void

onStart() void

reset() void

restart() void

root() return object Behaviour

setAgent(object Agent) void

setBehaviourName(string name) void

setDataStore(object DataStore)

```

#### Types of behaviours

All these classes inherit the functionalities of the base class **`Behaviour`**, as documented above:

##### ActionExecutor

##### BaseInitiator

##### CompositeBehaviour

##### CyclicBehaviour

##### DataStore

##### FSMBehaviour

##### LoadBehaviour

##### OneShotBehaviour

##### OntologyServer

##### OutcomeManager

##### ParallelBehaviour

##### SequentialBehaviour

##### SerialBehaviour

##### SimpleBehaviour

##### ThreadedBehaviourFactory

##### TickerBehaviour

##### WakerBehaviour

##### WrapperBehaviour





 


 	
 


