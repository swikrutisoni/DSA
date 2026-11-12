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

int findFloor(Node* root, int key) {

    int floor = -1;

    while (root != NULL) {

        if (root->data == key) {
            floor = root->data;
            return floor;
        }

        if (key < root->data) {
            root = root->left;
        }

        else {
            floor = root->data;
            root = root->right;
        }
    }

    return floor;
}

int main() {

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key = 5;

    cout << "Floor: " << findFloor(root, key);

    return 0;
}

/*# Floor in a Binary Search Tree (BST)

## 1. What is Floor?

The **Floor of a number X** is the greatest number in the BST that is smaller than or equal to X.

In simple words, find the largest value that is either equal to X or smaller than X.

### Example BST

        8
       / \
      4   12
     / \  / \
    2  6 10  14

| X | Floor | Reason |
|---|---|---|
| 5 | 4 | Greatest number smaller than 5 |
| 8 | 8 | Exact match |
| 9 | 8 | Greatest number smaller than 9 |
| 13 | 12 | Greatest number smaller than 13 |
| 1 | -1 | No suitable value exists |

## 2. Logic Behind Finding Floor

We use the Binary Search Tree property:

- Left subtree contains smaller values.
- Right subtree contains greater values.

We maintain a variable called **floor**, initially set to -1.

It stores the best possible answer found so far.

We follow three conditions:

### Case 1: Current node equals the key

If the current node's value is equal to the key, we have found the exact value.

Since Floor can be equal to the key, we return that value immediately.

### Case 2: Key is smaller than the current node

If the key is smaller than the current node:

- The current node cannot be the Floor because it is greater than the key.
- All values in its right subtree will also be greater.
- Therefore, we move to the left subtree.

### Case 3: Key is greater than the current node

This is the most important condition.

If the key is greater than the current node:

- The current node is a possible Floor because it is smaller than the key.
- We store its value in the floor variable.
- However, there might be a larger suitable value in the right subtree.

Therefore, we store the current value as a candidate and move RIGHT to search for a larger possible Floor.

If we find another suitable value, we update the floor variable.

## 3. Dry Run – Find Floor of 5

Consider this BST:

        8
       / \
      4   12
     / \
    2   6

We want to find the Floor of 5.

**Step 1: Current node = 8**

- 5 is smaller than 8.
- 8 cannot be the Floor.
- Move LEFT.

**Step 2: Current node = 4**

- 5 is greater than 4.
- 4 is a possible Floor.
- Store floor = 4.
- Move RIGHT.

**Step 3: Current node = 6**

- 5 is smaller than 6.
- 6 cannot be the Floor.
- Move LEFT.
- Floor remains 4.

**Step 4: Current node = NULL**

- We have reached an empty position.
- Stop searching.
- Return the stored Floor value.

**Final Answer: 4**

Notice how we stored 4 and continued searching for a larger valid value.

## 4. Important Conditions to Remember

| Condition | Action |
|---|---|
| Current node = key | Return current value |
| Key > current node | Store current value in Floor and move RIGHT |
| Key < current node | Move LEFT |
| Current node becomes NULL | Return stored Floor |

## 5. Why Do We Initialize Floor to -1?

Initially, we do not know whether a suitable value exists.

Therefore, we initialize Floor to -1.

Whenever we find a possible Floor, we update it.

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

- Floor means the greatest value smaller than or equal to the given key.
- If the current node equals the key, return it.
- If the key is smaller than the current node, go LEFT.
- If the key is greater than the current node, store the current value as a candidate and go RIGHT.
- Keep updating the candidate whenever a larger valid value is found.
- If no suitable value exists, return -1.

**Remember:** For Floor, when the key is greater than the current node, store the current node and move RIGHT because we are looking for a larger valid answer.*/