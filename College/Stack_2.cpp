//implemenation of stack using array 

#include <iostream>
#include <vector>
using namespace std;

class Stack{
private:
    vector<int> arr;
    int top;
public:
    Stack(int n);
    void push(int value);
    void pop();
    int Top();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int n) {
    arr.resize(n);
    top = -1;
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = value;
    cout << "Pushed: " << value << endl;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Popped: " << arr[top--] << endl;
}

int Stack::Top() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1; // Return a sentinel value
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == arr.size() - 1;
}

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.Top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.Top() << endl;
    return 0;
}

/*
vector<int> arr;	Stores the stack elements.
int top;	Tracks the index of the topmost element.
Stack(int n)	Constructor that sets the stack capacity.
arr.resize(n);	Creates n integer positions in the vector.
top = -1;	Initially, the stack is empty.
arr[++top] = value;	Increments top, then inserts the value.
arr[top--]	Accesses the top element, then decrements top.
return top == -1;	Returns true if the stack is empty.
return top == arr.size() - 1;	Returns true if the stack is full.*/