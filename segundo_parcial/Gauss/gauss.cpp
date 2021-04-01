#include<iostream>
#include<cmath>

using namespace std;

int main() {
   int n, k; 
   float a[101][102], p, s, x[101];

   cout<<"Cuantas ecuaciones toene el sistema: ";
   cin>>n; 
   int i =1, j=1;

   do{
      
      do{
         cout<<"a["<<i<<"]["<<j<<"] = ";
         cin>>a[i][j];
         j++;
      }while(j <= n);
      i++;
      j = 1; //
   }while(i <= n);

   i =1;
   do{
      cout<<"b["<<i<<"] = ";
      cin>>a[i][n+1];
      i++;
   }while( i <= n);

   //Impresion de a[n][n]
   cout<<endl;

     i =1;
   do{
       j=1; 
      do{
         cout<<a[i][j]<<"\t";
         j++;
      }while(j <= n+1);
      cout<<endl;
      i++;
   }while(i <= n);

   cout<<endl; 

   //Generacon de u[][]

   i =1; 
   do{
      p = a[i][i]; 
      k= i;
      do{
         a[i][k] = a[i][k] * (1 / p);
         k++;
      }while(k <= n+1);
      j = i + 1; 
      do{
         p = a[j][i];
         k =1;
         do{
            a[j][k] = a[j][k] - p * a[i][k];
            k++;
         }while(k <= n+1);
         j++;
      }while( j<= n);
      i++;

   }while(i <= n-1); 

   //Impresion de u[n][n]

     i =1;
   do{
       j=1; 
      do{
         cout<<a[i][j]<<"  ";
         j++;
      }while(j <= n+1);
      cout<<endl;
      i++;
   }while(i <= n);

   cout<<endl; 

   //Calculo de soluciones 

   x[n] = a[n][n+1] / a[n][n];

   i = n-1; 
   do{
      s = 0;
      j= n; 
      do{
         s += a[i][j] * x[j];
         j--; 
      }while(j >= i+1);

      x[i] = a[i][n+1] - s;
      i--;
   }while( i >= 1);

   //Impresion de soluciones 

   cout<<endl;

   i = 1;
   do{
      cout<<"x["<<i<<"] = "<<x[i]<<endl;
      i ++;

   }while(i <= n); 



   

  
}