# File: dpdlRootGraphics.h
#
# Example: 
# This Dpdl script executes an embedded 'ROOT' C/C++ script that displays random data points on a TGraph2D
#			
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main

println("test embedded ROOT C/C++...")

>>root
   auto canvas = new TCanvas("c","Graph2D example",0,0,700,600);
   double x, y, z, P = 6.;
   int np = 200;
   auto dt = new TGraph2D();
   auto r  = new TRandom();
   for (int N=0; N<np; N++) {
      x = 2*P*(r->Rndm(N))-P;
      y = 2*P*(r->Rndm(N))-P;
      z = (sin(x)/x)*(sin(y)/y)+0.2;
      dt->SetPoint(N,x,y,z);
   }
   dt->Draw("tri1 p0");
   canvas->Modified(); canvas->Update();
   canvas->RaiseWindow();
<<

int exit_code = dpdl_exit_code()

println("embedded ROOT exit code: " + exit_code)