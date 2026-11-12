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

int countNodes(Node* root) {

    if (root == NULL) {
        return 0;
    }
    /*
    for just leaf nodes
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
        
    for internal nodes
     if (root->left == NULL && root->right == NULL) {
        return 0;
    }*/

    int leftCount = countNodes(root->left);

    int rightCount = countNodes(root->right);

    return 1/*(for leaf nodes this willl not be there)*/ + leftCount + rightCount;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << "Number of nodes in the binary tree: " << countNodes(root) << endl;
    return 0;
}

/*
Complexity
- Time Complexity: \(O(n)\) — every node is visited once.
- Auxiliary Space Complexity: \(O(h)\) — recursion call stack, where h is the tree height.


5. Counting Leaf Nodes
1. What is a Leaf Node?
A Leaf Node is a node that has no children.

In other words:
- Left child = NULL
- Right child = NULL

We need to count only those nodes that have no children.

Our logic:
1. If root is NULL, return 0.
2. Check whether both left and right children are NULL.
3. If both are NULL, return 1 because we found a leaf node.
4. Otherwise, recursively count leaf nodes in the left and right subtrees.
5. Add both results.
The formula:
[
Leaf(root)=Leaf(left)+Leaf(right)
]

But if the current node is a leaf, return 1.

Counting Internal Nodes in a Binary Tree.
1. What is an Internal Node?
An Internal Node is a node that has at least one child.

Meaning:
- It has a left child, OR
- It has a right child, OR
- It has both children.

We need to count only nodes that have at least one child.

Our conditions:
1. If root == NULL, return 0.
2. If both children are NULL, it's a leaf node, so return 0.
3. Otherwise, count the current node as 1.
4. Recursively count internal nodes in the left and right subtrees.

Formula:
\[
Internal(root)=1+Internal(left)+Internal(right)
\]

Complexity
- Time Complexity: \(O(n)\)
- Auxiliary Space: \(O(h)\), due to recursion.

*/



