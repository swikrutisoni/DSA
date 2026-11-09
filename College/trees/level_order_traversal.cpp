#include<iostream>
#include<queue>
//for level order traversal we require a queue data structure. 
/*Put root into queue.
Take the first node.
Remove it from queue.
Store its data in vector.
Put its left child into queue.
Put its right child into queue.
Repeat.
*/
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



vector<int> levelOrderTraversal(Node* root){
    /*vector<int> means a vector that stores integers.
result is its name.
Initially, it is empty.*/
    vector<int> result; //This is where we store our final answer.
    if(root==NULL){
        return result;
    }
    queue<Node*> q; //First, we create a queue.
    q.push(root);//We insert the root node into the queue.
    while(!q.empty()){
        /*
 Keep repeating the code inside the loop as long as the queue is NOT empty.

If the queue has elements, process them.

If the queue becomes empty, stop.*/
        

Node* temp=q.front(); //Take the first node from the queue and let temp point to it.
//front() only sees the first element.
        q.pop();
        result.push_back(temp->data);
        //temp->data means access the data stored inside the node pointed to by temp.

//push_back() adds that data to the end of the vector.
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return result;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;

    vector<int> result=levelOrderTraversal(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}