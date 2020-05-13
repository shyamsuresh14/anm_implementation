/* Range Kutta Method */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
float f(float x, float y){
    return x + y;
}
float del_y(float h, float x0, float y0){
    float k1 = h*f(x0, y0);
    float k2 = h*f(x0 + h/2, y0 + k1/2);
    float k3 = h*f(x0 + h/2, y0 + k2/2);
    float k4 = h*f(x0 + h, y0 + k3);
    return (k1 + 2*k2 + 2*k3 + k4)/6;
}
int main(){
    cout<<"\nRange Kutta Method:\n";
    cout<<"-------------------\n";
    cout<<"Solve the ODE y' = x + y; y(0) = 1, y(0.2) = ?, y(0.4) = ?\n";
    float x0 = 0, x1 = 0.2, x2 = 0.4;
    float y0 = 1, y1, y2;
    float h = x2 - x1;
    cout<<"\nh = "<<h;
    float dely1 = del_y(h, x0, y0);
    cout<<"\n\ndely1 = "<<dely1<<endl; 
    y1 = y0 + dely1;
    cout<<"y(0.2) = y(0) + dely1 = "<<y1;
    float dely2 = del_y(h, x1, y1);
    cout<<"\n\ndely2 = "<<dely2<<endl; 
    y2 = y1 + dely2;
    cout<<"y(0.4) = y(0.2) + dely2 = "<<y2;
    cout<<"\n---------------------------------------------";
    return 0;
}