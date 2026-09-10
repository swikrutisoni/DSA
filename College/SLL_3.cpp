//insertion of node at the end of the linked list

#include <iostream>
using namespace std;

class Node {
    int data;
    Node *next;
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
    data = value;
}

Node* Node::getnext() {
    return next;
}

void Node::setnext(Node* nextNode) {
    next = nextNode;
}

int main() {
    Node *head = new Node(10);
    cout << head->getdata() << endl;
    Node *newNode = new Node(20);
    head->setnext(newNode);
    cout << newNode->getdata() << endl;
    Node *nextNode = new Node(30);
    newNode->setnext(nextNode);
    cout << nextNode->getdata() << endl;
    Node *thirdNode = new Node(25);
    nextNode->setnext(thirdNode);
    cout << thirdNode->getdata() << endl;
    Node *fourthNode = new Node(40);
    thirdNode->setnext(fourthNode);
    cout << fourthNode->getdata() << endl;

    Node *fifthNode = new Node(50);
    
    Node *current = head;
   while (current->getnext() != nullptr) {
    current = current->getnext();
}

    current->setnext(fifthNode);
    cout << fifthNode->getdata() << endl;
    return 0;
}