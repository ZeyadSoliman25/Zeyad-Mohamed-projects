
class FlightData:
    #This class is responsible for structuring the flight data.
    def __init__(self,city_from, date_from, data_to, price, city_to, city_from_code, city_to_code):
        self.city_from = city_from
        self.city_to = city_to
        self.city_from_code = city_from_code
        self.city_to_code = city_to_code
        self.date_from = date_from
        self.date_to = data_to
        self.price = price
