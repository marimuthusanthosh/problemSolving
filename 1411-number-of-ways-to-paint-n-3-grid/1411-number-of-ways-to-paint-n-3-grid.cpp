class Solution {
public:
    static const int MOD = 1e9 + 7;
    
    vector<vector<int>> patterns;
    vector<vector<int>> memo;

    bool validRow(vector<int>& p) {
        return p[0] != p[1] && p[1] != p[2];
    }

    bool compatible(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 3; i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int dfs(int row, int prev, int n) {
        if (row == n) return 1;   // all rows painted
        if (memo[row][prev] != -1) return memo[row][prev];

        long long ways = 0;
        for (int i = 0; i < patterns.size(); i++) {
            if (compatible(patterns[prev], patterns[i])) {
                ways = (ways + dfs(row + 1, i, n)) % MOD;
            }
        }

        return memo[row][prev] = ways;
    }

    int numOfWays(int n) {
        // generate valid patterns
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    vector<int> p = {a, b, c};
                    if (validRow(p)) patterns.push_back(p);
                }
            }
        }

        int m = patterns.size(); // 12
        memo.assign(n, vector<int>(m, -1));

        long long ans = 0;
        // first row is fixed here
        for (int i = 0; i < m; i++) {
            ans = (ans + dfs(1, i, n)) % MOD;
        }

        return ans;
    }
};
