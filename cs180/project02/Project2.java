/* 
 * Project2.java
 * Project 2
 * Purdue University has recently been contacted by the Boilerains on Purdation. It 
 * seems that they are engaged in a war with their evil neighbors, the Hoosatairians of 
 * Iuadon. This battle has raged for centuries. Just recently Space Force of the 
 * Boilerains received a grant to train more fighters. However, since the space 
 * surrounding the planet is full of fighting, they have no way of training the new 
 * pilots. This is where you can help the Boilerains fight the good fight and defeat the 
 * Hoosatairians. The simulation that the Boilerains are in most need of is a basic 
 * maneuvering simulation. They need you to create a program that will train their 
 * fighters to both avoid and collect objects as they fly through space.
 * 
 * @author Matt McCormick
 * @recitation 008 - Salman Al-Ansari
 * @date 10/08/2010
 * 
 */

import java.util.*;
import javax.swing.*;

public class Project2
{
    public static void main(String []args)
    {
        // setup gui
        Gui gui = new Gui();
        
        // setup variables
        boolean play = true;
        long duration = 0;
        
        // render display
        while (play)
        {
            long current = System.currentTimeMillis();
            
            if (gui.getPause() > 0)
            {
                gui.display();
                
                // check boundaries
                if (gui.getX() > gui.getWidth())
                    gui.setX(0);
                if (gui.getX() < 0)
                    gui.setX(gui.getWidth());
                if (gui.getY() > gui.getHeight())
                    gui.setY(0);
                if (gui.getY() < 0)
                    gui.setY(gui.getHeight());
                    
                // detect collisions (asteroid)
                for (int i = 0; i < 10; i++)
                {
                    double dist = Math.sqrt(Math.pow(gui.getAsteroidX(i) - gui.getX(), 2) +
                                            Math.pow(gui.getAsteroidY(i) - gui.getY(), 2));
                    if (dist <= 28)
                    {
                        gui.changeAsteroid(i);
                        gui.decreaseScore();
                    }
                }
                
                // detect collisions (enemy)
                for (int i = 0; i < 10; i++)
                {
                    double dist = Math.sqrt(Math.pow(gui.getEnemyX(i) - gui.getX(), 2) +
                                            Math.pow(gui.getEnemyY(i) - gui.getY(), 2));
                    if (dist <= 28)
                    {
                        gui.changeEnemy(i);
                        gui.increaseScore();
                    }
                }
                
                // check time
                duration += System.currentTimeMillis() - current;
                if (duration >= (30 * 1000))
                    play = false;
            }
            else
            {
                // do nothing
            }
        }
        
        // display score
        JOptionPane.showMessageDialog(null, "Your score was " + gui.getScore() + "!", "Score",  JOptionPane.INFORMATION_MESSAGE);
    }
}
