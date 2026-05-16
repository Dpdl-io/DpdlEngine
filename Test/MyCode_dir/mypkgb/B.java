package mypkgb;
    
public class B implements Runnable {
   public void run() {
      	System.out.println("Hello from a compiled class B :)");
   }

   public int testIt(int val, Object some){
 	for(int i = 0; i < val; i++){
		System.out.println("iter: " + i); 
	}
	System.out.println("testIt(..)-> val: " + val + " some: " + some.toString());
	return 23;
   }
}
