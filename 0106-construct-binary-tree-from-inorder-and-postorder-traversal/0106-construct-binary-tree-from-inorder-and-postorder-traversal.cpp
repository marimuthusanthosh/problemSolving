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
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, 
                            int& postIndex, unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd) {
            return NULL;
        }

        // Get the root node from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of root in inorder
        int inRoot = inorderMap[rootVal];

        // Build right subtree first (since postorder is L-R-Root)
        root->right = constructTree(inorder, postorder, inRoot + 1, inEnd, postIndex, inorderMap);
        root->left = constructTree(inorder, postorder, inStart, inRoot - 1, postIndex, inorderMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();

        // Store inorder values and their indices for quick lookup
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }

        // Postorder index starts at the last element
        int postIndex = n - 1;
        return constructTree(inorder, postorder, 0, n - 1, postIndex, inorderMap);
    }

};
