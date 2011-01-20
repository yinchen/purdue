package edu.purdue.shake;

import android.app.Activity;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

public class Shake extends Activity {
    /** Called when the activity is first created. */
	SensorManager sensorMgr;
	ShakeListener listener;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        listener = new ShakeListener((TextView) findViewById(R.id.text));
        findViewById(R.id.button).setOnClickListener(listener);
    }

	@Override
	protected void onResume() {
		super.onResume();
		sensorMgr = (SensorManager) getSystemService(SENSOR_SERVICE);
		       	boolean accelSupported = sensorMgr.registerListener(
		       			listener,
		       			sensorMgr.getDefaultSensor(SensorManager.SENSOR_ACCELEROMETER),
		                   		SensorManager.SENSOR_DELAY_GAME);

	}

	@Override
	protected void onPause() {
		super.onPause();
		sensorMgr.unregisterListener(listener);
	}
	
}