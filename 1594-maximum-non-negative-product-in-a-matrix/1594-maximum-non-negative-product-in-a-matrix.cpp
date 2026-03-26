class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<long long, long long> f(int i, int j,
        vector<vector<int>>& grid,
        vector<vector<pair<long long,long long>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        // ✅ Base case
        if(i == n-1 && j == m-1) {
            return {grid[i][j], grid[i][j]};
        }

        // ✅ DP check
        if(dp[i][j].first != LLONG_MIN) {
            return dp[i][j];
        }

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        // 🔽 Move Down
        if(i + 1 < n) {
            auto down = f(i+1, j, grid, dp);

            long long a = down.first * grid[i][j];
            long long b = down.second * grid[i][j];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        // ➡ Move Right
        if(j + 1 < m) {
            auto right = f(i, j+1, grid, dp);

            long long a = right.first * grid[i][j];
            long long b = right.second * grid[i][j];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MAX})
        );

        auto res = f(0, 0, grid, dp);

        if(res.first < 0) return -1;

        return res.first % MOD;
    }
};