from selenium import webdriver
from selenium.webdriver import ChromeOptions
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time


chrome_options = ChromeOptions()
chrome_options.add_experimental_option("detach", True)

driver = webdriver.Chrome(options=chrome_options)
driver.get("https://www.linkedin.com/jobs/search/?currentJobId=3656983339&f_LF=f_AL&geoId=102257491&keywords=python%20developer&location=London%2C%20England%2C%20United%20Kingdom")
time.sleep(1)
sign_in = driver.find_element(By.LINK_TEXT, value="Sign in")
sign_in.click()
time.sleep(1)
user_name = driver.find_element(By.XPATH, value='//*[@id="username"]')
user_name.send_keys("YOUR EMAIL")
password = driver.find_element(By.XPATH, value='//*[@id="password"]')
password.send_keys("YOUR PASSWORD")
sign_in_after_credentials = driver.find_element(By.XPATH, value='//*[@id="organic-div"]/form/div[3]/button')
sign_in_after_credentials.click()

