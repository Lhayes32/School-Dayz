# -*- coding: utf-8 -*-
"""
Created on Wed Jul 11 20:50:02 2018

@author: Leonard Hayes
"""

import random 

a1 = []

for x in range (100):
 a1.append((random.randint(0, 1000)))

for i in range (1, len(a1)):
  j = i
  while j > 0 and a1[j - 1] > a1[j]:
    b = a1[j]
    a1[j] = a1[j - 1]
    a1[j - 1] = b
    j = j - 1
    

print(a1)