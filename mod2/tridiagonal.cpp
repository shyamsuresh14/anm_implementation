/* Tridiagonal matrix method */

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int dim = 4;

int main(){
    vector<vector<int>> matrix; 
    vector<int> r, a, b, c;
    vector<float> gamma, beta, y(dim, 0);

    cout<<"Tridiagonal matrix method"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"\nTridiagonal Matrix Equation: \n";
    ifstream f("input.txt");
    for(int i=0; i<dim; i++){
        vector<int> row;
        for(int j=0; j<dim; j++){
            int no;
            f>>no;
            //cout<<no<<" ";
            row.push_back(no);
        }
        matrix.push_back(row);
        //cout<<endl;
    }
    for(int i=0; i<dim; i++){
        int op;
        f>>op;
        r.push_back(op);
    }
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++)
            cout<<matrix[i][j]<<" ";
        cout<<" y"<<i+1<<"  "<<r[i]<<endl;
    }
    a.push_back(0);
    for(int i=1; i<dim; i++){
        a.push_back(matrix[i][i-1]);
        c.push_back(matrix[i-1][i]);
    }
    c.push_back(0);
    for(int i=0; i<dim; i++)
        b.push_back(matrix[i][i]);

    cout<<"\na = [ "; for(auto x: a) cout<<x<<" "; cout<<"]";
    cout<<"\nb = [ "; for(auto x: b) cout<<x<<" "; cout<<"]";
    cout<<"\nc = [ "; for(auto x: c) cout<<x<<" "; cout<<"]";
    cout<<"\nr = [ "; for(auto x: r) cout<<x<<" "; cout<<"]\n";

    beta.push_back(b[0]);
    gamma.push_back(r[0]/beta[0]);

    for(int i=1; i<dim; i++){
        beta.push_back(b[i] - (a[i]*c[i-1]/beta[i-1]));
        cout<<b[i]<<" "<<a[i]<<" "<<c[i-1]<<" "<<beta[i-1]<<endl;
        gamma.push_back((r[i] - a[i]*gamma[i-1]) / beta[i]);
    }

    cout<<"\nbeta = [ "; for(auto x: beta) cout<<x<<" "; cout<<"]";
    cout<<"\ngamma = [ "; for(auto x: gamma) cout<<x<<" "; cout<<"]\n";

    y[dim-1] = gamma[dim-1];
    for(int i=1; i<dim; i++){
        y[dim-1-i] = gamma[dim-1-i] - (c[dim-1-i] * y[dim-i]) / beta[dim-1-i];
    }

    cout<<"\ny = [ "; for(auto x: y) cout<<x<<" "; cout<<"]\n";
    return 0;
}