class Solution {
public:

    int solve(int i, vector<int> &arr, int k, bool buy, vector<vector<int>> &dp) {
        int n = arr.size();

        if (i == n) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        int res = 0;

        if (buy) {
            // Option 1: Buy the stock
            int take = -arr[i] + solve(i + 1, arr, k, false, dp);

            // Option 2: Skip
            int skip = solve(i + 1, arr, k, true, dp);

            res = max(take, skip);
        } else {
            // Option 1: Sell the stock (pay fee here)
            int sell = arr[i]-k + solve(i + 1, arr, k, true, dp);

            // Option 2: Skip
            int skip = solve(i + 1, arr, k, false, dp);

            res = max(sell, skip);
        }

        return dp[i][buy] = res;
    }

    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, arr, k, true, dp);
    }
};