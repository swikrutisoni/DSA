/*
Height tells us the longest path from the root to a leaf node.
At every node:
1. Find the height of its left subtree.
2. Find the height of its right subtree.
3. Take whichever is greater.
4. Add 1 for the current node.
Formula:
\[
Height = 1 + \max(LeftHeight, RightHeight)
\]*/

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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(7);

    cout << "Height of the binary tree: " << height(root) << endl;

    return 0;
}