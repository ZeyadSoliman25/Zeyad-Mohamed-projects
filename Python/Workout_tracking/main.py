import requests
from datetime import datetime

NUTRINTIONIX_ENDPOINT = "https://trackapi.nutritionix.com/v2/natural/exercise"
SHEETY_ENDPOINT = ""

APP_ID = ""
APP_KEY = ""
exercise_text = input("What exercise did you do? ")


SHEETY_HEADER = {
    "Authorization": "",
}

NUTRINTIONIX_headers = {
    "x-app-id":APP_ID,
    "x-app-key":APP_KEY,
}

NUTRINTIONIX_parameters = {
    "query":exercise_text,
     "gender":"male",
     "weight_kg":88.5,
     "height_cm":175.64,
     "age":21,
}
exercise_data = requests.post(url=NUTRINTIONIX_ENDPOINT, headers=NUTRINTIONIX_headers, json=NUTRINTIONIX_parameters)
exercise_data.raise_for_status()
exercise_json = exercise_data.json()

exercise_name = exercise_json["exercises"][:]


for name in exercise_name:
    date_completed = datetime.now()
    date_completed_formatted = date_completed.strftime("%Y/%m/%d")
    time_formatted = date_completed.strftime("%H:%M:%S")


    SHEETY_PARAMETERS = {
        "workout":{
            "date":date_completed_formatted,
            "time":time_formatted,
            "exercise":name["name"],
            "duration":name["duration_min"],
            "calories":name["nf_calories"],
        }
    }

    updated_data = requests.post(url=SHEETY_ENDPOINT, headers=SHEETY_HEADER, json=SHEETY_PARAMETERS)



