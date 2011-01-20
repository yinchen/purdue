import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.util.*;
import javax.swing.event.*;

public class Gui extends JFrame implements KeyListener, ActionListener, MenuListener {
  private Graphics g2d; //object that draws to image
  private Image dbImage; //image that draws to Jpanel
  private int x;  //x position of player
  private int y;  //y position of player
  private int dx; //incrments x position when the players moves left or right
  private int dy; //incrments y position when the players moves up or down 
  boolean turn = true;  //boolean that gives animation to player
  //boolean gamestate = true;  used previously to keep hold of game status
  private ArrayList enemies = new ArrayList();  //holds a list of objects containing enemies
  private ArrayList asteroids = new ArrayList(); //holds a list of objects contaning asteroids
  private int score = 0; // holds the score
  JPanel frame;
  int gameState; //0=running 1=paused, -1 = quit, do not save data
  
  public Gui(){    //sets cursor in the middle
    x=400;
    y=400;
    dx=0;
    dy=0;
    
    frame = new JPanel();
    frame.setBackground(Color.WHITE);
    setLocation(0,0);
    setSize(850,850);
    setResizable(false);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    
    //menu bar
 JMenuBar menuBar;
 JMenu menu;
 JMenuItem menuItem;
 menuBar = new JMenuBar(); 

 menu = new JMenu("Game");
 menu.addMenuListener(this);
 menuBar.add(menu); 
 
 menuItem = new JMenuItem("New");
 menuItem.addActionListener(this);
 menu.add(menuItem);
 
 menuItem = new JMenuItem("Quit");
 menuItem.addActionListener(this);
 menu.add(menuItem);
 
 menuItem = new JMenuItem("Pause");
 menuItem.addActionListener(this);
 menu.add(menuItem);
 
 menuItem = new JMenuItem("Exit/Close");
 menuItem.addActionListener(this);
 menu.add(menuItem);
 
 menu = new JMenu("Settings");
 menu.addMenuListener(this);
 menuBar.add(menu); 
 
 menuItem = new JMenuItem("Speed");
 menuItem.addActionListener(this);
 menu.add(menuItem);
 
 menuItem = new JMenuItem("Window Size");
 menuItem.addActionListener(this);
 menu.add(menuItem);

 menu = new JMenu("Scores");
 menu.addMenuListener(this);
 menuBar.add(menu);

 setJMenuBar(menuBar);
 
    frame.setFocusable(true);
    frame.requestFocusInWindow();
    frame.addKeyListener(this);
    add(frame);
    setVisible(true);
 
    try{       //initilizes enemies
      for(int i=0;i<10;i++)
        enemies.add(i,new Enemies());
    }catch(Exception e){}
    
    try{       //initilizes asteroids
      for(int i=0;i<10;i++)
        asteroids.add(i,new Asteroids());
    }catch(Exception e){}
  }
  
  public void actionPerformed(ActionEvent e) {
        String event = e.getActionCommand();
 System.out.println(" " + event);
 if(event.equals("New")){
  
 }
 if(event.equals("Quit")){
  gameState = -1;
 }
 if(event.equals("Pause")){
  if(gameState == 0)
   gameState = 1;
  else
   gameState = 0;
 }
 if(event.equals("Exit/Close")){
  System.exit(0);
 }
 if(event.equals("Speed")){
  
 }
 if(event.equals("Window Size")){
  
 }
  }
  
  public void refresh(){
   x=400;
   y=400;
   dx=0;
   dy=0;
   score = 0;
  }

  public int gameState(){
 return gameState;
  }

  public void menuCanceled(MenuEvent e){}

  public void menuDeselected(MenuEvent e){
 gameState = 0;
  }
  public void menuSelected(MenuEvent e){
 gameState = 1;
  }
 
