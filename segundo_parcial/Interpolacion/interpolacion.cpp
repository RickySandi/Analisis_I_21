#include<iostream>
#include<cmath>

using namespace std;

int main() {

    int m, n, i, j;
    float a[101][101], x, sum, pro, pn;

    cout<<"Ingrese el numero de pares de datos: ";
    cin>>m;

    n= m - 1;

    cout<<"Ingrese los datos en pares"<<endl;
    i=1;
    do{
        cin>>a[i][1]>>a[i][2];
        i++;

    }while(i <= m);

    //Calculo de las diferencias divididas

    j = 3;
    do{
        i = 1;
        do{
            a[i][j] = (a[i+1][j-1] - a[i][j-1]) / (a[i+j-2][1] - a[i][1]);
            i++; 
        }while(i <= n-j+3);
        j++;
    }while(j <= n+2);

    //Impresion de [A]
    cout<<endl; 
    i =1; 
    do{
        j=1;
        do{
            cout<<a[i][j]<<"\t";
            j++;
        }while(j <= m+1);
        cout<<endl;
        i++;
    }while(i <= m);

    //Interpolacion 

    cout<<"Ingrese el valor que quiere interpolar: ";
    cin>>x;

    sum =0;
    i =1;
    do{
        pro =1;
        j=0;
        do{
            pro *= (x-a[j+1][1]);
            j++;
        }while(j <= i-1);
        sum += a[1][i+2] * pro;
        i++;
    }while(i <= n);

    pn = a[1][2] + sum; 

    cout<<"El valor es: "<<pn<<endl; 
}