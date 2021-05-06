#include <iostream>
#include <math.h> 
#include <cmath>
#include <vector>
#include <stdio.h> 

using namespace std;


// An example function whose solution is determined using 
// Bisection Method. The function is x^3 - x^2 + 2 
float func(float x) 
{ 
	return exp(-x) - log(x) * 1.000; 
    //return (x+2) * (x-3);
}

bool errorEsMayor(float error_calculado, float porcentaje_error){
    return (error_calculado >= porcentaje_error);
}

void imprimirValores(int i, float a, float b, float c, float fa, float fb, float fc, float error=0.000){

    cout<<"i: "<<i<<" - a: "<<a<<" - b: "<<b<<" - c: "<<c<<" - fa: "<<fa<<" - fb: "<<fb<<" - fc: "<<fc<<" - error: "<<error*100<<"%"<<endl;
    //redondear aqui

}

float error(vector <float> vec_c, int i){
     float max_limit = 101.000;

    if(i >= 1 && vec_c.size() >= 2){
        //cout<<"i-1: "<<vec_c[i-1]<<"- i: "<<vec_c[i]<<endl;
        return round((abs((vec_c[i] - vec_c[i-1]) / vec_c[i])) *1000) /1000; 
        
    }
    else{
        return max_limit; 
    } 
}

// Prints root of func(x) with error of EPSILON 
void bisection(float a, float b) 
{ 
	if (func(a) * func(b) >= 0.000) 
	{ 
		cout << "You have not assumed right a and b\n"; 
		return; 
	} 

	float c = (a / 1.000) * 1.000; 
    int i = 0.000;
    vector <float> vec_c; 
    float error_calculado = 101.000;
    float porcentaje_error = 0.005; 

	while (errorEsMayor(error_calculado, porcentaje_error)) 
	{ 
        
		// Find middle point 
        
		c = (a * 1.000 + b * 1.000)/2.000;
        // cout<<"c "<<c<<endl;
        vec_c.push_back(c);
        cout<<"vec_size / iteraciones: "<<vec_c.size()<<endl;

        if(i == 0){
            imprimirValores(i, a, b, c,func(a), func(b), func(c));
        }
         

		// Check if middle point is root 
		if (func(c) == 0.000) 
			break; 

		// Decide the side to repeat the steps 
		else if (func(c)*func(b) > 0)         //(func(c)*func(a) < 0) //(func(a)*func(b) < 0)
		    b = c;	              
		else
            a = c;
			            

        if( i >= 1){
            // cout<<"Error calculado "<<error(vec_c, i)<<endl; 
            error_calculado = error(vec_c, i);
            // cout<<"Error calculado 2 "<<error_calculado<<endl;
            imprimirValores(i, a, b, c,func(a), func(b), func(c), error_calculado); 
        }
        i++;        
	}

	cout << "The value of root is : " << c<<endl;
    //cout<<"Error "<<error(vec_c, i) * 100.000<<endl;  

    for(int x =0; x<vec_c.size(); x++){
        cout<<vec_c[x]<<" ";
    }
} 

// Driver program to test above function 
int main() 
{ 
	// Initial values assumed 
	float a =1.000, b = 2.000; 
    //float a =1.000, b = 9.000; 
	bisection(a, b); 
	return 0; 
} 
