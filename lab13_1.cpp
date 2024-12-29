#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double a[] ,int n ,double b[]){
    double max = a[0] , min = a[0];
    double sum = 0 , sum2 = 0 , sumg = 1 , sumh = 0  ;
    for(int i=0; i < n; i++){
        sum = sum + a[i];
        sum2 = sum2 + pow(a[i],2);
        sumg = sumg*a[i];
        sumh = sumh+(1/a[i]);
    }

    b[0] = sum/n; 
    b[1] = sqrt((sum2/n)-pow(sum/n,2)) ;
    double gm,hm;
    gm = pow(sumg,1.0/n);
    b[2] = gm;
    hm = (n/sumh);
    b[3] = hm;

    for(int i=0; i<n ; i++){
        if(a[i]>max) max = a[i] ;
        if(a[i]<min) min = a[i] ;
    }

    b[4] = max;
    b[5] = min;
}