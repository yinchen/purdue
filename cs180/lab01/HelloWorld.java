/**
 * MATT MCCORMICK (MBMCCORM@PURDUE.EDU)
 * 
 * HelloWorld.java
 * Lab 1
 *
 * A simple java program asks you name then welcomes you to cs180 and the programing world
 * @author (Tyler Holzer)
 * @version (5/14/2010)
 */

 import java.awt.*;
 import javax.swing.*;
 
public class HelloWorld extends JFrame
{
 private static JPanel panel = new JPanel();
 private static JLabel label = new JLabel();
 
 public HelloWorld()
 {
  super("Hello CS180 Students");
  panel.setPreferredSize(new Dimension(400,50));
  label.setText("Greetings, stranger");
  add(panel, BorderLayout.CENTER);
  panel.add(label, BorderLayout.CENTER);
  pack();
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
 }
 
 public static void main(String [] args)
 {
  String text;
  HelloWorld GUI = new HelloWorld();
  text=JOptionPane.showInputDialog(null, "Please enter your name.","Enter Name");
  label.setText("Greetings "+text+", Welcome to CS180 and Purdue.");
 }
}