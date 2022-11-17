import numpy as np
x = np.random.random(size = (3, 3))
print(x)
print("")

y = x * 10
print(y)
print("")

z = y.astype('int')

print(z)
print("")

w = z.reshape((9, 1))

print(w)
print("")

v = np.zeros((9, 2))
print(v)

p = np.concatenate((w, v), axis = 1)
print("")
print(p)
print("")