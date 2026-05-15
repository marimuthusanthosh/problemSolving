class Solution {
public:

    // ─── RECURSIVE + MEMOIZATION ──────────────────────────────
    int solve(int n, vector<int>& memo) {
        // Base cases
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (memo[n] != -1) return memo[n];

        int result = n;                       // worst case: press A n times

        // Try breaking at every point b (need min 3 keys: CtrlA+CtrlC+CtrlV)
        // b = number of keys used for multiply block at end
        for (int b = 3; b <= n; b++) {
            // dp[n-b] = A's on screen before multiply block
            // (b-1)   = multiplier (1 CtrlA + 1 CtrlC + (b-2) CtrlV)
            int cur = solve(n - b, memo) * (b - 1);
            result = max(result, cur);
        }

        return memo[n] = result;
    }

    int optimalKeys(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};