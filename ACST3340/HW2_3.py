# -*- coding: utf-8 -*-
"""
Created on Thu Jul 19 16:58:52 2018

@author: Lhnet
"""

import numpy as np
import pylab as plt

x = np.random.random(50)
y = np.random.random(50)
c = np.random.random(50) 
s = 500 * np.random.random(50) 
fig, ax = plt.subplots()
im = ax.scatter(x, y, c=c, s=s, cmap=plt.cm.jet)
fig.colorbar(im, ax=ax)
im.set_clim(0.0, 1.0)