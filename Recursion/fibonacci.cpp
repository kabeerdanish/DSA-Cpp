#include<iostream>
using namespace std;

int fib(int n){ // tc
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fib(n-1) + fib(n-2);
}


int main(){

    // int prev = 0;
    // int curr = 1;
    // int next = 0;

    // for(int i=0; prev<10 ; i++){ // we can use condition i<n for n terms
    //     cout << prev << " ";
    //     next = prev + curr;
    //     prev = curr;
    //     curr = next;
    // }
    int n;
    cout << "Enter no of terms you want for fibonacci: ";
    cin >> n; 
    int i=0;
    while(i < n){
        cout << fib(i) << " ";
        i++;
    }

}