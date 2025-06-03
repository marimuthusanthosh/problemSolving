class Solution {
public: 
    int helper(TreeNode* root, int& maxi) {

        if (root == NULL) {
            return 0;
        }  

        // Calculate left and right branch sums (ignore negative sums)
        int leftSum = max(0, helper(root->left, maxi));
        int rightSum = max(0, helper(root->right, maxi));

        // Update the global maximum with the sum including the current node
        maxi = max(maxi, root->val + leftSum + rightSum);

        // Return the best path sum including the current node
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;  // Stores the max path sum
        helper(root, maxi);
        return maxi;
    }
};