#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct SmartListNode {
    int id;
    string name;
    unique_ptr<SmartListNode> next; //no raw pointers
};

class SmartNodeList {
private:
    unique_ptr<SmartListNode> head;
    int count;

public:
    SmartNodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        auto newNode = make_unique<SmartListNode>();
        newNode->id = id;
        newNode->name = name;
        newNode->next = nullptr;

        if (!head) {
            head = move(newNode); 
        } else {
            SmartListNode* temp = head.get();
            while (temp->next) {
                temp = temp->next.get();
            }
            temp->next = move(newNode);
        }
        count++;
    }

    void display() const {
        SmartListNode* temp = head.get();
        while (temp) {
            cout << "[" << temp->id << ": " << temp->name << "] ->";
            temp = temp->next.get();
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SmartNodeList myNodes;
    myNodes.addNode(1, "Router-A");
    myNodes.addNode(2, "Switch-B");

    cout << "Smart Pointer List:" << endl;
    myNodes.display();

    return 0;
}