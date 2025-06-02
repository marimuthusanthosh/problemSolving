#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {   
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;
        if (i == m - 1 && j == n - 1) return 1;    
        if (dp[i][j] != -1) return dp[i][j];

        int bottom = f(i + 1, j, m, n, obstacleGrid, dp);
        int right = f(i, j + 1, m, n, obstacleGrid, dp);
        return dp[i][j] = bottom + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Check if the starting point is an obstacle
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, obstacleGrid, dp);
    }
};