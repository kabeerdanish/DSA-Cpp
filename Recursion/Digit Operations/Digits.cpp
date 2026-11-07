#include<iostream>
using namespace std;

int count(int n){
    if(n == 0) return 0;
    return 1 + count(n/10);
}

int sum(int n){
    if(n == 0) return 0;
    return n%10 + sum(n/10); 
}

int product(int n){
    if (n == 0 || n == 1) return n;
    return (n%10) * product(n/10);
}

void printDigits(int n){
    if(n == 0){
        cout << endl;
        return;
    }
    cout << n%10 << " ";
    printDigits(n/10);
    cout << n%10 << " ";
}



int reverseDigtis(int n, int reversed){
    if(n == 0) return reversed;
    reversed = reversed*10 + (n%10);
    return reverseDigtis(n/10, reversed);
}

bool isPalindrome(int n){
    if(n < 0) return true;
    if(n == reverseDigtis(n, 0)) return true; // return n == reverseDigits(n, 0)
    return false;
}

int firstDigit(int n){
    if(n == (n/10 == 0)) return n;
    return firstDigit(n/10);
}

int main(){
    cout << count(45678) << endl;
    cout << sum(12345) << endl;
    cout << product(123) << endl;
    printDigits(12345);
    cout << endl;
    int reversed = reverseDigtis(123456, 0);
    printDigits(reversed);
    cout << endl;
    cout << isPalindrome(131) << endl;
    cout << firstDigit(61234) << endl;

}
 