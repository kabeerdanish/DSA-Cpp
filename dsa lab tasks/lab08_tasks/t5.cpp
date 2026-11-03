#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(){
    int x;

    cout << "Enter value (-1 for no node): ";
    cin >> x;

    if(x == -1) return nullptr;

    Node* n = new Node;
    n->data = x;

    cout << "Left child of " << x << endl;
    n->left = create();

    cout << "Right child of " << x << endl;
    n->right = create();

    return n;
}

void preorder(Node* root){
    if(root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    cout << "Create Binary Tree\n";

    Node* root = create();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}