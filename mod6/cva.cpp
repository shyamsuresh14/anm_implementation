/* Central Value Approximation */

#include<iostream>
#include<cmath>
#define N 3
using namespace std;
void getCofactor(float A[N][N], float temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        {  
            if (row != p && col != q) 
            { 
                temp[i][j++] = A[row][col]; 
 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
float determinant(float A[N][N], int n) 
{ 
    float D = 0; 
    if (n == 1) 
        return A[0][0]; 
  
    float temp[N][N];
  
    int sign = 1;  
  
    for (int f = 0; f < n; f++) 
    { 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
        sign = -sign; 
    } 
  
    return D; 
} 
   
void adjoint(float A[N][N],float adj[N][N]) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 

    int sign = 1; float temp[N][N]; 
  
    for (int i=0; i<N; i++) 
    { 
        for (int j=0; j<N; j++) 
        {  
            getCofactor(A, temp, i, j, N);  
            sign = ((i+j)%2==0)? 1: -1; 
            adj[j][i] = (sign)*(determinant(temp, N-1)); 
        } 
    } 
} 

bool inverse(float A[N][N], float inverse[N][N]) 
{ 
    float det = determinant(A, N); 
    if (det == 0) 
    { 
        cout << "Singular matrix, can't find its inverse"; 
        return false; 
    } 
    float adj[N][N]; 
    adjoint(A, adj); 
    for (int i=0; i<N; i++) 
        for (int j=0; j<N; j++) 
            inverse[i][j] = adj[i][j]/float(det); 
  
    return true; 
} 
int main(){
    cout<<"\nGiven, y\"(x) - y(x) = x ; y(0)=0; y(1)=0; h=1/4";
    cout<<"\n\nAccd to Central Value Approx: y\" = (yk-1 - 2yk + yk+1) / h^2";
    cout<<"\n=> yk-1 -2yk + yk+1 - h^2*yk = h^2*xk";
    cout<<"\n=> yk-1 -(2+h^2)yk + yk+1 = h^2*xk\n";
    float y0 = 0, y1 = 0;
    float h = 0.25; 
    float A[N][N], B[N];
    A[0][0] = -(2+h*h);
    A[0][1] = 1;
    A[0][2] = 0;
    A[1][0] = 1;
    A[1][1] = -(2+h*h);
    A[1][2] = 1;
    A[2][0] = 0;
    A[2][1] = 1;
    A[2][2] = -(2+h*h);
    B[0] = h*h*(1*h) - y0;
    B[1] = h*h*(2*h);
    B[2] = h*h*(3*h) - y1;
    cout<<"\nMatrix eqn: \n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<A[i][j]<<" ";
        cout<<"\ty"<<(i+1)<<"\t=\t"<<B[i]<<endl;
    }
    float inv[N][N];
    if(inverse(A, inv)){
        float X[N];
        for(int i=0; i<N; i++){
            X[i] = 0;
            for(int j=0; j<N; j++){
                X[i] += inv[i][j]*B[j];
            }
        }
        cout<<"\nSolution: \n";
        for(int i=0; i<N; i++){
            cout<<"y"<<(i+1)<<" = "<<X[i]<<" ";
        }
    }
    return 0;
}