//post order, in order, pre order traversal of binary tree using a single stack
#include <iostream>
#include <stack>
#include <vector>
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

vector<int> preInPostOrderTraversal(Node* root){
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if(root==NULL){
        return {};
    }
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right, 1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
vector<int> result;
    result.insert(result.end(), pre.begin(), pre.end());
    result.insert(result.end(), in.begin(), in.end());
    result.insert(result.end(), post.begin(), post.end());
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = preInPostOrderTraversal(root);
    cout << "Preorder: ";
    for(int i=0; i<result.size()/3; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "Inorder: ";
    for(int i=result.size()/3; i<2*result.size()/3; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "Postorder: ";
    for(int i=2*result.size()/3; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}