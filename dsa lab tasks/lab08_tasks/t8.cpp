#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    vector<int> h;

public:
    void heapifyUp(int i){
        while(i > 0){
            int p = (i-1)/2;

            if(h[i] > h[p]){
                swap(h[i], h[p]);
                i = p;
            }
            else{
                break;
            }
        }
    }

    void insert(int x){
        h.push_back(x);
        heapifyUp(h.size()-1);
    }

    void heapifyDown(int i){
        int n = h.size();

        while(true){
            int l = 2*i+1;
            int r = 2*i+2;
            int b = i;

            if(l < n && h[l] > h[b])
                b = l;

            if(r < n && h[r] > h[b])
                b = r;

            if(b == i) break;

            swap(h[i], h[b]);
            i = b;
        }
    }

    int extractMax(){
        if(h.empty()) return -1;

        int x = h[0];
        h[0] = h.back();
        h.pop_back();

        if(!h.empty())
            heapifyDown(0);

        return x;
    }

    void display(){
        for(int x : h)
            cout << x << " ";

        cout << endl;
    }
};

int main(){
    MaxHeap h;

    h.insert(40);
    h.insert(15);
    h.insert(30);
    h.insert(50);
    h.insert(10);
    h.insert(60);

    cout << "Max Heap: ";
    h.display();

    cout << "Removed: " << h.extractMax() << endl;

    cout << "Updated Heap: ";
    h.display();

    return 0;
}