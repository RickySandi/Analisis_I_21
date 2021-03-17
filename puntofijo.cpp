#include<iostream>
#include<cmath>//biblioteca para poder utilizar la funcion pow() 
using namespace std; 
/*para encontrar una raiz de la ecuaci�n f(x)=0 analiticamente, proporcionar la funcion
F(X)
DATOS:
-->a Y b que forman un intervalo, en donde se halla una raiz
-->TOL criterio de convergencia//la tolerancia
-->EX criterio de exactitud
-->MAXIT n�mero maximo de iteraciones
RESULTADOS:
-->X la raiz aproximada o mensaje de falla
*/
double funcion(double x){

	return exp(-x) + x - 2;	
}

double funcion_g(double x){

	return 2 - (exp(-x)); 

}
double funcion_g_prima(double x){

	return exp(-x); 

}
// void imprimir_valores(){

// }

void puntoFijo(int a, int b, float x0, float error){
     
    if(funcion_g_prima(a) <=1 && funcion_g_prima(b) <=1 && funcion_g_prima(x0) <=1){
            int i =0; 
            float x =x0;
            float x_ant = 0.0;
            float gx = funcion_g(x0);
            float error_calculado =100.0;  
 
        do{
            cout<<"i"<<"  "<<"x"<<"       "<<"gx"<<"       "<<"error"<<"       "<<endl;
            cout<<i<<"  "<<x<<"  "<<gx<<"  "<<error_calculado<<"  "<<endl; 
            
            x_ant = x;
            x = gx;
            gx = funcion_g(x);
       
            error_calculado = abs(((x-x_ant)/x))*100;
              
            i++;

       }while (error_calculado > error);
       cout<<"La raiz es "<<x_ant<<" en "<<i-1<<" iteraciones"<<endl;

    }
    else{
        cout<<"No se puede calcular";
    }
} 

int main (int argc, char *argv[]) {
    int xa, xb, x0;
    float error; 

    cout<<"Ingresa xa: ";
    cin>>xa;
    cout<<"Ingresa xb: ";
    cin>>xb;
    cout<<"Ingresa x0: ";
    cin>>x0;
    cout<<"Ingresa el error: ";
    cin>>error;

    error = error / 10;

    puntoFijo(xa, xb, x0, error);
    // intervalos (a,b, #interaciones, tol, error)
    // return 0; 
}

