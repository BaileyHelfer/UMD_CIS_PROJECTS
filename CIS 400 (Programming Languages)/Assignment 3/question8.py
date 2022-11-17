import tensorflow as tf

A1 = tf.random.uniform([9],dtype = tf.float32)
A2 = tf.random.uniform([9],dtype = tf.float32)
print(A1,"\n",A2,"\n")
B1 = tf.reshape(A1,(3,3))
B2 = tf.reshape(A1,(3,3))
print(B1,"\n",B2,"\n")
C1 = tf.matmul(B1,B2)
C2 = tf.transpose(C1)
print(C1,"\n",C2,"\n")
D1 = tf.cast(C1,dtype = tf.int32)
print(D1)