import com.ridgesoft.io.Display;
import com.ridgesoft.intellibrain.IntelliBrain;
import com.ridgesoft.robotics.Servo;

public class MyBot 
{
    public static void main(String args[]) 
	{
        try 
		{
			//Change the display on the Robot
			Display display = IntelliBrain.getLcdDisplay();
			display.print(0, "CS180 Lab 5");
			display.print(1, "Version 1.0");
			Thread.sleep(800);

			//Intitilize the two servos
			Servo leftServo = IntelliBrain.getServo(1);
			Servo rightServo = IntelliBrain.getServo(2);

			//Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

			//Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

			//Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(1000);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(1000);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(1000);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(1000);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

            //Travel forward for 5000ms
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(800);

			//turn for 850ms
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(150);

			//turnoff the servos
			leftServo.off();
			rightServo.off();
			Thread.sleep(800);
		}	
		catch (Throwable t) 	
		{
			t.printStackTrace();
		}

    }
}
