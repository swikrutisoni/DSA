#include<iostream>
using namespace std;

struct Node{
    Node* right;
     Node* left;
     int data;

     Node(int val) {
        data = val;
         left = NULL;
         right = NULL;
     }

    };

    void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}

/*Important BST property
Inorder traversal of a BST always produces values in sorted ascending order, provided the BST follows the usual strict ordering rule.

This is useful when you want to display all BST elements in sorted order.
Complexity
- Time: O(n) — every node is visited once.
- Auxiliary space: O(h) — recursion stack.*/