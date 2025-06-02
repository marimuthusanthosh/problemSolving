class Solution {
public:
    long long f(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX; // Out of bounds, return a large value
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j]; // Reached the bottom-right corner
        }  
        if(dp[i][j]!=-1) return dp[i][j];
        long long down = grid[i][j] + f(i + 1, j, grid,dp); // Move downward
        long long right = grid[i][j] + f(i, j + 1, grid,dp); // Move rightward
        return dp[i][j]=min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return f(0, 0, grid,dp);
    }
};
