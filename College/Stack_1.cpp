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