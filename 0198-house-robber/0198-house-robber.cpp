class Solution {
public:
    int f(int ind, vector<int>& a, vector<int>& dp) {
        if (ind == 0) return a[0]; 
        if (ind < 0) return 0;  
        if (dp[ind] != -1) return dp[ind];  
        int take = a[ind] + f(ind - 2, a, dp); 
        int nottake = f(ind - 1, a, dp); 
        return dp[ind] = max(take, nottake); 
    }
    int rob(vector<int>& nums) 
    {  
        vector<int> dp(nums.size(), -1);
        return f(nums.size() - 1, nums, dp); 
    }
};