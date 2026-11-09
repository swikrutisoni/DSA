#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* searchBST(Node* root, int key) {

    while (root != NULL && root->data != key) {

        if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return root;
}

int main() {

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    Node* result = searchBST(root, key);

    if (result != NULL) {
        cout << "Element found: " << result->data;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}