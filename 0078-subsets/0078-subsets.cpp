class Solution {
public: 
    void f(int i, vector<int> &a, vector<int> &ds, vector<vector<int>> &ans) {
        if (i == a.size()) {
            ans.push_back(ds);
            return;
        }

        // Include the current element
        ds.push_back(a[i]);
        f(i + 1, a, ds, ans);
        ds.pop_back();
        f(i + 1, a, ds, ans);

        // Exclude the current element
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ds; 
        vector<vector<int>> ans;
        f(0, nums, ds, ans);
        return ans;
    }  
};
