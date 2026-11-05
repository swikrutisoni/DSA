#include<iostream>
using namespace std;

int arr[5];
int top = -1;

void push(int value) {
    if (top >= 4) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = value;
    cout << "Pushed: " << value << endl;
}
void pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Popped: " << arr[top--] << endl;
}
void seek(){
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}
void display() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void size() {
    cout << "Stack size: " << top + 1 << endl;
}

int main () {
    push(10);
    push(20);
    push(30);
    display();
    seek();
    size();
    pop();
    display();
    size();
    return 0;
}

/*
Why not just use an array for everything?
[Certain] An array lets you touch any position at any time. A stack or queue deliberately removes that freedom. 
The restriction guarantees order (LIFO or FIFO), so the program is easier to reason about and harder to break. 
Think of a one-way street: the road is the same, but the rule creates predictable traffic. 
Also, stack and queue are ADTs (behaviours), while an array is just one way to store them.

Is a stack a data structure or an ADT?
[Certain] It’s an ADT, defined by its operations (push, pop, peek). You can implement it with an array or a linked list.

why is top initialized to -1 and not zero?
stores the index of the most recent element. In an array, valid indices start at 0, so an empty stack has no valid index,
 and -1 is the natural “points to nothing” value.
 
 Empty check: top == -1 means empty. It reads cleanly and needs no extra variable.
Push: top++ then arr[top] = x. The first push moves top from -1 to 0, which is exactly where the first element belongs.
Full check: top == n - 1, since the last valid index is n-1.
Size: top + 1, because indices start at 0.*/