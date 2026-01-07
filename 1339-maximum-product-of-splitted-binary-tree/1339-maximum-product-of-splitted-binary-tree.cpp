class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProductVal = 0;

    long long subtreeSum(TreeNode* root) {
        if (!root) return 0;

        long long left = subtreeSum(root->left);
        long long right = subtreeSum(root->right);

        long long curr = left + right + root->val;

        maxProductVal = max(maxProductVal, curr * (totalSum - curr));

        return curr;
    }

    int maxProduct(TreeNode* root) {
        totalSum = subtreeSum(root);   // first pass to get total sum
        maxProductVal = 0;
        subtreeSum(root);              // second pass to compute products
        return maxProductVal % MOD;
    }
};
