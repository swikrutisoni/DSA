//deletion of head from te end of linked list

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

    /*Store the last node in temp.
Make second-last's next = NULL.
Delete temp.*/

  Node *current = head;
    while(current->getnext()->getnext() != nullptr){
            current = current->getnext();
        }
        Node* temp = current->getnext();
        current->setnext(nullptr);
        delete temp;

        cout << "list after deletion: ";

Node* current2 = head;

while (current2 != nullptr) {
    cout << current2->getdata() << " ";
    current2 = current2->getnext();
}
    return 0;
}