# File: dpdlRootSolver.h
#
# Example: 
# This Dpdl script executes an embedded 'ROOT' C/C++ script that solves a linear equation in 4 different ways
# root script from ROOT tutorials by CERN
#			
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main

println("test embedded ROOT C/C++...")

# we push the required ROOT libs to the dpdl_stack
dpdl_stack_push("libMatrix", "libGpad")

>>root
   #include "Riostream.h"
   #include "TMatrixD.h"
   #include "TVectorD.h"
   #include "TGraphErrors.h"
   #include "TDecompChol.h"
   #include "TDecompSVD.h"
   #include "TF1.h"
   
   
   cout << "Perform the fit  y = c0 + c1 * x in four different ways" << endl;
 
   Double_t eps = 1.e-12;
   
   const Int_t nrVar  = 2;
   const Int_t nrPnts = 4;
 
   Double_t ax[] = {0.0,1.0,2.0,3.0};
   Double_t ay[] = {1.4,1.5,3.7,4.1};
   Double_t ae[] = {0.5,0.2,1.0,0.5};
 
   // Make the vectors 'Use" the data : they are not copied, the vector data
   // pointer is just set appropriately
 
   TVectorD x; x.Use(nrPnts,ax);
   TVectorD y; y.Use(nrPnts,ay);
   TVectorD e; e.Use(nrPnts,ae);
 
   TMatrixD A(nrPnts,nrVar);
   TMatrixDColumn(A,0) = 1.0;
   TMatrixDColumn(A,1) = x;
 
   cout << " - 1. solve through Normal Equations" << endl;
 
   const TVectorD c_norm = NormalEqn(A,y,e);
 
   cout << " - 2. solve through SVD" << endl;
   // numerically  preferred method
 
   // first bring the weights in place
   TMatrixD Aw = A;
   TVectorD yw = y;
   for (Int_t irow = 0; irow < A.GetNrows(); irow++) {
      TMatrixDRow(Aw,irow) *= 1/e(irow);
      yw(irow) /= e(irow);
   }
 
   TDecompSVD svd(Aw);
   Bool_t ok;
   const TVectorD c_svd = svd.Solve(yw,ok);
 
   cout << " - 3. solve with pseudo inverse" << endl;
 
   const TMatrixD pseudo1  = svd.Invert();
   TVectorD c_pseudo1 = yw;
   c_pseudo1 *= pseudo1;
 
   cout << " - 4. solve with pseudo inverse, calculated brute force" << endl;
 
   TMatrixDSym AtA(TMatrixDSym::kAtA,Aw);
   const TMatrixD pseudo2 = AtA.Invert() * Aw.T();
   TVectorD c_pseudo2 = yw;
   c_pseudo2 *= pseudo2;
 
   cout << " - 5. Minuit through TGraph" << endl;
 
   TGraphErrors *gr = new TGraphErrors(nrPnts,ax,ay,0,ae);
   TF1 *f1 = new TF1("f1","pol1",0,5);
   gr->Fit("f1","Q");
   TVectorD c_graph(nrVar);
   c_graph(0) = f1->GetParameter(0);
   c_graph(1) = f1->GetParameter(1);
 
   // Check that all 4 answers are identical within a certain
   // tolerance . The 1e-12 is somewhat arbitrary . It turns out that
   // the TGraph fit is different by a few times 1e-13.
 
   Bool_t same = kTRUE;
   same &= VerifyVectorIdentity(c_norm,c_svd,0,eps);
   same &= VerifyVectorIdentity(c_norm,c_pseudo1,0,eps);
   same &= VerifyVectorIdentity(c_norm,c_pseudo2,0,eps);
   same &= VerifyVectorIdentity(c_norm,c_graph,0,eps);
   if (same)
      cout << " All solutions are the same within tolerance of " << eps << endl;
   else
      cout << " Some solutions differ more than the allowed tolerance of " << eps << endl;
<<

int exit_code = dpdl_exit_code()

println("embedded ROOT exit code: " + exit_code)