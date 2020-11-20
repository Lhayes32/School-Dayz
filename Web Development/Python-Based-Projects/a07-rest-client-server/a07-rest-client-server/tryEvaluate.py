

import requests


# Send a request and test the response.  Print the result if the response was ok
#       Print the error, and indicate it is an error, if there is an error
# Evaluate polynomial x + 7 and x = 3.5
fr = {
    'x': 3.5,
    'poly': [7, 1]
}
poly = None
response = requests.get("http://localhost:5000/evaluate", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)
# Send a request and test the response.  Print the result if the response was ok
#       Print the error, and indicate it is an error, if there is an error
# Evaluate polynomial x + 7 and x = 3.5
# But, introduce an error: don't spell 'poly' correctly, use 'polyy' instead
fr = {
    'x': 3.5,
    'polyy': [7, 1]
}
poly = None
response = requests.get("http://localhost:5000/evaluate", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)

# Send a request and test the response.  Print the result if the response was ok
#       Print the error, and indicate it is an error, if there is an error
# The 'x' value should be 3.5, but the polynomial should just be 3 (not a list!)
fr = {
    'x': 3.5,
    'poly': 3
}
poly = None
response = requests.get("http://localhost:5000/evaluate", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)