import requests
from bs4 import BeautifulSoup as BS4

url = "https://www.geeksforgeeks.org/cpp-stl-cheat-sheet/"

response = requests.get(url)

soup = BS4(response.text,'lxml')

article = soup.find('article')

print(article.text)