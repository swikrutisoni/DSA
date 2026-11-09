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

Node* searchBST(Node* root, int key) {

    while (root != NULL && root->data != key) {

        if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return root;
}

int main() {

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    int key = 6;

    Node* result = searchBST(root, key);

    if (result != NULL) {
        cout << "Element found: " << result->data;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}

/*
# Ceil in a Binary Search Tree (BST)

## 1. What is Ceil?

The **Ceil of a number X** is the smallest number in the BST that is greater than or equal to X.

In simple words, find the smallest value that is either equal to X or bigger than X.

### Example BST

        8
       / \
      4   12
     / \  / \
    2  6 10  14

| X | Ceil | Reason |
|---|---|---|
| 5 | 6 | Smallest number greater than 5 |
| 8 | 8 | Exact match |
| 9 | 10 | Smallest number greater than 9 |
| 13 | 14 | Smallest number greater than 13 |
| 15 | -1 | No suitable value exists |

## 2. Logic Behind Finding Ceil

We use the Binary Search Tree property:

- Left subtree contains smaller values.
- Right subtree contains greater values.

We maintain a variable called **ceil**, initially set to -1.

It stores the best possible answer found so far.

We follow three conditions:

### Case 1: Current node equals the key

If the current node's value is equal to the key, we have found the exact value.

Since ceil is the smallest value greater than or equal to the key, we return that value immediately.

### Case 2: Key is greater than the current node

If the key is greater than the current node:

- The current node cannot be the ceil because it is smaller than the key.
- All values in its left subtree are also smaller.
- Therefore, we move to the right subtree.

### Case 3: Key is smaller than the current node

This is the most important condition.

If the key is smaller than the current node:

- The current node is a possible ceil because it is greater than the key.
- We store its value in the ceil variable.
- However, there might be a smaller suitable value in the left subtree.

Therefore, we store the current value as a candidate and move LEFT to search for a smaller possible ceil.

If we find another suitable value, we update the ceil variable.

## 3. Dry Run – Find Ceil of 5

Consider this BST:

        8
       / \
      4   12
     / \
    2   6

We want to find the ceil of 5.

**Step 1: Current node = 8**

- 5 is smaller than 8.
- 8 is a possible ceil.
- Store ceil = 8.
- Move LEFT.

**Step 2: Current node = 4**

- 5 is greater than 4.
- 4 cannot be the ceil.
- Move RIGHT.
- Ceil remains 8.

**Step 3: Current node = 6**

- 5 is smaller than 6.
- 6 is a possible ceil.
- Update ceil = 6.
- Move LEFT.

**Step 4: Current node = NULL**

- We have reached an empty position.
- Stop searching.
- Return the stored ceil value.

**Final Answer: 6**

Notice how the answer changed from 8 to 6. We kept searching for a smaller valid candidate.

## 4. Important Conditions to Remember

| Condition | Action |
|---|---|
| Current node = key | Return current value |
| Key > current node | Move RIGHT |
| Key < current node | Store current value in ceil and move LEFT |
| Current node becomes NULL | Return stored ceil |

## 5. Why Do We Initialize Ceil to -1?

Initially, we do not know whether a suitable value exists.

Therefore, we initialize ceil to -1.

Whenever we find a possible ceil, we update it.

If no suitable value is found after searching the BST, the function returns -1.

Note: This convention assumes -1 is not being used as a valid answer in the BST.

## 6. Time and Space Complexity

Let N = Number of nodes and H = Height of the BST.

**Time Complexity: O(H)**

We visit nodes along only one path from the root to a leaf or NULL.

- Balanced BST: O(log N)
- Worst case (skewed BST): O(N)

**Auxiliary Space Complexity: O(1)**

We use an iterative approach and only maintain a few variables. No recursion or extra stack is required.

## 7. Quick Revision

- Ceil means the smallest value greater than or equal to the given key.
- If the current node equals the key, return it.
- If the key is greater than the current node, go RIGHT.
- If the key is smaller than the current node, store the current value as a candidate and go LEFT.
- Keep updating the candidate whenever a smaller valid value is found.
- If no suitable value exists, return -1.

**Remember:** For Ceil, when the key is smaller than the current node, store the current node and move LEFT because we are looking for a smaller valid answer.*/