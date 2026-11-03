#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* create(char x){
    Node* n = new Node;
    n->data = x;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void preorder(Node* root){
    if(root == nullptr) return;

    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == nullptr) return;

    if(root->left != nullptr) cout << "(";

    inorder(root->left);
    cout << root->data;
    inorder(root->right);

    if(root->right != nullptr) cout << ")";
}

void postorder(Node* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main(){
    Node* root = create('*');

    root->left = create('+');
    root->right = create('-');

    root->left->left = create('A');
    root->left->right = create('B');

    root->right->left = create('C');
    root->right->right = create('D');

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}