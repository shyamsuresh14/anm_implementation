/* Type of Partial Differential Equation */

#include<iostream>
#include<string>
#include<climits>
using namespace std;
int A(int x){
    return x*x;
}
int B(){
    return 0;
}
int C(int y){
    return 1 - y*y;
}
int det(int x, int y){
    return B()*B() - 4*A(x)*C(y);
}
int main(){
    cout<<"\nGiven PDE: x^2*fxx + (1 + y^2)*fyy ; ";
    cout<<"Limits: -1 < y < 1 and -inf < x < inf"<<endl<<endl;
    int y1 = -1, y2 = 1;
    int x1 = INT16_MIN, x2 = INT16_MAX;
    cout<<"Determiner: B^2 - 4AC"<<endl<<endl;
    bool asign, bsign;
    cout<<"When x = "<<((x1 == INT16_MAX) ? "inf" : "-inf")<<", "<<"A = "<<((A(x1) > 0) ? "positive" : "negative")<<" ";
    cout<<"When x = "<<((x2 == INT16_MAX) ? "inf" : "-inf")<<", "<<"A = "<<((A(x2) > 0) ? "positive" : "negative")<<endl;
    cout<<"When y = "<<y1<<", "<<"C = "<<((C(y1) > 0) ? "positive" : "negative")<<" ";
    cout<<"When y = "<<y2<<", "<<"C = "<<((C(y2) > 0) ? "positive" : "negative")<<endl;
    asign = (A(x1)>0 && A(x2)>0) ? true : false;
    bsign = (C(y1)>0 && C(y2)>0) ? true : false;
    cout<<"\nSo, A is "<<(asign ? "pos":"neg")<<", B is "<<(bsign ? "pos":"neg")<<endl;
    int detVal = det(x2/2, y2/2);
    cout<<"So, B^2 - 4AC is "<<(detVal > 0 ? "pos" : (detVal == 0) ? "0" : "neg");
    cout<<"\n\nHence, the PDE is ";
    if(detVal < 0) cout<<"elliptic";
    else if(detVal == 0) cout<<"parabolic";
    else cout<<"hyperbolic";
    return 0;
}