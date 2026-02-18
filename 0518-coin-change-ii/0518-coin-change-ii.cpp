class Solution {
public:
    
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        
        // ✅ Base cases
        if(amount == 0) return 1;                 // valid combination
        if(amount < 0) return 0;                  // invalid path
        if(i >= coins.size()) return 0;           // no coins left
        
        // ✅ If already computed
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        // ✅ Take coin (stay at same index)
        int take = f(i, amount - coins[i], coins, dp);
        
        // ✅ Skip coin (move to next index)
        int skip = f(i + 1, amount, coins, dp);
        
        return dp[i][amount] = take + skip;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // dp[i][a] = ways to make amount 'a' using coins from index i
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return f(0, amount, coins, dp);
    }
};
