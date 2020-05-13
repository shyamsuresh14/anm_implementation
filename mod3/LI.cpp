/* Lagrange's Interpolation Method */

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<"Lagrange's Interpolation Method:\n";
    cout<<"------------------------------------\n";
    cout<<"Points: (5,12), (6,13), (9,16), (11,16)\n";
    cout<<"Polynomial order: 3 => find value at x\n";
    int n = 3;
    int X[] = {5,6,9,11};
    int Y[] = {12,13,16,16};
    float x;
    cout<<"\nEnter x: ";
    cin>>x;
    float fx = 0;
    for(int i=0; i<=n; i++){
        float fxi = 1;
        for(int j=0; j<=n; j++){
            if(i != j)
                fxi *= (x - X[j])/(X[i] - X[j]); 
        }
        fx += fxi*Y[i];
    }
    cout<<"\nf(x) = "<<fx;
    cout<<"\n--------------";
    return 0;
}