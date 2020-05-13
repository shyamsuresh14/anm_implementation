/* Jacobi method */

#include<iostream>
#include<algorithm>
#include<cmath>
#define PI 3.14159
#define N 3
using namespace std;
void matmul(float A[N][N], float B[N][N], float C[N][N], bool transpose=false){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            float s = 0;
            for(int k=0; k<N; k++)
                s += A[transpose ? k : i][transpose ? i : k]*B[k][j]; 
            C[i][j] = abs(s) < 1e-05 ? 0 : s;
        }
    }
}
void printMat(float M[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}
bool isDiagonalMat(float M[N][N]){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i!=j && M[i][j] != 0) return false;
    return true;
}
bool findEigenValues(float A[N][N], float B[N][N]){
    static int it = 1;
    cout<<"Iteration "<<it++<<": "<<endl;
    cout<<"------------\n";
    int m = 0, ind = -1;
    for(int i=1; i<N; i++)
        if(A[0][i] > m) 
            m = A[0][i], ind = i;
    cout<<"Chosen value: A(1,"<<ind+1<<") = "<<m<<endl;
    float theta = 0.5*atan(2*m / (A[0][0] - A[ind][ind]));
    cout<<"Theta = "<<theta<<" radians"<<endl;
    float S[N][N] = {0};
    S[0][0] = cos(theta); S[0][ind] = -sin(theta);
    S[ind][0] = sin(theta); S[ind][ind] = cos(theta);
    S[ind == 2 ? 1 : 2][ind == 2 ? 1 : 2] = 1;
    cout<<"S = \n";
    printMat(S);
    float temp[N][N];
    matmul(A, S, temp);
    matmul(S, temp, B, true);
    cout<<"B = \n";
    printMat(B);
    return isDiagonalMat(B);
}
int main(){
    cout<<"\nJacobi Method: \n";
    cout<<"--------------\n\n";
    float A[N][N] = {
        1, sqrt(2), 2,
        sqrt(2), 3, sqrt(2),
        2, sqrt(2), 1
    };

    float B[N][N]; bool done = false;
    while(1){
        done = findEigenValues(A, B);
        if(done) break;
        cout<<"Not a diagonal matrix!\n\n";
        swap(A, B);
    }
    cout<<"\nEigen values: ";
    for(int i=0; i<N; i++) cout<<B[i][i]<<" ";
    cout<<"\n--------------------------";
    return 0; 
}