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
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

   Node* head = new Node(arr[0]);
   Node* prev = head;

    for(int i=1;i<n;i++){
          Node* newNode = new Node(arr[i]);
          prev->setnext(newNode);
          newNode->setprev(prev);
          prev = newNode;
     }
    
     // Print the doubly linked list
     Node* current = head;
     cout << "Doubly Linked List: ";
     while(current != nullptr){
          cout << current->getdata() << " ";
          current = current->getnext();
     }
     cout << endl;
    
     return 0;
}