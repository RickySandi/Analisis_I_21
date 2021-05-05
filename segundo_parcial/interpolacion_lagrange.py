# Declaracion de variables
x=[-3,5,7,8]
y=[9,2,-1,0]
f=6.1
resultado=[0,0,0,0] #un 0 por cada elemento de x o y 
tam = [0,1,2,3] # de 0 a grado - 1

#Bucle multiplicacion
for i in tam:
    multiplicacion = 1
    for j in tam:
        if(j!=i and x[j]!=0 and y[i]!=0):
            multiplicacion = (f-x[j])/(x[i]-x[j]) * multiplicacion
    resultado[i] = y[i]* multiplicacion

#Funcion Sumar Resultados
aux=0
for k in tam:
    aux = aux + resultado[k]
    
#Resultado
print("El resutado es: ",aux)