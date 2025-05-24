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
    TreeNode*helper(vector<int>&arr,int low,int high) {
        if(low > high) return NULL;
        int mid = (high+low)/2; 
        TreeNode*root=new TreeNode(arr[mid]);
        root->left=helper(arr,low,mid-1);
        root->right=helper(arr,mid+1,high);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n=arr.size();
        return helper(arr,0,n-1);
    }
};