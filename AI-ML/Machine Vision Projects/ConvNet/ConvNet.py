# Building Convolutional Neural Networks to Classify the Dog and Cat Images. This is a Binary Classification Model i.e. 0 or 1
# Used Dataset -- a Subset (10,000) Images ==> (8,000 for training_set: 4,000 Dogs and 4,000 Cats) and (2,000 for test_set: 1,000 Dogs and 1,000 Cats of Original Dataset (25,000 images) of Dogs vs. Cats | Kaggle
# Original Dataset link ==> https://www.kaggle.com/c/dogs-vs-cats/data
# You might use 25 or more epochs and 8000 Samples per epoch

# Installing Theano
# Installing Tensorflow
# Installing Keras

# Part 1 - Building the ConvNet

# Importing the Keras libraries and packages
from keras.models import Sequential
from keras.layers import Convolution2D
from keras.layers import MaxPooling2D
from keras.layers import Flatten
from keras.layers import Dense
from matplotlib import pyplot
import sys
import os


train_path = os.path.dirname(os.path.abspath(__file__)) +  '\\training_set/'
test_path = os.path.dirname(os.path.abspath(__file__))  + '\\test_set/'
# plotting curve
def plot_diagnostics(hist):
    # plot loss
    pyplot.subplot(211)
    pyplot.title('Loss')
    pyplot.plot(hist.history['loss'], color='blue', label='train')
    pyplot.plot(hist.history['val_loss'], color='orange', label='test')
    # plot accuracy
    pyplot.subplot(212)
    pyplot.title('Accuracy')
    pyplot.plot(hist.history['accuracy'], color='blue', label='train')
    pyplot.plot(hist.history['val_accuracy'], color='orange', label='test')
    # save plot to a file
    filename = sys.argv[0].split('/')[-1]
    pyplot.savefig(filename + '_plot.png')
    pyplot.close()


# Initializing the ConvNet
classifier = Sequential()

# Step 1 - Building the Convolution Layer
classifier.add(Convolution2D(32, 3, 3, input_shape = (64, 64, 3), activation = 'relu'))

# Step 2 - Building the Pooling Layer
classifier.add(MaxPooling2D(pool_size = (2, 2)))

# Adding The Second Convolutional Layer
classifier.add(Convolution2D(32, 3, 3, activation = 'relu'))
classifier.add(MaxPooling2D(pool_size = (2, 2)))

# Step 3 - Building the Flattening Layer
classifier.add(Flatten())

# Step 4 - Building the Fully Connected Layer
classifier.add(Dense(output_dim = 128, activation = 'relu'))
classifier.add(Dense(output_dim = 1, activation = 'sigmoid'))

# Compiling the ConvNet
classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])

# Part 2 - Fitting the ConvNet to the Images

from keras.preprocessing.image import ImageDataGenerator
# ..... Fill the Rest (a Few Lines of Code!)

# Create data generator
datagen = ImageDataGenerator(rescale=1.0/255.0)

# Prepare
train = datagen.flow_from_directory('ConvNet_dataset/training_set/', 
   class_mode='binary', batch_size=64, target_size=(64, 64))
test = datagen.flow_from_directory('ConvNet_dataset/test_set/',
    class_mode='binary', batch_size=64, target_size=(64,64))

# Fit model
hist = classifier.fit_generator(train, steps_per_epoch=len(train),
    validation_data=test, validation_steps=len(test), epochs=25, verbose=0)

# Evaluate model
_, acc = classifier.evaluate_generator(train, steps=len(test), verbose=0)
print('> %.3f' % (acc * 100.0))

plot_diagnostics(hist)


