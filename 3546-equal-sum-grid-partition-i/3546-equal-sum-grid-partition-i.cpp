class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = grid[i][j];

                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
            }
        }

        long long total = dp[n-1][m-1];

        if(total % 2 != 0) return false;

        long long target = total / 2;

        for(int i = 0; i < n - 1; i++) {
            long long top = dp[i][m-1];
            if(top == target) return true;
        }

        for(int j = 0; j < m - 1; j++) {
            long long left = dp[n-1][j];
            if(left == target) return true;
        }

        return false;
    }
};