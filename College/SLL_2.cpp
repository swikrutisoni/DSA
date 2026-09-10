//insertion of node in the middle ol SLL
/*
to find the middle:
Step 1: Count how many nodes are there
Step 2: Find the middle position
Step 3: Go to that position
Step 4: Insert the new node
New node → Old next {if we do not do this as 1st step then you have temporarily lost the connection to next node.}
Previous node → New node

Before:
Previous → Next
After:
Previous → New → Next*/

/*
but to know the middle position we need to traverse the list and find out the middle
but there is even a better method like, slow and fast pointers
Both start at head.
->slow moves one node at a time
->fast moves two nodes at a time

### Slow and Fast Pointer Logic

1. Start both **slow** and **fast** pointers from the head.

2. Move **slow by 1 node** at a time.

3. Move **fast by 2 nodes** at a time.

4. Continue until **fast reaches the end** of the linked list.

5. At that point, **slow will be at the middle node**.

### Example

10 → 20 → 30 → 40 → 50 → NULL

* Initially: slow = 10, fast = 10
* After 1st move: slow = 20, fast = 30
* After 2nd move: slow = 30, fast = 50

Therefore, **30 is the middle node**.

### Remember

**Slow → 1 step**
**Fast → 2 steps**
**Fast reaches END → Slow reaches MIDDLE**
*/



#include<iostream>
using namespace std;

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
    Node *thirdNode = new Node(25);
    nextNode->setnext(thirdNode);
    cout << thirdNode->getdata() << endl;
    Node *fourthNode = new Node(40);
    thirdNode->setnext(fourthNode);
    cout << fourthNode->getdata() << endl;
    Node *fifthNode = new Node(50);
    fourthNode->setnext(fifthNode);
    cout << fifthNode->getdata() << endl;

    
   Node* current = head;



    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->getnext() != nullptr) {
        slow = slow->getnext();              // 1 step
        fast = fast->getnext()->getnext();   // 2 steps
    }
    cout << "Middle node data: " << slow->getdata() << endl;
    Node* middleNode = new Node(35);
    middleNode->setnext(slow->getnext());
    slow->setnext(middleNode);
    
    cout<<"list after inserting middle node: "<<endl;
    current = head;
    while (current != nullptr) {
        cout << current->getdata() << " ";
        current = current->getnext();
    }
    

    return 0;
}

/*### Mistakes I Made and Their Solutions

**1. Traversal mein `head` ko move kar diya**

Mistake:
while (head != nullptr)


mein `head = head->getnext()` kiya.

Isse traversal ke end mein `head = nullptr` ho gaya. Phir `slow = head` aur `fast = head` karne par dono `nullptr` ho gaye.

**Solution:**
`head` ko change nahi karna chahiye. Traversal ke liye ek temporary pointer `current` use karo.

head → 10 → 20 → 30 → 40 → NULL

current → 10 → 20 → 30 → 40 → NULL


`current` move hoga, `head` same rahega.

**2. Slow aur Fast ko `head` traverse karne ke baad initialize kiya**

Mistake:

Pehle head se complete traversal
↓
head = nullptr
↓
slow = head
fast = head

**Solution:**
Traversal ke baad bhi `head` first node ko point karna chahiye. Isliye `current` use karo.

**3. Middle find karne se pehle list ka size consider nahi kiya**

Slow-fast method mein:

Slow → 1 node
Fast → 2 nodes

Fast ke end par pahunchne par slow middle par hota hai.

**Note:** Even number of nodes mein 2 middle positions ho sakti hain, isliye question ke according middle choose karna hota hai.

**4. Middle insertion mein links ka order important hai**

Insertion:

Before:
Previous → Next

After:
Previous → New → Next

Pehle:

New → Old Next

Phir:

Previous → New

Agar pehle `Previous → New` kar diya, toh old next node ka connection lose ho sakta hai.

### Main Things to Remember

**Head ko preserve karo → traversal ke liye `current` use karo.**

**Slow = 1 step**

**Fast = 2 steps**

**Fast reaches END → Slow reaches MIDDLE**

**Insertion: New → Old Next, then Previous → New**
*/
