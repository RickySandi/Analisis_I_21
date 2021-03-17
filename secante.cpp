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
    double x,x0,x1,e,fx0,fx1,err;
    int iter = 0;
    cout.precision(4);
    cout<<"Ingresa los valores iniciales\n";
    cout<<"x0 = ";
    cin>>x;
    cout<<"x1 = ";
    cin>>x0;
    cout<<"Ingresa el error\n";
    cin>>e;
    cout <<"x{i}"<<"     "<<"x{i+1}"<<"     "<<"f(xi)"<<"     "<<"f(xi +1)"<<"     "<<"error"<<endl;

    do
    {
        x1 = x0;
        x0=x;
        fx0=f(x0);
        fx1 = f(x1);
        x = x1-((fx1*(x0-x1))/(fx0-fx1));
        err = fabs(x-x0);
        cout<<x0<<"        "<<x1<<"        "<<fx0<<"        "<<fx1<<"        "<<err<<endl;
        cout<<"Error Absoluto "<<err<<"\n"<<endl;
        iter++;
    }while (err>e);
    cout<<"La raiz de la encuacion es "<<x1<<endl;
    cout<<"Iteraciones: "<<iter -1<<endl;
    return 0;
}
