#include<iostream>
using namespace std;

// void insertionSort(int arr[], int n){
//     int curr,prev;
//     for(int i=1; i<n; i++){
//         curr = i;   // *curr = arr[i]
//         prev = i-1;
//         while(prev>=0 && arr[prev]>curr){
//             arr[prev+1] = arr[prev];
//             prev--;

//         }
//         arr[prev+1] = curr;
//     }

//         for(int i=0; i<n; i++){
//             cout << arr[i] << endl;
//         }
//     }



void insertionSort(int arr[], int n){
    int curr,prev;
    for(int i=1; i<n; i++){
        curr = arr[i];
        prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }

}
int main(){
    int arr[] = {7,3,8,2,6};
    insertionSort(arr,5);
    for (int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}













