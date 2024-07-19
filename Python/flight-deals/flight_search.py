import requests

FLIGHT_SEARCH_ENDPOINT = "https://tequila-api.kiwi.com"
FLIGHT_SEARCH_HEADER = {
    "apikey": "Key",
}
FLIGHT_SEARCH_PARAMETERS = {
    "term":"",
    "location_types":"city"
}


class FlightSearch:
    #This class is responsible for talking to the Flight Search API.
    def __init__(self):
        self.response = 0
        self.response_json = 0
        self.city_code = ""
        self.flight = 0
        self.flight_json= 0


    def get_iatacode(self):
        self.response = requests.get(url=f"{FLIGHT_SEARCH_ENDPOINT}/locations/query",
                                     params=FLIGHT_SEARCH_PARAMETERS,
                                     headers=FLIGHT_SEARCH_HEADER)
        self.response.raise_for_status()
        self.response_json = self.response.json()
        self.city_code = self.response_json["locations"][0]["code"]
        return self.city_code

    def get_destination(self,fly_from, date_from, date_to, **kwargs):
        flight_params = {
            "fly_from":fly_from,
            "date_from":date_from,
            "date_to":date_to,
            "fly_to":kwargs["fly_to"],
            "curr":"USD",
            "nights_in_dst_from":7,
            "nights_in_dst_to":28,
            "one_for_city":1,
            "flight_type": "round"
        }
        self.flight = requests.get(url=f"{FLIGHT_SEARCH_ENDPOINT}/v2/search",
                                   headers=FLIGHT_SEARCH_HEADER,
                                   params=flight_params,
                                   )
        self.flight.raise_for_status()
        return self.flight.json()

