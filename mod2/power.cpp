/* Power Method */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int dim = 3;
float max_val;

bool cmpf(float x, float y, float epsilon = 0.01f)
{
    return (fabs(x - y) < epsilon);
}

vector<float> mat_mul(vector<vector<int>> a, vector<float> x){
    vector<float> op;
    for(int i=0; i<dim; i++){
        float res = 0;
        for(int j=0; j<dim; j++){
            //cout<<a[i][j]<<","<<x[j]<<" ";
            res += a[i][j]*x[j];
        }
        //cout<<endl;
        //cout<<res<<" ";
        op.push_back(res);
    }
    //cout<<endl;
    return op;
}

int trace(vector<vector<int>> a){
    int t = 0;
    for(int i=0; i<dim; i++)
        t += a[i][i];
    return t;
}

int det(vector<vector<int>> a){
    int d = 0;
    d = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1]) - 
    a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0]) + 
    a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    return d;
}

float divide(float x) {return x/max_val;}

int main(){
    vector<vector<int>> matrix; 
    vector<float> x(dim, 1);  //X_0

    cout<<"Power method"<<endl;
    cout<<"-------------"<<endl;
    cout<<"Enter a 3x3 matrix: \n";
    for(int i=0; i<dim; i++){
        vector<int> row;
        for(int j=0; j<dim; j++){
            int no;
            cin>>no;
            row.push_back(no);
        }
        matrix.push_back(row);
    }
    float prev_max = 0.0f;
    cout<<endl;
    while (1)
    {
        vector<float> op = mat_mul(matrix, x);
        max_val = *max_element(op.begin(), op.end());
        transform(op.begin(), op.end(), op.begin(), divide);
        
        cout<<max_val<<" x [";
        for(auto x: op)
            cout<<x<<" ";
        cout<<"]\n";
        
        if(cmpf(max_val, prev_max))
            break;

        prev_max = max_val;
        x = op;
    }
    
    float l1 = max_val;
    float l2_l3 = trace(matrix) - l1;
    float l2l3 = det(matrix) / l1;
    float l2 = (l2_l3 + sqrt(l2_l3*l2_l3 - 4*l2l3)) / 2;
    float l3 = (l2_l3 - sqrt(l2_l3*l2_l3 - 4*l2l3)) / 2;

    cout<<"\nEigen values: "<<l1<<" , "<<l2<<" , "<<l3<<endl;
    return 0;
}