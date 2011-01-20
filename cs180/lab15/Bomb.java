/*
 * Matt McCormick
 * Hieu Tran
 * 
 * Lab 15 - 11/30/2010
 * 
*/


package edu.purdue.ball;

import android.graphics.Canvas;
import android.graphics.Color;

public class Bomb extends ActionPoint {

 BasePoint cursor;
  
 public Bomb(BasePoint x){
  super();
  cursor=x;
  x_vel=2;
  y_vel=2;
  this.setColor(Color.BLACK);

 }

 public void move(){
   
   if (x < cursor.x)
     x += x_vel;
   else
     x -= x_vel;
   
   if (y < cursor.y)
     y += y_vel;
   else
     y -= y_vel;
   
   position();
 }
 
}
