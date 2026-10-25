
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Editor {
    stack<string> undoSt, redoSt;
    string doc;

public:
    void type(string word) {
        undoSt.push(word);
        redoSt = stack<string>();
        if (doc != "")
            doc += " ";
        doc += word;
        print();
    }

    void undo() {
        if (undoSt.empty()) {
            cout << "Nothing to undo\n";
            print();
            return;
        }

        string word = undoSt.top();
        undoSt.pop();
        redoSt.push(word);

        if (doc.size() == word.size())
            doc = "";
        else
            doc.erase(doc.size() - word.size() - 1);

        print();
    }

    void redo() {
        if (redoSt.empty()) {
            cout << "Nothing to redo\n";
            print();
            return;
        }

        string word = redoSt.top();
        redoSt.pop();
        undoSt.push(word);

        if (doc != "")
            doc += " ";
        doc += word;

        print();
    }

    void print() {
        cout << "Document: " << doc << endl;
    }
};

int main() {
    Editor e;

    e.type("Hello");
    e.type("World");
    e.undo();
    e.redo();
    e.undo();
    e.type("There");
    e.redo();

    return 0;
}
