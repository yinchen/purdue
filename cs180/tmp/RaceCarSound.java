/*
 * Description:
 * A simple race car sound generator
 * 
 * Created by: Aditya Mathur
 * Date: September 27, 2010
 * 
 * */

import java.applet.*; // Used to create a sound clip
import java.net.URL; // Used for providing the location of a sound file.


public class RaceCarSound { // Declare class
    
    // Create a URL objects that points to sound files.
    URL raceCarURL = new URL("http://www.autospeak.com/grpsndc/cartcar.wav");
    URL startYourEngines=new URL("http://www.autospeak.com/grpsndc/gmenstar.wav");
    URL aroundTheCurve=new URL("http://www.autospeak.com/grpsndb/thecurve.wav");
    
    // Create audio clips. Note that while AudioClip might appear to be a class, it is not.
    // In fact it is an interface. We will discuss interfaces later in this course.
    
    AudioClip raceCarClip = Applet.newAudioClip(raceCarURL); // Create audio clip for engine starts
    AudioClip startEnginesClip = Applet.newAudioClip(startYourEngines); // Create audio clip for race car
    AudioClip aroundTheCurveClip = Applet.newAudioClip(aroundTheCurve); // Create audio clip for around the curve
    
    
    public RaceCarSound() throws Exception{ // Constuctor begins here. 
    }
    
    public void startEnginsSound(){
        startEnginesClip.loop();  
    }
    
    public void startRaceSound(){
        startEnginesClip.stop(); 
        raceCarClip.loop(); // generate race car noise 
        
    }
    
    public void aroundTheCurveSound () throws Exception{
        aroundTheCurveClip.loop(); // generate passing car sound
        Thread.sleep(2000);
        aroundTheCurveClip.stop();
        
    }
}
    
