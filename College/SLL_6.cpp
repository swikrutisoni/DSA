// deletion of node from middle of SLL

#include<iostream>
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

Node::Node(int value){
    data=value;
    next=nullptr;
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
int main(){
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

    Node *fast = head;
    Node *slow = head;
    Node* current; 

while(fast != nullptr && fast->getnext() != nullptr) {
        slow = slow->getnext();              // 1 step
        fast = fast->getnext()->getnext();   // 2 steps
    }
    cout << "Middle node data: " << slow->getdata() << endl;
    cout << "Node before middle node: " << current->getdata();

    return 0;
}
    