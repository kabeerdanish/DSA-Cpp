#include<iostream>
using namespace std;

int sum(int n){ // tc and sc -> O(n)
    if (n == 0) return 0;
    return n + sum(n-1);
}

int sumEven(int n){
    if (n <= 1) return 0;
    if(n % 2 == 0) return n + sumEven(n-2);
    return sumEven(n-1);
}

int sumOdd(int n){
    if(n <= 0) return 0;
    if(n % 2 != 0) return n + sumOdd(n-2);
    return sumOdd(n-1);
}


int product(int n){
    if(n <= 1) return 1;
    return n*product(n-1);
}

int sumSquares(int n){
    if(n <= 0) return 0;
    return (n*n) + sumSquares(n-1);
}

int sumCubes(int n){
    if(n <= 0) return 0;
    return (n*n*n) + sumSquares(n-1);
}


int main(){
    cout << sum(10) << endl;
    cout << product(5) << endl;
    cout << sumEven(11) << endl;
    cout << sumOdd(14) << endl;
}

