#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

int factorial(int n){ // tc and sc -> O(n)
    if (n == 0) return 1;
    return n*factorial(n-1);
    
}


int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fib(n-1) + fib(n-2);
}

void printnto1(int n){

    cout << n << " ";
    if (n == 1) return;
    printnto1(n-1);
    cout << n << " ";
}

void display(Node* p){ // linked list recursive display
    if (p == nullptr) return;
    cout << p->data << "->";
    display(p->next);
  
}


int main(){
    // Node *head = new Node(5);
    // head->next = new Node(4);
    // display(head);
    // cout << "NULL";
    
    // int n = 4;
    //  cout << "\nFactorial of " << n << " is ";
    // for(int i=n; i>0; i--){
    //     if (i==1) cout << i;
    //     else cout << i << "*";
    // }
    // cout << " = " << factorial(n);
    // cout << endl;
    // cout << sum(5) << endl;


    int prev = 0;
    int curr = 1;
    int next = 0;

    for(int i=0; prev<10; i++){
        cout << prev << " ";
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    cout << endl;
    printnto1(5);


}




