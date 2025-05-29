# File: modelica/dpdlModelicaExample_simple.h
#
# Example: Dpdl sample code that makes use of embedded 'Modelica' code to simulate a bouncing ball physical model.
#			The results of the simulation is saved in a csv file which can than be further processed or plotted
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("executing a bouncing ball physical model simulation using embedded Modelica code...")

float coeff_restitution = 0.7
float initial_height = 9.81

dpdl_stack_obj_put("cR", coeff_restitution)
dpdl_stack_obj_put("gA", initial_height)

dpdl_stack_push("dpdl:applyvars")

>>modelica

model BouncingBall
  parameter Real e={{cR}} "coefficient of restitution";
  parameter Real g={{gA}} "gravity acceleration";
  Real h(fixed=true, start=1) "height of ball";
  Real v(fixed=true) "velocity of ball";
  Boolean flying(fixed=true, start=true) "true, if ball is flying";
  Boolean impact;
  Real v_new(fixed=true);
  Integer foo;

equation
  impact = h <= 0.0;
  foo = if impact then 1 else 2;
  der(v) = if flying then -g else 0;
  der(h) = v;

  when {h <= 0.0 and v <= 0.0,impact} then
    v_new = if edge(impact) then -e*pre(v) else 0;
    flying = v_new > 0;
    reinit(v, v_new);
  end when;

end BouncingBall;

simulate(BouncingBall, outputFormat="csv");

<<

int exit_code = dpdl_exit_code()

println("model simulation exit code: " + exit_code)

