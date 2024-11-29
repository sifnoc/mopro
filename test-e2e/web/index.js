const { execSync } = require('child_process');
const { Builder, By } = require('selenium-webdriver');
const chrome = require('selenium-webdriver/chrome');

(async function testStatusCheck() {    
    // Detect Chrome and ChromeDriver paths
    const chromeBin = process.env.CHROME_BIN || '/usr/bin/google-chrome-stable';
    const chromedriverBin = process.env.CHROMEDRIVER_BIN || '/usr/bin/chromedriver';

    // Log detected paths
    // TODO: remove after checking 
    console.log(`Using Chrome binary: ${chromeBin}`);
    console.log(`Using ChromeDriver binary: ${chromedriverBin}`);

    // Check versions of detected binaries
    const chromeVersion = execSync(`${chromeBin} --version`, { encoding: 'utf-8' });
    const chromedriverVersion = execSync(`${chromedriverBin} --version`, { encoding: 'utf-8' });
    console.log(`Chrome version: ${chromeVersion.trim()}`);
    console.log(`ChromeDriver version: ${chromedriverVersion.trim()}`);

    // Configure Selenium WebDriver to use the detected binaries
    const options = new chrome.Options();
    options.setChromeBinaryPath(chromeBin);
    options.addArguments('--headless');

    const service = new chrome.ServiceBuilder(chromedriverBin).build(); // Use the custom ChromeDriver binary
    const driver = await new Builder()
        .forBrowser('chrome')
        .setChromeOptions(options)
        .setChromeService(service)
        .build();

    try {
        // Load the test page with `serve` default port
        await driver.get('http://127.0.0.1:3000');

        // Wait for the test completion marker
        const statusDiv = await driver.findElement(By.id('test-status'));
        await driver.wait(async () => {
            const status = await statusDiv.getAttribute('data-status');
            return status === 'passed' || status === 'failed';
        }, 10000); // 10 seconds timeout

        // Check the final test status
        const finalStatus = await statusDiv.getAttribute('data-status');

        if (finalStatus === 'passed') {
            console.log("All tests passed!");
            process.exit(0);
        } else {
            console.log("Some test(s) failed");
            process.exit(1);
        }
    } catch (error) {
        console.error("Error during test:", error);
        process.exit(1);
    } finally {
        await driver.quit();
    }
})();
