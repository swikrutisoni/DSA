#include<iostream>
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

void inorderTraversal(Node* root){
    if(root==NULL){//intially calls come for the root of tree
        return;
    }
    inorderTraversal(root->left); 
    cout<<root->data<<" ";// root will be printed 
    inorderTraversal(root->right);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;
    cout<<root->right->left->data<<endl;
    cout<<root->right->right->data<<endl;
    cout<<"Inorder Traversal of the tree is: ";

    inorderTraversal(root);

    return 0;
}

