# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 12:59:54 2020

@author: Lhnet
"""
import numpy as np #Math
import matplotlib as plt #Plotting
import pandas as pd #Manage Data Sets
import keras 
import tensorflow as tf
import keras.backend as bd
import seaborn as sns

# Part 1 - Data Preprocessing
df = pd.read_csv('Linear-Regression-Data.csv')
X = df.iloc[:, 0].values
y = df.iloc[:,1].values

# Splitting the dataset into the Training set and Test Set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)


# Part 2 - ANN

# Importing the Keras libraries and packages
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import RMSprop

# Initialising the ANN
model = Sequential()

# Adding the input layer and the first hidden layer
model.add(Dense(activation=tf.nn.relu, units=32, input_dim=1))

# Adding the second hidden layer
model.add(Dense(activation=tf.nn.relu, units=32))

# Adding the third hidden layer
model.add(Dense(activation=tf.nn.relu, units=32))

# Adding the output hidden layer
model.add(Dense(units=1))

# Compiling the ANN
model.compile(optimizer=RMSprop(learning_rate=0.0099), loss='mean_squared_error')

# Fitting the ANN to the training set
model.fit(X_train, y_train, epochs=500)

# Predicting the Test set results
y_pred = model.predict(X_test)

print(model.predict([200]))

sns.scatterplot(x='x', y='y', data=df)

