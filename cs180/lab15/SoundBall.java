package edu.purdue.ball;

import android.graphics.Canvas;
import android.graphics.Color;

public class SoundBall extends ActionPoint {
 
 public SoundBall(int x, int y){
  super(x,y);
  this.setColor(Color.RED);
  x_vel=4;
  x_vel=4;
  ball.setColor(color);
 }
 
 public SoundBall(){
  super();
  this.setColor(Color.CYAN);
  x_vel=4;
  y_vel=4;
  ball.setColor(color);

 }

 public void hit(Screen e){

  Screen.playSound();
  super.hit(e);

 }
}



