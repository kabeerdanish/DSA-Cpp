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

class singlyLinkedList{
    public:
    Node* head;

    public:
    singlyLinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int val){ // if using tail time comp = O(1) otherwise O(n)
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

    void merge(singlyLinkedList& other){
        Node* h2 = other.head;

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = h2;
        this->display();

    }

    void sort(){
        Node* s = new Node(-1);
        Node* temp = head;
        Node* curr = s;

        while(temp != nullptr){
            if(temp == head){
                Node* newNode = new Node(temp->data);
                curr->next = newNode;

            }
            else{

            curr = s;
            while(curr != nullptr){
                if(temp->data > curr->next->data){
                    curr = curr->next;
                    break;
                }
                Node* newNode = new Node(temp->data);
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
        temp = temp->next;

        }
        head = s;

    }




    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main(){
    singlyLinkedList l1;
    singlyLinkedList l2;
    l1.insertAtEnd(1);
    l1.insertAtEnd(5);
    l1.insertAtEnd(7);
    l1.insertAtEnd(3);
    l1.display();

    // l2.insertAtEnd(2);
    // l2.insertAtEnd(4);
    // l2.insertAtEnd(6);
    // l2.insertAtEnd(8);
    // l2.display();

    l1.sort();
    l1.display();
    








    
    
}



