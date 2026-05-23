/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
public:

    int f(Node* root) {

        if (root == NULL) {
            return 0;
        }

        int val = root->data;

        int left = f(root->left);

        int right = f(root->right);

        root->data = left + right;

        return val + root->data;
    }

    void toSumTree(Node* root) {

        f(root);
    }
};