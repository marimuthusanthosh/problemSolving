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
    int maxLevelSum(TreeNode* root) {
        
        int ans=1,c=1;
        int maxi=root->val; 
        queue<TreeNode*>q; 
        q.push(root);

        while(!q.empty()){
            int sum=0;
             int levelSize=q.size(); 
             for(int i=0;i<levelSize;i++){

                TreeNode* curr=q.front();
                q.pop(); 
                sum=sum+curr->val; 

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
             }


            if(sum>maxi){
                maxi=sum;
                ans=c;
            }
             c++; 
        }

        return ans;
        
    }
};