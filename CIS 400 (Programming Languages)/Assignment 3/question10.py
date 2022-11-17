#importing numpy, pandas and matplotlib.pyplot libraries and others
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow import keras


class_names = ['top','trouser','pullover','dress','coat','snadal','sneaker','bag','ankle boot']
fashion_mnist = tf.keras.datasets.fashion_mnist

(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()
model = keras.models.Sequential()
model.add(keras.layers.Flatten(input_shape = [28,28]))
model.add(keras.layers.Dense(512,activation = "relu"))
model.add(keras.layers.Dense(256,activation = "relu"))

model.add(keras.layers.Dense(10,activation = "softmax"))
opt = keras.optimizers.Adam(learning_rate=0.01)

model.compile(loss="sparse_categorical_crossentropy",optimizer = opt,metrics = ["accuracy"])
model.summary() 
history = model.fit(x_train, y_train, epochs=10,validation_data=(x_test, y_test))
pred = model.predict(x_test)
for item in range(10):
    print(pred[item], "     ", print(class_names[np.argmax(pred[item])]))
    