

import requests

#  Do 5 requests
#  Use the polynomial x^2 - 2  in all the requests, except as noted
# use 1e-10 for the tolerance
# Test the response for error indications and act accordingly

# a =1 and  b = 2
# the response should be the square root of 2
fr = {
    'a': 1,
    'b': 2,
    'poly': [-2, 0, 1],
    'tolerance': 1e-10
}
poly = None
response = requests.get("http://localhost:5000/bisection", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)

# a = 2 and b = 1
# The response should be an error message
fr = {
    'a': 2,
    'b': 1,
    'poly': [-2, 0, 1],
    'tolerance': 1e-10
}
poly = None
response = requests.get("http://localhost:5000/bisection", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)


# a = -1  and b = -2
# The response should be the negative of the square root of 2
fr = {
    'a': -1,
    'b': -2,
    'poly': [-2, 0, 1],
    'tolerance': 1e-10
}
poly = None
response = requests.get("http://localhost:5000/bisection", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)


# a = -1 and b = -2
# Polynomial should just be 14, not a list
fr = {
    'a': 1,
    'b': 2,
    'poly': 14,
    'tolerance': 1e-10
}
poly = None
response = requests.get("http://localhost:5000//bisection", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)


# path should be '/bisectio'  (note the misspelling!)
fr = {
    'a': 1,
    'b': 2,
    'poly': [-2, 0, 1],
    'tolerance': 1e-10
}
poly = None
response = requests.get("http://localhost:5000//bisectio", json=fr)
if response.status_code == requests.codes.ok:
    poly = response.json()
    print(poly)
else:
    print("error in response")
    print(response.text)
