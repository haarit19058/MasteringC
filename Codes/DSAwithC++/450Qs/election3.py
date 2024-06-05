from selenium import webdriver
from bs4 import BeautifulSoup as BS4
import requests
import time
import pandas as pd
from pymongo import MongoClient


def extract(url):
    response = requests.get(url)
    soup = BS4(response.text,"lxml")
    table = soup.find('table', class_='table')
    state = soup.find("strong").text
    data = []
    for row in table.find_all('tr'):
        # print(row)
        cols = row.find_all(['th', 'td'])
        cols = [col.text.strip() for col in cols]
        data.append(cols)

    pdData=pd.DataFrame(data)
    # print("**********************************************************************")
    # print(state)
    # print(pdData)
    # print("\n\n\n**********************************************************************\n\n\n")

    # with open("data.txt","a") as f:
    #     f.write(f"\n\n\n********************************{state}***********************************\n\n\n")
    #     f.write(pdData.to_string())
    #     f.write("\n\n\n**********************************************************************\n\n\n")
    return pdData


for i in range(30):
    if i < 10:
        num = "0"+str(i)
    else:
        num = str(i)
    try:
        url = f"https://results.eci.gov.in/PcResultGenJune2024/partywiseresult-S{num}.htm"
        data = extract(url)
        data.reset_index()
        # print(data.to_dict())
        client =  MongoClient("localhost",27017)
        db = client['local']
        collection = db['election2024']
        # data.reset_index(inplace=True)
        data_dict = data.to_dict()
        str_dict = {str(key):value for key,value in data_dict.items()}
        # Insert collection
        print(str_dict)
        collection.insert_one(str_dict)
    except Exception as e:
        print(e)



