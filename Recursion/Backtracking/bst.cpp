#include<iostream>
#include<stack>
#include <queue>
#include <algorithm>
using namespace std;

// A tree is a non-linear data structure made up of nodes connected through edges.
// A binary tree is a tree in which each node can have at most two children:
// 1. Left child.
// 2. Right child.

// full binary tree
// Every node has either zero children or exactly two children.

// complete binary tree
// All levels are completely filled except possibly the last level, and the last level is filled from left to right.

// perfect binary tree
// Every internal node has exactly two children, and all leaves are at the same level.

// Skewed binary tree
// Every node has only one child, producing a chain.

// Balanced binary tree
// A balanced tree keeps its height relatively small compared with its number of nodes.

// A binary tree only restricts the number of children.
// A Binary Search Tree adds an ordering rule.

// For every node:
// - Every value in its left subtree must be smaller.
// - Every value in its right subtree must be greater.
// - Both subtrees must themselves satisfy the BST property


// 2. Do they have different codes?
// YES! Some code structures are shared, but their operations are different.
// Operation	Binary Tree	BST
// Node structure	Same	Same
// Insert	General placement rules	Based on value
// Search	Usually traverse nodes	Compare and go left/right
// Minimum	Traverse to find smallest	Keep going left
// Maximum	Traverse to find largest	Keep going right
// Delete	General tree logic	BST-specific cases
// Inorder	Left, Root, Right	Produces sorted order
// Preorder	Same	Same
// Postorder	Same	Same
// Height	Same concept	Same concept













class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node* insertion(Node* root, int val){
    if(root == nullptr) return new Node(val);
    if(val < root->data) root->left = insertion(root->left, val);
    else if(val > root->data) root->right = insertion(root->right, val);
    return root;
}

bool search(Node* root, int key){
    if(root == nullptr) return false;
    if(root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    if(key > root->data)  return search(root->right, key);
}

Node* findMin(Node* root){
    if(root == nullptr) return nullptr;
    if(root->left == nullptr) return root;
    return findMin(root->left);
}

Node* findMax(Node* root){
    if(root == nullptr) return nullptr;
    if(root->right == nullptr) return root;
    return findMax(root->right);
}

Node* findPredecessor(Node* root){
    if(root == nullptr || root->left == nullptr) return nullptr;
    return findMax(root->left);
}

Node* findSuccessor(Node* root){
    if(root == nullptr || root->right == nullptr) return nullptr;
    return findMin(root->right);
}

// Finding successor when right subtree doesn't exist:
// Move upward through ancestors until you find an ancestor for which the target node lies in its left subtree.


// Node* successor(Node* node)
// {
//     if(node == nullptr)
//         return nullptr;

//     if(node->right != nullptr)
//         return findMin(node->right);

//     Node* parent = node->parent;

//     while(parent != nullptr && node == parent->right)
//     {
//         node = parent;
//         parent = parent->parent;
//     }

//     return parent;
// }


// Node* predecessor(Node* node)
// {
//     if(node == nullptr)
//         return nullptr;

//     if(node->left != nullptr)
//         return findMax(node->left);

//     Node* parent = node->parent;

//     while(parent != nullptr && node == parent->left)
//     {
//         node = parent;
//         parent = parent->parent;
//     }

//     return parent;
// }

Node* predecessor(Node* root, int key)
{
    if(root == nullptr)
        return nullptr;

    if(key > root->data)
    {
        Node* ans = predecessor(root->right, key);

        if(ans != nullptr)
            return ans;

        return root;  // Backtracking: current ancestor
    }

    else if(key < root->data)
    {
        return predecessor(root->left, key);
    }

    else
    {
        if(root->left != nullptr)
            return findMax(root->left);

        return nullptr;
    }
}

Node* successorByParents(Node* root, int key){
    if(root == nullptr) return nullptr;
    
    if(key < root->data){
        Node* ans = successorByParents(root->left, key);
        if(ans != nullptr) return ans;
        return root;
    } else if(key > root->data) return successorByParents(root->right, key);
    else{
        if(root->right != nullptr) return findMin(root->right);
        return nullptr;
    }


}




    //       10
    //      /  \
    //     5    20
    //    / \     \
    //   3   7     30

// traversals

// 4 2 5 1 6 3 7
// 1 2 4 5 3 6 7
// 4 5 2 6 7 3 1


// inorder-> left->root->right

void inorder(Node* root){ // recursive
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Logic:
// 1. Keep moving left and push every node onto the stack.
// 2. When you reach NULL, pop the top node.
// 3. Print it.
// 4. Move to its right child.
// 5. Repeat until both the current pointer and stack are empty.

void inOrder(Node* root){ // iteratively
    stack<Node*> s;
    Node* curr = root;
    while(curr !=nullptr || !s.empty()){
        while(curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}


// preorder-> root->left->right
void preorder(Node* root){ // recursively
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Logic:
// 1. Push root onto stack.
// 2. While stack is not empty:
//    - Pop a node.
//    - Print it.
//    - Push its right child.
//    - Push its left child.

void preOrder(Node* root){ // iteratively
    if(root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if(curr->right != nullptr) s.push(curr->right);
        if(curr->left != nullptr) s.push(curr->left);
    }
}



// postorder-> left->right->root
void postorder(Node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}


// Logic
// 1. Push root into stack 1.
// 2. Pop a node from stack 1.
// 3. Push it into stack 2.
// 4. Push its left and right children into stack 1.
// 5. When stack 1 becomes empty, pop and print stack 2

void postorder(Node* root) // iteratively
{
    if(root == nullptr)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node* curr = s1.top();
        s1.pop();

        s2.push(curr);

        if(curr->left != nullptr)
            s1.push(curr->left);

        if(curr->right != nullptr)
            s1.push(curr->right);
    }

    while(!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}




// level order traversal(bfs) using queue

void levelOrder(Node* root)
{
    if(root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != nullptr)
            q.push(curr->left);

        if(curr->right != nullptr)
            q.push(curr->right);
    }
}

void printLevels(Node* root)
{
    if(root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    int level = 0;

    while(!q.empty())
    {
        int size = q.size();

        cout << "Level " << level << ": ";

        for(int i = 0; i < size; i++)
        {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if(curr->left != nullptr)
                q.push(curr->left);

            if(curr->right != nullptr)
                q.push(curr->right);
        }

        cout << endl;
        level++;
    }
}

// Recursive height function
// The logic is simple:
// 1. If the tree is empty, return -1.
// 2. Find the height of the left subtree.
// 3. Find the height of the right subtree.
// 4. Return the greater height plus 1.


int height(Node* root)
{
    if(root == nullptr)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int height(Node* root)
{
    if(root == nullptr)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}


// delete leafNodes
Node* deleteNode(Node* root, int key){
    if (root == nullptr) return nullptr;
    if(key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
    }

    return root;
}

// delete node has exactly one child
// node has only a left child or right child

Node* deleteNode(Node* root, int key) {

    if (root == nullptr)
        return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {

        // Case 1 and Case 2

        if (root->left == nullptr) {
            Node* child = root->right;
            delete root;
            return child;
        }

        if (root->right == nullptr) {
            Node* child = root->left;
            delete root;
            return child;
        }
    }

    return root;
}

// delete node has exactly two childerns


int main(){
    Node* root;
    root = insertion(root, 50);
    root = insertion(root, 30);
}