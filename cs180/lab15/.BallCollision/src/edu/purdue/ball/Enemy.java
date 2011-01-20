package edu.purdue.ball;

import android.app.Activity;
import android.graphics.Canvas;
import android.graphics.Color;
import android.os.Vibrator;

public class Enemy extends BasePoint {
	
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
	}

	public void move(){
		x+=x_vel;
		y+=y_vel;
		
		position();
	}
	
	public void draw(Canvas b){
		ball.setColor(color);
		super.draw(b);
	}
	
	public void setSpace(int width,int height){
		super.setSpace(width, height);
		x=(int)(Math.random()*width);
		y=(int)(Math.random()*height);
	}
	
	public void hit(Screen e){
		e.vibrate();
		super.hit(e);
	}

}
