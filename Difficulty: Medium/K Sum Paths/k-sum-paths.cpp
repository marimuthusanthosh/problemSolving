class Solution {
  public:

    void f(Node *root, int k, long long sum, int &c, 
           unordered_map<long long,int> &mp) {

        if(root == NULL)
            return;

        // add current node value
        sum += root->data;

        // path starting from root
        if(sum == k)
            c++;

        // check prefix sum
        if(mp.find(sum - k) != mp.end())
            c += mp[sum - k];

        // store prefix sum
        mp[sum]++;

        f(root->left, k, sum, c, mp);
        f(root->right, k, sum, c, mp);

        // backtrack
        mp[sum]--;
    }

    int countAllPaths(Node *root, int k) {

        int c = 0;
        long long sum = 0;

        unordered_map<long long,int> mp;

        f(root, k, sum, c, mp);

        return c;
    }
};