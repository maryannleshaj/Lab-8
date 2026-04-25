#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int id;
    string name;
    ListNode* next;
};

class NodeList {
private:
    ListNode* head;
    int count;

public:
    NodeList() : head(nullptr), count(0) {}

    //add node to the END of list
    void addNode(int id, string name) {
        ListNode* newNode = new ListNode{id, name, nullptr};
        if (!head) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }
    //Remove node by ID
    void removeNode(int id) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return; //ID not found

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp; // manual memory cleanup
        count--;
    }

    void display() const {
        ListNode* temp = head;
        while (temp) {
            cout << "[" << temp->id << ": " << temp->name << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    //The Destructor - CRITICAL for Manual Memory
    ~NodeList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current; // clean up each node
            current = nextNode;
        }
        head = nullptr;
    }
};

int main() {
    NodeList myNodes;
    myNodes.addNode(1, "Router-A");
    myNodes.addNode(2, "Switch-B");
    myNodes.display();

    myNodes.removeNode(1);
    cout << "After removing ID 1: " << endl;
    myNodes.display();

    return 0;
}

