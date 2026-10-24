#include<iostream>
using namespace std;

void printnto1(int n){
    if (n == 1){
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    printnto1(n-1);
    // cout << n << " ";
}


int main(){
    printnto1(5);
}