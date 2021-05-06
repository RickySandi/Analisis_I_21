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
double F(double x){
    
    //3*x^3-2*x-5->funci�n tomado como referencia
    //3*pow(x,3)-2*x-5;
    return exp(-x) - log(x);
}
double biseccion(double a,double b,int MAXIT,double TOL,double EX){
    double cont=0.0;
    string esp = "    ";
    double m, mx= 1000.0;
    double fm;
    while(cont<MAXIT){
    	 //&& mx>EX
        mx = m;
    
        m= a - F(a)*(a-b)/(F(a)-F(b));  
        
        mx = abs(m-mx)/m * 100;
        
        fm=F(m);
        
        // impresion linea de resultados 
        cout<<"i"<<"   "<<"xa"<<"        "<<"xb"<<"        "<<"m"<<"        "<<"f(xa)"<<"        "<<"f(xb)"<<"        "<<"f(m)"<<"        "<<"error"<<endl;
        cout << cont << esp << a << esp << b << esp << m << esp << F(a) << esp << F(b) << esp << fm << esp << mx << endl;
        cout<<endl;
        
        if(abs(b-a)<TOL)
          return m;
        if(abs(fm)<EX)
          return m;
        if(F(a)*fm<0)
            b=m;
        if(fm*F(b)<0)
            a=m;
        cont=cont+1;
    }
    return m, cont, mx;
} 

int main (int argc, char *argv[]) {
    int xa, xb;
    float error, float_error;
    double m, res_error =0.0;
    int i;
    cout<<"Ingresa los valores iniciales"<<endl;
    cout<<"Xa: ";
    cin>>xa; 
    cout<<"Xb: ";
    cin>>xb; 

    cout<<"Ingresa el error %"<<endl;
    cin>>error;
    float_error = error / 1000.0;
    
    cout<<"float error"<<float_error<<endl;  

    m, i, res_error = biseccion(xa,xb,100,float_error,float_error);
    cout<<endl;

    cout<<"La reiz es (m) "<<m<<" en (i)"<<i<<" iteraciones con error "<<res_error<<"%"<<endl;
    return 0; 
}

