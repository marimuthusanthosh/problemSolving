// class Solution {
// public:
//     int minCount = INT_MAX;

//     void f(int i, vector<int>& coins, int amount, int count) {
//         if (amount == 0) {
//             minCount = min(minCount, count);
//             return;
//         }
//         if (amount < 0 || i < 0) {
//             return;
//         }

//         f(i, coins, amount - coins[i], count + 1);
//         f(i - 1, coins, amount, count);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.rbegin(), coins.rend());
//         f(coins.size() - 1, coins, amount, 0);
//         return minCount == INT_MAX ? -1 : minCount;
//     }
// };
class Solution {
public:
    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (amount < 0 || i < 0) return INT_MAX;
        if (dp[i][amount] != -1) return dp[i][amount];

        // Exclude the current coin
        int exclude = f(i - 1, coins, amount, dp);

        // Include the current coin
        int include = INT_MAX;
        if (amount >= coins[i]) {
            int res = f(i, coins, amount - coins[i], dp);
            if (res != INT_MAX) include = 1 + res;
        }
        return dp[i][amount] = min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        
        int result = f(coins.size() - 1, coins, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};