class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, vector<int>& a, int n, int buy) 
    {
        if (i == n) 
        {
            return 0;
        }
        if (dp[i][buy] != -1) 
        {
            return dp[i][buy];
        }
        if (buy == 0) 
        {
            int buyStock = f(i + 1, a, n, 1) - a[i];
            int skipStock = f(i + 1, a, n, 0);
            dp[i][buy] = max(buyStock, skipStock);
        } 
        else 
        {
            int sellStock = a[i] + f(i + 1, a, n, 0);
            int skipSell = f(i + 1, a, n, 1);
            dp[i][buy] = max(sellStock, skipSell);
        }

        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {  
        int n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(2, -1));
        return f(0, prices, n, 0);
    }
};
