#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

void insertAtEnd(Node* &head, int val){

    Node* newNode = new Node(val);

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    
}

void modifyLL(Node* &head){
    Node* temp = head;
    Node* eh = nullptr, *et = nullptr;
    Node* oh = nullptr, *ot = nullptr;
    while(temp != nullptr){
        if(temp->data % 2 == 0){ 
            if(eh == nullptr){
                eh = et = temp;
            }else{
            et->next = temp;
            et = temp;
            }
        }
        else{
            if(oh == nullptr){
                oh = ot = temp;
            }else{
            ot->next = temp;
            ot = temp;
            }
        }
    temp = temp->next;
    }

    if(eh == nullptr){
        head = oh;
    }else{
        head = eh;
        et->next = oh;
    }

    if(ot != nullptr){
        ot->next = nullptr;
    }
}


void display(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}



int main(){
    Node* head = nullptr;
    int n;
    int val;

    cout << "Enter the number of nodes: " ;
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Enter Node " << i+1 << " data: ";
        cin >> val;

        insertAtEnd(head, val);
    }

    cout << "Input: ";
    display(head);
    cout << endl;
    modifyLL(head);
    cout << "Output: ";
    display(head);

}