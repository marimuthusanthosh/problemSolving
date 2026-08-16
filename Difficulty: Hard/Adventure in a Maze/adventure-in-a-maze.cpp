class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;

    pair<long long, int> f(int i, int j, vector<vector<int>>& grid,
                            vector<vector<pair<long long, int>>>& dp) {
        if (i >= n || j >= n) return {0, INT_MIN}; // out of bounds -> no valid path

        if (i == n - 1 && j == n - 1) return {1, grid[i][j]};

        if (dp[i][j].first != -1) return dp[i][j];

        long long totalCount = 0;
        int maxSum = 0;

        if (grid[i][j] == 1 || grid[i][j] == 3) {
            auto right = f(i, j + 1, grid, dp);
            if (right.first > 0) {
                totalCount = (totalCount + right.first) % MOD;
                maxSum = max(maxSum, grid[i][j] + right.second);
            }
        }
        if (grid[i][j] == 2 || grid[i][j] == 3) {
            auto down = f(i + 1, j, grid, dp);
            if (down.first > 0) {
                totalCount = (totalCount + down.first) % MOD;
                maxSum = max(maxSum, grid[i][j] + down.second);
            }
        }

        return dp[i][j] = {totalCount, maxSum};
    }

    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<pair<long long, int>>> dp(n, vector<pair<long long, int>>(n, {-1, -1}));
        auto res = f(0, 0, grid, dp);
        return {(int)res.first, res.second};
    }
};