#include<iostream>
using namespace std;

// recursively
int fib(int n){ // tc->O(2^n) , sc->O(n)
    if (n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}


// iteratively
void fibI(int n){
    int a=0, b=1, c = 0;
    for(int i=1; i<=n; i++){
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main(){
    // for(int i=0; i<8; i++){
    //     cout << fib(i) << " ";
    // }
    fibI(8);
}