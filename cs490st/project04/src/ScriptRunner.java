import java.io.*;
import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.ExpectedCondition;
import org.openqa.selenium.support.ui.Select;
import org.openqa.selenium.support.ui.WebDriverWait;

public class ScriptRunner {
	public static void main(String[] args) {
		WebDriver driver = new FirefoxDriver();
		
		StringBuilder sb = new StringBuilder();
		
		try {
			driver.get("http://localhost/schoolmate/index.php");
			
			WebElement username = driver.findElement(By.name("username"));
			WebElement password = driver.findElement(By.name("password"));
			
			username.sendKeys("admin");
			password.sendKeys("admin");
			
			WebElement login = driver.findElement(By.xpath("//input[@value='Login']"));
			login.click();
			
			FileInputStream fis = new FileInputStream("input1");
			DataInputStream dis = new DataInputStream(fis);
			BufferedReader br = new BufferedReader(new InputStreamReader(dis));
			
			String line;
			while ((line = br.readLine()) != null) {
				if (line.startsWith("[") == true) {
					sb.append(line + "\n");
					
					line = line.trim().substring(1, line.length() - 2); // remove brackets
					
					WebElement add = driver.findElement(By.xpath("//input[@value='Add']"));
					add.click();
					
					WebElement title = driver.findElement(By.name("title"));
					Select teacher = new Select(driver.findElement(By.name("teacher")));
					Select semester = new Select(driver.findElement(By.name("semester")));
					WebElement sectionnum = driver.findElement(By.name("sectionnum"));
					WebElement roomnum = driver.findElement(By.name("roomnum"));
					WebElement periodnum = driver.findElement(By.name("periodnum"));
					Select substitute = new Select(driver.findElement(By.name("substitute")));
					List<WebElement> group1 = driver.findElements(By.name("group1"));
					
					String[] values = line.split(", "); // split the array values
					
					int i = 0;
					for (String value : values) {
						value = value.trim().substring(1, value.length() - 1); // remove quotes
						
						switch (i) {
							case 0:
								title.sendKeys(value);
								break;
							case 1:
								teacher.selectByVisibleText(value);
								break;
							case 2:
								semester.selectByVisibleText(value);
								break;
							case 3:
								sectionnum.sendKeys(value);
								break;
							case 4:
								roomnum.sendKeys(value);
								break;
							case 5:
								periodnum.sendKeys(value);
								break;
							case 6:
								substitute.selectByVisibleText(value);
								break;
							case 7:
								for (WebElement radio : group1)
									if (radio.getAttribute("value") == value)
										radio.click();
								break;
							default: 
								break;
						}
						
						i++;
					}
					
					WebElement submit = driver.findElement(By.xpath("//input[@value='Add Class']"));
					submit.click();
					
					// validate here
				}
				else {
					sb.append(line + "\n");
				}
			}
			
			dis.close();
		}
		catch (Exception ex) {
			System.err.println("Error: " + ex.getMessage());
		}
		
		System.out.println(sb.toString());
		
		// driver.quit();
	}
}
