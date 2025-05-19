# File: modelica/dpdlModelicaExample_mechanics.h
#
# Example: Dpdl sample code that makes use of embedded 'Modelica' code to simulate the model mechanics
#			of a Second Order Rotational System
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("executing a Second Order Rotational System model using embedded Modelica code...")

float inertia_J1 = 0.4
float inertia_J2 = 1.0
int stiffness_c1 = 11
int stiffness_c2 = 5
float damping_d1 = 0.2
float damping_d2 = 1.0

dpdl_stack_obj_put("param_J1", inertia_J1)
dpdl_stack_obj_put("param_J2", inertia_J2)
dpdl_stack_obj_put("param_c1", stiffness_c1)
dpdl_stack_obj_put("param_c2", stiffness_c2)
dpdl_stack_obj_put("param_d1", damping_d1)
dpdl_stack_obj_put("param_d2", damping_d2)

dpdl_stack_push("dpdlbuf_modelsimout")

>>modelica

model SecondOrderSystemInitParams
  "A parametric second order rotational system"
  type Angle=Real(unit="rad");
  type AngularVelocity=Real(unit="rad/s");
  type Inertia=Real(unit="kg.m2");
  type Stiffness=Real(unit="N.m/rad");
  type Damping=Real(unit="N.m.s/rad");
  Angle phi1_init = 0;
  Angle phi2_init = 1;
  AngularVelocity omega1_init = 0;
  AngularVelocity omega2_init = 0;
  Inertia J1={{param_J1}} "Moment of inertia for inertia 1";
  Inertia J2={{param_J2}} "Moment of inertia for inertia 2";
  Stiffness c1={{param_c1}} "Spring constant for spring 1";
  Stiffness c2={{param_c2}} "Spring constant for spring 2";
  Damping d1={{param_d1}} "Damping for damper 1";
  Damping d2={{param_d2}} "Damping for damper 2";
  Angle phi1 "Angle for inertia 1";
  Angle phi2 "Angle for inertia 2";
  AngularVelocity omega1 "Velocity of inertia 1";
  AngularVelocity omega2 "Velocity of inertia 2";
initial equation
  phi1 = phi1_init;
  phi2 = phi2_init;
  omega1 = omega1_init;
  omega2 = omega2_init;
equation
  omega1 = der(phi1);
  omega2 = der(phi2);
  J1*der(omega1) = c1*(phi2-phi1)+d1*der(phi2-phi1);
  J2*der(omega2) = c1*(phi1-phi2)+d1*der(phi1-phi2)-c2*phi2-d2*der(phi2);
end SecondOrderSystemInitParams;

<<

int exit_code = dpdl_exit_code()

println("model simulation exit code: " + exit_code)

object model_output = null

if(exit_code)
	model_output = dpdl_stack_obj_get("dpdlbuf_modelsimout")

	println("Model output->")
	println(model_output)
fi
