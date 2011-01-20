package edu.purdue.ball;

import android.graphics.Canvas;
import android.graphics.Color;

public class Bomb extends BasePoint {

	BasePoint cursor;
		
	public Bomb(BasePoint x){
		super();
		cursor=x;
		x_vel=2;
		y_vel=2;
		this.setColor(Color.BLACK);

	}

	public void move(){
		double tx = cursor.x-x;
		double ty = cursor.y-y;
		
		double length =Math.sqrt(tx*tx+ty*ty);
		
		tx/=length;
		ty/=length;
		
		x_vel=(int)(tx*3);
		y_vel=(int)(ty*3);
		
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
		y=height;
	}
	
	public void hit(Screen e){
		super.hit(e);
	}
}
