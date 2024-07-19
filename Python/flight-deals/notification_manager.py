from twilio.rest import Client

account_sid = ""
auth_token = ""
to_number = ""
from_number = ""
client = Client(account_sid, auth_token)


class NotificationManager:
    # This class is responsible for sending notifications with the deal flight details.
    def __init__(self, message):
        self.client = Client(account_sid, auth_token)
        self.message = self.client.messages.create(body=message, from_=from_number, to=to_number)
