import numpy as np

A = np.matrix([[2, 3, 0],[1, -4, 2], [8, -2, 5]])
b = np.matrix([[8],[-10]])

if np.linalg.det(A) == 0:
    x = None
    print("No se puede resolver")
else:
    x = (A**-1)*b

print(x)

