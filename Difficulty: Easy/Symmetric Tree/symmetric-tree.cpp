/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
  
    void f(Node* rootLeft,Node* rootRight,bool &ans){
        
        if (rootLeft == NULL && rootRight == NULL) return;
        
        if(rootLeft==NULL||rootRight==NULL){
            ans = false;
            return ;
        }
        
        f(rootLeft->left,rootRight->right,ans);
        if(rootLeft->data!=rootRight->data){
            ans=false; 
            return;
        }
        f(rootLeft->right,rootRight->left,ans);
        
    }
    bool isSymmetric(Node* root) {
        // Code here
        if (root == NULL) return true;
        bool ans=true;
        f(root->left,root->right,ans);
        return ans;
    }
};