/* Newton's Foward Difference Method */

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
int main(){
    cout<<"\nNewton's Foward Difference Method:\n";
    cout<<"----------------------------------\n";
    int X[] = {140,150,160,170,180};
    int n = sizeof(X)/sizeof(int);
    unordered_map<int, float> f({
        {140, 3.685},
        {150, 4.854},
        {160, 6.302},
        {170, 8.076},
        {180, 10.225}
    });
    vector<unordered_map<int, float>> dels;
    dels.push_back(f);
    while(dels.back().size() > 1){
        unordered_map<int, float> del, prev = dels.back();
        for(int i=1; i<prev.size(); i++){
            del[X[i-1]] = prev[X[i]] - prev[X[i-1]]; 
        }
        dels.push_back(del);
    }
    cout<<"\nNewton's table: \n";
    for(int i=0; i<n; i++){
        cout<<X[i]<<" ";
        for(auto del: dels)
            if(del[X[i]]) cout<<del[X[i]]<<" ";
        cout<<endl;
    }
    float x;
    cout<<"\nEnter x: ";
    cin>>x;
    
    int ind = upper_bound(X, X + n, x) - X;
    if(ind > n/2)
        cout<<"\nWarning: Better to go for Newton's backward formula!\n";
    
    float u = (x - X[0])/(X[1] - X[0]);
    float fx = dels[0][X[0]];
    for(int i=0; i<dels.size() - 1; i++){
        float ui = 1;
        for(int j=0; j<=i; j++) ui*=(u-j); 
        ui /= factorial(i+1);
        fx += ui*dels[i+1][X[0]]; 
    }
    cout<<"\nf(x) = "<<fx;
    cout<<"\n--------------------";
    return 0;
}