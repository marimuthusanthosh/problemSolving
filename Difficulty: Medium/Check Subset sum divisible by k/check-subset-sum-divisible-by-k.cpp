class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Optimization: Pigeonhole Principle
        if (n >= k) return true;
        
        // dp[r] stores whether a subset sum with remainder 'r' modulo k exists
        vector<bool> dp(k, false);
        
        for (int num : arr) {
            // Check if current single element directly matches modulo 0
            if (num % k == 0) return true;
            
            // Create a temporary DP array for current iteration
            vector<bool> temp = dp;
            
            // Include the current element alone
            temp[num % k] = true;
            
            // Combine current element with all previously formed subset remainders
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    temp[(r + num) % k] = true;
                }
            }
            
            dp = temp;
            
            // Early return if a subset sum modulo k == 0 is formed
            if (dp[0]) return true;
        }
        
        return dp[0];
    }
};