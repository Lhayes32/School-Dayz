# -*- coding: utf-8 -*-
"""
Created on Thu Jul 19 15:56:54 2018

@author: Lhnet
"""

import numpy as np
import matplotlib.pyplot as plt
x = np.arange(0, 5, .01)
y1 = x**2
y2 = x**3

fig, ax1 = plt.subplots()

ax2 = ax1.twinx()
ax1.plot(x, y1, 'b-',label = r'$area(m^2)$')
ax2.plot(x, y2, 'r-',label = r'$volume(m^3)$')

ax1.legend(loc=0)
ax2.legend(loc=0)

ax1.set_xlabel(' ')
ax1.set_ylabel(r'$area(m^2)$', fontsize = 18, color='b')
ax2.set_ylabel(r'$volume(m^3)$', fontsize = 18, color='r')
# Place a legend to the right of this smaller subplot.
plt.legend(bbox_to_anchor=(1.05, 1), loc=2, borderaxespad=0.)

plt.show()