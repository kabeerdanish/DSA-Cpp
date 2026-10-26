#include<iostream>
using namespace std;

bool checkSorted(int arr[], int n){ // tc->O(n) <-sc
    if(n == 0 || n == 1) return true;
    return arr[n-1] >= arr[n-2] && checkSorted(arr, n-1);
}

int main(){
    int arr[] = {1, 2, 3, 8, 5};
    cout << (sizeof(arr)/sizeof(arr[0])) << endl;
    cout << checkSorted(arr, 5);
}