#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[] , int n , double b[]){
    double sum = 0 , sumstd = 0 , prod = 1 , sumHar = 0 , Max = -9999 , Min = 9999;
    for(int i = 0 ; i < n ; ++i){
        sum += a[i];
        prod *= a[i];
        sumHar += 1.0 / a[i];
        if(a[i] > Max)
            Max = a[i];
        if(a[i] < Min)
            Min = a[i];
    }
    b[0] = sum / n;
    for(int i = 0 ; i < n ; ++i){
        sumstd += (a[i] - b[0])*(a[i] - b[0]);
    }
    b[1] = sqrt(sumstd / n);
    b[2] = pow(prod , 1.0/n);
    b[3] = double(n) / sumHar; 
    b[4] = Max;
    b[5] = Min;   
}
