#include <iostream>
#include <algorithm>
using namespace std;

void display(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void heapify(int arr[], int n, int i, int &sw){
    int b = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && arr[l] > arr[b])
        b = l;

    if(r < n && arr[r] > arr[b])
        b = r;

    if(b != i){
        swap(arr[i], arr[b]);
        sw++;

        heapify(arr, n, b, sw);
    }
}

void heapSort(int arr[], int n){
    int sw = 0;

    for(int i = n/2-1; i >= 0; i--)
        heapify(arr, n, i, sw);

    cout << "Max Heap: ";
    display(arr, n);

    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        sw++;

        heapify(arr, i, 0, sw);

        cout << "After extraction: ";
        display(arr, n);
    }

    cout << "Sorted Array: ";
    display(arr, n);

    cout << "Total Swaps: " << sw << endl;
}

int main(){
    int arr[] = {42, 17, 63, 28, 51, 9, 36, 74, 23};

    int n = 9;

    heapSort(arr, n);

    return 0;
}