class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int pos, int prev, int n, int m,
              vector<vector<int>>& dp) {

        if(pos == n)
            return 1;

        if(prev != 0 && dp[pos][prev] != -1)
            return dp[pos][prev];

        long long ways = 0;

        for(int x = 1; x <= m; x++) {

            if(prev == 0 ||
               prev % x == 0 ||
               x % prev == 0) {

                ways += solve(pos + 1, x, n, m, dp);
            }
        }

        // ways %= MOD;

        if(prev != 0)
            dp[pos][prev] = ways;

        return ways;
    }

    int count(int n, int m) {

        vector<vector<int>> dp(n + 1,
                               vector<int>(m + 1, -1));

        return solve(0, 0, n, m, dp);
    }
};