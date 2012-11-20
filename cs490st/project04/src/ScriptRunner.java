import java.io.*;
import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.ExpectedCondition;
import org.openqa.selenium.support.ui.Select;
import org.openqa.selenium.support.ui.WebDriverWait;

public class ScriptRunner
{
    public static void main(String[] args)
    {
        // initialize the webdriver
        WebDriver driver = new FirefoxDriver();
        
        // initialize the output
        StringBuilder sb = new StringBuilder();        
        
        // navigate to the application
        driver.get("http://localhost/schoolmate/index.php");
        
        // find the login fields
        WebElement username = driver.findElement(By.name("username"));
        WebElement password = driver.findElement(By.name("password"));
        
        // enter the login information
        username.sendKeys("admin");
        password.sendKeys("admin");
        
        // login to the application
        WebElement login = driver.findElement(By.xpath("//input[@value='Login']"));
        login.click();
        
        try
        {
        	// initialize the input file
        	FileInputStream fis = new FileInputStream("input1");
        	DataInputStream dis = new DataInputStream(fis);
        	BufferedReader br = new BufferedReader(new InputStreamReader(dis));
        
	        // iterate through each line in the file
	        String line;
	        while ((line = br.readLine()) != null)
	        {
	            // check if line starts with a '[', otherwise ignore it
	            if (line.startsWith("[") == true)
	            {
	                String original = line; // store a copy of this line
	                String[] expected = new String[8];
	                
                	line = line.trim().substring(1, line.length() - 2); // remove brackets
	                
	                try
	                {
	                	// find the add button, navigate to the add classes page
		                WebElement add = driver.findElement(By.xpath("//input[@value='Add']"));
		                add.click();                    
		                
		                // split the array values
		                String[] values = line.split(", ");
		                
		                // iterate through each value in the line
		                int i = 0;
		                for (String value : values)
		                {
		                    // remove quotes
		                	if (i == 7) value = value.trim().substring(1, value.length());
		                	else        value = value.trim().substring(1, value.length() - 1);
		                    expected[i] = value;
		                    
		                    // find the form fields and enter the values
		                    switch (i)
		                    {
		                        case 0:
		                            WebElement title = driver.findElement(By.name("title"));
		                            title.sendKeys(value);
		                            break;
		                        case 1:
		                            Select teacher = new Select(driver.findElement(By.name("teacher")));
		                            teacher.selectByVisibleText(value);
		                            break;
		                        case 2:
		                            Select semester = new Select(driver.findElement(By.name("semester")));
		                            semester.selectByVisibleText(value);
		                            break;
		                        case 3:
		                            WebElement sectionnum = driver.findElement(By.name("sectionnum"));
		                            sectionnum.sendKeys(value);
		                            break;
		                        case 4:
		                            WebElement roomnum = driver.findElement(By.name("roomnum"));
		                            roomnum.sendKeys(value);
		                            break;
		                        case 5:
		                            WebElement periodnum = driver.findElement(By.name("periodnum"));
		                            periodnum.sendKeys(value);
		                            break;
		                        case 6:
		                            Select substitute = new Select(driver.findElement(By.name("substitute")));
		                            substitute.selectByVisibleText(value);
		                            break;
		                        case 7:
		                            List<WebElement> group1 = driver.findElements(By.name("group1"));
		                            for (WebElement radio : group1)
		                                if (radio.getAttribute("value").equals(value))
		                                    radio.click();
		                            break;
		                        default: 
		                            break;
		                    }
		                    
		                    i++;
		                }
		                
		                // find the submit button and submit the form
		                WebElement submit = driver.findElement(By.xpath("//input[@value='Add Class']"));
		                submit.click();
		                
		                if (driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(2)")).getText().equals(expected[0]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(3)")).getText().equals(expected[1]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(4)")).getText().equals(expected[2]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(5)")).getText().equals(expected[3]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(6)")).getText().equals(expected[4]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(7)")).getText().equals(expected[5]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(8)")).getText().equals(expected[7]) &&
		                	driver.findElement(By.cssSelector("table.dynamiclist tr:last-child td:nth-child(9)")).getText().equals(expected[6]))
		                {
		                	sb.append("P " + original + "\n");
		                }
		                else
		                {
		                	sb.append("F " + original + " : Record was not created or values do not match.\n");
		                }
	                }
	                catch (Exception ex)
	                {
	                	if (ex.getMessage().startsWith("Modal dialog present") == true)
	                	{
	                		sb.append("F " + original + " : XSS injection succeeded\n");
	                	}
	                	else
	                	{
	                		sb.append("F " + original + " : " + ex.getMessage() + "\n");
	                	}
	                }
	            }
	            else
	            {
	                // append line to output
	                sb.append(line + "\n");
	            }
	        }
	        
	        // close the input file
            dis.close();
        }
        catch (IOException ex)
        {
            System.err.println("Error: " + ex.getMessage());
        }
        
        try
        {
        	// create the output file
        	File output = new File("output1");
        	if (output.exists() == true)
        	{
        		output.delete();
        		output.createNewFile();
        	}
        	
        	// initialize the output file
        	FileWriter fw = new FileWriter(output.getAbsolutePath());
        	BufferedWriter bw = new BufferedWriter(fw);
        	
        	// write the output to the file
        	bw.write(sb.toString());
        	bw.close();
        }
        catch (IOException ex)
        {
        	System.err.println("Error: " + ex.getMessage());
        }
        
        // close the webdriver
        driver.quit();
    }
}
