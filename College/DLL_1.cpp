// deletion in DLL
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value);
    int getdata();
    void setdata(int value);
    Node* getnext();
    void setnext(Node* nextNode);
    Node* getprev();
    void setprev(Node* prevNode);
};

Node::Node(int value){
    data = value;
    next = nullptr;
    prev = nullptr;
}
int Node::getdata(){
    return data;
}
void Node::setdata(int value){
    data = value;
}
Node* Node::getnext(){
    return next;
}
void Node::setnext(Node* nextNode){
   
    next = nextNode;
}
Node* Node::getprev(){
    return prev;
}
void Node::setprev(Node* prevNode){
    prev = prevNode;
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
    Node *thirdNode = new Node(25);
    nextNode->setnext(thirdNode);
    thirdNode->setprev(nextNode);
    cout << thirdNode->getdata() << endl;
    Node *fourthNode = new Node(40);
    thirdNode->setnext(fourthNode);
    fourthNode->setprev(thirdNode);
    cout << fourthNode->getdata() << endl;

    cout << "Deleting the third node (25)" << endl;
    Node* nodeToDelete = thirdNode;
    if (nodeToDelete->getprev() != nullptr) {
        nodeToDelete->getprev()->setnext(nodeToDelete->getnext());
    }

    if (nodeToDelete->getnext() != nullptr) {
        nodeToDelete->getnext()->setprev(nodeToDelete->getprev());
    }

    delete nodeToDelete;

    // Traversing the list after deletion
    cout << "List after deletion:" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->getdata() << endl;
        current = current->getnext();
    }

    return 0;
}