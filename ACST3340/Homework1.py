# -*- coding: utf-8 -*-
"""
Created on Sat Jul 14 19:23:58 2018

@author: Lhnet
"""
print('===========Part 1=============')
def pairs(x): return x[0]
def sorted_pairs(y):
    return sorted(y, key = pairs)
print('Sorted by First Number')
print(sorted_pairs([(2, 5), (1, 2), (4, 4), (3, 3), (5, 1)]))

def pairs2(x): return x[1]
def sorted_pairs2(y):
    return sorted(y, key = pairs2)
print('Sorted by Second Number')
print(sorted_pairs2([(2, 5), (1, 2), (4, 4), (3, 3), (5, 1)]))

print('============Part 2=============')

a1=dict()
for x in range(1,16):
    a1[x] = x**2
print(a1)

print('============Part 3=============')

a2 = [('h', 'i'), ('j', 'k'), ('l', 'm')]
print ('a2 is:', a2)
a2 = [(x[0], 'n') for x in a2]
print('a2 now:', a2)