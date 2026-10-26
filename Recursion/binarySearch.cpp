// we search an word in dictionary this is real life or pracical example of binary search alogorithm
// linear search -> tc->O(n) and its optimization is binary search based on tc -> O(log n) applied on sorted or ordered data structures
// it means binary serach work on sorted array etc even its ascending or decending 
// for binary search
//(1) find mid st=0, end=n-1, mid = (st+end)/2 
// if target > arr[mid] i have to search on 2nd half
// and if target < arr[mid] i have to search on first half
// and if target == arr[mid] then my answer is mid idx
// worst case in mid case st and end are int they can be max int_max and when they got add it can cause overflow
// which can cause wrong mid value ad to prevent this we have an optimztion is -> we use mid = st + (end-st)/2 its mathematicallly same but to prvent overflow its working

#include<iostream>
using namespace std;

int binarySearch(int arr[], int target, int n ){ // iteratively tc->O(log n) sc->O(1)
    int st = 0;
    int end = n-1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) end = mid-1;
        else st = mid+1;
    }
    return -1;
}

int binarySearchR(int arr[], int st, int end, int target){ // recursively tc and sc-> O(logn)
    if (st > end) return -1;
    
    int mid = st + (end-st)/2;
    
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearchR(arr, st, mid-1, target);
    else return binarySearchR(arr, mid+1, end, target);

} 



int main(){
    int arr[] = {-1, 0, 3, 4, 5, 9, 12};
    int target = 3; // return idx if found else -1
    cout << target << " Found at index " << binarySearchR(arr, 0, 7-1, target) << endl;
}
