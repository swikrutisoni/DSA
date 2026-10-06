//insert in dll

#include<iostream>
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
    Node *thirdNode = new Node(25);
    nextNode->setnext(thirdNode);
    thirdNode->setprev(nextNode);
    cout << thirdNode->getdata() << endl;
    Node *fourthNode = new Node(40);
    thirdNode->setnext(fourthNode);
    fourthNode->setprev(thirdNode);

    cout << "Inserting a new node with value 15 "<< endl;

    Node *insertNode = new Node(15);
    head->setnext(insertNode);
    insertNode->setprev(head);
    insertNode->setnext(newNode);
    newNode->setprev(insertNode);
    cout << insertNode->getdata() << endl;

    cout << "Traversing the list after insertion: " << endl;
    Node* current = head;
    while(current != nullptr){
        cout << current->getdata() << " ";
        current = current->getnext();
    }

    return 0;


}
