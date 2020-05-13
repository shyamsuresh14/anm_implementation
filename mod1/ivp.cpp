/* Iterative method */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

float f(float x){
    return exp(x) - 3*x;
}
float phi(float x){
    return exp(x)/3;
}
float phi_dx(float x){
    return phi(x);
}
bool cmpf(float x, float y, float epsilon = 0.0001f)
{
    return (fabs(x - y) < epsilon);
}

int main(){
    float x, res;

    cout<<"Iterative method"<<endl;
    cout<<"-------------"<<endl;
    cout<<"Input: A number"<<endl;
    cout<<"Output: Its root value calculated by Iterative method"<<endl;

    cout<<"f(x) = e^x - 3x"<<endl;

    int i = 1;
    while(1){
        if(f(i-1) * f(i) < 0){
            break;
        }
        i++;
    }
    cout<<"\nInterval: ["<<i-1<<","<<i<<"]"<<endl;
    float x0;
    if(-f(i-1) < f(i)) x0 = ((float)i/2) + (f(i-1) > 0 ? 0.1 : -0.1);
    else x0 = ((float)i/2) + (f(i) > 0 ? 0.1 : -0.1); 
    cout<<"\nphi(x) = (e^x)/3\n";
    cout<<"|phi'(0)| = "<<abs(phi_dx(0))<<" < 1, ";
    cout<<"|phi'(1)| = "<<abs(phi_dx(1))<<" < 1"<<endl;
    cout<<"\nx0 = "<<x0<<endl;
    
    i = 0; 
    float xi = x0;
    while(1){
        float val = phi(xi);
        i++;
        cout<<"x"<<i<<" = "<<val<<endl;
        if(cmpf(val, xi)) break;
        xi = val;
    }
    cout<<"\nIterations: "<<i;
    return 0;
}