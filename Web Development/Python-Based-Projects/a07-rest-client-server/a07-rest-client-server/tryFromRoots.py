

import requests
import random

# the result from this request should be [24, -50, 35, -10, 1]
fr = {
    'roots': [1, 2, 3, 4]
}
poly = None
response = requests.get("http://localhost:5000/from_roots", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)

# # if you have evaluate working, the following will output 4 0's
for r in fr['roots']:
    ev = {
        'x': r,
        'poly': poly,
     }
    response = requests.get("http://localhost:5000/evaluate", json=ev)
    if response.status_code == requests.codes.ok:
         print(response.json())
    else:
         print("error in response")
         print(response.text)


# the following request will get an error response
fr = {
    'roots': 5
}
poly = None
response = requests.get("http://localhost:5000/from_roots", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)


# the following request will get an error response
fr = {
    'root':  [1, 2, 3, 4]
}
poly = None
response = requests.get("http://localhost:5000/from_roots", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)


# the following request will get an error response
fr = {
    'roots':  [1, 2, 3, 'four']
}
poly = None
response = requests.get("http://localhost:5000/from_roots", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)


