package edu.purdue.ball;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.view.View;


public class BasePoint extends Point {

	protected int radius;
	protected int color;
	protected Paint ball;
	protected int width;
	protected int height;
	protected int x_vel;
	protected int y_vel;
		
	public BasePoint(){
		super(30, 30);
		radius=15;
		color= Color.BLUE;
		ball = new Paint();
		ball.setColor(color);
		ball.setAntiAlias(true);
		width=0;
		height=0;
		x_vel=0;
		y_vel=0;
	}
	

	public BasePoint(int x, int y){
		super(x,y);
		radius=17;
		color= Color.BLUE;
		ball = new Paint();
		ball.setColor(color);
		ball.setAntiAlias(true);
		width=0;
		height=0;
		x_vel=0;
		y_vel=0;
	}
	
	public void draw(Canvas c){
		c.drawCircle(getXF(), getYF(), getRadius(), ball);

	}
	
	public void setSpace(int width, int height){
		this.width=width;
		this.height=height;
		
		this.x=(int)(width/2);
		this.y=(int)(height/2);
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public float getXF(){
		return (float)x;
	}
	
	public float getYF(){
		return (float)y;
	}

	public int getRadius(){
		return radius;
	}
	
	public void setColor(int color){
		this.color=color;
		ball = new Paint(color);
	}
	
	public void move(){
		x+=x_vel;
		y+=y_vel;

		position();
		
		x_vel=0;
		y_vel=0;
	}
	
	public void position(){
		if(x>width)
		    x=0;
		else if(x<0)
			x=width;
		
		if(y>height)
			y=0;
		else if(y<0)
			y=height;
	}

	public void move(int dx,int dy){
		x_vel+=dx;
		y_vel+=dy;
	}
	
	public double distance(int x,int y){
		return Math.hypot(Math.abs((x-this.x)),Math.abs(y-this.y));
	}
	
	public void hit(Screen e) {
		

	}
	
	
}
