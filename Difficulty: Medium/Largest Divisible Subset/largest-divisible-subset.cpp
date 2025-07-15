class Solution {
  public:
    map<pair<int, int>, vector<int>> dp;

    vector<int> f(int i, int j, vector<int>& a) {
        if (j == a.size()) {
            return {};
        }

        if (dp.count({i, j})) {
            return dp[{i, j}];
        }

        vector<int> pick, notPick;

        if (i == -1 || a[j] % a[i] == 0) {
            pick = f(j, j + 1, a);
            pick.insert(pick.begin(), a[j]);
        }

        notPick = f(i, j + 1, a);

        if (pick.size() > notPick.size()) {
            return dp[{i, j}] = pick;
        } else {
            return dp[{i, j}] = notPick;
        }
    }

    vector<int> largestSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        return f(-1, 0, arr);
    }
};