  public static void main(String []args){  //test for gui
    Gui simplegame = new Gui();
    simplegame.display();
  }
  
  
  public void display()  //updates screen and movement of enemies and asteroids as well as sleeps the loop so there will be playable gameplay
  {
    
    long starttime=System.currentTimeMillis();
    movement();
    movement();
    gameRender();
    paintScreen();
    long time = System.currentTimeMillis()-starttime;
    //System.out.println(time);
    int sleep;
    if(60-time>0)
      sleep=(int)(60-time);
    else
      sleep=5; 
    try{Thread.sleep(sleep);}catch(Exception e){e.printStackTrace();}
    starttime=System.currentTimeMillis(); 
  }
  
  
  private void paintScreen() //paint to screen
    // actively render the buffer image to the screen 
  { 
    Graphics g; 
    try { 
      g = frame.getGraphics();  // get the panel?s graphic context 
      if ((g != null) && (dbImage != null)) 
        g.drawImage(dbImage, 0, 0, null); 
      g.dispose(); 
    } 
    catch (Exception e) 
    { System.out.println("Graphics context error: " + e);  } 
  } // end of paintScreen() 
  
  
  public void gameRender(){  //draws player, enemies, and asteroids to image
    if(dbImage==null){
      dbImage = createImage(getWidth(),getHeight());
      if(dbImage==null){
        System.out.println("dbImage is null");
        return;
      }else
        g2d = dbImage.getGraphics();
    }
    
    g2d.setColor(Color.WHITE);
    g2d.fillRect(0,0,getWidth(),getHeight());
    
    if(turn){
      g2d.setColor(Color.BLUE);
      g2d.drawOval(x,y,20,20);
      g2d.drawOval(x+10,y,20,20);
      g2d.drawOval(x-10,y,20,20);
      g2d.drawOval(x,y-10,20,20);
      g2d.drawOval(x,y+10,20,20);
      turn=false;
    }else
    {
      g2d.setColor(Color.ORANGE);
      g2d.drawOval(x,y,20,20);
      g2d.drawOval(x+10,y+10,20,20);
      g2d.drawOval(x-10,y-10,20,20);
      g2d.drawOval(x+10,y-10,20,20);
      g2d.drawOval(x-10,y+10,20,20);
      turn=true;
    }
    
    
    
    //Draw Enemies
    g2d.setColor(Color.GREEN);
    for(int i=0;i<enemies.size();i++)
      g2d.fillOval((int)(((Enemies)enemies.get(i)).getX()),(int)(((Enemies)enemies.get(i)).getY()),30,30);    
    
    //Draw Asteroidss
    g2d.setColor(Color.RED);
    for(int i=0;i<enemies.size();i++)
      g2d.fillOval((int)(((Asteroids)asteroids.get(i)).getX()),(int)(((Asteroids)asteroids.get(i)).getY()),30,30);    
    
    
    //Counter
    g2d.drawString("Score: "+score,50,50);
    
  }
  
  public void keyPressed(KeyEvent e) {
    int key = e.getKeyCode();
    if(key==KeyEvent.VK_LEFT)
      dx=-10;
    if(key==KeyEvent.VK_RIGHT)
      dx=10;
    if(key==KeyEvent.VK_UP)
      dy=-10;
    if(key==KeyEvent.VK_DOWN)
      dy=10;
  }
  public void keyReleased(KeyEvent e) {
    int key = e.getKeyCode();
    if(key==KeyEvent.VK_RIGHT)
      dx=0;
    if(key==KeyEvent.VK_LEFT)
      dx=0;
    if(key==KeyEvent.VK_UP)
      dy=0;
    if(key==KeyEvent.VK_DOWN)
      dy=0;
  }
  
  public void keyTyped(KeyEvent e){}
  
