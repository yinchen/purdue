package edu.purdue.shake;

import java.util.ArrayList;
import java.util.Arrays;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class ShakeListener implements SensorEventListener, OnClickListener {
 
 TextView view;
 
 int[] list = new int[10];
 int counter=0;
 
 float last_x=0;
 float last_y=0;
 float last_z=0;
 long lastUpdate = -1;
 
 boolean run;
 
 static final int SHAKE_THRESHOLD = 800;
 
 public ShakeListener(TextView text){
  view=text;
 }

 public void onAccuracyChanged(Sensor arg0, int arg1) {

 }

 public void onSensorChanged(SensorEvent event) {
   if(event.sensor.getType()==SensorManager.SENSOR_ACCELEROMETER && run){
    long curTime = System.currentTimeMillis();

    if ((curTime - lastUpdate) > 100) {
     long diff = (curTime - lastUpdate);
          lastUpdate = curTime;

    
    float x = event.values[SensorManager.DATA_X];
    float y = event.values[SensorManager.DATA_Y];
    float z = event.values[SensorManager.DATA_Z];
   
    float speed = Math.abs(x+y+z - last_x - last_y - last_z)/ diff * 10000;
    
    if(speed>600){
     view.setText(""+(int)speed);
      final float k = speed;
      new Thread(new Runnable(){
 public void run(){
       add(list,(int)k);
 }
 }).start();
 
    }
    
    last_x=x;
    last_y=y;
    last_z=z;
    
   }
    
 }

}
 
 
 //TODO PART 2
 public void add(int[] array, int num){
   array = sort(array);
   array[array.length - 1] = num;
 }

 public void onClick(View v) {
  if(run){ 
   run=false;
   ((Button)v).setText("Resume");
   sort(list);
   view.setText(printArray(list));
  }
  else{ 
   run=true;
   ((Button)v).setText("Stop");
  }
  
 }

 //TODO PART 3
 public int[] sort(int[] array){
  boolean swapped = true;
  int j = 0;
  int tmp;
  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < array.length - j; i++) {
       if (array[i] < array[i + 1]) {
         tmp = array[i];
         array[i] = array[i + 1];
         array[i + 1] = tmp;
         swapped = true;
        }
      }
    } 
  
  return array;
 }
 
 //TODO PART 1 
 public String printArray(int[] array){
  String val = "";
   for (int i = 0; i < 10; i++)
  {
     if (i < array.length)
       val = val + array[i] + "\n";
  }
  return val;
 }
 

}
