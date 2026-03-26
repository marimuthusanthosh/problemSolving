class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int size = n * m;

        // 🔹 Flatten grid
        vector<int> arr(size);
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[idx++] = grid[i][j] % mod;
            }
        }

        // 🔹 Build answer in 1D
        vector<long long> ans1D(size, 1);

        // Prefix pass (left product)
        long long prefix = 1;
        for(int i = 0; i < size; i++) {
            ans1D[i] = prefix;
            prefix = (prefix * arr[i]) % mod;
        }

        // Suffix pass (right product)
        long long suffix = 1;
        for(int i = size - 1; i >= 0; i--) {
            ans1D[i] = (ans1D[i] * suffix) % mod;
            suffix = (suffix * arr[i]) % mod;
        }

        // 🔹 Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        idx = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = ans1D[idx++];
            }
        }

        return ans;
    }
};