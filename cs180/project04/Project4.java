/* 
 * Project4.java
 * Project 4
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
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class Project4 implements ActionListener, MenuListener
{
    static Gui gui;
    static long startTime;
    static String lastName = "";
    static String[] students = new String[16];
    static int[] scores = new int[16];
    int numScores = 0;
    
    int gameState = 0;    
    int gameSpeed = 0;
    
    JMenu scoresMenu;
    
    public Project4()
    {
        gui = new Gui();
        setupMenuBar();
    }

    public void run()
    {        
        while (true)
        {
            if (gameState == 0)
            {
                gui.display();                
                movement();
                movement();
            }
            else
            {
                startTime = System.currentTimeMillis() - (System.currentTimeMillis() - startTime);
            }
            
            if (checkTime() && gameState == 0)
            {
                saveScoreAndShow();
                break;
            }
            
            try
            {
                // Thread.sleep(gameSpeed);
            }
            catch(Exception ex)
            {
            }
        }
        
        gameState = -1;
        // newGame();
    }
    
    public void newGame()
    {
        if (lastName == "")
            lastName = JOptionPane.showInputDialog(gui, "Who are you?", "Please enter your name.");
        else
            lastName = JOptionPane.showInputDialog(gui, "Who are you?", lastName);
        startTime = System.currentTimeMillis();        
        
        // gui = new Gui();
        gui.setX(400);
        gui.setY(400);
        
        while(gui.getScore() != 0)
        {
            if (gui.getScore() > 0)
                gui.decreaseScore();
            else
                gui.increaseScore();
        } 
        
        gameState = 0;
        
        setupMenuBar();
        updateScoresMenu();
        
        run();
    }
    
    public void sort()
    {   
        int tmp1;
        String tmp2;
        
        for (int i = 0; i < numScores; i++)
        {
            for (int j = 0; j < numScores - 1; j++)
            {
                if (scores[j] < scores[j + 1])
                {
                    tmp1 = scores[j];
                    tmp2 = students[j];
                    scores[j] = scores[j + 1];
                    students[j] = students[j + 1];
                    scores[j + 1] = tmp1;
                    students[j + 1] = tmp2;
                }
            }
        }
    }
  
    public void showScores()
    {
        String scoreBoard = "";
        
        for(int i = 0; i < numScores && i < 15; i++)
        {
            scoreBoard += students[i] + " " + scores[i] + "\n";
        }
        JOptionPane.showMessageDialog(gui, scoreBoard, "High Scores", JOptionPane.PLAIN_MESSAGE);
    }
    
    public void movement()
    {
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
    }
    
    public void saveScoreAndShow()
    {
        JOptionPane.showMessageDialog(gui, lastName + ", your game has ended.\nScore: " + gui.getScore(), "Game Over", JOptionPane.WARNING_MESSAGE);
        students[numScores] = lastName;
        scores[numScores] = gui.getScore();
        if (numScores != 15)
            numScores++;
        sort();
        updateScoresMenu();
        showScores();
    }
    
    public void updateScoresMenu()
    {
        scoresMenu.removeAll();
        
        JMenuItem mi;
        for (int i = 0; i < numScores; i++)
        {
            mi = new JMenuItem(students[i] + " " + scores[i]);
            scoresMenu.add(mi);
        }
    }
    
    public boolean checkTime(){
        return (System.currentTimeMillis() - startTime) >= 30000; // 30000;
    }
    
    public void setupMenuBar()
    {
        JMenuBar m = new JMenuBar();
        JMenuItem mi;
        
        JMenu m1 = new JMenu("Game"); m1.addMenuListener(this);
        mi = new JMenuItem("Start New Game"); mi.addActionListener(this); m1.add(mi);
        mi = new JMenuItem("Quit Game"); mi.addActionListener(this); m1.add(mi);
        mi = new JMenuItem("Pause"); mi.addActionListener(this); m1.add(mi);
        mi = new JMenuItem("Exit"); mi.addActionListener(this); m1.add(mi);
        m.add(m1);
        
        JMenu m2 = new JMenu("Settings"); m2.addMenuListener(this);
        mi = new JMenuItem("Increase Game Speed"); mi.addActionListener(this); m2.add(mi);
        mi = new JMenuItem("Decrease Game Speed"); mi.addActionListener(this); m2.add(mi);
        m.add(m2);
        
        scoresMenu = new JMenu("Scores"); scoresMenu.addMenuListener(this);
        m.add(scoresMenu);
        
        gui.setJMenuBar(m);
    }
    
    public void actionPerformed(ActionEvent e)
    {
        String event = e.getActionCommand();
        System.out.println(event);
        
        if(event.equals("Start New Game"))
        {
            if (checkTime() && gameState == 0)
            {
                if (JOptionPane.showConfirmDialog(gui, "Are you sure you want to start a new game?", "Start New Game", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION)
                {
                    newGame();
                }
            }
            else
            {
                newGame();
            }
        }
        if(event.equals("Quit Game"))
        {
            if (JOptionPane.showConfirmDialog(gui, "Are you sure you want to end your current game?", "Quit Game", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION)
            {
                gameState = -1;
                saveScoreAndShow();
            }
            else
            {
                gameState = 0;
            }
        }
        if(event.equals("Pause"))
        {
            ((JMenuItem)e.getSource()).setText("Resume");
            gameState = 1;
        }
        if(event.equals("Resume"))
        {
            ((JMenuItem)e.getSource()).setText("Pause");
            gameState = 0;
        }
        if(event.equals("Exit"))
        {
            System.exit(0);
        }
        if(event.equals("Increase Game Speed"))
        {
            if (JOptionPane.showConfirmDialog(gui, "Are you sure you wish to change the settings? Doing so will restart the game and the score will not be saved.", "Change Settings", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION)
            {
                gameSpeed -= Integer.parseInt(JOptionPane.showInputDialog(gui, "Enter the amount you would like to increase speed (ms).", gameSpeed));
                if (gameSpeed < 0)
                    gameSpeed = 0;
                newGame();
            }
        }
        if(event.equals("Decrease Game Speed"))
        {
            if (JOptionPane.showConfirmDialog(gui, "Are you sure you wish to change the settings? Doing so will restart the game and the score will not be saved.", "Change Settings", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION)
            {
                gameSpeed += Integer.parseInt(JOptionPane.showInputDialog(gui, "Enter the amount you would like to decrease speed (ms).", gameSpeed));
                newGame();
            }
        }
    }
    
    public void menuCanceled(MenuEvent e) { }

    public void menuDeselected(MenuEvent e) { gameState = 0; }
    
    public void menuSelected(MenuEvent e) { gameState = 1; }
    
    public static void main(String args[])
    {
        Project4 game = new Project4();
        game.newGame();
    }
}
