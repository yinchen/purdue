

/*
 * 
 * Description:
 * 
 * This class is used to generate vehicles. 
 * Vehicle position can be obtained by callking getX() and getY(), in that sequence.
 * Positions are generated randomly and have no relation to the speed of the vehicle.
 * Obviously, this class has a lot of scope for some real creativity!
 * 
 * Author: Aditya Mathur
 * Date: Monday September 27, 2010
 * 
 */

import java.util.*;
public class Vehicle{
    
    double x, y; // Current position of the vehicle.
    double min=5, max=10; // Minimum and maximum movement in x-direction  in 1 second.
    double maxYDisp=1.2; // Maximum movement in Y-direction with respect to movement in X direction
                         // + or 1 a random double in the range 0--1.
    Random gen=new Random();
    
    public Vehicle() throws Exception{
      
        
    }
    
    public double getX(){
        x=gen.nextDouble()*(max-min)+min; // Get new x-coordinate.
        return(x);
    }
    
    public double getY(){
        y=x*maxYDisp+gen.nextGaussian()-0.5;
        return(y);
    }  
}