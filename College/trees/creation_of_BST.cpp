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

    Node* insertNode(Node* root, int key) {

    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 8);
    insertNode(root, 3);
    insertNode(root, 10);
    insertNode(root, 1);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);

    cout << "Binary Search Tree created successfully." << endl;

    /*
    Complexity
Case	Time
Best / Balanced	O(log n)
Worst / Skewed	O(n)

Auxiliary space: O(h), due to recursion.*/

    return 0;
}