  private void movement(){
    x+=dx; //increments player's x coordinate
    y+=dy; //increments player's y coordinate
    
    //keeps asteroids moving
    for(int i=0;i<asteroids.size();i++){
      ((Asteroids)asteroids.get(i)).move((int)(((Asteroids)asteroids.get(i)).getX()-15),(int)(((Asteroids)asteroids.get(i)).getY()));
      
      if((((Asteroids)asteroids.get(i)).getX()>getWidth()))
        ((Asteroids)asteroids.get(i)).move(0,(int)(((Asteroids)asteroids.get(i)).getY()));
      if((((Asteroids)asteroids.get(i)).getY()>getHeight()))
        ((Asteroids)asteroids.get(i)).move((int)(((Asteroids)asteroids.get(i)).getX()),0);
      if((((Asteroids)asteroids.get(i)).getX())<0)
        ((Asteroids)asteroids.get(i)).move(getWidth(),(int)(Math.random()*getHeight()));
      if((((Asteroids)asteroids.get(i)).getY())<0)
        ((Asteroids)asteroids.get(i)).move((int)(((Asteroids)asteroids.get(i))).getX(),getHeight());
    }
    
    
    //keeps enemies moving 
    for(int i=0;i<enemies.size();i++){
      ((Enemies)enemies.get(i)).move((int)(((Enemies)enemies.get(i)).getX()-5),(int)(((Enemies)enemies.get(i)).getY()));
      
      if((((Enemies)enemies.get(i)).getX()>getWidth()))
        ((Enemies)enemies.get(i)).move(0,(int)(((Enemies)enemies.get(i)).getY()));
      if((((Enemies)enemies.get(i)).getY()>getHeight()))
        ((Enemies)enemies.get(i)).move((int)(((Enemies)enemies.get(i)).getX()),0);
      if((((Enemies)enemies.get(i)).getX())<0)
        ((Enemies)enemies.get(i)).move(getWidth(),(int)(Math.random()*getHeight()));
      if((((Enemies)enemies.get(i)).getY())<0)
        ((Enemies)enemies.get(i)).move((int)(((Enemies)enemies.get(i))).getX(),getHeight());
    }
    
  }
  
  public void changeEnemy(int i){ //given enemy is placed randomly on the screen
    ((Point)enemies.get(i)).setLocation((int)(Math.random()*800),(int)(Math.random()*800));
  }
  
  public void changeEnemyPosotion(int i, int x, int y){  //changes enemy's coordinates at given position to given x and y
    ((Point)enemies.get(i)).setLocation(x,y);
  }
  
  public double getEnemyX(int i){  //returns x coordinate of enemy
    return ((Point)enemies.get(i)).getX();
  }
  
  
  public double getEnemyY(int i){  //returns y coordinate of enemy at given position
    return ((Point)enemies.get(i)).getY();
  }
  
  public Point getEnemy(int i){  //returns Point class of enemy at given position
    return ((Point)enemies.get(i));
  }
  
  public int enemiesSize(){ // returns the number of enemies
    return enemies.size();
  }
  
  public int asteroidsSize(){ //returns the number of asteroids
    return asteroids.size();
  }
  
  public void changeAsteroid(int i){  //change asteroid a position to a randmo location on screen
    ((Point)asteroids.get(i)).setLocation((int)(Math.random()*800),(int)(Math.random()*800));
  }
  
  public void changeAsteroidPosotion(int i, int x, int y){  //change x and y position of of asteroid at given location 
    ((Point)asteroids.get(i)).setLocation(x,y);
  }
  
  public double getAsteroidX(int i){  //returns x coordinate of asteroid at given position
    return ((Point)asteroids.get(i)).getX();
  }
  
  
  public double getAsteroidY(int i){  //returns y coordinate of asteroid at given position
    return ((Point)asteroids.get(i)).getY();
  }
  
  public Point getAsteroid(int i){  //returns Point of asteroid at given position
    return ((Point)asteroids.get(i));
  }
  
  public int getX(){  //returns players x coordinate
    return x;
  }
  
  public int getY(){  //returns players y coordinate
    return y; 
  }
  
  public void setX(int x){  //changes player's x coordinate to given parameter
    this.x=x;
  }
  
  public void setY(int y){ //changes player's y coordinate to given parameter
    this.y=y;
  }
  
  public void increaseScore(){ //increases score by one
    score++;
  }
  
  public void decreaseScore(){ //decreases score by one
    score--;
  }
  
  public int getScore(){ //returns score
    return score; 
  }

public void menuKeyTyped(MenuKeyEvent e) {

   }
   public void menuKeyPressed(MenuKeyEvent e) {
 System.out.print("it's pressed");
   }
   public void menuKeyReleased(MenuKeyEvent e) {
   
   }

  
}

//Enemies add points to score and are green filled circles
class Enemies extends Point{
  Enemies(){
    super((int)(Math.random()*800),(int)(Math.random()*800));
  }
  
  Enemies(int x, int y){ 
    super(x,y);
  }
}

//Asteroids subtracts point to score and are red filled circles
class Asteroids extends Point{
  Asteroids(){
    super((int)(Math.random()*800),(int)(Math.random()*800));
  }
  
  Asteroids(int x, int y){
    super(x,y);
  }
}

