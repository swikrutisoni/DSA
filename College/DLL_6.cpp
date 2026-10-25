//Revesarl of of Double Linked List

//Reversing a doubly linked list = swap next and prev of every node + make the last node the new head.
/*
Node 1:
next = NULL
prev = 2

Node 2:
next = 1
prev = 3

Node 3:
next = 2
prev = 4

Node 4:
next = 3
prev = NULL*/

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* n;
    Node* p;
    Node(int val);
    int getData();
    void setData(int val);
    Node* getNext();
    void setNext(Node* next);
    Node* getPrev();
    void setPrev(Node* prev);
};

Node::Node(int val){
    data = val;
    n = nullptr;
    p = nullptr;
}

int Node::getData(){
    return data;
}

void Node::setData(int val){
    data = val;
}

Node* Node::getNext(){
    return n;
}

void Node::setNext(Node* next){
    n = next;
}

Node* Node::getPrev(){
    return p;
}

void Node::setPrev(Node* prev){
    p = prev;
}

int main(){
    Node *head =  new Node(1);
    cout << head->getData() << endl;
    Node *newNode = new Node(2);
    head->setNext(newNode);
    newNode->setPrev(head);
    cout << newNode->getData() << endl;
    Node *nextNode = new Node(3);
    newNode->setNext(nextNode);
    nextNode->setPrev(newNode);
    cout << nextNode->getData() << endl;
    Node *thirdNode = new Node(4);
    nextNode->setNext(thirdNode);
    thirdNode->setPrev(nextNode);
    cout << thirdNode->getData() << endl;


    
   Node* temp = head;
Node* newHead = nullptr;

while(temp != nullptr){

    Node* nextNode = temp->getNext();

    temp->setNext(temp->getPrev());
    temp->setPrev(nextNode);

    newHead = temp;
    temp = nextNode;
}

cout << "Reversed Doubly Linked List: ";
    Node* current = newHead;
    while(current != nullptr){
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
    return 0;
}

/*
1 ⇄ 2 ⇄ 3 ⇄ 4

We want:

4 ⇄ 3 ⇄ 2 ⇄ 1
1. Start from head
Node* temp = head;

head is pointing to 1.

So:

temp
 ↓
[1] ⇄ [2] ⇄ [3] ⇄ [4]

temp is basically saying: "Which node am I currently working on?"

2. Create newHead
Node* newHead = nullptr;

Initially, we don't know what the new head will be.

newHead → NULL

After reversal, the new head will be 4.

Now the while loop
while(temp != nullptr)

Meaning:

Keep working as long as temp is pointing to a node.

3. Save the original next
Node* nextNode = temp->getNext();

We're currently at Node 1.

Node 1 looks like:

1:
prev = NULL
next = 2

So:

nextNode = 2;

Why save it?

Because we're about to change Node 1's next.

If we don't save 2, we won't know where to go next.

So:

temp
 ↓
[1] ⇄ [2] ⇄ [3] ⇄ [4]
       ↑
    nextNode
4. Swap next
temp->setNext(temp->getPrev());

Node 1 has:

prev = NULL
next = 2

We put prev into next.

So:

next = NULL

Now Node 1:

prev = NULL
next = NULL

But don't panic. We already saved 2 inside nextNode.

5. Swap prev
temp->setPrev(nextNode);

Remember:

nextNode = 2

So now:

Node 1:

next = NULL
prev = 2

Exactly what we want after reversal.

6. Update newHead
newHead = temp;

Currently:

temp = Node 1

So:

newHead = Node 1

This keeps updating as we process nodes.

Eventually:

newHead = Node 4
7. Move temp forward
temp = nextNode;

Remember:

nextNode = 2

So:

temp = 2

Now we work on Node 2.

Then Node 2

Before changing it:

Node 2:

prev = 1
next = 3
Save next:
Node* nextNode = temp->getNext();

So:

nextNode = 3
Swap:
temp->setNext(temp->getPrev());

Now:

next = 1
Swap other side:
temp->setPrev(nextNode);

Now:

prev = 3

So Node 2 becomes:

next → 1
prev → 3

Then:

temp = nextNode;

moves us to Node 3.

The entire process
START

temp = 1

Node 1:
save next = 2
next = NULL
prev = 2
move temp → 2

Node 2:
save next = 3
next = 1
prev = 3
move temp → 3

Node 3:
save next = 4
next = 2
prev = 4
move temp → 4

Node 4:
save next = NULL
next = 3
prev = NULL
move temp → NULL

At the end:

newHead = 4

And the reversed list is:

NULL ← 4 ⇄ 3 ⇄ 2 ⇄ 1 → NULL
The 4 lines you REALLY need to understand
Node* nextNode = temp->getNext();

Save where I'm going next.

temp->setNext(temp->getPrev());

Put old prev into next.

temp->setPrev(nextNode);

Put old next into prev.

temp = nextNode;

Go to the next node I saved earlier.

So mentally remember:

SAVE → SWAP → SWAP → MOVE

That's the whole reversal logic.*/