#include<iostream>
using namespace std;


int factorial(int n){ // tc and sc -> O(n)
    if (n == 0) return 1;
    return n*factorial(n-1);
    
}


int main(){
    int n = 6;
    cout << "Factorial of " << n << " is ";
    for(int i=n; i>0; i--){
        if (i == 1) cout << i;
        else cout << i << "*";
    }
    cout << " = " << factorial(n);

}




