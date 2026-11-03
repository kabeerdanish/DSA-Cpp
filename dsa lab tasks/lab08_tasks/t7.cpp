#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    vector<int> h;

public:
    void heapifyUp(int i){
        while(i > 0){
            int p = (i-1)/2;

            if(h[i] < h[p]){
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
            int s = i;

            if(l < n && h[l] < h[s])
                s = l;

            if(r < n && h[r] < h[s])
                s = r;

            if(s == i) break;

            swap(h[i], h[s]);
            i = s;
        }
    }

    int extractMin(){
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
    MinHeap h;

    h.insert(35);
    h.insert(12);
    h.insert(25);
    h.insert(8);
    h.insert(40);
    h.insert(5);

    cout << "Min Heap: ";
    h.display();

    cout << "Removed: " << h.extractMin() << endl;

    cout << "Updated Heap: ";
    h.display();

    return 0;
}