package edu.purdue.ball;

import android.app.Activity;
import android.graphics.Canvas;
import android.graphics.Color;
import android.os.Vibrator;

public class Enemy extends ActionPoint {
 
 Vibrator v;
 
 public Enemy(int x, int y){
  super(x,y);
  this.setColor(Color.RED);
  x_vel=4;
  x_vel=4;
  
 }
 
 public Enemy(){
  super();
  this.setColor(Color.RED);
  x_vel=4;
  y_vel=4;
  ball.setColor(color);

 }

 
 public void hit(Screen e){
  e.vibrate();
  super.hit(e);
 }
 

}
