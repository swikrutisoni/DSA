// insertion of node at begining of linked list
#include<iostream>
using namespace std;


/**/
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

 Node::Node(int value){
    data = value;
    next = nullptr;
 }
int Node::getdata(){
    return data;
}
void Node::setdata(int value){
    cout << "Setting data to: " << value << endl;
    data = value;
}
Node* Node::getnext(){
    return next;
}
void Node::setnext(Node* nextNode){
   
    next = nextNode;
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


     //Make the new node point to the current head
    Node*insertnodeatbegining = new Node(5);
    insertnodeatbegining->setnext(head);
    //after pointing the new node to the current head, we need to update the head also
    head = insertnodeatbegining;
    cout << "Inserted node data: " << head->getdata() << endl;
    

/*Start at head, print the current node's data, move current to current->next, and keep doing this until current becomes nullptr.
That's the entire traversal logic. And this is why your getnext() function exists — it lets you move from one node to the next node.*/
    while(head != nullptr){
        cout << head->getdata() << " ";
        head = head->getnext();
    }



    return 0;
}
