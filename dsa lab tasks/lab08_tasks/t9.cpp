#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Request{
    string id;
    int priority;
    int order;
};

class PriorityQueue{
    vector<Request> h;
    int cnt = 0;

    bool better(Request a, Request b){
        if(a.priority == b.priority)
            return a.order < b.order;

        return a.priority < b.priority;
    }

    void heapifyUp(int i){
        while(i > 0){
            int p = (i-1)/2;

            if(better(h[i], h[p])){
                swap(h[i], h[p]);
                i = p;
            }
            else{
                break;
            }
        }
    }

    void heapifyDown(int i){
        int n = h.size();

        while(true){
            int l = 2*i+1;
            int r = 2*i+2;
            int s = i;

            if(l < n && better(h[l], h[s]))
                s = l;

            if(r < n && better(h[r], h[s]))
                s = r;

            if(s == i) break;

            swap(h[i], h[s]);
            i = s;
        }
    }

public:
    void insert(string id, int p){
        Request x;
        x.id = id;
        x.priority = p;
        x.order = cnt++;

        h.push_back(x);
        heapifyUp(h.size()-1);
    }

    void remove(){
        if(h.empty()){
            cout << "Queue is empty\n";
            return;
        }

        cout << "Processed: " << h[0].id
             << " Priority: " << h[0].priority << endl;

        h[0] = h.back();
        h.pop_back();

        if(!h.empty())
            heapifyDown(0);
    }

    void peek(){
        if(h.empty()){
            cout << "Queue is empty\n";
            return;
        }

        cout << "Next Request: " << h[0].id
             << " Priority: " << h[0].priority << endl;
    }

    void display(){
        for(int i = 0; i < h.size(); i++){
            cout << h[i].id << "(" << h[i].priority << ") ";
        }

        cout << endl;
    }
};

int main(){
    PriorityQueue q;

    q.insert("R1", 3);
    q.insert("R2", 1);
    q.insert("R3", 4);
    q.insert("R4", 2);
    q.insert("R5", 1);
    q.insert("R6", 5);

    cout << "Emergency Queue:\n";
    q.display();

    q.peek();

    q.remove();

    cout << "Updated Queue:\n";
    q.display();

    q.peek();

    return 0;
}