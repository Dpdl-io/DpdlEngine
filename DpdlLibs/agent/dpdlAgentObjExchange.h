# File: agent/dpdlAgentObjExchange.h
#
# Example: Dpdl code that implements two 'Agents' (via embedded java code) that exchange serialized java objects
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#


println("starting dpdl agent management platform to run two agents that exchange serialized java objects, using embedded java code...")

object agent_mgt = new("DpdlAgentManagementPlatform")

raise(agent_mgt, "Error in starting agent management platform...")

println("version: " + agent_mgt.getVersion())

dpdl_stack_push("dpdlstack:myagent_config", "dpdlagent:-code java -container -host localhost -port 1049")

println("starting Object writer agent...")

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
			while(true){
			  System.out.println(getLocalName() + " waiting for an Obj_Read_Agent to register via AP");
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
			  System.err.println(getLocalName() + " search with AP resulted in exception: " + fe.getMessage());
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

println("Writer Agent GUID is: " + wagent.getName())
println("")

println("starting Object reader agent...")

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
	  dfd.addOntologies("Test_ontology");

	  try {
		DFService.register(this,dfd);
	  } catch (FIPAException e) {
		System.err.println(getLocalName() + " registration with AP resulted in exception: " + e.getMessage());
		doDelete();
	  }

	  System.out.println(getLocalName() + " successful with AP");

	  while(true){
		try {
		  System.out.println(getLocalName() + " is waiting for message");
		  ACLMessage msg = blockingReceive();
		  System.out.println(getLocalName() + " rx msg" + msg);

		  if ("JavaSerialization".equals(msg.getLanguage())) {
			  Person p = (Person)msg.getContentObject();
			  System.out.println(getLocalName() + " read Java Object " + p.getClass().getName() + "-> " + p.toString());
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
		  System.err.println(getLocalName() + " de-registration with AP resulted in exception: " + e.getMessage());
		}
	}
<<

object ragent = dpdl_agent_get("readeragent")

raise(ragent, "Error in creating agent")

println("Reader Agent GUID is: " + ragent.getName())
println("")

println("both agents are now running and can be controlled individually via the DpdlAgentManagementPlatform object functions,")
println("and also controlled and inspected via a dedicated Agent Management UI")

while(true)
	print(".")
	sleep(5000)
endwhile


