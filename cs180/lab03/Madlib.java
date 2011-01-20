/* 
 * Lab03.java
 * Lab03
 * In this lab you will take user input of strings to create a madlib
 */
 
import java.util.*;
import javax.swing.JOptionPane;

public class Madlib {
 public static void main(String []args) {
    //set up variable here
   String noun1, noun2, noun3, noun4, noun5, noun6, noun7, noun8, noun9, noun10;
   String verb1, verb2;
   String adj1, adj2, adj3, adj4;
   String name1;
 
   //create a new scanner
   Scanner s = new Scanner(System.in);
  
   //prompt the user for 10 nouns, 2 verbs, 4 adj, 1 name. 
   System.out.println("Enter a noun: ");
   noun1 = s.nextLine();
   System.out.println("Enter a noun: ");
   noun2 = s.nextLine();
   System.out.println("Enter a noun: ");
   noun3 = s.nextLine();
   
   System.out.println("Enter a verb: ");
   verb1 = s.nextLine();
   System.out.println("Enter a verb: ");
   verb2 = s.nextLine();
   
   System.out.println("Enter an adjective: ");
   adj1 = s.nextLine();
   System.out.println("Enter an adjective: ");
   adj2 = s.nextLine();   
   System.out.println("Enter an adjective: ");
   adj3 = s.nextLine();
   
   System.out.println("Enter a name: ");
   name1 = s.nextLine();
   
   //combine the madlib string and print it out
   System.out.println("Purdue\n");
   System.out.println("Purdue University is a very " + adj1 + " educational " + noun1 + ". At Purdue, all the students are extremely " + adj2 + ", " + 
                       "and like to " + verb1 + ", " + verb2 + ", and study. Purdue was founded in 1869 and named after benefactor " + name1 + ". The University " +
                       "is one of the " + noun2 + "'s leading research institutions with a reputation for excellent and affordable " + noun3 + ". And we " +
                       "have a really big drum. Obviously we're " + adj3 + ".\n");
   
   
   
   //prompt the user for 7 nouns, 1 adj. 
   noun4 = JOptionPane.showInputDialog("Enter a noun: ");
   noun5 = JOptionPane.showInputDialog("Enter a noun: ");
   noun6 = JOptionPane.showInputDialog("Enter a noun: ");
   noun7 = JOptionPane.showInputDialog("Enter a noun: ");
   noun8 = JOptionPane.showInputDialog("Enter a noun: ");
   noun9 = JOptionPane.showInputDialog("Enter a noun: ");
   noun10 = JOptionPane.showInputDialog("Enter a noun: ");
   
   adj4 = JOptionPane.showInputDialog("Enter an adjective: ");   
   
   //combine the madlib string and print it out
   System.out.println("Computer Science is Awesome!\n");
   System.out.println("Computer Science is the very best discipline in the " + noun4 + ". Computer scientists get to create " + adj4 + " software to " +
                      "solve age-old problems such as how to calculate the " + noun5 + " of a " + noun6 + " and how to efficiently search a " + noun7 + " for a " + 
                      "specific " + noun8 + ". Computer scientists are always on the cutting " + noun9 + " of technology, and enjoy speaking in binary in " +
                      "order to impress the nearby " + noun10 + ".\n");
  
    //Lucky Number
    Random generator = new Random();
    int r = generator.nextInt(91);
    System.out.println("Your lucky number is " + (r + 10) + ".");
  }
}
