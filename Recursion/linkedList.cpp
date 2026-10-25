#include<iostream>
using namespace std;


// Level 1 — Basic recursion
// Start here
// [ ] 1. Display all nodes from head to tail
// [ ] 2. Display all nodes in reverse order
// [ ] 3. Count the total number of nodes
// [ ] 4. Find the sum of all node values
// [ ] 5. Search for a given value




// Level 2 — Return values
// [ ] 6. Find the maximum element
// [ ] 7. Find the minimum element
// [ ] 8. Find the value at index k
// [ ] 9. Count occurrences of a given value
// [ ] 10. Check whether the list is sorted




// Level 3 — Pointer manipulation
// [ ] 11. Insert a node at the end recursively
// [ ] 12. Delete the first occurrence of a value
// [ ] 13. Reverse the linked list recursively
// [ ] 14. Remove all occurrences of a value
// [ ] 15. Check whether a linked list is a palindrome

// // Try to solve these recursively. Avoid loops unless a problem explicitly allows them.

// 1. display(head) — print all nodes from first to last.
// 2. displayReverse(head) — print the list from last to first.
// 3. countNodes(head) — return the number of nodes.
// 4. sumNodes(head) — return the sum of all node values.
// 5. maxNode(head) — return the maximum value in the list.

// Recursion Practice: Linked Lists — Continued

// Recursion • Activation Records • Fibonacci

// 6. search(head, key) — recursively determine whether key exists.
// 7. countOccurrences(head, key) — count how many times key occurs.
// 8. getNode(head, index) — return the node/value at a given index.
// 9. reverseDisplay(head) — print nodes in reverse order without changing links.
// 10. isSorted(head) — recursively check whether the list is non-decreasing.

// More Challenging Linked-List Recursion

// Recursion • Activation Records • Fibonacci

// 11. removeAll(head, key) — recursively remove every occurrence of key.
// 12. insertSorted(head, key) — recursively insert a value into a sorted list.
// 13. compareLists(a, b) — recursively check whether two lists are identical.
// 14. isPalindrome(head) — recursively determine whether the list reads the same
// forward/backward.

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

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

int countNodes(Node* head){
    // if (head == nullptr) return n;
    // return countNodes(head->next, n+1);

    if (head == nullptr) return 0;
    return 1 + countNodes(head->next);
}

int sumNodes(Node* head){
    if(head == nullptr) return 0;
    return head->data + sumNodes(head->next);
}

bool search(Node* head, int key){
    if (head == nullptr) return false;
    if (head->data == key) return true;
    else return search(head->next, key);
}

int findMax(Node* head){
    if (head->next == nullptr) return head->data;
    int maxRest = findMax(head->next);
    if(maxRest >= head->data) return maxRest;
    else return head->data;
}

Node* reverse(Node* head){
    if (head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;

}

void display(Node* head){ // linked list recursive display
    if (head == nullptr) return;
    cout << head->data << "->";
    display(head->next);
    // cout << head->data << "->";
}


int main(){
    Node *head = new Node(5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);
    display(head);
    cout << "NULL" << endl;
    cout << countNodes(head) << endl;
    cout << sumNodes(head) << endl;
    cout << findMax(head) << endl;
    Node *newH = reverse(head);
    display(newH) ;
    cout << "NULL" << endl;

    
}