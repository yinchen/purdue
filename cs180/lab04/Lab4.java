/* 
 * Lab4.java
 * Lab4
 * For this lab you will need to take in scores for projects, lab, midterm 1, midterm 2, and final.
 * After obtaining the input. you will print out each score, the course total, and your letter grade.
 * 
 * @author Matt McCormick
 * @recitation 008 - Salman Al-Ansari
 * @date 09/14/2010
 * 
 */

import java.util.*;

public class Lab4
{
 public static void main(String []args)
 {
   // setup scanner
   Scanner s = new Scanner(System.in);
   
   // collect input from user
   System.out.println("Enter Projects total: ");
   float projects = s.nextFloat();
   System.out.println("Enter lab total: ");
   float lab = s.nextFloat();
   System.out.println("Enter midterm #1 score: ");
   float midterm1 = s.nextFloat();
   System.out.println("Enter midterm #2 score: ");
   float midterm2 = s.nextFloat();
   System.out.println("Enter final exam score: ");
   float finalexam = s.nextFloat();
   
   // calculate the total
   float total = (float)((projects * 0.25) + (lab * 0.15) + (midterm1 * 0.15) + (midterm2 * 0.15) + (finalexam * 0.30));
   total = (float)((total / 100) * 670);
   
   // calculate the grade
   int chargrade[] = { 70, 70, 70, 70, 70, 70, 68, 67, 66, 65, 65 };
   
   float grade = (float)((projects * 0.25) + (lab * 0.15) + (midterm1 * 0.15) + (midterm2 * 0.15) + (finalexam * 0.30));
   int lettergrade = (int)(grade / 10);
   
   // print out the scores
   System.out.println();
   System.out.format("Projects: %-3.1f\n", projects);
   System.out.format("Lab: %-3.1f\n", lab);
   System.out.format("Midterm #1: %-3.1f\n", midterm1);
   System.out.format("Midterm #2: %-3.1f\n", midterm2);
   System.out.format("Final: %-3.1f\n", finalexam);
   System.out.println();
   System.out.format("Total: %-3.1f\n", total);
   System.out.println();   
   System.out.format("Letter Grade: %c\n", (char)chargrade[lettergrade]);
 }
}
