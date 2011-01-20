/*
 * The Guio class will be given to the students and all changes made to the position of game components such the cursor/person
 * enemies, and asteroids. Students will also detect collision detection and deal with reapperance and disapperance of asteriods and enemies.
 * 
 * The Gui class offers ideas of arrays, arrays can be implemented if decided upon.
 * 
 * I've made all feilds private so students have to call methods to access fields
 * 
 * 
 * */


import javax.swing.JOptionPane;
import java.io.*;
import java.util.*;

public class Students implements Runnable{
  Gui gui;  //holds gui object
  long starttime;  //holds start time to be check in loop
  String lastName = "";
  String[] students = new String[16];
  int[] scores = new int[16];
  int numScores = 0;
  
  public Students(){
    gui= new Gui();
    lastName = JOptionPane.showInputDialog(gui, lastName, "Please Enter Your Name:", 1);
    starttime=System.currentTimeMillis();
  }
  
  /*
   * very basic way of doing things
   * each method upadates variables 
   * The order of the methods called here does not matter.
   * 
   * */
  public void run(){
    readIn();
    
    while(true){
     if(gui.gameState() == 0){
      gui.display();  //updates the image made by the gui from the variables held by gui
      movement();  //updates all movement of player, enemies, and asteriods
     }
     else{
      starttime = System.currentTimeMillis()-(System.currentTimeMillis()-starttime);
     }
      if(checkTime() && gui.gameState() == 0){   //checkTime() just check if 30 seconds has passed, if it has passed then the method will return true and show JOptionPane
      JOptionPane.showMessageDialog(gui, lastName + " your game has ended \n Score: "+gui.getScore(),
                                    "DONE", JOptionPane.WARNING_MESSAGE);
        students[numScores] = lastName;
        scores[numScores] = gui.getScore();
        if(numScores != 15)
         numScores++;
        sort();
        showScores();
      break;
      }
      if(gui.gameState() == -1){//quit, do not save data
       JOptionPane.showMessageDialog(gui, lastName + " you have quit your game, yours score will not be saved",
                                    "QUIT", JOptionPane.WARNING_MESSAGE);
      }
        
    } 
     writeOut();
     newGame();
  }
  
  public void newGame(){
   lastName = JOptionPane.showInputDialog(gui, null, "Please Enter Your Name:", 1);
   starttime=System.currentTimeMillis();
   gui.refresh();
   run();
  }
  
  public void readIn(){
   //use buffered readers to read file in\
    try
    {
      BufferedReader in = new BufferedReader(new FileReader("scores.txt"));
      
      String next;
      int count = 0;
      while ((next = in.readLine()) != null)
      {
        students[count] = next.split(" ")[0];
        scores[count] = Integer.parseInt((next.split(" ")[1]));
        count++;
      }
      numScores = count;
      in.close();
    }
    catch(IOException x)
    {
    }
    finally
    {      
    }
  }
  
  public void writeOut(){
   //use buffered writers to write file
   // remember you only need to save the highest 15 scores
    try
    {
      PrintWriter out = new PrintWriter(new FileOutputStream("scores.txt"));
    
      for (int i = 0; i < 15; i++)
      {
        if (students[i] != null)
          out.write(students[i] + " " + scores[i] + "\n");
      }
      out.flush();
      out.close();
    }
    catch(IOException x)
    {
      System.out.println("error");
    }
    finally
    {
    }
  }
  
  public void sort(){
   //implement bubble sort function
    int tmp1;
    String tmp2;
    for (int i = 0; i < numScores; i++)
    {
     for (int j = 0; j < numScores - 1; j++)
     {
      if (scores[j] < scores[j+ 1])
      {
       tmp1 = scores[j];
       tmp2 = students[j];
       scores[j] = scores[j + 1];
       students[j] = students[j + 1];
       scores[j+1] = tmp1;
       students[j+1] = tmp2;
      }
     }
    }
  }
  
  public void showScores(){
   //this funtion needs to be rewritten for lab13, file I/O
   String scoreBoard = "";
   for(int i=0; i<numScores && i<15; i++){
    scoreBoard += students[i] + "        " + scores[i] + "\n";
   }
   JOptionPane.showMessageDialog(gui, scoreBoard, "HIGH SCORES", JOptionPane.PLAIN_MESSAGE);
  }
  
  public void movement(){  //updates all movement of enemies and asteriods
   
    //this first block of code simply makes sure the player stay on the board, so that if the player exits on one side
    //the player return on the other side of the board
    
    if(gui.getX()>gui.getWidth())
      gui.setX(0);
    if(gui.getY()>gui.getHeight())
      gui.setY(0);
    if(gui.getX()<0)
      gui.setX(gui.getWidth());
    if(gui.getY()<0)
      gui.setY(gui.getHeight());
    
    
    //these two second blocks of code check if the distance of the of each enemy and/or asteroid is less than or equal to the radius of the player plus the enemy/asteroid
    //radius is hard coded here figured they have called method
    //the score is also increased or decresed based on if it's an asteroid or enemy
    
     for(int j=0;j<gui.enemiesSize();j++){
     if((gui.getEnemy(j)).distance(gui.getX(),gui.getY())<=28){
     try{
     gui.changeEnemy(j);
     }catch(Exception e){
     System.out.println("Exception at "+j);
     }
     gui.increaseScore();
     }
     }
     
     for(int j=0;j<gui.asteroidsSize();j++){
     if((gui.getAsteroid(j)).distance(gui.getX(),gui.getY())<=28){
     try{
     gui.changeAsteroid(j);
     }catch(Exception e){
     System.out.println("Exception at "+j);
     }
     gui.decreaseScore();
     }
     }
     
  }
  
  //checkTime() just check if 30 seconds has passed, if it has passed then the method will return true
  public boolean checkTime(){
    return (System.currentTimeMillis()-starttime)>=3000;
  }
  
  public static void main(String args[]){   //I used a thread to implement the student side, does not have to be done, but would like to show them how one looks
    Thread game = new Thread(new Students());
    game.start();
  }
  
}
