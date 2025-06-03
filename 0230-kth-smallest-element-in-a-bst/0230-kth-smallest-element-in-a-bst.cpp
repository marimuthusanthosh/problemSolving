class Solution {
public:  
   void f(TreeNode* root,int k,int& c,int& result){
    if(root==NULL){
        return ;
    }
    f(root->left,k,c,result);
      c++;
     if(c==k){
        result=root->val; 
        return ; 
     }
    f(root->right,k,c,result);
   }
    
    int kthSmallest(TreeNode* root, int k) {   
        int c=0,result=0;
        f(root,k,c,result); 
        return result;
    }
};