#include<iostream>
using namespace std;

void printTable(int n, int i){
    if(i < 1) return; // or i > 10
    // cout << n << " * " << i << " = " << n*i << endl;
    printTable(n, i-1); // then i+1
    cout << n << " * " << i << " = " << n*i << endl;

 
}

int main(){
    printTable(5, 10);
}