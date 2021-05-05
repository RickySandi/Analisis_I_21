import pprint
import scipy
import scipy.linalg   # SciPy Linear Algebra Library

A = scipy.array([[2, -1, 0], [-1, 4, 3], [0, 3, 6]])
L = scipy.linalg.cholesky(A, lower=True)
U = scipy.linalg.cholesky(A, lower=False)

print ("A:")
pprint.pprint(A)

print ("L:")
pprint.pprint(L)

print ("U:")
pprint.pprint(U)