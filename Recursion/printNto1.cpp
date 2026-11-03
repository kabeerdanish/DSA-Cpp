#include<iostream>
using namespace std;

void printnto1(int n){
    if (n == 0) return;
    cout << n << " "; // prints n to 1
    printnto1(n-1);
    // cout << n << " "; // prints 1 to n
} 


int main(){
    cout << "Print number from n to 1: " ;
    printnto1(5);
}