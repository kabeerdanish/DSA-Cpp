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


void display(Node* p){ // linked list recursive display
    if (p == nullptr) return;
    cout << p->data << "->";
    display(p->next);
  
}

int factorial(int n){ // tc and sc -> O(n)
    if (n == 0) return 1;
    return n*factorial(n-1);
    
}


int main(){
    // Node *head = new Node(5);
    // head->next = new Node(4);
    // display(head);
    // cout << "NULL";
    
    int n = 6;
    cout << "Factorial of " << n << " is ";
    for(int i=n; i>0; i--){
        if (i==1) cout << i;
        else cout << i << "*";
    }
    cout << " = " << factorial(n);

}




