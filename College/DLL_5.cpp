//Delete Kth Element of Doubly Linked List

#include <iostream>
using namespace std;

class Node {


    public:
    Node *next;
    int data;
    Node *prev;
    Node(int value);
    int getdata();
    void setdata(int value);
    Node* getnext();
    void setnext(Node* nextNode);
    Node* getprev();
    void setprev(Node* prevNode);
};

Node::Node(int value){
    data=value;
    next=nullptr;
    prev=nullptr;
}

int Node::getdata(){
    return data;
}

void Node::setdata(int value){
    data=value;
}

Node* Node::getnext(){
    return next;
}

void Node::setnext(Node* nextNode){
    next=nextNode;
}

Node* Node::getprev(){
    return prev;
}

void Node::setprev(Node* prevNode){
    prev=prevNode;
}

int main(){
    Node *head = new Node(10);
    cout << head->getdata() << endl;
    Node *newNode = new Node(20);
    head->setnext(newNode);
    newNode->setprev(head);
    cout << newNode->getdata() << endl;
    Node *nextNode = new Node(30);
    newNode->setnext(nextNode);
    nextNode->setprev(newNode);
    cout << nextNode->getdata() << endl;

    // Delete the Kth element
    int k;
    cout << "Enter the position of the element to delete: ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid position." << endl;
        return 0;
    }

    Node* current = head;
    for (int i = 1; i < k && current != nullptr; i++) {
        current = current->getnext();
    }

    if (current == nullptr) {
        cout << "Position exceeds the length of the list." << endl;
        return 0;
    }

    if (current->getprev() != nullptr) {
        current->getprev()->setnext(current->getnext());
    } else {
        head = current->getnext(); // Update head if first node is deleted
    }

    if (current->getnext() != nullptr) {
        current->getnext()->setprev(current->getprev());
    }

    delete current; // Free memory

    // Traversing the list after deletion

    cout << "List after deletion:" << endl;
    current = head;
    while (current != nullptr) {
        cout << current->getdata() << " ";
        current = current->getnext();
    }

    return 0;
}
