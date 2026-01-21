class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));

        // prefix sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] = mat[i-1][j-1]
                         + ps[i-1][j]
                         + ps[i][j-1]
                         - ps[i-1][j-1];
            }
        }

        int ans = 0;

        for (int k = 1; k <= min(n, m); k++) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    int sum = ps[i+k][j+k]
                            - ps[i][j+k]
                            - ps[i+k][j]
                            + ps[i][j];
                    if (sum <= threshold)
                        ans = k;
                }
            }
        }

        return ans;
    }
};
