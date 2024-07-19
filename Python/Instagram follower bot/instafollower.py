from selenium import webdriver
from selenium.common import ElementClickInterceptedException
from selenium.webdriver.common.by import By
import time
from selenium.webdriver.common.keys import Keys


class InstaFollower:
    def __init__(self):
        chrome_options = webdriver.ChromeOptions()
        chrome_options.add_experimental_option("detach", True)

        self.driver = webdriver.Chrome(options=chrome_options)
        self.username = ""
        self.password = ""


    def login(self,username,password):
        self.driver.get(url="https://www.instagram.com/")
        time.sleep(3)
        self.username = self.driver.find_element(By.XPATH, value='//*[@id="loginForm"]/div/div[1]/div/label/input')
        self.username.send_keys(username)
        self.password = self.driver.find_element(By.XPATH, value='//*[@id="loginForm"]/div/div[2]/div/label/input')
        self.password.send_keys(password)
        login = self.driver.find_element(By.XPATH, value='//*[@id="loginForm"]/div/div[3]')
        login.click()


    def search_followers(self,account):
        self.driver.get(f"https://www.instagram.com/{account}/followers")

    def follow(self):
        follow_buttons = []
        for n in range(1,51):
            follow = self.driver.find_element(By.XPATH, value=f"/html/body/div[5]/div[1]/div/div[2]/div/div/div/div/div[2]/div/div/div[3]/div[1]/div/div[{n}]/div/div/div/div[3]/div/button/div/div")
            follow_buttons.append(follow)
            time.sleep(0.5)

        for follow_button in follow_buttons:
            try:
                follow_button.click()
                time.sleep(1)
            except ElementClickInterceptedException:
                cancel_button = self.driver.find_element(By.XPATH,'/html/body/div[5]/div/div/div/div[3]/button[2]')
                cancel_button.click()


