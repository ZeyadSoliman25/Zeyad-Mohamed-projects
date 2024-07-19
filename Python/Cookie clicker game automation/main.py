from selenium import webdriver
from selenium.webdriver.common.by import By
import time

timeout = time.time() + 60*5

chrome_options = webdriver.ChromeOptions()
chrome_options.add_experimental_option("detach", True)

driver = webdriver.Chrome(options=chrome_options)
driver.get("https://orteil.dashnet.org/experiments/cookie/")

check_prices = 0
prices = [
    '//*[@id="buyCursor"]/b',
    '//*[@id="buyGrandma"]/b',
    '//*[@id="buyFactory"]/b',
    '//*[@id="buyMine"]/b',
    '//*[@id="buyShipment"]/b',
    '//*[@id="buyAlchemy lab"]/b',
    '//*[@id="buyPortal"]/b',
    '//*[@id="buyTime machine"]/b',
        ]

while True:
    time.sleep(0.05)
    if time.time() > timeout:
        break

    cookie_click = driver.find_element(By.CSS_SELECTOR, value="div #cookie")
    cookie_click.click()
    check_prices += 1
    now_prices = []
    if (check_prices % 100) == 0:
        cookies_now = int(driver.find_element(By.XPATH, value='//*[@id="money"]').text)
        available_prices = []
        for item in prices:
            now_price = driver.find_element(By.XPATH, value=f"{item}").text.split('-')[1].strip()
            if ',' in now_price:
                now_price_cleaned = int(now_price.replace(',',''))
            else:
                now_price_cleaned = int(now_price)

            if now_price_cleaned <= cookies_now:
                available_prices.append((item,now_price_cleaned))
        if not available_prices:
            pass
        else:
            buy_now_price = max(available_prices, key=lambda x:x[1])
            buy_now = driver.find_element(By.XPATH, value=f"{buy_now_price[0]}")
            buy_now.click()

print(driver.find_element(By.XPATH, value='//*[@id="money"]').text)
print(driver.find_element(By.XPATH, value='//*[@id="cps"]').text)
driver.quit()
