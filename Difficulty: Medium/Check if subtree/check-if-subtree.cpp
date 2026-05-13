class Solution {
public:

    bool same(Node* root1, Node* root2) {

        if (root1 == NULL && root2 == NULL) {
            return true;
        }

        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        if (root1->data != root2->data) {
            return false;
        }

        return same(root1->left, root2->left) &&
               same(root1->right, root2->right);
    }

    bool f(Node* root1, Node* root2) {

        if (root1 == NULL) {
            return false;
        }

        // check identical subtree
        if (same(root1, root2)) {
            return true;
        }

        // search left or right
        return f(root1->left, root2) ||
               f(root1->right, root2);
    }

    bool isSubTree(Node *root1, Node *root2) {

        return f(root1, root2);
    }
};