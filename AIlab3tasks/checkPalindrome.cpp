#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    static int counter;

    Node(char val){
        this->data = val;
        this->next = nullptr;
        counter ++;
    }
};
int Node::counter = 0;

void insertAtEnd(Node* &head, Node* &tail, char val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

char *arrayOfLL(Node* head){

    char* arr = new char[Node::counter];
    Node* temp = head;

    for(int i=0; i<Node::counter && temp != nullptr; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }
    return arr;
}

bool checkPalindrome(Node* &head){
    char * charr = arrayOfLL(head);
    int si = 0;
    int li = Node::counter-1;
    for(; si<li; si++,li--){
        if(charr[si] != charr[li]){
            delete []charr; 
            return false;
        }
    }
    delete []charr; 
    return true;
    
}
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int x;
    char n;
    cout << "Enter the number of nodes: ";
    cin >> x;
    for(int i=0; i<x; i++){
        cout << "Enter node " << i+1 << " data: ";
        cin >> n; 

        insertAtEnd(head,tail,toupper(n));
    }

    display(head);
    cout << checkPalindrome(head) << endl;
}