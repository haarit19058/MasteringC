from selenium import webdriver
from bs4 import BeautifulSoup as BS4
import requests
import time
import pandas as pd

url="https://results.eci.gov.in/PcResultGenJune2024/partywiseresult-S05.htm"
response = requests.get(url)
soup = BS4(response.text,"lxml")
print(soup.find("strong").text)
table = soup.find('table', class_='table')
data = []
for row in table.find_all('tr'):
    # print(row)
    cols = row.find_all(['th', 'td'])
    cols = [col.text.strip() for col in cols]
    data.append(cols)

pdData=pd.DataFrame(data)
# print(pdData)