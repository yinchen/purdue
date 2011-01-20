
/*
 * Program name: CheckPrimeConc
 * 
 * Decsription:
 * This program demonstrates how multiple threads can be used to check for primality of a positive integer.
 * The programs asks the user to enter an integer. It then
 * uses two threads to check for the primality of the number input. 
 * The given number is checked against  divisors from 2 until sqrt(number).
 * One thread checks for divisibility by numbers from 2 till sqrt(number)/2 and
 * the other by numbers from sqrt(number)/2+1 until sqrt(number).
 * If neither thread is able to find the divisor then the number
 * is prime else it is not.
 * 
 * Author: Aditya Mathur
 * Date: June 27, 2010
 * Revised: July 19, 2010
 * 
 * The student should carefully note the following:
 * 
 * 1. How the program is structured into one class and several methods.
 * 2. How threads are created and started.
 * 3. How the main() method waits for both threads to stop functioning.
 * 4. The use of variable names, especially the use of the same name in 
 * different contents (e.g. num).
 * 
 * Play with the program:
 * 1. Locate the two constructors. Remove the first one, which is empty. Now compile the program.
 * Does the program compile?
 * 
 * 2. How many threads does this program create? 
 * 
 * 3. Is there any difference in the code executed by each thread created?
 * 
4. Modify the program so it prints the total elapsed time to check if
 * the given number is a prime. Compile and run the modified program. Then compare the
 * time taken by the multithreaded program against the single threaded
 * program that you have played with in the past. Use the following numbers in your experiment:
 * 104729 
 * 611953
 * 595453013  
 * 3300451039 
 * 9990454997 

5. Are the two threads independent? Is there any chance of a deadlock?

6. [Advanced exercise] Modify the program so that it uses three threads 
to check for primality. Then compare the time taken by the modified program
with that of the program with two threads. Use the numbers listed above to
compare the execution times.

 * */


import java.util.Scanner; // This class is needed for input.


public class CheckPrimeConc extends Thread{
    static long num;  // Check if this is a prime.
    long initDivisor; // This will be the smallest divisor for a thread.
    long finalDivisor; // This will be the largest divisor for a thread.
    static boolean []  isPrime=new boolean[3]; // Each thread places its result in this array.
    static long [] divisibleBy=new long [3]; // Holds the divisor, if any found
    int threadID; //ID of a thread
    static long startTime, endTime;
    
    public CheckPrimeConc(){}
    public CheckPrimeConc(int ID, long num, long initDivisor, long  finalDivisor){
        threadID=ID;
        this.num=num;
        this.initDivisor=initDivisor;
        this.finalDivisor=finalDivisor;
    } 
    // The run() method is invoked when the thread is started.
    public void run(){
              System.out.println("Thread "+threadID+ " checking divisibility from "+initDivisor+" till "+finalDivisor);
        if(isItPrime(threadID, num, initDivisor, finalDivisor)){
            CheckPrimeConc.isPrime[threadID]=true;
        }
        else {
            CheckPrimeConc.isPrime[threadID]=false;
        }
    }
    
    // Check if num is divisible by any integer from 2 to divisor
    
    public boolean isItPrime(int ID, long num, long initDivisor, long finalDivisor){ 
       if(num==2) 
            return (true);
        for(long i=finalDivisor; i>initDivisor; --i){
            if(num%i==0){
                divisibleBy[ID]=i;
                return(false);
            }
        }
        return(true);  
    }
    
    // Ask the user to enter a number to be checked for primality.
    
    public static long getNum(Scanner in){
       long num=0;  // To be input by the user; 0 is the default value.
        boolean cont; // Use to decide whether or not to perform primality check.
        
        while(true){ // This loop terminates only 0 or a valid number is entered.
            System.out.println("Enter a positive integer or enter 0 to exit: "); 
            cont=true; // Assume that input will be OK and set flag so primality check could continue.
            try{
                num=in.nextLong();  // Get a number from the user. An exception will be generated 
                                    // if the user types a non-number.   
            }catch(Exception e){// if the user types a non-number.
                cont=false; // In that case no need to check. 
                System.out.println("Sorry, input not a number or is too large, try again.");
                String useless=in.next(); // The string typed by the user needs to be flushed.
            } 
            // The next loop checks whether or not the number is valid or 0 (for exit).
            while(cont){
                if(num<0){
                    System.out.println("Sorry, try a positive number.");
                    cont=false;
                }
                else if(num==0){
                    System.out.println("Thanks for using this program.");
                    System.exit(0);
                }
                else
                    return(num); // Number is well formed.
            }  
        }
    }
    // Display the results of chcking num for prmality.
    
    public static void displayOutcome(){
        if(num==1){
            System.out.println("1 is not prime by definition");
            return;
        }
        if(isPrime[0]&&isPrime[1]){
            System.out.println("Indeed, "+ num+ " is prime.");
        }
        else {
            if(!isPrime[0])
                System.out.println( num+ " is not a prime. It is divisible by "+divisibleBy[0]);
            if (!isPrime[1])
                System.out.println( num+ " is not a prime. It is also divisible by "+
                                   divisibleBy[1]+" and probably by other integers");
        }
    }
    
    // main method where the action is initiated.
    
    public static void main(String args[]){   
        long num; //Holds the number to be checked for primality.
        Scanner in=new Scanner(System.in); // This object is to get keyboard input.
        
        while(true){ // This is infinite loop but
            num=getNum(in); //the program may exit inside getNum().
            
            startTime = System.currentTimeMillis(); // Get current time.
            
            long maxDivisor=(long)Math.sqrt(num);
            long maxD=(long)maxDivisor/3;
            CheckPrimeConc t1=new CheckPrimeConc(0,num, 2, maxD); // Create a thread
            CheckPrimeConc t2=new CheckPrimeConc(1,num, maxD+1, maxD+maxD); // and another one.
            CheckPrimeConc t3=new CheckPrimeConc(2,num, maxD+maxD+1, maxDivisor); // and another one.
            t1.start(); // Start the first thread,
            t2.start(); // and now the second.
            t3.start(); // and now the third.
            try{
                t1.join(); // Wait for t1 and
                t2.join(); // t2 to terminate.
                t3.join(); // t3 to terminate.
            }catch(Exception e){}     
            displayOutcome();     
            
            endTime = System.currentTimeMillis(); // Get end time.
            System.out.println("Time elapsed: " + (endTime-startTime) + " milleseconds");  
            
        }
    }
}


