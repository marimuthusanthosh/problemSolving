/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:   
  void f(TreeNode* p,TreeNode* q,bool& ans)
  { 
     if(p==NULL&&q!=NULL||(q==NULL&&p!=NULL)) 
       ans=false;
    //    return ;   
      if(p==NULL||q==NULL)
      return ;
    f(p->left,q->left,ans);      
     cout<<p->val<<" "<<q->val;
    if(p->val!=q->val)
      ans=false; 
    f(p->right,q->right,ans); 
    
  }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {  
        bool ans=true;
        f(p,q,ans);  
        return ans;
    }
};