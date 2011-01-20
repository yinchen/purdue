package edu.purdue.cs180;

import android.app.Activity;
import android.hardware.Camera;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageView;


public class Main extends Activity {
  /** Called when the activity is first created. */
	
	Display d;
	
  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    
    requestWindowFeature(Window.FEATURE_NO_TITLE);
    getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,   
    		                              WindowManager.LayoutParams.FLAG_FULLSCREEN);  
    
    setContentView(R.layout.lab13);
    
    
    
  }
  

protected void onResume() {
	super.onResume();
	
    Camera c = Camera.open();
    new Shutter(this, c);
    
    new Display(this);
    new Preview(this,c);
    new StudentThread("MyLab").start();
}


  
}