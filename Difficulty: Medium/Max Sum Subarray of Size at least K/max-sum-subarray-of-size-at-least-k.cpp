class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        // maxSum[i] = maximum subarray sum ending at i
        vector<int> maxSum(n);
        maxSum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            maxSum[i] = max(arr[i], maxSum[i - 1] + arr[i]);
        }

        // Sum of first window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int ans = windowSum;

        for (int i = k; i < n; i++) {
            // Slide the window
            windowSum += arr[i] - arr[i - k];

            // Length exactly k
            ans = max(ans, windowSum);

            // Length > k
            ans = max(ans, windowSum + maxSum[i - k]);
        }

        return ans;
    }
};