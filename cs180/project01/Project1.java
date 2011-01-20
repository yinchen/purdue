/* 
 * Project1.java
 * Project 1
 * Develop a prototype checkout system. The checkout system should 
 * ask the customer for a name, shipping address, three product names 
 * and the weight and price of each of the three aforementioned 
 * products. The checkout system should first calculate the subtotal by 
 * adding the prices of the three products. Next it will generate a 
 * random sales tax that ranges from 5% to 12% and calculate the sales 
 * tax for this specific order. The program will then add the three 
 * weights, and use this to generate the shipping cost. Finally, the 
 * program will add this all up to reach the order total and print a 
 * detailed receipt to the console.
 * 
 * @author Matt McCormick
 * @recitation 008 - Salman Al-Ansari
 * @date 09/19/2010
 * 
 */

import java.util.*;

public class Project1
{
  public static void main(String []args)
  {
    // setup scanner
    Scanner s = new Scanner(System.in);
    
    // collect general info input from user
    System.out.println("Enter name: ");
    String name = s.nextLine();
    System.out.println("Enter street address: ");
    String address = s.nextLine();
    System.out.println("Enter city: ");
    String city = s.nextLine();
    System.out.println("Enter state: ");
    String state = s.nextLine();
    System.out.println("Enter zip code: ");
    String zipcode = s.nextLine();
    System.out.println();
    
    // calculate three products info from user
    System.out.println("Enter name of Product #1: ");
    String p1name = s.nextLine();
    System.out.println("Enter weight of Product #1: ");
    float p1weight = s.nextFloat();
    System.out.println("Enter price of Product #1: ");
    float p1price = s.nextFloat();
    System.out.println();
  
    System.out.println("Enter name of Product #2: ");
    s.nextLine();
    String p2name = s.nextLine();
    System.out.println("Enter weight of Product #2: ");
    float p2weight = s.nextFloat();
    System.out.println("Enter price of Product #2: ");
    float p2price = s.nextFloat();
    System.out.println();
 
    System.out.println("Enter name of Product #3: ");
    s.nextLine();
    String p3name = s.nextLine();
    System.out.println("Enter weight of Product #3: ");
    float p3weight = s.nextFloat();
    System.out.println("Enter price of Product #3: ");
    float p3price = s.nextFloat();
    System.out.println();
 
    // calculate the subtotal
    float subtotal = p1price + p2price + p3price;
 
    // calculate the tax
    Random generator = new Random();
    float tax = (float)(generator.nextInt(7) + 5);
    float taxamt = subtotal*((float)(tax/100));
  
    // calculate the weight
    float weight = p1weight + p2weight + p3weight;
 
    // calculate the shipping
    float shipping = (float)(weight / 15);
 
    // calculate the grand total
    float total = subtotal + taxamt + shipping;
  
    // print out the receipt
    System.out.println(name);
    System.out.println(address);
    System.out.println(city + ", " + state + " " + zipcode);
    System.out.println();
    System.out.println("Product\t\tWeight\t\tPrice");
    System.out.println("------------------------------------------------------------");
    System.out.format("%s\t%-3.2f lbs\t$%-3.2f\n", p1name, p1weight, p1price);
    System.out.format("%s\t%-3.2f lbs\t$%-3.2f\n", p2name, p2weight, p2price);
    System.out.format("%s\t%-3.2f lbs\t$%-3.2f\n", p3name, p3weight, p3price); 
    System.out.println("------------------------------------------------------------");
    System.out.format("Sub Total\t\t\t$%-3.2f\n", subtotal);
    System.out.println();
    System.out.format("Tax\t\t\t\t%-2.2f%%\n", tax);
    System.out.format("Total Tax\t\t\t$%-3.2f\n", taxamt);
    System.out.format("Total Weight\t\t\t%-3.2f lbs\n", weight);
    System.out.format("Shipping Cost\t\t\t$%-3.2f\n", shipping);
    System.out.println("------------------------------------------------------------");
    System.out.format("Grand Total\t\t\t$%-3.2f\n", total);
  }
}
