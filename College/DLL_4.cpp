#include<iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    void setnext(Node* n) {
        next = n;
    }

    void setprev(Node* p) {
        prev = p;
    }

    Node* getnext() {
        return next;
    }

    Node* getprev() {
        return prev;
    }

    int getdata() {
        return data;
    }
};

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

    cout<< "delition of tail:"<<endl;

    Node* temp = head;

while (temp->getnext() != nullptr) {
    temp = temp->getnext();
}

temp->getprev()->setnext(nullptr);
delete temp;

cout << "After deletion of tail, the list is: ";

    Node* current = head;
    while (current != nullptr) {
        cout << current->getdata() << " ";
        current = current->getnext();
    }
    cout << endl;

    return 0;
}
