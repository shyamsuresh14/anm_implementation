/* Secant Method */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

float no;

float f(float x){
    return x*x - no;
}
float next_x(float x, float y){
    return (x*f(y) - y*f(x)) / (f(y) - f(x));
}
bool cmpf(float x, float y, float epsilon = 0.00001f)
{
    return (fabs(x - y) < epsilon);
}

int main(){
    float x, res;
    vector<float> x_n;

    cout<<"Secant method"<<endl;
    cout<<"-------------"<<endl;
    cout<<"Input: A number"<<endl;
    cout<<"Output: Its root value calculated by secant method"<<endl;
    
    cout<<"\nEnter a value: ";
    cin>>no;

    cout<<"\nx = sqrt("<<no<<")"<<endl;
    cout<<"f(x) = x^2 - "<<no<<endl;

    int i = 1;
    while(1){
        if(f(i-1) * f(i) < 0){
            break;
        }
        i++;
    }
    x_n.push_back(i-1);
    x_n.push_back(i);
    cout<<"Interval: ["<<i-1<<","<<i<<"]"<<endl;

    while(1){
        float x_i = next_x(x_n[x_n.size() - 2], x_n[x_n.size() - 1]);
        x_n.push_back(x_i);
        if(cmpf(x_n[x_n.size() - 2], x_n[x_n.size() - 1]))
            break;
        i++;
    }
    cout<<"\nValues: "<<endl;
    cout<<"------"<<endl;
    for(int i=0; i<x_n.size(); i++){
        cout<<"x"<<i<<" = "<<x_n[i]<<endl;
    }
    cout<<"\nValue of root of "<<no<<" = "<<x_n[x_n.size() - 1]<<endl;
    return 0;
}