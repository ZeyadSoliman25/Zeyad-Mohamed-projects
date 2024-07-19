import requests
import twilio.rest

STOCK_NAME = "TSLA"
COMPANY_NAME = "Tesla Inc"

STOCK_ENDPOINT = "https://www.alphavantage.co/query"
NEWS_ENDPOINT = "https://newsapi.org/v2/everything"
STOKE_API_KEY = "="
NEWS_API_KEY = ""
ACCOUNT_SID = ""
AUTH_TOKEN = ""

STOCK_PARAMS = {
    "function":"TIME_SERIES_DAILY",
    "symbol":STOCK_NAME,
    "apikey":STOKE_API_KEY,
}

NEWS_PARAMS = {
    "q":COMPANY_NAME,
    "apikey":NEWS_API_KEY,
    "from": "2023-09-19"
}

stock_data = requests.get(url=STOCK_ENDPOINT, params=STOCK_PARAMS)
stock_data.raise_for_status()
stock_data_json = stock_data.json()

news_data = requests.get(url=NEWS_ENDPOINT, params=NEWS_PARAMS)
news_data.raise_for_status()
news_data_json = news_data.json()
print(news_data_json)

client = twilio.rest.Client(ACCOUNT_SID,AUTH_TOKEN)

yesterday_closing_price = float(stock_data_json["Time Series (Daily)"]["2023-09-19"]['4. close'])
day_before_yesterday_closing_price = float(stock_data_json["Time Series (Daily)"]["2023-09-18"]['4. close'])
difference = round (abs(yesterday_closing_price - day_before_yesterday_closing_price),2)
symbol = "🔻"

if (yesterday_closing_price - day_before_yesterday_closing_price) > 0:
    symbol = "🔺"

difference_percentage = round((difference / day_before_yesterday_closing_price) * 100, 2)

if difference_percentage >= 5 :
    #print("Get news")
    articles = news_data_json["articles"][1:4]
    article_1 = articles[0]
    article_2 = articles[1]
    article_3 = articles[2]
    message_1 = client.messages.create(to='+201092816069', from_='+19376603337',
                                       body=f"TSLA:{symbol} {difference_percentage}%. \nheadline:{article_1['title']}\n"
                                            f"Brief:{article_1['description']} ")

    message_2 = client.messages.create(to='', from_='',
                                       body=f"TSLA:{symbol} {difference_percentage}%. \nheadline:{article_2['title']}\n"
                                            f"Brief:{article_2['description']} ")

    message_3 = client.messages.create(to='', from_='',
                                       body=f"TSLA:{symbol} {difference_percentage}%. \nheadline:{article_3['title']}\n"
                                            f"Brief:{article_3['description']} ")
