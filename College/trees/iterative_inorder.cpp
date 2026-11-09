// we will be using stack data structure 
//root left right
//stack is last in first out data structure
// first u will take node ka right then left child and push it into stack
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<int> iterativePreorderTraversal(Node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop(); /*
        - s.top() accesses the top node.
- s.pop() removes that node.
For example:

Stack = [1]

After these two lines:
- temp = 1
- Stack = []*/


//Part 6: Store the node's data
   result.push_back(temp->data);
    

   //Part 7: Push the right child
   

       //Part 8: Push the left child
       if(temp->left!=NULL){
           s.push(temp->left);
       }
       if(temp->right!=NULL){
       s.push(temp->right);
   }
       
   
    }
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = iterativePreorderTraversal(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}


