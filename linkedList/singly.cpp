#include<iostream>
using namespace std;

// insertion:
 //after data



// deletion:
// by value, and even everyy values same in ll will get delted or changed


// search



class Node{
 public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = nullptr;
    }

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
 public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = tail = nullptr;
    }


    



    // //only if the value is not the head node neither the tail node, you have to write specific conditions for both head and tail
	// void deletebyvalue(int value){
	// 	node *curr=head;
	// 	node *prev=head;
	// 	while(curr->next!=NULL && curr->data!=value ){
	// 		prev=curr;
	// 		curr=curr->next;
	// 	}
	// 	prev->next=curr->next;
	// 	delete curr;
	// }

    int search(int val){ // O(n)
        bool isfound = false;
        int idx = 0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == val){
                isfound = true;
                cout << "Its founded: ";
                cout << temp->data << " at index " << idx; 
                // return idx;
            }
            temp = temp->next;
            idx++;
        }
        if(isfound == false) cout << "Its Not founded!";
        
    }


    void concatenate(LinkedList &other){

        if(other.head == nullptr){
            return;
        }
        if(head == nullptr){
            head = other.head;
            tail = other.tail;
        }else{
            tail->next = other.head;
            tail = other.tail;
        }

        other.head = other.tail = nullptr;
    }




    

    bool detectCycle(){
        Node* slow = head;
        Node* fast = head;
        bool isCycle;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;
        Node* prev = nullptr;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = nullptr;

        return false;
    }



};



