from pprint import pprint
from flight_search import *
from flight_data import FlightData
from notification_manager import NotificationManager

SHEET_ENDPOINT = "Sheet Endpoint"
SHEET_HEADER = {
    "Auth key"
}

flight_manager = FlightSearch()

class DataManager:
    #This class is responsible for talking to the Google Sheet.
    def __init__(self):
        self.response = requests.get(url=SHEET_ENDPOINT, headers=SHEET_HEADER)
        self.response_json = self.response.json()
        self.updated_param = {
            "price": {}
        }
        self.flight_data = 0

    def show_data(self):
        pprint(self.response_json)

    def check_IATA_CODE(self):
        for iatacode in self.response_json["prices"]:
            if iatacode["iataCode"] == "":
                FLIGHT_SEARCH_PARAMETERS["term"] = iatacode["city"]
                iatacode["iataCode"] = flight_manager.get_iatacode()
            self.updated_param["price"] = iatacode
            self.update_data()
        print("Sheet is updated")

    def update_data(self):
        update_response = requests.put(url=SHEET_ENDPOINT+str(self.updated_param["price"]["id"]),
                                            headers=SHEET_HEADER,
                                            json=self.updated_param,
                                            )

        update_response.raise_for_status()

    def search_destination(self,fly_from, date_from, date_to):
        for destination in self.response_json["prices"]:
            self.flight_data = flight_manager.get_destination(fly_from=fly_from,
                                                              fly_to=destination["iataCode"],
                                                              date_from=date_from,
                                                              date_to=date_to,
                                                             )
            print(f"{destination['city']}: ${self.flight_data['data'][0]['price']}")
            if self.flight_data['data'][0]['price'] < destination['lowestPrice']:
                flight = FlightData(city_from=f"{self.flight_data['data'][0]['cityFrom']}-{self.flight_data['data'][0]['flyFrom']}",
                                    city_to=f"{self.flight_data['data'][0]['cityTo']}-{self.flight_data['data'][0]['flyTo']}",
                                    price=self.flight_data['data'][0]['price'],
                                    date_from=self.flight_data['data'][0]['route'][0]['local_departure'].split('T')[0],
                                    data_to=self.flight_data['data'][0]['route'][1]['local_departure'].split('T')[0],
                                    city_from_code=self.flight_data['data'][0]['flyFrom'],
                                    city_to_code=self.flight_data['data'][0]['flyTo']
                                    )
                message = (f"Low price alert! only ${flight.price} to fly from {flight.city_from}-{flight.city_from_code}"
                          f"to {flight.city_to}-{flight.city_to_code} from {flight.date_from} to {flight.date_to}")
                notification = NotificationManager(message)
                return notification