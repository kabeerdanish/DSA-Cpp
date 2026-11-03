#include<iostream>
using namespace std;



// 1. Direct Recursion – function calls itself directly.

// 2. Indirect Recursion – function A calls function
// B, which calls A again.

// Recursion vs Iteration

// Recursion:

// Simpler logic

// Uses more memory (stack)

// Iteration:

// Uses loops

// Faster and memory efficient

// Writing recursive algorithms

// Methods for searching arrays

// Recursive data structures

// Recursive methods for a LinkedList class

// Solving the Towers of Hanoi problem with recursion

// Processing 2-D images with recursion

// Backtracking to solve searchproblems, as in mazes


//
No.	Problem	Expected result
1	Display array from left to right	10 20 30 40 50
2	Display array from right to left	50 40 30 20 10
3	Calculate sum of array	150
4	Calculate product of elements	12000000
5	Count even elements	2
6	Count odd elements	3
7	Find maximum element	50
8	Find minimum element	10

// Level	Problems
// Towers of Hanoi

// Counting grid squares in a blob
reverse string, finding length of string, print string char wise, gcd
// digit sum, reverse number, count digits
// Medium	Array sum, maximum, minimum, search, sorted check
// Medium	Reverse array, palindrome string, binary search
// // Medium–Hard	Subsequences, string permutations, multiple recursive calls
// Hard	Tower of Hanoi, Josephus problem, recursive maze paths
// Advanced	Recursive generation, complex recurrence, recursion + memoization


int factorial(int n){ // tc and sc -> O(n)
    if(n == 0 || n == 1) return 1;
    return n*factorial(n-1);
    
}


int main(){
    int n = 6;
    cout << "Factorial of " << n << " is ";
    for(int i=n; i>0; i--){
        if (i == 1) cout << i;
        else cout << i << "*";
    }
    cout << " = " << factorial(n);
}







