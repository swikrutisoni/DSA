#include<iostream>
using namespace std;

class SLL{
    int data;
    SLL *next;
public:
    SLL(int value);
    int getData();
    void setData(int value);
    SLL* getNext();
    void setNext(SLL *nextNode);
};

SLL::SLL(int value){
    data = value;
    next = nullptr;
}

int SLL::getData(){
    return data;
}

void SLL::setData(int value){
    cout << "Setting data to: " << value << endl;
    data = value;
}

SLL* SLL::getNext(){
    return next;
}

void SLL::setNext(SLL *nextNode){
    cout << "Setting next node." << endl;
    next = nextNode;
}

int main(){
    SLL *head = new SLL(10);
    cout << "Head data: " << head->getData() << endl;
    SLL *newNode = new SLL(20);
    head->setNext(newNode);
    cout << "New node data: " << newNode->getData() << endl;
    SLL *nextNode = new SLL(30);
    newNode->setNext(nextNode);
    cout << "Next node data: " << nextNode->getData() << endl;
    return 0;
}

