class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {

        int n = arr.size();

        int sum = arr[0];       
        int deleted = 0;        

        int maxi = arr[0];

        for (int i = 1; i < n; i++) {

            int prevSum = sum;

            sum = max(arr[i], sum + arr[i]);

            deleted = max(prevSum, deleted + arr[i]);

            maxi = max(maxi, max(sum, deleted));
        }

        return maxi;
    }
};