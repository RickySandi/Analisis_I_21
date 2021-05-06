import numpy as np
from scipy.linalg import solve

def GaussSeidel(A, B, x, n):
    L = np.tril(A)
    U = A-L
    for i in range(n):
        x = np.dot(np.linalg.inv(L), B - np.dot(U, x))
        print(x)
    return x

def main():
    A = eval(input('Enter the matrix A: '))
    #as np.array([[a11, a12, a13], [a21, a22, a23], [a31, a32, a33]])
    B = eval(input('Enter the matrix B: ')) # as [b1, b2, b3]
    x = eval(input('Enter the guess of x: ')) # as [x1, x2, x3]      [0, 0, 0]
    n = eval(input('Enter the number of iterations: ')) 
    x = GaussSeidel(A, B, x, n)
    print('Solution using the solve syntax: \n', solve(A, B)) 

    #LOS VALORES QUE SE MUESTRAN SON POSITIVOS

if __name__ == "__main__":
    main()