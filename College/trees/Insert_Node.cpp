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

Node* insertNode(Node* root, int key) {

    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->data) {
        if (root->left == NULL) {
            root->left = new Node(key);
            return root;
        }
        else {
            return insertNode(root->left, key);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = new Node(key);
            return root;
        }
        else {
            return insertNode(root->right, key);
        }
    }
}

int main() {

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key;
    cout << "Enter the element to insert: ";
    cin >> key;

    root =insertNode(root, key);
    cout << "root->data: " << root->data << endl;


    return 0 ;

}