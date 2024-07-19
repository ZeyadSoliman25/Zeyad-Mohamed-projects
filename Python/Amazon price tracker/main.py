import lxml
import requests
from bs4 import BeautifulSoup


BROWSER_HEADERS = {
    "User-Agent":"",
    "Accept-Language":"en-US,en;q=0.9",
    "Accept":"",
    "Accept-Encoding":"gzip, deflate, br",
    "sec-fetch-site":"cross-site",
    "sec-fetch-mode":"navigate",
    "sec-fetch-user":"?1",
    "sec-fetch-dest":"document",
}
url = "https://www.amazon.com/dp/B075CYMYK6?ref_=nav_signin&returnFromLogin=1&th=1"
response = requests.get(headers=BROWSER_HEADERS,
                        url=url)
webpage = response.content
soup = BeautifulSoup(webpage, "lxml")

price = soup.find(class_="a-offscreen").get_text()
price_no_currency = float(price.split("$")[1])
print(price_no_currency)