/* 
 * PhotoGUI.java 
 * The Gui and Action handler portion of a program designed to
 * allow you to load pictures then mirror, reflect a down the middle,
 * adjust the color, or rotate the colors in the pixel
 * 
 * @author Matt McCormick
 * @date 11/11/2010
 * 
 */
 
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PhotoGUI extends JFrame implements ActionListener {

 private JLabel image; //contains the image to display
 private JScrollPane pane; //scrollable pane that holds the image
 private JMenuBar menuBar; //the menubar
 private JMenu file, operations, thread, mirror, reflect, adjust, pixelrotate;
 private JMenuItem open, save, mirrorh, mirrorv, reflectleft, reflectright, reflecttop, reflectbottom, adjustr, adjustg, adjustb, adjustrg, adjustrb, adjustgb, adjustrgb, pixelrotatel, pixelrotater; //menuitem
 private ButtonGroup threads;
 private JRadioButtonMenuItem thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8;
 private Picture pic; //holds the actual picture
 private JFileChooser fc; //file chooser to choose file
 private JLabel timeElapsed; //contains the timeElapsed
 
 /*constructor
  * sets the components of the GUI as well as initilizes pic, numThreads, and Threads
  **/
 public PhotoGUI() {
  super("PhotoGUI"); // Sets the title of the super (parent) class (the JFrame)
  setDefaultCloseOperation(EXIT_ON_CLOSE);
  
  //initialize file chooser
  fc = new JFileChooser(); 
  
  //initialize the display window
  image=new JLabel();
  pane=new JScrollPane();
  pane.getViewport().add(image);
  add(pane,BorderLayout.CENTER); // Add pane to the frame.
  
  //initalize the menuBar with all menus
  menuBar=new JMenuBar();
  
  file=new JMenu("File");
  menuBar.add(file);  
  
  operations=new JMenu("Operations");
  menuBar.add(operations);  
  
  thread=new JMenu("Thread");
  menuBar.add(thread);
    
  //intialize and add open, save to the file menu
  open=new JMenuItem("Open");
  open.addActionListener(this);
  file.add(open);
  
  save=new JMenuItem("Save");
  save.addActionListener(this);
  file.add(save);
  
  //intialize and add mirror, reflect, adjust, rotate to the operations menu
  mirror=new JMenu("Mirror");
  operations.add(mirror);
  mirrorh=new JMenuItem("Horizontal");
  mirrorh.addActionListener(this);
  mirror.add(mirrorh);  
  mirrorv=new JMenuItem("Vertical");
  mirrorv.addActionListener(this);
  mirror.add(mirrorv);  
  
  reflect=new JMenu("Reflect");
  operations.add(reflect);  
  reflectleft=new JMenuItem("Left Side");
  reflectleft.addActionListener(this);
  reflect.add(reflectleft);  
  reflectright=new JMenuItem("Right Side");
  reflectright.addActionListener(this);
  reflect.add(reflectright);  
  reflecttop=new JMenuItem("Top");
  reflecttop.addActionListener(this);
  reflect.add(reflecttop);  
  reflectbottom=new JMenuItem("Bottom");
  reflectbottom.addActionListener(this);
  reflect.add(reflectbottom);
  
  adjust=new JMenu("Adjust");
  operations.add(adjust);
  adjustr=new JMenuItem("Red");
  adjustr.addActionListener(this);
  adjust.add(adjustr);
  adjustg=new JMenuItem("Green");
  adjustg.addActionListener(this);
  adjust.add(adjustg);
  adjustb=new JMenuItem("Blue");
  adjustb.addActionListener(this);
  adjust.add(adjustb);
  adjustrg=new JMenuItem("RG");
  adjustrg.addActionListener(this);
  adjust.add(adjustrg);
  adjustrb=new JMenuItem("RB");
  adjustrb.addActionListener(this);
  adjust.add(adjustrb);
  adjustgb=new JMenuItem("GB");
  adjustgb.addActionListener(this);
  adjust.add(adjustgb);
  adjustrgb=new JMenuItem("RGB");
  adjustrgb.addActionListener(this);
  adjust.add(adjustrgb);
  
  pixelrotate=new JMenu("Pixel Rotate");
  operations.add(pixelrotate);
  pixelrotatel=new JMenuItem("Left");
  pixelrotatel.addActionListener(this);
  pixelrotate.add(pixelrotatel);
  pixelrotater=new JMenuItem("Right");
  pixelrotater.addActionListener(this);
  pixelrotate.add(pixelrotater);
  
  //intialize and add 1, 2, 3, 4, 5, 6, 7, 8 to the operations menu
  threads=new ButtonGroup();
  thread1=new JRadioButtonMenuItem("1");
  thread1.addActionListener(this);
  thread1.setSelected(true);
  threads.add(thread1);
  thread.add(thread1);
  thread2=new JRadioButtonMenuItem("2");
  thread2.addActionListener(this);
  threads.add(thread2);
  thread.add(thread2);
  thread3=new JRadioButtonMenuItem("3");
  thread3.addActionListener(this);
  threads.add(thread3);
  thread.add(thread3);
  thread4=new JRadioButtonMenuItem("4");
  thread4.addActionListener(this);
  threads.add(thread4);
  thread.add(thread4);
  thread5=new JRadioButtonMenuItem("5");
  thread5.addActionListener(this);
  threads.add(thread5);
  thread.add(thread5);
  thread6=new JRadioButtonMenuItem("6");
  thread6.addActionListener(this);
  threads.add(thread6);
  thread.add(thread6);
  thread7=new JRadioButtonMenuItem("7");
  thread7.addActionListener(this);
  threads.add(thread7);
  thread.add(thread7);
  thread8=new JRadioButtonMenuItem("8");
  thread8.addActionListener(this);
  threads.add(thread8);
  thread.add(thread8);
  
  //intialize the time elapsed label
  timeElapsed=new JLabel("Time Elapsed: 0 milliseconds");  
  
  //pack and set display visible
  add(menuBar,BorderLayout.NORTH);
  add(timeElapsed,BorderLayout.SOUTH);
  pack();
  setVisible(true);
  
  //initialize pic
  pic=null;
    }
    
    /*
     * ActionPerformed
     * handles all actions that occur in the GUI, while this method is being run, all buttons are deactivated
     * 
     * @param ActionEvent e: the event that caused this to be run
     */
    public void actionPerformed(ActionEvent e) {
     String filename="";
     
     int numThreads = 1;
     if (thread1.isSelected())
        numThreads = 1;
     else if (thread2.isSelected())
        numThreads = 2;
     else if (thread3.isSelected())
        numThreads = 3;
     else if (thread4.isSelected())
        numThreads = 4;
     else if (thread5.isSelected())
        numThreads = 5;
     else if (thread6.isSelected())
        numThreads = 6;
     else if (thread7.isSelected())
        numThreads = 7;
     else if (thread8.isSelected())
        numThreads = 8;
        
     System.out.println("Currently using " + numThreads + " threads.");
     
     //handles open being pressed
     if(e.getSource()==open) {
         try {
             fc.showOpenDialog(this);
             filename=fc.getSelectedFile().getPath();
             pic = new Picture(filename);
         }
         catch(ImageException ie) {
             pic=null; //display error if exception is caught
             JOptionPane.showMessageDialog(null,"An error has occured while opening the file you specified\nPlease verify the filename is correct and try again","Error",0);
         }
         catch(Exception E) { //handles the user closing or pressing the X on the JOptionPane
             pic=null;
         }
         if(pic!=null) { //if sucessful, update the title and pane
             setTitle("PhotoGUI -- "+filename);
             pane.getViewport().remove(image);
             image=pic.getImage();
             pane.getViewport().add(image);
             pack();
         }
     }
     
     //handles save being pressed
     if(e.getSource()==save) {
         try {
             fc.showSaveDialog(this);
             filename=fc.getSelectedFile().getPath();
             pic.save(filename);
         }
         catch(ImageException ie) {
             filename=""; //display error if exception is caught
             JOptionPane.showMessageDialog(null,"An error has occured while saving\nPlease verify the name is valid and try again","Error",0);
         }
         catch(Exception E) { //handles the user closing or pressing the X on the JOptionPane
             filename="";
         }
         if(filename!="") { //update title
             setTitle("PhotoGUI -- "+filename);
             pane.getViewport().remove(image);
             image=pic.getImage();
             pane.getViewport().add(image);
             pack();
         }
     }
     
     //start the timer     
     long start = System.currentTimeMillis();
     
     //handles mirrorh being pressed
     if(e.getSource()==mirrorh) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getHeight()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Mirror(pic, from, pic.getHeight() - 1, 0);
            else
                th[n] = new Mirror(pic, from, to, 0);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles mirrorv being pressed
     if(e.getSource()==mirrorv) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Mirror(pic, from, pic.getWidth() - 1, 1);
            else
                th[n] = new Mirror(pic, from, to, 1);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles reflecttop being pressed
     if(e.getSource()==reflecttop) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Reflect(pic, from, pic.getWidth() - 1, 0);
            else
                th[n] = new Reflect(pic, from, to, 0);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles reflectbottom being pressed
     if(e.getSource()==reflectbottom) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Reflect(pic, from, pic.getWidth() - 1, 1);
            else
                th[n] = new Reflect(pic, from, to, 1);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles reflectleft being pressed
     if(e.getSource()==reflectleft) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getHeight()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Reflect(pic, from, pic.getHeight() - 1, 2);
            else
                th[n] = new Reflect(pic, from, to, 2);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles reflectright being pressed
     if(e.getSource()==reflectright) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getHeight()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Reflect(pic, from, pic.getHeight() - 1, 3);
            else
                th[n] = new Reflect(pic, from, to, 3);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustr being pressed
     if(e.getSource()==adjustr) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, z, 0, 0);
            else
                th[n] = new Adjust(pic, from, to, z, 0, 0);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustg being pressed
     if(e.getSource()==adjustg) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, 0, z, 0);
            else
                th[n] = new Adjust(pic, from, to, 0, z, 0);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustb being pressed
     if(e.getSource()==adjustb) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, 0, 0, z);
            else
                th[n] = new Adjust(pic, from, to, 0, 0, z);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustrg being pressed
     if(e.getSource()==adjustrg) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, z, z, 0);
            else
                th[n] = new Adjust(pic, from, to, z, z, 0);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustrb being pressed
     if(e.getSource()==adjustrb) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, z, 0, z);
            else
                th[n] = new Adjust(pic, from, to, z, 0, z);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustgb being pressed
     if(e.getSource()==adjustgb) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, 0, z, z);
            else
                th[n] = new Adjust(pic, from, to, 0, z, z);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles adjustrgb being pressed
     if(e.getSource()==adjustrgb) {
         int z = promptForRGB();
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new Adjust(pic, from, pic.getWidth() - 1, z, z, z);
            else
                th[n] = new Adjust(pic, from, to, z, z, z);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles pixelrotatel being pressed
     if(e.getSource()==pixelrotatel) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new PixelRotate(pic, from, pic.getWidth() - 1, 0);
            else
                th[n] = new PixelRotate(pic, from, to, 0);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }
     
     //handles pixelrotater being pressed
     if(e.getSource()==pixelrotater) {
         Thread[] th = new Thread[numThreads];
         
         int diff = (int)Math.ceil(pic.getWidth()/numThreads);
         
         int from = 0;
         int to = diff;
         
         for (int n = 0; n < numThreads; n++)
         {
            if ((n + 1) == numThreads) // is this the last thread?
                th[n] = new PixelRotate(pic, from, pic.getWidth() - 1, 1);
            else
                th[n] = new PixelRotate(pic, from, to, 1);
            from = to + 1;
            to = to + diff;
         }
         for (int n = 0; n < numThreads; n++)
         {
            th[n].start();
         }
         for (int n = 0; n < numThreads; n++)
         {
             try {
                 th[n].join();
             }
             catch(Exception ex) { }
         }
     }     
     
     timeElapsed.setText("Time Elapsed: " + (System.currentTimeMillis() - start) + " milliseconds");
     
     repaint();
    }
    
    public int promptForRGB() {
        return Integer.parseInt(JOptionPane.showInputDialog(this, "Enter the amount you would like to adjust the RGB value.", ""));      
    }
    
    public static void main(String [] args) {
        PhotoGUI gui= new PhotoGUI();
    }
}
