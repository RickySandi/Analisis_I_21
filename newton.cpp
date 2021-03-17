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

double funcion_f_prima(double x){

	return  1 - exp(-x); 

}
// void imprimir_valores(){

// }

void puntoFijo(double x0, float error){
     
    int i =0; 
   
    float x_ant = 0.0;
    float fx = funcion(x0);
    float f_prima = funcion_f_prima(x0);
    float error_calculado =100.0; 

    double x = x0;
 
        do{
            cout<<"i"<<"  "<<"x"<<"       "<<"fx"<<"       "<<"f'x"<<"       "<<"error"<<"       "<<endl;
            cout<<i<<"  "<<x<<"  "<<fx<<"  "<<f_prima<<"  "<<error_calculado<<"  "<<endl; 
            
           
            x_ant = x;
            x = x_ant - (funcion(x_ant) / funcion_f_prima(x_ant));
            
            fx =funcion(x);
            f_prima = funcion_f_prima(x);
       
            error_calculado = abs(((x-x_ant)/x))*100;
              
            i++;

       }while (error_calculado > error);
    //    cout<<"Error claculado"<<error_calculado<<endl;
       cout<<"La raiz es "<<x_ant<<" en "<<i-1<<" iteraciones"<<endl;

} 

int main (int argc, char *argv[]) {
    
    float error; 
    double x0;

    // cout<<"Ingresa xa: ";
    // cin>>xa;
    // cout<<"Ingresa xb: ";
    // cin>>xb;
    cout<<"Ingresa x0: ";
    cin>>x0;
    cout<<"Ingresa el error: ";
    cin>>error;
    cout<<"error"<<error<<endl;

    //error = error / 10;

    puntoFijo(x0, error);
    // intervalos (a,b, #interaciones, tol, error)
    // return 0; 
}

