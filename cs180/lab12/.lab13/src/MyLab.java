import java.util.Vector;

import edu.purdue.cs180.Shutter;
import edu.purdue.cs180.Display;
import edu.purdue.cs180.Picture;

public class MyLab extends Thread 
{
  
  int num = 0;   // holds the value for adding a picture objet to the pics array
  Picture[] pics = new Picture[20]; //holds all pictures
  int length = 0;  //holds how many picture are in the pics array, used primarly 
                   //when there are less than 20 pictures in the pics array
  int showInt = 0; //holds the position in the array for which picture is shown in the left screen.
  
  int current = 0;
  
  public MyLab(){
    
    new Thread(){
      public void run(){
        while(true){
         //TODO: Implement Taking Picture
         pics[length] = waitForPicture();
         showPicture(pics[length]);
         
         setText("Picture " + length);
         popupToast("That is all");
         
         showInt = length;
         
         current = length;
         
         if (length == 19)
         {
           length = 0;
         }
         else
         {
           length++;
         }
        }
      }
    }.start();
    
    
    new Thread(){      
      public void run(){
        while(true){
          //TODO: Implement Button Action
          if (waitForButton()) // next
          {
            if (pics[showInt + 1] != null)
            {
              showInt++;
            }
            else
            {
              showInt = 0;
            }
            popupToast("Next");
            showPicture(pics[showInt]);
            setText("Picture " + showInt);              
          }
          else //previous
          {
            if (pics[showInt - 1] != null)
            {
              showInt--;              
            }
            else
            {
              showInt = length;
            }
            popupToast("Previous");
            showPicture(pics[showInt]);
            setText("Picture " + showInt);
          }
          
          current = showInt;
        }        
      }
      
    }.start();
    
  }
  
  public static void main(String[] args) 
  { 
    
    new MyLab();
    
  }
}
