#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

double f(double x){
    double ans = exp(-x)+x-2;
    return ans;
}

int main()
{
    double x,xi,xi_1,xi_2,e,fxi,fxi_1,err,x2_ant;
    int iter2=0; 
    cout.precision(4);
    cout<<"Ingresa los valores iniciales\n";
    cout<<"xi = ";
    cin>>xi;
    cout<<"xi + 1 = ";
    cin>>xi_1;
    cout<<"Ingresa el error\n";
    cin>>e;
    cout <<"x{i}"<<"     "<<"x{i+1}"<<"     "<<"x(i+2)"<<"     "<<"f(xi)"<<"     "<<"f(xi +1)"<<"     "<<"error"<<endl;

    do
    { 
       fxi = f(xi); 
       fxi_1 = f(xi_1); 

        xi_2 = xi_1 - (((fxi_1)*(xi - xi_1)) /(fxi - fxi_1));
        //x2_ant = xi_2;
        err = abs((xi_2-xi) /xi_2) * 100; 

        if(err > e && iter2 >=1 ){
            xi = xi_1;
            xi_1 = xi_2; 

            fxi = fxi_1;
            //fxi_1 = fxi_2;

            // iter ++; 
        }

       
    
        cout<<xi<<"        "<<xi_1<<"        "<<xi_2<<"        "<<fxi<<"        "<<fxi_1<<"        "<<err<<endl;
        cout<<"Error Absoluto "<<err<<"\n"<<endl;
        iter2 ++;
        
    }while (err>e);
    cout<<"La raiz de la encuacion es "<<xi_2<<endl;
    cout<<"Iteraciones: "<<iter2 -1<<endl;
    return 0;
}
