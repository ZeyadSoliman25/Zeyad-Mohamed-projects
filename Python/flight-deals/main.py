#This file will need to use the DataManager,FlightSearch, FlightData, NotificationManager classes to achieve the program requirements.
from data_manager import DataManager
import datetime


data_manager = DataManager()
now_date = str((datetime.datetime.now()).strftime("%d/%m/%Y"))
search_date = str((datetime.datetime.now() + datetime.timedelta(days=6*30)).strftime("%d/%m/%Y"))


data_manager.check_IATA_CODE()
data_manager.search_destination(fly_from="CAI",
                                date_from=now_date,
                                date_to=search_date,
                                )

