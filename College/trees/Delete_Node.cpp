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

/*# Delete a Node in Binary Search Tree (BST)

## 1. What is BST Deletion?

BST deletion means removing a particular node from a Binary Search Tree while maintaining the BST property.

- Left subtree contains smaller values.
- Right subtree contains greater values.

There are three cases when deleting a node.

## 2. Three Cases of Deletion

### Case 1: Node has no children (Leaf Node)

If the node has no left or right child, simply delete it and return NULL.

Example: Delete 2.

Before:
```text
    4
   /
  2
```

After:
```text
    4
```

### Case 2: Node has only one child

If the node has only one child, replace the node with its existing child.

Example: Delete 4.

Before:
```text
    8
   /
  4
   \
    6
```

After:
```text
    8
   /
  6
```

The child takes the deleted node's position.

### Case 3: Node has two children

If the node has both left and right children, we use the Inorder Successor.

**Inorder Successor:** The smallest value in the right subtree of the node.

Steps:
1. Find the smallest node in the right subtree.
2. Copy its value into the node being deleted.
3. Delete the original inorder successor from the right subtree.

Example: Delete 8.

Before:
```text
       8
      / \
     4   12
    / \  / \
   2  6 10 14
```

The right subtree of 8 contains 12, 10 and 14. Its smallest value is 10.

Replace 8 with 10 and delete the original 10.

After:
```text
       10
      /  \
     4    12
    / \     \
   2   6     14
```

## 3. How Does the Recursive Function Work?

The deletion function follows these steps:

1. If root is NULL, return NULL because the node does not exist.
2. If the key is smaller than root's data, search in the left subtree.
3. If the key is greater than root's data, search in the right subtree.
4. If the key matches root's data, handle one of the three deletion cases.
5. Finally, return root.

## 4. Why Do We Return Root?

The deletion function returns the **root of the updated subtree**, not necessarily the deleted node.

Consider deleting 4 from this tree:

Before:
```text
        8
       / \
      4   12
     / \  / \
    2  6 10 14
```

After:
```text
        8
       / \
      6   12
     /   /  \
    2   10  14
```

The function returns:

- For the subtree rooted at 4: it returns 6.
- For the entire tree rooted at 8: it returns 8.

This happens because the recursive call updates the parent's child pointer.

For example:

`root->left = deleteNode(root->left, key);`

The updated subtree root is assigned back to the parent's left pointer.

**Important:** If the actual root of the entire tree is deleted, the returned value may become the new root.

Therefore, in main(), always write:

`root = deleteNode(root, key);`

This ensures that the root is updated if necessary.

## 5. Difference*/