/*
 * *************************************************************************
 * Program name: CheckPrimality
 * 
 * Description:
 * 
 * This program takes an integer as input and checks if it
 * is prime or not. This program is intended to be used 
 * in Lab 2 to understand what we mean by "Play-and-Learn".
 * You will likely not understand all aspects of this
 * program but it will help you enter the play-and-learn realm 
 * of programming.
 * 
 * There are two other versions of this program that we will make available to
 * you at a later date. One of these is a multithreaded version and the other a
 * multithreaded and GUI version. Both versions are much
 * more fun to dissect, but more complex too!
 * 
 * Author: Aditya Mathur
 * Date: June 30, 2010
 * Revised: July 5, 2010, August 2, 2010
 * 
 * *************************************************************************
 * 
 * Lab tasks A: Pre-compilation 
 * 
 * Spend a few minutes browsing this program and try to
 * answer the following questions prior to compiling it.
 * 
 * 1. List all classes used explicitly methods in this program.
 * 2. List all methods defined as well as used in this program.
 * 3. For each method, list its return type.
 * 4. What is the purpose of the Scanner class?
 * 5. What does the println() method do?
 * 6. Can you locate the constructor for CheckPrimality?
 * 7. List all the primitive types used in this program.
 * 8. After having browsed the program, can you explain 
 * the method used here to check for primality?
 * 9. What differences and similarities do you notice in the naming of classes,
 * methods, and variables? 
 * 
 * Lab tasks B: Post-compilation
 * 
 * 1. Compile and run the program. 
 *    When asked for a number input the following strings (one on each request):
 * 
 *   104,395,301
 *    1234560
 *    123gg22
 *    -3
 *    0
 * What happens when you type a non-number?
 * 
 * Lab tasks C: Tracing
 * 
 * 1. Add a breakpoint at the following statement:
 * 
 * isItPrime(num);
 * 
 * 2. Add variable num to the watch list.
 * 3. Compile the program.
 * 4. Enable Debug Mode.
 * 5. Now run the program first with input 13, then with input 14, and lastly with input 
 * 4gg. Trace the program using SkipInto and Skip Over options.
 * 5. Play as much as you wish with the tracing features and try to
 * learn how to trace through the program.
 * 6. Remove all breakpoints.
 * 
 * */
import java.util.Scanner; // This class is needed for input from the keyboard.

// Define a class that contains methods to solve the given problem.

public class CheckPrimality {
    static long startTime, endTime;
    
    // This method checks if the number input is a prime or not.
    // It also displays the result on the console.
    private static void isItPrime(long num) { // Remove the keyword "static" and compile. 
        System.out.println("Checking");
        if (num == 1)
            System.out.println(num + " is not a prime by definition");
        else if (num == 2)
            System.out.println(num + " is a prime number.");
        else {  
            // OK, it is neither 1 nor 2, so proceed with check.
            long divisor = num / 2;  // This will serve as a divisor for num. Can you think of a better starting divisior?
            for (long i = divisor; i > 1; --i) {
                if (num % i == 0) {
                    System.out.println(num + " is divisible by " + i + " hence is not a prime.");
                    return; // Remove this return and observe the effect.
                }
            }
            System.out.println(num + " is a prime.");
        }
    }
    
    public static void main(String args[]) {
        long num = 0;  // To be input by the user; 0 is the default value.
        Scanner in = new Scanner(System.in); // This object named "in" will aid us in getting an input.
        
        while (true) { // This loop will terminate only if done so by user entering a 0.
            System.out.println("Enter a positive integer or enter 0 to exit: "); 
            try {
                num = in.nextLong();  // Get a number from the user. An exception will be generated 
            } catch (Exception e) { // if the user types a non-number.
                System.out.println("Sorry, input not a number or is too large, try again.");
                in.nextLine(); // flush input to end of line
                continue;
            } 
            if (num == 0)
                break;
            else if (num < 0)
                System.out.println("Sorry, try a positive number.");
            else {
                // All is well, make note of the current time and begin checking.
                startTime = System.currentTimeMillis(); // Get current time.
                isItPrime(num);  // Check if it is prime.
                endTime = System.currentTimeMillis(); // Get end time.
                System.out.println("Time elapsed: " + (endTime-startTime) + " milleseconds");             
            }
        }
        System.out.println("Thanks for using this program.");
    }
}


