package edu.purdue.ball;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.Vibrator;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.Window;
import android.view.WindowManager;
import android.view.SurfaceHolder.Callback;

public class MainS extends Activity implements Callback  {
	Screen game;
	SurfaceView surface;
	SurfaceHolder holder;
	SensorManager sensorMgr;
	
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
        		 
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        
        setContentView(R.layout.game);
        
        surface = (SurfaceView) findViewById(R.id.surfaceview);
    	holder = surface.getHolder();
    	surface.getHolder().addCallback(this);
    	
		  
    	
    }

	@Override
	protected void onPause() {
		super.onPause();
		
		
		sensorMgr.unregisterListener(game);
		sensorMgr = null;
		holder=null;
		
		game.setVibrator(null);

	}

	@Override
	protected void onResume() {
		super.onResume();
		
    	game = new Screen(holder, this ); 

		sensorMgr = (SensorManager) getSystemService(SENSOR_SERVICE);
		boolean accelSupported = sensorMgr.registerListener(game, 
				sensorMgr.getSensorList(Sensor.TYPE_ACCELEROMETER).get(0), SensorManager.SENSOR_DELAY_GAME);
		
		Vibrator k = (Vibrator) getSystemService(Activity.VIBRATOR_SERVICE);  
		  
		game.setVibrator(k);
		  
		
	}
	
	

	@Override
	protected void onRestoreInstanceState(Bundle savedInstanceState) {
		super.onRestoreInstanceState(savedInstanceState);
		
	}

	@Override
	protected void onSaveInstanceState(Bundle outState) {
		// TODO Auto-generated method stub
		super.onSaveInstanceState(outState);
	}

	public void surfaceChanged(SurfaceHolder arg0, int arg1, int width, int height) {
		game.setSpace(width, height);
	}

	public void surfaceCreated(SurfaceHolder holder) {
		game.start();
	}

	public void surfaceDestroyed(SurfaceHolder holder) {
		// TODO Auto-generated method stub
		try{
			game.stopGame();
			game=null;
			}catch(Exception e){}
	}
}
