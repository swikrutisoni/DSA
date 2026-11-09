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


Node* deleteNode(Node* root, int key) {

    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = root->right;

        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    Node* result = deleteNode(root->left, 4);
    cout << result->data;

    return 0;
}