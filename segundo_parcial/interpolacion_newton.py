print ("Diferencias Divididas (Newton)")
n = int(input("Ingrese el grado del polinomio a evaluar: "))+1
matrix = [0.0] * n
for i in range(n):
    matrix[i] = [0.0] * n

vector = [0.0] * n

print("***VALORES DE X, Y***")
for i in range(n):
    x = input("Ingrese el valor de x: ")
    y = input("Ingrese el valor de f("+x+"): ")
    vector[i]=float(x)
    matrix[i][0]=float(y)
print("**************")

print (vector)
print (matrix)

point_offset = float(input("Ingrese el punto a evaluar: "))


for i in range(1,n):
    for j in range(i,n):
        print ("i=",i,"    j=",j)
        print ("(",matrix[j][i-1],"-",matrix[j-1][i-1],")/(",vector[j],"-",vector[j-i],")")
        matrix[j][i] = ( (matrix[j][i-1]-matrix[j-1][i-1]) / (vector[j]-vector[j-i]))
        print ("matrix[",j,"][",i,"] = ",(matrix[j][i-1]-matrix[j-1][i-1])/(vector[j]-vector[j-i]))

for i in range(n):
    print (matrix[i])
aprx = 0
mul = 1.0
for i in range(n):
    print ("matrix[",i,"][",i,"]","=",matrix[i][i])
    mul = matrix[i][i];
    for j in range(1,i+1):
        mul = mul * (point_offset - vector[j-1])
    aprx = aprx + mul
    
print ("El valor aproximado de f(",point_offset,") es: ", aprx)