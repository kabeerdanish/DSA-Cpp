// circular node we can traverse from any node untill we reach visited node
#include<iostream>
using namespace std;

class Node{
    public:
    string playerName;
    Node* next;
    static int n;

    Node(string name){
        this->playerName = name;
        this->next = nullptr;
        n++;

    }


};
int Node :: n = 0;

class CircularLL{
    Node* head;

    public:
    CircularLL(){
        head = nullptr;
    }
    
    void insertAtStart(string name){
        Node* newNode = new Node(name);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(string name){
        Node* newNode = new Node(name);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;

    }

    void deleteAtStart(){
        if(head == nullptr){
            cout << "Circular Linked list is empty!"<< endl;
            return;
        }
        Node* temp = head;
        Node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }

        if(curr == head){
            delete temp,curr;
            head = nullptr;
            return;
        }

        head = head->next;
        curr->next = head;
        delete temp;


    }

    void deleteATEnd(){
        if(head == nullptr){
            cout << "Circular Linked list is empty!"<< endl;
            return;
        }
        Node *temp = head;
        Node *curr = head;
        while(curr->next != head){
            temp = curr;
            curr = curr->next;
        }
        if(curr == head){
            delete curr,temp;
            head = nullptr;
        }
        temp->next = head;
        delete curr;
    }

    void removePlayers(){
        if(head == nullptr){
            cout << "Circular Linked list is empty!"<< endl;
            return;
        }

    
        Node* curr = head;
        Node* prev = head;

        while (prev->next != head) {
            prev = prev->next;
        }

        int count = 1;
        int n  = Node::n;
        

        while( n > 1){
            if(count < 3){
                prev = curr;
                curr = curr->next;
                count++;
            }else
            {

                // Save the next node before deleting curr
            Node* nextNode = curr->next;

            // If curr is head, move head forward
            if (curr == head) {
                head = nextNode;
            }

            // Skip curr in the circular list
            prev->next = nextNode;

            delete curr;
            curr = nextNode;

                n--;
                count = 1;
            }
        }

        
    }


    void display(){   
        Node* temp = head;
        if(temp == nullptr){
            cout << "Circular Linked list is empty!" << endl;
            return;
        }
        do{
        cout << temp->playerName << "->";
        temp = temp->next;
        }while(temp != head);

        cout << "Head" << endl;
    }
};

int main(){
    CircularLL l1;
    // string name;
    // cout << "Enter six players names:"<<endl;
    // for(int i=0; i<6; i++){
    //     cout << "Enter palyer " << i+1 << " name: ";
    //     cin >> name;
    //     l1.insertAtEnd(name);
    // }
    // l1.display();
    // l1.insertAtStart("Abdullah");
    // l1.display();
    // l1.insertAtStart("Kabeer");
    // l1.display();

    // l1.insertAtEnd("Hussain");
    // l1.display();
    // l1.insertAtEnd("Freshie");
    // l1.display();

    // l1.removePlayers();
    // l1.display();

    // l1.deleteAtStart();
    // l1.display();

    // l1.deleteATEnd();
    // l1.display();

    // l1.deleteATEnd();
    // l1.display();

    // l1.deleteAtStart();
    // l1.display();

l1.insertAtEnd("Babar Azam");
l1.insertAtEnd("Mohammad Rizwan");
l1.insertAtEnd("Fakhar Zaman");
l1.insertAtEnd("Shaheen Afridi");
l1.insertAtEnd("Haris Rauf");
l1.insertAtEnd("Naseem Shah");
l1.insertAtEnd("Shadab Khan");
l1.insertAtEnd("Iftikhar Ahmed");
l1.insertAtEnd("Imad Wasim");
l1.insertAtEnd("Mohammad Amir");
l1.insertAtEnd("Saim Ayub");
l1.insertAtEnd("Abdullah Shafique");
l1.insertAtEnd("Azam Khan");
l1.insertAtEnd("Usama Mir");
l1.insertAtEnd("Hasan Ali");

l1.removePlayers();

cout << "Survivor: " ;
l1.display(); 
cout << endl;

}