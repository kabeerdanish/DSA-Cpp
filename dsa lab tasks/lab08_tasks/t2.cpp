#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(int x){
    Node* n = new Node;
    n->data = x;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void preorder(Node* root){
    if(root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = create(15);
    root->left = create(8);
    root->right = create(25);
    root->left->left = create(4);
    root->left->right = create(12);
    root->right->right = create(30);

    cout << "Preorder: ";
    preorder(root);

    return 0;
}