import com.ridgesoft.io.Display;
import com.ridgesoft.intellibrain.IntelliBrain;
import com.ridgesoft.robotics.Servo;
import com.ridgesoft.intellibrain.IntelliBrainDigitalIO;

public class MyBot 
{
 public static void main(String args[]) 
 {
   try {
   int[] command = {4,0,1,0,2, 0,3, 2,4,0,4,1,2,1,2,4,0,1,4, 2,3,2,3,-1};
   int[] sleep = {0,3000,4000,1500,650,2000,650,1800,2,1200,1,1500,800,900,100,4,1200,1200,3,500,500,1600,2500};
   String[] message = {"Hello World", "CS180", "Robot Lab 1", "Aditya Mathur", "Robots!!!"};

   Display display = IntelliBrain.getLcdDisplay();
   
   //set up servo's and sonar
   Servo leftServo = IntelliBrain.getServo(1);
   Servo rightServo = IntelliBrain.getServo(2);
   IntelliBrainDigitalIO sonar = IntelliBrain.getDigitalIO(3);
   sonar.enablePulseMeasurement(true);

   int i = 0;
   int line = 0;
   while (command[i] >= 0)
   {
     if (command[i] == 0)
     {
         leftServo.setPosition(100);
         rightServo.setPosition(0);
     }
     else if (command[i] == 1)
     {
         leftServo.setPosition(0);
         rightServo.setPosition(100);
     }
     else if (command[i] == 2)
     {
         leftServo.setPosition(100);
         rightServo.setPosition(100);
     }
     else if (command[i] == 3)
     {
         leftServo.setPosition(0);
         rightServo.setPosition(0);
     }
     else if (command[i] == 4)
     {
         display.print(line, message[sleep[i]]);
         if (line == 0)
           line = 1;
         else
           line = 0;
         leftServo.setPosition(50);
         rightServo.setPosition(50);
         Thread.sleep(1500);
     }

     Thread.sleep(sleep[i]);

     i++;
   }
   }
   catch (Throwable t)  
  {
   t.printStackTrace();
  }
 }
}
