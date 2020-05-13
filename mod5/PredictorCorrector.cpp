/* Adam BashForth Adam Moulton Predictor Corrector Method */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
float f(float x, float y){
    return 1 + y*y;
}
float del_y(float h, float x0, float y0){
    float k1 = h*f(x0, y0);
    float k2 = h*f(x0 + h/2, y0 + k1/2);
    float k3 = h*f(x0 + h/2, y0 + k2/2);
    float k4 = h*f(x0 + h, y0 + k3);
    return (k1 + 2*k2 + 2*k3 + k4)/6;
}
int main(){
    cout<<"\nAdam BashForth Adam Moulton Predictor Corrector Method:\n";
    cout<<"-------------------------------------------------------\n";
    cout<<"Solve the ODE y' = 1 + y^2; y(0) = 0\n";
    cout<<"Find the predictor and corrector value of y(0.8)";
    float x0 = 0, x1 = 0.2, x2 = 0.4, x3 = 0.6, x4 = 0.8;
    float y0 = 0, y1, y2, y3, y4_p, y4_c;
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
    float dely3 = del_y(h, x2, y2);
    cout<<"\n\ndely3 = "<<dely3<<endl; 
    y3 = y2 + dely3;
    cout<<"y(0.6) = y(0.4) + dely3 = "<<y3;
    cout<<"\n\nPredictor value: ";
    y4_p = y3 + (h/24)*(55*f(x3,y3) - 59*f(x2,y2) + 37*f(x1,y1) - 9*f(x0,y0));
    cout<<"y(0.8) = "<<y4_p;
    cout<<"\n\nCorrector value: ";
    y4_c = y3 + (h/24)*(9*f(x4,y4_p) + 19*f(x3,y3) - 5*f(x2,y2) + f(x1,y1));
    cout<<"y(0.8) = "<<y4_c;
    cout<<"\n---------------------------------------------";
    return 0;
}