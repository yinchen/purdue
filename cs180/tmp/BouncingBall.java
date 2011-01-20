 /*
 * Bouncing ball problem. Integrated program.
 * Author: Aditya Mathur. Date: June 15, 2009.
 */
import java.util.*; 
import java.lang.String;
// import javax.swing.*;
import javax.swing.*;
public class BouncingBall {
    public BouncingBall() {
        System.out.print("Hi! ");
        String frameTitle = "Bouncing Ball";
        double height,coeffRestitution;
        int bounces; 
// Begin solution to sub-problem 1.
        // Declare user prompt strings.
        String enterH = "Enter the height.";
        String enterC = "Enter coefficient of restitution.";
        String enterK = "Enter the number of bounces.";;
        // Prompt the user, get data, and convert to appropriate type.
        String response = JOptionPane.showInputDialog(null, enterH, frameTitle, 
                                                      JOptionPane.QUESTION_MESSAGE); 
       // height = Double.valueOf(response).doubleValue(); // Use this...
        height=Double.parseDouble(response); //.. or this to convert string to double.
        response = JOptionPane.showInputDialog(null, enterC, frameTitle,
                                               JOptionPane.QUESTION_MESSAGE);  
        coeffRestitution = Double.valueOf(response).doubleValue();
        response = JOptionPane.showInputDialog(null, enterK, frameTitle, 
                                               JOptionPane.QUESTION_MESSAGE); 
       //
      //bounces = Integer.valueOf(response).intValue(); 
// Begin solution to sub-problem 2.
        bounces=Integer.parseInt(response);
        double ballHeight = height*Math.pow(coeffRestitution, bounces);
// Begin solution to sub-problem 3.
        // Display calculated height and goodbye message!
        String formattedHeight = String.format("%f",ballHeight);
        String message = "After "+Integer.toString(bounces)+
            " bounces the height of the ball is: "+formattedHeight+" feet"; 
        JOptionPane.showMessageDialog(null, message, frameTitle, JOptionPane.INFORMATION_MESSAGE);
    }
    public static void main(String[] args) {
        BouncingBall(); // Create a BouncingBall object.
    }   
}