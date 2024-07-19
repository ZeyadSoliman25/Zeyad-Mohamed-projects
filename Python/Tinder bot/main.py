from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time


chrome_options = webdriver.ChromeOptions()
chrome_options.add_experimental_option("detach", True)

driver = webdriver.Chrome(options=chrome_options)
driver.get(url="https://tinder.com/")

login_button = driver.find_element(By.XPATH, value='//*[@id="s1477815459"]/div/div[1]/div/main/div[1]/div/div/div/div/header/div/div[2]/div[2]/a/div[2]/div[2]')
login_button.click()

time.sleep(1)

facebook_login = driver.find_element(By.XPATH, value='//*[@id="s-250565617"]/main/div/div/div[1]/div/div/div[2]/div[2]/span/div[2]/button/div[2]/div[2]/div/div')
facebook_login.click()

time.sleep(2)

email_ = driver.find_element(By.XPATH, value='//*[@id="email"]')
email_.send_keys("")

password = driver.find_element(By.XPATH, value='//*[@id="pass"]')
password.send_keys('')