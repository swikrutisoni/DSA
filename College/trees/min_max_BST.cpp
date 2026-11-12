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

    int findMin(Node* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

/*Complexity
Operation	Time
Find minimum	O(h)
Find maximum	O(h)

- Balanced BST: O(log n)
- Skewed BST: O(n)
Here, h means the height of the tree.*/

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    cout << "Minimum value in the BST: " << findMin(root) << endl;
    cout << "Maximum value in the BST: " << findMax(root) << endl;

    return 0;
}