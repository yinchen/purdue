import java.awt.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.*;

public class MyApplet extends JApplet implements ActionListener
{
  // declare widgets
  JLabel title;
  JPanel p;
  JButton b[] = new JButton[7];
  
  int hold[][] = new int[8][7];
  int player1 = 0;
  int player2 = 0;
  
  IconPanel icons[][] = new IconPanel[8][7];
    
  public void init()
  {
    setLayout(new BorderLayout());
    
    title = new JLabel("Connect Four");
    add(title, BorderLayout.NORTH);
    
    setPreferredSize(new Dimension(400, 400));
    
    p = new JPanel(new GridLayout(9, 7, 10, 10));
        
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        icons[i][j] = new IconPanel();
        p.add(icons[i][j]); 
      }
    }
    
    for (int i = 0; i < 7; i++)
    {
      b[i] = new JButton(String.valueOf(i + 1));
      b[i].addActionListener(this);
      p.add(b[i]);
    }
    
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 7; j++)
        hold[i][j] = 0;

    
    add(p, BorderLayout.CENTER);
  }
  
  public void actionPerformed(ActionEvent e)
  {
    JButton button = (JButton)e.getSource();
    IconPanel.placeChipAt(hold, Integer.valueOf(button.getText()) - 1, 1);
    
    Random gen = new Random();
    int col = gen.nextInt(7);
    
    IconPanel.placeChipAt(hold, col, 2);
    
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        icons[i][j].setColor(hold[i][j]);
      }
    }
    
    System.out.println("Placed Chip!");
  }
}
