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


// [ ] 1. Display all nodes from head to tail
// 1. display(head) — print all nodes from first to last.
// [ ] 2. Display all nodes in reverse order

void display(Node* head){ // linked list recursive display
    if (head == nullptr) return;
    cout << head->data << "->";
    display(head->next);
    // cout << head->data << "->"; // (2)
}



// [ ] 3. Count the total number of nodes
// 3. countNodes(head) — return the number of nodes.

int countNodes(Node* head){
    // if (head == nullptr) return n;
    // return countNodes(head->next, n+1);

    if (head == nullptr) return 0;
    return 1 + countNodes(head->next);
}


// [ ] 4. Find the sum of all node values
// 4. sumNodes(head) — return the sum of all node values.

int sumNodes(Node* head){
    if(head == nullptr) return 0;
    return head->data + sumNodes(head->next);
}



// [ ] 5. Search for a given value
// 6. search(head, key) — recursively determine whether key exists.



bool search(Node* head, int key){
    if (head == nullptr) return false;
    if (head->data == key) return true;
    else return search(head->next, key);
}


// [ ] 6. Find the maximum element
// 5. maxNode(head) — return the maximum value in the list.

int findMax(Node* head){
    if (head->next == nullptr) return head->data;
    int maxRest = findMax(head->next);
    if(maxRest >= head->data) return maxRest;
    else return head->data;
}


// [ ] 7. Find the minimum element // just change the comparsion condition in findmax


// 9. reverse(head) — print nodes in reverse order with changing links.
// [ ] 13. Reverse the linked list recursively


Node* reverse(Node* head){
    if (head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;

}


// [ ] 8. Find the value at index k
// 8. getNode(head, index) — return the node/value at a given index.

int getValueAtIndex(Node* head, int k ){  // k->idx
     if (head == nullptr || k < 0) return -1;
     if (k==0) return head->data;
     return getValueAtIndex(head->next, k-1);
}



// [ ] 9. Count occurrences of a given value
// 7. countOccurrences(head, key) — count how many times key occurs.

int countOccurrences(Node* head, int key){
    if (head == nullptr) return 0;
    if (head->data == key) return 1 + countOccurrences(head->next, key);
    return countOccurrences(head->next, key);

    // int count = 0;
    // if(head->data == key) count = 1;
    // return count + countOccurrences(head->next, key);
}



// [ ] 10. Check whether the list is sorted
// 10. isSorted(head) — recursively check whether the list is non-decreasing.

bool isSorted(Node* head){
    if (head == nullptr || head->next == nullptr) return true;
    if(head->data <= head->next->data) return isSorted(head->next);
    return false;
}


// [ ] 12. Delete the first occurrence of a value

Node* deleteFirstOccurence(Node* head, int key){
    if (head == nullptr) return head;
    if(head->data == key){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    head->next = deleteFirstOccurence(head->next, key);
    return head;
}





// [ ] 14. Remove all occurrences of a value
// 11. removeAll(head, key) — recursively remove every occurrence of key.







// [ ] 11. Insert a node at the end recursively


// [ ] 15. Check whether a linked list is a palindrome
// 14. isPalindrome(head) — recursively determine whether the list reads the same
// forward/backward.



// 12. insertSorted(head, key) — recursively insert a value into a sorted list.



// 13. compareLists(a, b) — recursively check whether two lists are identical.



void insertAtEnd(Node* head, int val){
    Node *newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
        return;
    } 
    Node *temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}




int main(){
    Node *head = new Node(5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 5);
    insertAtEnd(head, 8);
    insertAtEnd(head, 5);
    display(head);
    cout << "NULL" << endl;
    cout << countNodes(head) << endl;
    cout << sumNodes(head) << endl;
    cout << findMax(head) << endl;
    head = reverse(head);
    display(head) ;
    cout << "NULL" << endl;
    int k = 0;
    while(k < 5){
    cout << getValueAtIndex(head, k) << " ";
    k++;
    }
    cout << endl;
    cout << countOccurrences(head, 5) << endl;
}