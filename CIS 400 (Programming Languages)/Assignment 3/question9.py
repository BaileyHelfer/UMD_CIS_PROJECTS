import tensorflow as tf

W = tf.random.uniform((784, 100), -1, 1)
x = tf.random.uniform((100, 784), 0, 1)
b = tf.zeros((100, 1))

matrixMatMul = tf.matmul(x, W)
addMatrix = tf.add(matrixMatMul, b)
h = tf.nn.relu(addMatrix)
print(h)