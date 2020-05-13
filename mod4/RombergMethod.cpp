/* Romberg method */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
float f(float x){
    return 1/(1+x);
}
bool cmpf(float x, float y, float epsilon = 0.0001f)
{
    return (fabs(x - y) < epsilon);
}
float calculateIntegral(float x1, float x2, float h){
    const int n = (x2-x1)/h;
    vector<float> fx(n+1);
    for(int i=0; i<=n; i++)
        fx[i] = f(x1 + i*h);
    float ans = fx[0] + fx[n];
    for(int i=1; i<n; i++) ans += 2*fx[i];
    ans *= h/2;
    return ans;
}
int main(){
    cout<<"\nRomberg Method:\n";
    cout<<"---------------\n";
    cout<<"Integrate 1/(1+x) from 0 to 1\n\n";
    float x1 = 0, x2 = 1;
    float h = x2 - x1;
    int i = 1; float prev = 0;
    while(1){
        h /= 2;
        cout<<"Iteration "<<i++<<": "<<"h = "<<h<<"\n";
        float op = calculateIntegral(x1, x2, h);
        cout<<"Output = "<<op<<endl;
        if(cmpf(prev, op)){
            cout<<"\nAns = "<<op;
            break;
        }
        prev = op;
    }
    return 0;
}