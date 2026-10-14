// Question #03
//
// Pakistan is playing a crucial World Cup match. To manage the batting rotation,
// the coach maintains the players in a Circular Singly Linked List, where each
// node contains the name of a Pakistani player. Since the list is circular,
// after the last player, the turn goes back to the first player.
//
// Starting from the head, the coach decides to remove every 3rd player from
// the batting rotation. After a player is removed, counting continues from
// the next remaining player.
//
// The process continues until only one player remains. The remaining player
// is the winner/survivor.
//
// Tasks:
// 1. Create a Circular Singly Linked List containing the names of the players.
// 2. Take player names as input from the user (at least 11 players).
// 3. Implement the required basic linked list functions for insertion and display.
// 4. Implement a separate function removePlayers() that removes every 3rd player.
// 5. After each deletion, counting should continue from the next remaining player.
// 6. Continue the process until only one player remains.
// 7. Display the name of the player who survives till the end.
//
// Example:
//
// Batting Rotation:
// Babar Azam → M.Rizwan → Fakhar Zaman → Shaheen Afridi → Haris Rauf
// → Naseem Shah → back to Babar Azam
//
// Starting from Babar Azam, every 3rd player is removed.
//
// Elimination order:
// Fakhar Zaman → Naseem Shah → Shaheen Afridi → M. Rizwan → Haris Rauf
//
// Final player:
// Babar Azam
//
// Important:
// The list must remain circular after every deletion.
// The last node should always point back to the head.
// Do not allow the list to become a normal singly linked list after deletion.

#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    string name;
    Node(string n){
        name = n;
        next = nullptr;
    }
};
class CLL{
    private:
    Node* head;
    public:
    CLL(){
        head = nullptr;
    }
    void pushBack(string n){
        Node* newNode = new Node(n);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        
    }
    void pushFront(string n){
        Node* newNode = new Node(n);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;

    }
    void deletePlayer(){
        Node* temp = head;
        Node* curr = nullptr;
        temp = head->next;
        curr = head->next->next;
        
        temp->next = curr->next;
        delete curr;

        head = temp->next;
       
       

    }
    string remainingPlayer(){
        if(head == nullptr)
        return "";

        // if(head->next == head)
        // return head->name;

        while(head->next->next != head){
             deletePlayer();
            
        }
         Node* temp = head;
         head = head->next;
         temp->next = nullptr;
         delete temp;
         head->next = head;
         return head->name;
        
        
    }
    void display(){
        Node* temp = head;
        if(temp == nullptr){
            cout<<"CLL is empty"<<endl;
            return;
        }
        cout<<temp->name<<"->";
        temp = temp->next;
        while(temp != head){
         cout<<temp->name<<"->";
          temp = temp->next;
        }
        cout<<head->name;
    }
};
int main(){
    CLL l;
  int n=0;
    cout<<"Enter the number of nodes you want to enter:";
    cin>>n;
    for(int i=0;i<n;i++){
        string input="0";
        cout<<"Enter "<<i+1<<" Node Value :";
        cin>>input;
         l.pushBack(input);
    }
    l.display();
    cout<<endl;
    cout<<l.remainingPlayer();
    
    
    return 0;
}