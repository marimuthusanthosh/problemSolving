class Solution {
  public:
    int minimumCost(vector<int>& cost, int w) {
        int n = cost.size();

        // dp[i] = min cost to buy exactly i kg
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;                              // 0 kg costs 0

        for (int i = 1; i <= w; i++) {
            for (int j = 0; j < n; j++) {
                int weight = j + 1;              // packet weight
                int price  = cost[j];

                if (price == -1) continue;       // unavailable
                if (weight > i) continue;        // too heavy for current i

                if (dp[i - weight] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - weight] + price);
                }
            }
        }

        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};