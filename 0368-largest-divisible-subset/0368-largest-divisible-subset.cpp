class Solution {
public:
    vector<int> ansf;
    vector<int> dp;   

    void f(int i, vector<int>& nums, vector<int>& ans) {
        if (i >= nums.size()) {
            if (ans.size() > ansf.size()) {
                ansf = ans;
            }
            return;
        }
        if ((ans.size() == 0 || nums[i] % ans.back() == 0) && dp[i] < (int)ans.size() + 1) {
            dp[i] = ans.size() + 1;
            ans.push_back(nums[i]);
            f(i + 1, nums, ans);
            ans.pop_back();
        }

        f(i + 1, nums, ans);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        vector<int> ans;
        sort(nums.begin(), nums.end()); 
        dp.resize(nums.size(), -1);   
        f(0, nums, ans);
        return ansf;
    }
};
