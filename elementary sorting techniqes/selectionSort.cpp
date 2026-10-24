#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int si = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[si]){
                si = j;
            }
        }
        swap(arr[i],arr[si]);
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {4,1,5,2,3};
    selectionSort(arr,5);
    display(arr,5);

}