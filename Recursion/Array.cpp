#include<iostream>
using namespace std;


void inputArrElments(int arr[], int n, int i){
    if (i == n) return ;

    cout << "Enter elments at index " << i << ": ";
    cin >> arr[i];
    inputArrElments(arr, n, i+1);

}

void displayArr(int arr[], int n, int i){
    if (i == n) return ;
    // cout << arr[i] << " ";
    displayArr(arr, n, i+1);
    cout << arr[i] << " ";
}



int main(){
    int arr[100];
    
    int n;
    cin >> n;
    inputArrElments(arr, n, 0);
    displayArr(arr, n, 0);

}