#include <iostream>
using namespace std;

class CompleteBinaryTree{
    int arr[100];
    int count;

public:
    CompleteBinaryTree(){
        count = 0;
    }

    void insert(int x){
        arr[count] = x;
        count++;
    }

    void preorder(int i){
        if(i >= count) return;

        cout << arr[i] << " ";
        preorder(2*i + 1);
        preorder(2*i + 2);
    }

    void inorder(int i){
        if(i >= count) return;

        inorder(2*i + 1);
        cout << arr[i] << " ";
        inorder(2*i + 2);
    }

    void postorder(int i){
        if(i >= count) return;

        postorder(2*i + 1);
        postorder(2*i + 2);
        cout << arr[i] << " ";
    }
};

int main(){
    CompleteBinaryTree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);

    cout << "Preorder: ";
    t.preorder(0);

    cout << "\nInorder: ";
    t.inorder(0);

    cout << "\nPostorder: ";
    t.postorder(0);

    return 0;
}