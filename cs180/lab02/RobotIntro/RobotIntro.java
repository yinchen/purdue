public class RobotIntro {

	public static void main(String args[]) {
        try {
			Display display = IntelliBrain.getLcdDisplay();
			display.print(0, "Welcome CS180");
			display.print(1, "Program 101");
			Thread.sleep(1000);
			Servo leftServo = IntelliBrain.getServo(1);
			Servo rightServo = IntelliBrain.getServo(2);
			leftServo.setPosition(100);
			rightServo.setPosition(0);
			Thread.sleep(5000);
			leftServo.setPosition(0);
			rightServo.setPosition(100);
			Thread.sleep(5000);
			leftServo.setPosition(100);
			rightServo.setPosition(100);
			Thread.sleep(5000);
		}
		catch (Throwable t) {
			t.printStackTrace();
		}
	}
}