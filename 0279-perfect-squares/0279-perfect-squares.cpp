class Solution {
public:
    int f(int n, vector<int>& memo) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        int minCount = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            minCount = min(minCount, 1 + f(n - i * i, memo));
        }
        return memo[n] = minCount;
    }

    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return f(n, memo);
    }
};