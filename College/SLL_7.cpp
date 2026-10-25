
#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int value);
    int getdata();
    void setdata(int value);
    Node* getnext();
    void setnext(Node* nextNode);
};

Node::Node(int value) {
    data = value;
    next = nullptr;
}

int Node::getdata() {
    return data;
}

void Node::setdata(int value) {
    cout << "Setting data to: " << value << endl;
    data = value;
}

Node* Node::getnext() {
    return next;
}

void Node::setnext(Node* nextNode) {
    next = nextNode;
}

// Display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->getdata() << " -> ";
        temp = temp->getnext();
    }

    cout << "nullptr" << endl;
}

// Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->getnext();
        current->setnext(prev);

        prev = current;
        current = nextNode;
    }

    return prev;
}

int main() {
    Node* head = new Node(10);

    Node* newNode = new Node(20);
    head->setnext(newNode);

    Node* nextNode = new Node(30);
    newNode->setnext(nextNode);

    Node* thirdNode = new Node(25);
    nextNode->setnext(thirdNode);

    Node* fourthNode = new Node(40);
    thirdNode->setnext(fourthNode);

    Node* fifthNode = new Node(50);
    fourthNode->setnext(fifthNode);

    cout << "Original list: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    display(head);

    return 0;
}
