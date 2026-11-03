#include<iostream>
using namespace std;

// Question variation	What changes?
// Generate all subsets	Include / exclude
// Generate subsets of size exactly k	Print only when size == k at completion
// Generate subsets whose sum equals target	Maintain a running sum
// Generate subsets containing a particular value	Add a condition at the leaf
// Generate subsets of positive values with sum below target	Add pruning
// Generate unique subsets when input has duplicates	Avoid duplicate branches or duplicate outputs
// Generate all subsets that contain exactly two elements.





 // time complexity -> total calls * work done in each call
const int n = 3;

int arr[n] = {1, 2, 3};
int subset[n];


void printSubset(int size){
  cout << "{" ;
    for(int i=0; i<size; i++){
     cout << subset[i] << " ";
    }
    cout << "}" << endl;
}


void generateSubsets(int index, int size){ 

  if (index == n){
    printSubset(size);
    return;
  }

  subset[size] = arr[index]; // this is for include
  generateSubsets(index+1, size+1);
  generateSubsets(index+1, size);
}


int main(){
  generateSubsets(0, 0);
}