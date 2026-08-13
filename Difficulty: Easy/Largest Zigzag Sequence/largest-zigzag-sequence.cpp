class Solution {
public:

    int f(int i, int prev, int n,
          vector<vector<int>>& mat,
          vector<vector<int>>& dp) {

        if (i == n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int ans = 0;

        for (int j = 0; j < n; j++) {

            if (j == prev)
                continue;

            ans = max(ans,
                      mat[i][j] +
                      f(i + 1, j, n, mat, dp));
        }

        return dp[i][prev + 1] = ans;
    }

    int zigzagSequence(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, n, mat, dp);
    }
};