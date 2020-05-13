/* Trapezoidal Rule */

#include<iostream>
#include<cmath>
#define n 6
using namespace std;
float f(float x){
    return log(x);
}
int main(){
    cout<<"\nTrapezoidal Rule:\n";
    cout<<"------------------------\n";
    cout<<"Integrate ln(x) from 4 to 5.2\n\n";
    cout<<"n = "<<n<<endl;
    float  x1 = 4, x2 = 5.2;
    float h = (x2 - x1)/n;
    cout<<"h = "<<h<<endl;
    float fx[n+1];
    for(int i=0; i<=n; i++){
        fx[i] = f(x1 + i*h);
    }
    float ans = fx[0] + fx[n];
    for(int i=1; i<n; i++) ans += 2*fx[i];
    ans *= h/2;
    cout<<"\nAns = "<<ans;
    cout<<"\n---------------";
    return 0;
}