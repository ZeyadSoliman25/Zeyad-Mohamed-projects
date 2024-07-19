from instafollower import InstaFollower
import time

SIMILAR_ACCOUNT = ""
USERNAME = ""
PASSWORD = ""

bot = InstaFollower()
bot.login(USERNAME, PASSWORD)
time.sleep(5)
bot.search_followers(SIMILAR_ACCOUNT)
time.sleep(5)
bot.follow()