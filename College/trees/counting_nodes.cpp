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

    int leftCount = countNodes(root->left);

    int rightCount = countNodes(root->right);

    return 1 + leftCount + rightCount;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << "Number of nodes in the binary tree: " << countNodes(root) << endl;
    return 0;
}
