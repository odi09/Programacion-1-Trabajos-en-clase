package com.accademy;

import java.util.concurrent.TimeUnit;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.SearchContext;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class GoogleSearchTest<WebDriver> {

	private ChromeDriver driver;
	private By drive;
	
	@Before
	
    public void setUp() {
		System.setProperty("webdriver.chrome.driver", "./src/test/resources/chromedriver/chromedriver.exe");
		driver = new ChromeDriver();
		driver.manage().window().maximize();
		driver.get("https://www.google.com/");
	}
	@SuppressWarnings("deprecation")
	@Test
	public void testGooglePage()
	{
		WebElement searchbox = drive.findElement((SearchContext) By.name("q"));
		
		searchbox.clear();
		searchbox.sendKeys("quality-stream Introduccion a la Automatizacion de Pruebas de Software");
		searchbox.submit();
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
		
		assertEquals("quality-stream Introduccion a la Automatizacion de Pruebas de Software - Google Search",driver.getTitle());
		
	}
	private void assertEquals(String string, String title) {
		// TODO Auto-generated method stub
		
	}
	@After
	public void tearDown() {
		driver.quit();
	}
}
