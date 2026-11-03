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

void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = create(35);
    root->left = create(18);
    root->right = create(55);
    root->left->left = create(10);
    root->left->right = create(25);
    root->right->left = create(45);
    root->right->right = create(65);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}