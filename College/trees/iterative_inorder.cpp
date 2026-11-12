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

vector<int> iterativePostorderTraversal(Node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();

        if(temp->left!=NULL){
            s.push(temp->left);
        }
        if(temp->right!=NULL){
            s.push(temp->right);
        }
    }
        
}