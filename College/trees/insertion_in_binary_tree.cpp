//We use a Queue because we need to check nodes level by level.

/*Our algorithm:
1. If root is NULL, create a new node and return it.
2. Create a queue.
3. Insert root into the queue.
4. Remove the front node.
5. Check whether its left child is empty.
   - If yes, insert the new node there and stop.
6. Otherwise, insert its left child into the queue.
7. Check whether its right child is empty.
   - If yes, insert the new node there and stop.
8. Otherwise, insert its right child into the queue.
9. Repeat until insertion happens.*/


#include <iostream>
#include <queue>
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

Node* insertNode(Node* root, int val) {

    Node* newNode = new Node(val);

    if (root == NULL) {
        return newNode;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        }
        else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        }
        else {
            q.push(temp->right);
        }
    }

    return root;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int val = 6;

    root = insertNode(root, val);

    cout << "New node inserted: " << val << endl;

    return 0;
}

/*
Why do we return root?

Remember, this is important!

The root pointer is the entry point of our tree. Insertion changes the links between nodes, but usually does not change the root itself.

If the tree was empty, however, we return newNode because that becomes the root.*/