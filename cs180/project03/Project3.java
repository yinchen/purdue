/*
* Project3.java
* Project 3
* It is important that you develop your program incrementally. First devekop
* the GUI that shows the calculator as indicated in Step I below. Then add
* listeners to each key and the calculator screen. This is explained in Step
* II. Next add code to perform various operations in response to a user
* pressing a calculator key. This is explained in Step III. Make sure you test
* your code after coding each step and before you move to the next step.
*
* @author Matt McCormick
* @recitation 008 - Salman Al-Ansari
* @date 10/24/2010
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Project3 implements ActionListener
{
    // initialize GUI variables
    JFrame mainFrame;       
    JPanel mainPanel; 
    JPanel buttonPanel;    
    JButton[] buttons;    
    JTextField window;
    
    // initialize calculator variables
    double memory = 0;
    boolean clear = false;
    String prevop = " ";
    
    // create frame
    private void createFrame()
    {  
        mainFrame = new JFrame("CS180 Calculator");
        mainFrame.setSize(500, 340);
        mainFrame.setBackground(Color.WHITE);
        mainFrame.add(mainPanel);
 
        mainFrame.setVisible(true);
    }
    
    // create panels
    private void createPanels()
    {  
        mainPanel = new JPanel(new BorderLayout());
        mainPanel.setPreferredSize(new Dimension(340, 500));
        mainPanel.setBackground(Color.WHITE);
        
        buttonPanel = new JPanel(new GridLayout(4, 6));
        buttonPanel.setPreferredSize(new Dimension(300, 500));
        buttonPanel.setBackground(Color.WHITE);
        for(int i = 0; i < 24; i++)
        {
            buttonPanel.add(buttons[i]);  
            buttons[i].addActionListener(this);
        }   
        
        mainPanel.add(window, BorderLayout.NORTH);
        mainPanel.add(buttonPanel, BorderLayout.CENTER);   
    }
    
    // create buttons
    private void createButtons()
    {        
        buttons = new JButton[24];
        buttons[0] = new JButton("1");
        buttons[1] = new JButton("2");
        buttons[2] = new JButton("3");
        buttons[3] = new JButton("+");
        buttons[4] = new JButton("-");
        buttons[5] = new JButton("sin");
        buttons[6] = new JButton("4");
        buttons[7] = new JButton("5");
        buttons[8] = new JButton("6");
        buttons[9] = new JButton("*");
        buttons[10] = new JButton("/");
        buttons[11] = new JButton("cos");
        buttons[12] = new JButton("7");
        buttons[13] = new JButton("8");
        buttons[14] = new JButton("9");
        buttons[15] = new JButton("^");
        buttons[16] = new JButton("√");
        buttons[17] = new JButton("tan");
        buttons[18] = new JButton(".");
        buttons[19] = new JButton("0");
        buttons[20] = new JButton("=");
        buttons[21] = new JButton(" "); 
        buttons[22] = new JButton("log");
        buttons[23] = new JButton("nlog");      
    }
    
    // create text field
    private void createTextField()
    {
        window = new JTextField("0", 8);
        window.setEditable(false);
    }
    
    // handle button click
    public void actionPerformed(ActionEvent e)
    {
        JButton button = (JButton)e.getSource();
        
        // debug
        System.out.println("Button " + button.getText() + " pressed.");
        System.out.println("Window displaying " + window.getText() + ".");
        
        if (clear)
        {
            window.setText("0");
            clear = false;
        }
        
        switch(button.getText().charAt(0))
        {
            case '0':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "0");
                break;
            case '1':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "1");
                break;
            case '2':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "2");
                break;
            case '3':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "3");
                break;
            case '4':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "4");
                break;
            case '5':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "5");
                break;
            case '6':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "6");
                break;
            case '7':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "7");
                break;
            case '8':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "8");
                break;
            case '9':
                if (window.getText().length() < 9)
                    window.setText(window.getText() + "9");
                break;
            case '.':
                if (window.getText().length() < 9 && 
                    window.getText().indexOf(".") < 0)
                    window.setText(window.getText() + ".");
                break;
            case '+':
                calculate();
                prevop = "+";
                break;
            case '-':
                calculate();
                prevop = "-";
                break;
            case '*':
                calculate();
                prevop = "*";
                break;
            case '/':
                calculate();
                prevop = "/";
                break;
            case 's':
                prevop = "s";
                calculate();
                memory = 0;
                break;
            case 'c':
                prevop = "c";
                calculate();
                memory = 0;
                break;
            case 't':
                prevop = "t";
                calculate();
                memory = 0;
                break;
            case '^':
                calculate();
                prevop = "^";
                break;
            case '√':
                prevop = "√";
                calculate();
                memory = 0;
                break;
            case 'l':
                prevop = "l";
                calculate();
                memory = 0;
                break;
            case 'n':
                prevop = "n";
                calculate();
                memory = 0;
                break;
            case '=':
                calculate();
                prevop = " ";
                memory = 0;
                break;
        }
        
        window.setText(window.getText().replaceAll("^0*", ""));
        window.setText(window.getText().replaceAll("\\.0+$", ""));
        if (window.getText().length() == 0)
            window.setText("0");
            
        if (window.getText().charAt(0) == '.')
            window.setText("0" + window.getText());
            
        if (window.getText().length() > 8)
            window.setText(window.getText().substring(0, 8));
    }
    
    private void calculate()
    {
        switch(prevop.charAt(0))
        {
            case '+':
                memory = memory + Double.valueOf(window.getText());
                break;
            case '-':
                memory = memory - Double.valueOf(window.getText());
                break;
            case '*':
                memory = memory * Double.valueOf(window.getText());
                break;
            case '/':
                memory = memory / Double.valueOf(window.getText());
                break;
            case 's':
                memory = Math.sin(Double.valueOf(window.getText()));
                break;
            case 'c':
                memory = Math.cos(Double.valueOf(window.getText()));
                break;
            case 't':
                memory = Math.tan(Double.valueOf(window.getText()));
                break;
            case '^':
                memory = Math.pow(memory, Double.valueOf(window.getText()));
                break;
            case '√':
                memory = Math.sqrt(Double.valueOf(window.getText()));
                break;
            case 'l':
                memory = Math.log10(Double.valueOf(window.getText()));
                break;
            case 'n':
                memory = Math.log(Double.valueOf(window.getText()));
                break;
            default:
                memory = Double.valueOf(window.getText());
                break;
        }
    
        clear = true;
        window.setText(String.valueOf(memory));
    }
    
    public static void main(String args[])
    {        
        Project3 p = new Project3();
        p.createTextField();
        p.createButtons();
        p.createPanels();
        p.createFrame();
    }
}
