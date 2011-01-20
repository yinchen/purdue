package edu.purdue.ball;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import android.app.Activity;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.media.MediaPlayer;
import android.os.Vibrator;
import android.view.SurfaceHolder;

public class Screen extends Thread implements SensorEventListener{
	
	SurfaceHolder holder;
	Canvas c;
	boolean gamestate;
	long time;
	int height;
	int width;
	Vibrator vibrator;
    int count;
	boolean gameend;
	boolean win;
	BasePoint cursor;
	
	static Activity v;
	ArrayList points;
	  
	public Screen(SurfaceHolder h,Activity activity)  {
		holder = h;
		gamestate = true;
	    points = new ArrayList(); 
	    v = activity;
	     cursor = new BasePoint();

	    
	   points.add(0, new BasePoint()); 
	    points.add(1, new Bomb(((BasePoint) points.get(0))));
	    points.add(2, new Enemy());
	    points.add(3,new SoundBall());
	    
	    
	}
	
	public synchronized void draw(){
		
		c= holder.lockCanvas();
		if(c!=null)
			holder.unlockCanvasAndPost(paintCanvas(c));
	}
	
	public Canvas paintCanvas(Canvas b){
		
		Paint background = new Paint();
		background.setColor(Color.WHITE);
		b.drawRect(0, 0, b.getWidth(), b.getHeight(), background);
		
		
		for(int i = 0; i<points.size();i++){
			BasePoint temp = ((BasePoint) points.get(i));
	    	((BasePoint) points.get(i)).draw(b);
		}
		
		return b;
	}
	
	public void run(){
		
		long startime;
		while(gamestate){
			startime = android.os.SystemClock.elapsedRealtime();
			movement();
			checkPosition(((BasePoint) points.get(0)).getX(),((BasePoint) points.get(0)).getY(),cursor.getRadius());
			draw();
			long sleep = android.os.SystemClock.elapsedRealtime()-startime;
			 if(sleep<32)
			try {TimeUnit.MILLISECONDS.sleep(32-sleep);} catch (InterruptedException e) {e.printStackTrace();}
		}
		
	}

	public void checkPosition(int x, int y,int radius) {
		for(int i = 0; i<points.size();i++){
			BasePoint temp = ((BasePoint) points.get(i));
			if((temp.distance(x,y)<(temp.radius+radius)))
			temp.hit(this);
		}
	}

	
	public void movement() {
		cursor.move();
		
		for(int i = 0; i<points.size();i++){
			BasePoint temp = ((BasePoint) points.get(i));
				temp.move();
		}
	}
	
	public void setSpace(int width, int height){
		this.width=width;
		this.height=height;
				
		for(int i = 0; i<points.size();i++)
	    	((BasePoint) points.get(i)).setSpace(width,height);
	}
	
	public void stopGame(){
		gamestate=false;
		interrupt();
	}

	public void onAccuracyChanged(Sensor sensor, int accuracy) {
		
	}

	public void onSensorChanged(SensorEvent event) {
		if((event.sensor.getType()==Sensor.TYPE_ACCELEROMETER)&&((time<0)||(System.currentTimeMillis()-time)>20))
			((BasePoint) points.get(0)).move(-(int)event.values[0],(int) event.values[1]);

		
	}

	public void vibrate() {
		vibrator.vibrate(20l);

	}
	
	public void setVibrator(Vibrator v){
		vibrator =v;
	}

	public static void playSound(){
		try{ new SoundPlayer(v,5).play();}catch(Exception e){e.printStackTrace();}
		
	}
	
}
