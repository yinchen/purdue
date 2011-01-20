import javax.swing.*;
import java.awt.*;
import javax.swing.border.LineBorder;

public class IconPanel extends JPanel{
  
  
  public IconPanel(){
   setSize(500,500); 
   setBorder(new LineBorder(Color.BLACK));
   setBackground(Color.WHITE);
   
  }
  
  public void setColor(int color){
    switch(color){
      case 0: setBackground(Color.WHITE); break;
      case 1: setBackground(Color.BLUE); break;
      case 2: setBackground(Color.RED); break;
    }
  }
  
  public static boolean placeChipAt(int[][] array,int num,int player){
    if((num < 0) || (num > 6))
      return false;
    
    for(int i = 7;i>=0;i--){
      if(array[i][num]==0){
        array[i][num]=player;
        return true;
      }
      if(i==0)
        return false;
    }
  
    return false;
    
  }
  
  
   public static boolean checkWin(int[][] array,int player){
    
    //check horizontally
    for(int i = 1;i<8;i++)
      for(int j = 0;j<7;j++){
      if(array[i][j]==player && array[i-1][j]==player)
        try{
        if(array[i+1][j]==player && array[i+2][j]==player)
          return true;
      }catch(Exception e){}
    }
    
    //check vertically
    for(int i = 0;i<8;i++)
      for(int j = 1;j<7;j++){
      if(array[i][j]==player && array[i][j-1]==player)
        try{
        if(array[i][j+1]==player && array[i][j+2]==player)
          return true;
      }catch(Exception e){}
    }
    
    //check diagnol to upper right
    for(int i = 5;i<8;i++)
      for(int j = 0;j<4;j++){
      if(array[i][j]==player && array[i-1][j+1]==player)
        try{
        if(array[i-2][j+2]==player && array[i-3][j+3]==player)
          return true;
      }catch(Exception e){}
    }
    
    
    
    //check diagnol to the right
    for(int i = 7;i>=4;i--)
      for(int j = 6;j>=3;j--){
      if(array[i][j]==player && array[i-1][j-1]==player)
        try{
        if(array[i-2][j-2]==player && array[i-3][j-3]==player)
          return true;
      }catch(Exception e){}
    }
    
    
    return false;
  }
  
  
  
  
  
}