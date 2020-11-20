# -*- coding: utf-8 -*-
"""
Created on Wed Jul 11 20:51:49 2018

@author: Lhnet
"""

import random 

a1 = []

for x in range (100):
 a1.append((random.randint(0, 1000)))
 
for i in range(0, len(a1) - 1): #Putting - 2 makes it so the last one isn't sorted
    j = i + 1
    tmp = a1[j]
    while j > 0 and tmp > a1[j - 1]:
        a1[j] = a1[j - 1]
        j = j - 1
       
    a1[j] = tmp

print(a1)
        