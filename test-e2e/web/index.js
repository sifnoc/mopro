const { execSync } = require('child_process');
const { Builder, By } = require('selenium-webdriver');
const chrome = require('selenium-webdriver/chrome');

(async function testStatusCheck() {
    // TODO: remove after checking 
    const chromeVersion = execSync('chrome --version', { encoding: 'utf-8' });
    const chromedriverVersion = execSync('chromedriver --version', { encoding: 'utf-8' });
    console.log(`Using ChromeDriver: ${chromeVersion.trim()}`);
    console.log(`Using ChromeDriver: ${chromedriverVersion.trim()}`);

    const options = new chrome.Options();
    options.addArguments('--headless');

    const driver = await new Builder().forBrowser('chrome').setChromeOptions(options).build();

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
