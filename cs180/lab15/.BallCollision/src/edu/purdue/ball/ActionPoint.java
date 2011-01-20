package edu.purdue.ball;

import android.graphics.Canvas;
import android.graphics.Color;

public class ActionPoint extends BasePoint {
	
	public ActionPoint(){
		super();
	}
	
	public ActionPoint(int x, int y){
		super(x,y);
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

}
