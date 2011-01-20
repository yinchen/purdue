
/*
 *
 * This program demonstrates the creation of a simple GUI.
 * The GUI created has one button and one text field.
 * The text field displays the number of
 * times the button is clicked.
 * 
 * Author: Aditya Mathur
 * Date: October 18, 2010
 * Revised: None
 * 
 * Purpose: For CS 180 in class demo
 */

import java.awt.event.*;
import javax.swing.*;
import java.awt.GridLayout;
import java.awt.*;

public class PlusMinus implements ActionListener{
    
    // Declarations for widgets.
    
    JButton buttonPlus; // A button object is declared
    JButton buttonMinus; // Another  button object is declared
    JTextField text; // A text object is declared
    JPanel panel; // A panel object is declared
    JFrame f; // A frame object is declared
    
    // Other useful variables.
    
    int clicks=0; // Number if clicks so far.
    
    // Methods for creating te GUI follow.
    
    public void createButton(){
        buttonPlus=new JButton("+"); // A labelled button object is created
        buttonMinus=new JButton("-");// And another one
        buttonPlus.addActionListener(this); // This class becomes a listener for buttonPlus,
        buttonMinus.addActionListener(this); // and also for the buttonMinus.
    }
    
    public void createTextField(){
        text=new JTextField("0", 10); // A textfield object 10 columns wide is created.
                                      //Initially it contains the string 0 
                                      // indicating that the button has not been clicked.
        text.setHorizontalAlignment(JTextField.CENTER);
    }
    
    public void createPanel(){
        panel=new JPanel(new GridLayout(3,1)); // A panel object is created;
        panel.setBackground(Color.GREEN); // Set the background color of the panel
        panel.add(buttonPlus); // Add the button object to the panel
        panel.add(buttonMinus); // and the other one also.
        panel.add(text); // Add the text object to the panel.   
    }
    
    public void createFrame(){
        f=new JFrame("CS 180 GUI Example 2. October 18, 2010"); // A frame object is created  and given a title.
        f.setSize(350,300); // Its size is set to 350 (Wide)x300(High) pixels.
        f.add(panel); // A panel object is added to the frame.
        f.setVisible(true); // The frame is made visible.
    }
    
    public void actionPerformed(ActionEvent e){
        Object clicked=e.getSource();
        if(clicked==buttonPlus){
            clicks++;
        }else{
            clicks--;
        }
        String s=Integer.toString(clicks);
        text.setText(s);
    }
    
    public static void main(String arg[]){
        PlusMinus gui=new PlusMinus();
        gui.createButton();
        gui.createTextField();
        gui.createPanel();
        gui.createFrame();
        
    }
    
    
}