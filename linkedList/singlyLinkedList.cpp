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


    void insertAtHead(int val){
        Node* newNode = new Node(val);  // dynamic
        // Node newNode(val); static
        if(head == nullptr){
            head = newNode;
            return;
        }
        newNode->next = head; // (*newNode).next = head
        head = newNode;
    }

    void insertAtPosition(int position, int val){

        if(position < 1){
            cout << "Invalid Position" << endl;
            return;
        }

        if(position == 1){
            insertAtHead(val);
            return;
        }


        Node* temp = head;
        for(int i=1; i<position-1 && temp!= nullptr; i++){ // for after position use i<pos
            temp = temp->next;
        }

        if(temp == nullptr){
                cout << "Invalid Position" << endl;
                return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        
        // Node* newNode = new Node(val);
        // Node *curr, *prev;
        // curr = head;
        // for(int i=1; i<position; i++){
        //     prev = curr;
        //     curr = curr->next;
        // }
        // newNode->next = curr;
        // prev->next = newNode;

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

    void insertAfterData(int k , int val){

        Node* curr = head;
        while(curr != nullptr && curr->data != k){
            curr = curr->next;
        }
        if(curr = nullptr){
            cout << "Data not found" << endl;
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;


        // node *newnode= new node(data);
    	// node *curr=head;
    	// node *prev=head;
    	// while(curr->next!=NULL && curr->data!=existingdata){
    	// 	curr=prev;
    	// 	prev=prev->next;
		// }
		// curr->next=newnode;
		// newnode->next=prev;
    }

    void deleteAtStart(){
        if(head == nullptr){
            cout << "Linked list is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp; // free(temp)
    }

    void deleteAtPosition(int position){

        if(position < 1){
            cout << "Invalid Position" << endl;
            return;
        }

        if(position == 1){
            deleteAtStart();
            return;
        }

        Node* temp = head;
        for(int i=1; i<position-1 && temp!= nullptr; i++){
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid Position" << endl;
            return;
        }

        Node* ft = temp->next;
        temp->next = ft->next;
        delete ft;

        // Node* prev = nullptr;
        // Node* curr = head;
        // for(int i=1; i<position; i++){ // for after position i < p+1 or starts i with zero 
        //     prev = curr;
        //     curr = curr->next;
        // }
        // prev->next = curr->next;
        // curr->next = nullptr;
        // delete curr;
    }

    void deleteAtEnd(){
        if(head == nullptr){
            cout << "Linked list is empty!" << endl;
            return;
        }
        if (head->next == nullptr){
        	delete head;
        	head = nullptr;
        	return;
    	}

        Node* sl = head;
        Node* temp;
        while(sl->next->next != nullptr){
            sl = sl->next;
        }
        temp = sl->next;
        sl->next = nullptr;
        delete temp;
        
    }

    void deleteByData(int val){

        if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
        return;
        }

        if(head->data = val){
           Node* temp = head;
           head = head->next;
           delete temp;
           return;
        }
        
        Node *curr=head->next;
		Node *prev=head;
		while(curr !=NULL && curr->data!= val ){
			prev=curr;
			curr=curr->next;
		}
        if (curr == nullptr) {
            cout << "Data not found" << endl;
            return;
        }
		prev->next=curr->next;
		delete curr;
    }

    void deleteAlter(){
        if (head == nullptr){
            cout << "Linked List is empty!" << endl;
            return;
        }

        Node* curr = head;

        
        while(curr != nullptr && curr->next != nullptr ){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            curr = curr->next;

        }
    }


    void updateAtPosition(int position, int val){
        Node* temp = head;
        for(int i=1; i<position && temp != nullptr; i++){
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid Position" << endl;
            return;
        }
        temp->data = val;
    }

    void reverseList(){
        Node* curr;
        Node* prev;
        Node* Next;
        curr = head;
        prev = nullptr;
        while(curr != nullptr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        head->next = nullptr;
        head = prev;
    }

    int findMiddle(){
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return -1;
        }
        // using single pointer
        // int c = Node::counter;
        // Node* temp = head;
        // int n = c/2;
        // for(int i =0; i<n; i++){
        //         temp = temp->next;
        // }
        // if(c % 2 == 0) return temp->data;
        // else return temp->data;

        // using double pointer\

        Node *slow = head;
        Node *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
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
    l1.display();
    l1.insertAtHead(5);
    l1.display();
    l1.insertAtHead(4);
    l1.display();
    l1.insertAtHead(3);
    l1.display();

    l1.insertAtEnd(9);
    l1.display();
    l1.insertAtEnd(10);
    l1.display();
    l1.insertAtEnd(11);
    l1.display();

    l1.insertAtPosition(4,6);
    l1.display();
    l1.insertAtPosition(5,7);
    l1.display(); 
    l1.insertAtPosition(6,8);
    l1.display();

    // l1.insertAfterData(6,11);

    // l1.updateAtPosition(5,6);

    // l1.insertAtEnd(12);
    // l1.display();

    l1.deleteAlter();
    l1.display();

    l1.deleteAtStart();
    l1.display();
    l1.deleteAtStart();
    l1.display();

    l1.deleteAtEnd();
    l1.display();
    l1.deleteAtEnd();
    l1.display();

    l1.deleteAtPosition(4);
    l1.display();

    



    cout << l1.findMiddle() << endl;;



    l1.reverseList();
    l1.display();





    
    
}



