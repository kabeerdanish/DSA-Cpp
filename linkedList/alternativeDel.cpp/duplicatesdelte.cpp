#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    static int counter;
 
    Node(int val){
        this->data = val;
        this->next = nullptr;
        counter += 1;
    }
};
int Node::counter = 0;

class singlyLinkedList{
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

    void deleteDup(){
        Node* curr = head;
        // while(curr->next != nullptr){
        //     if(curr->data == curr->next->data){
        //         Node* temp = curr->next;
        //         curr->next = temp->next;
        //         delete temp;
        //     }else{
        //         curr = curr->next;
        //     }
        // }

        while(curr != nullptr){
            while(curr->next && curr->data == curr->next->data){
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            curr = curr->next;  
        }
    }


    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* getHead(){
        return head;
    }
};

void displayInRev(Node* head){
        if (head == nullptr) return;    
        displayInRev(head->next);
        cout << head->data << "->";
    }


int main(){
    singlyLinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(3);
    l1.insertAtEnd(3);

    l1.display();

    l1.deleteDup();
    l1.display();



    displayInRev(l1.getHead());
    cout << "NULL" << endl;
}