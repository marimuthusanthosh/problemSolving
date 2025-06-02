class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size() - 1) return 0;  // Reached the last index
        if (dp[i] != -1) return dp[i];       // Return if already computed

        int minJumps = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {

            if (i + j < nums.size()) {

                int jumps = f(i + j, nums, dp);
                if (jumps != INT_MAX) {

                    minJumps = min(minJumps, 1 + jumps);
                    
                }

            }
        }
        return dp[i] = minJumps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);  // Memoization array
        return f(0, nums, dp);
    }
};