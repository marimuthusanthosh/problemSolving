/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    
    
   void f(Node* root, int sum, int c, int& maxi, int& pathLength) {
       
    if (root == NULL) {
        if (c > pathLength || (c == pathLength && sum > maxi)) {
            pathLength = c;
            maxi = sum;
        }
        return;
    }

    sum =sum+ root->data;

    f(root->left, sum, c + 1, maxi, pathLength);
    f(root->right, sum, c + 1, maxi, pathLength);
}

int sumOfLongRootToLeafPath(Node *root) {
    
    int maxi = 0;
    int pathLength = 0;
    f(root, 0, 0, maxi, pathLength);
    return maxi;
}

};