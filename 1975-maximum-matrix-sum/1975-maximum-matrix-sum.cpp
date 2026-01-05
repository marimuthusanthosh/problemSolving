class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long sum = 0;
        int mini = INT_MAX;
        int negativeCount = 0;

        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(a[i][j]);
                mini = min(mini, abs(a[i][j]));
                if (a[i][j] < 0) {
                    negativeCount++;
                }
            }
        }

        if (negativeCount % 2 != 0) {
            sum -= 2 * mini;
        }

        return sum;
    }
};
