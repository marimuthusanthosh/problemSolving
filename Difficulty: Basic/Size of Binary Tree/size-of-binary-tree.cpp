/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int f(Node* root){
        
        if(root==NULL){
            return 0;
        }
        
        return 1+f(root->left)+f(root->right); 
        
    }
    int getSize(Node* root) {
        // code here
        
        
        return f(root);
        
    }
};