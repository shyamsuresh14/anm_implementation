/* Newton's Dividend Difference Method */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
float f(float x){
    return x*x*x + x + 2;
}
int main(){
    cout<<"\nNewton's Dividend Difference Method:\n";
    cout<<"------------------------------------\n";
    cout<<"f(x) = x^3 + x + 2; args(1,3,6,11)\n";
    int X[] = {1,3,6,11};
    int n = sizeof(X)/sizeof(int);
    unordered_map<int, float> y;
    for(int i=0; i<n; i++)
        y[X[i]] = f(X[i]);
    vector<unordered_map<int, float>> dels;
    dels.push_back(y);
    int k=0;
    while(dels.back().size() > 1){
        unordered_map<int, float> del, prev = dels.back();
        for(int i=1; i<prev.size(); i++){
            del[X[i-1]] = (prev[X[i]] - prev[X[i-1]])/(X[i+k] - X[i-1]); 
        }
        dels.push_back(del);
        k++;
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

    float fx = 0;
    for(int i=0; i<dels.size(); i++){
        float fxi = dels[i][X[0]];
        for(int j=0; j<i; j++)
            fxi *= (x - X[j]);
        fx += fxi;
    }
    cout<<"\nf(x) = "<<fx;
    cout<<"\n----------------------";
    return 0;
}