import com.ridgesoft.io.Display;
import com.ridgesoft.intellibrain.IntelliBrain;
import com.ridgesoft.robotics.Servo;
import com.ridgesoft.intellibrain.IntelliBrainDigitalIO;

public class MyBot 
{
 public static void main(String args[]) 
 {
  try
  {
   //print on bot display
   //first line "My Bot"
   //second line "Collision Avoidance"
   Display display = IntelliBrain.getLcdDisplay();
   display.print(0, "My Bot");
   display.print(1, "Collision Avoidance");
    
   //set up servo's and sonar
   Servo leftServo = IntelliBrain.getServo(1);
   Servo rightServo = IntelliBrain.getServo(2);
   IntelliBrainDigitalIO sonar = IntelliBrain.getDigitalIO(3);
   sonar.enablePulseMeasurement(true);
   
   //set up variable's
   int distance = 1000;
   int counter = 1;
    
   //move robot forward
   
   do
   {
      sonar.pulse(2);
      Thread.sleep(50);
      distance = sonar.readPulseDuration();

      if (counter % 125 == 0)
      {
         if (counter % 2 == 0)
         {
            leftServo.setPosition(0);
            rightServo.setPosition(0);
            Thread.sleep(1000);
         }
         else
         {
            leftServo.setPosition(100);
            rightServo.setPosition(100);
            Thread.sleep(1000);
         }
      }
         leftServo.setPosition(100);
         rightServo.setPosition(0);

     display.print(0, "Distance from object");
     display.print(1, "" + distance);

     counter++;

   } while (distance > 500);

   for (int i = 0; i < 4; i++)
   { 
     if (i % 2 == 0)
     {
            leftServo.setPosition(0);
            rightServo.setPosition(0);
            Thread.sleep(1000);
     }
     else
     {
            leftServo.setPosition(100);
            rightServo.setPosition(100);
            Thread.sleep(1000);
     }
   }
  }
  catch (Throwable t)  
  {
   t.printStackTrace();
  }
 }
}

