from selenium import webdriver
from selenium.webdriver import ChromeOptions
from selenium.webdriver.common.by import By
import time


class TwitterBot :
    def __init__(self):
        self.chrome_options = ChromeOptions()
        self.chrome_options.add_experimental_option("detach", True)
        self.driver = webdriver.Chrome(options=self.chrome_options)
        self.down = 0
        self.up = 0

    def get_internet_speed(self):
        self.driver.get(url="https://fast.com/")
        time.sleep(30)
        self.down = self.driver.find_element(By.XPATH, value='//*[@id="speed-value"]').text
        show_more_info = self.driver.find_element(By.XPATH, value='//*[@id="show-more-details-link"]')
        show_more_info.click()
        time.sleep(20)
        self.up = self.driver.find_element(By.XPATH, value='//*[@id="upload-value"]').text
        print(f"Down: {self.down}")
        print(f"Up: {self.up}")


    def send_tweet(self):
        pass

