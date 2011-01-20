
/*
 * Description:
 * 
 * This program demonstrates how to use loops and if-else to solve
 * a real-time  car collision detection problem.
 * 
 * It uses a class named vehicle to create two cars and
 * obtain their posiions. The positions are generated randomly.
 * 
 * Race car sounds have been added just for fun and realism!
 * 
 * This program is for in-class demonstration during a CS 180 lecture.
 * 
 * Author: Aditya Mathur
 * Date: Monday September 27, 2010
 * 
 */

public class CollisionDetector{
    
    boolean moving=true;
    double posX1, posY1, posX2, posY2;
    double prevPosX1, prevPosY1, prevPosX2, prevPosY2;
    final double MIN_DISTANCE=2.0; // Minimum allowable distance;
    
    
    
    public CollisionDetector() throws Exception{
        
        // Create vehicles.
        Vehicle ferrari=new Vehicle(); 
        Vehicle porsche=new Vehicle(); 
        
        // Set initial status of the vehicles.
        
        boolean ferrariStopped=false;
        boolean porscheStopped=false;
        
        // Get initial  positions of both vehicles.
        
        posX1=ferrari.getX();
        posY1=ferrari.getY();
        posX2=porsche.getX();
        posY2=porsche.getY();
        
        // Generate race car sound generator and start engines sound!
        RaceCarSound raceCar= new RaceCarSound();
        raceCar.startEnginsSound();
        Thread.sleep(5000);
        raceCar.startRaceSound();
        
        // Enter loop to monitor vehicle positions 
        // until both stop.
        while(moving){
            
            // Display current positions.
            String format="%s %.2f %s  %.2f\n";
            System.out.format(format, "Ferrari at: x: ", posX1, " y: ",  posY1);
            System.out.format(format, "Porsche at: x: ", posX2, "  y:",  posY2);
            
            // Compute distance and isplay warning if needed.
            double xSquare=Math.pow((posX1-posX2), 2);
            double ySquare=Math.pow((posY1-posY2), 2);
            double distance=Math.sqrt(xSquare+ySquare);
            System.out.format("%s %.2f\n", "Distance: ", distance);
            if (distance<=MIN_DISTANCE){
                System.out.println( "           Warning: too close. ");
                raceCar.aroundTheCurveSound();
            }else{
                System.out.println( "           Safe distance. ");
            }
            
            // Save current positions.
            prevPosX1=posX1; prevPosY1=posY1;
            prevPosX2=posX2; prevPosY2=posY2;
            
            Thread.sleep(1000);  // Wait for 1 second.
            
            // Update vehicle positions.
            posX1=ferrari.getX();
            posY1=ferrari.getY();
            posX2=porsche.getX();
            posY2=porsche.getY();
            // Check if  vehicles have stopped.
            if((posX1==prevPosX1) && (posY1==prevPosY1)){
                ferrariStopped=true;
            }
            if((posX2==prevPosX2) && (posY2==prevPosY2)){
                porscheStopped=true;
            }
            
            // If both have stopped then update moving.
            if(ferrariStopped && porscheStopped){
                moving=false;
            }
            
        }
    }
    
    public static void main(String args[])throws Exception{
        new CollisionDetector();
        
    }
    
}



