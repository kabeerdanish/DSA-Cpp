#include<iostream>
using namespace std;
int main(){
   int arr[] = {1,2,3,4,5,6,8,7};
   int length = sizeof(arr)/sizeof(arr[0]);
   int temp;
   bool check = false;


   // diff inner loop boundary

    // for(int k=0 ; k<length-1; k++){
    //     for(int i=0;i<length-1;i++){
    //         int j=i+1;
    //         if(arr[i]>arr[j]){
    //             temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }





    //asic for loops approach and also optimized for loop approach (adaptive)

    for(int i=0; i<length-1; i++){
        bool swapped = false;
        for(int j=0; j<length-i-1; j++){
            if(arr[j]>arr[j+1]){
                // temp = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = temp;
                swap(arr[j], arr[j + 1]);


                swapped = true;
                check = true;

            }
        }
        if(swapped == false){
            break;
        }
    } 





   for(int numbers : arr){
    if(numbers == arr[length-1]) cout<<numbers;
    else cout<<numbers<<", ";
   }
    if(check == false) cout<<"\nAlready Sorted !";
    else cout<<"\nSorted Sucessfully!";
}