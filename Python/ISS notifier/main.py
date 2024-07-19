import requests
from datetime import datetime as dt
import smtplib
import time

my_email = ""
password = ""
MY_LONG = 0
MY_LAT = 0
MY_POSITION = (MY_LONG, MY_LAT)


def check_position():
    response = requests.get(url="http://api.open-notify.org/iss-now.json")
    data = response.json()
    longitude = float(data["iss_position"]["longitude"])
    latitude = float(data["iss_position"]["latitude"])
    if MY_LONG-5 <= longitude <= MY_LONG+5 and MY_LAT-5 <= latitude <= MY_LAT+5:
        return True


def is_night():
    parameters = {
        "lat": MY_LAT,
        "lng": MY_LONG,
        "formatted": 0
    }
    response_2 = requests.get(url="https://api.sunrise-sunset.org/json", params=parameters)
    response_2.raise_for_status()
    data_2 = response_2.json()
    sunrise = int(data_2["results"]["sunrise"].split("T")[1].split(":")[0])
    sunset = int(data_2["results"]["sunset"].split("T")[1].split(":")[0])
    time_now = dt.now().hour
    if time_now <= sunrise or time_now >= sunset:
        return True


while True:
    time.sleep(60)
    if check_position() and is_night():
        with smtplib.SMTP("smtp-mail.outlook.com", port=587) as connection:
            connection.starttls()
            connection.login(user=my_email, password=password)
            connection.sendmail(from_addr=my_email,
                                to_addrs="",
                                msg="subject:surprise!\n\n look up!")
