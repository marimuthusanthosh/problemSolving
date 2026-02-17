class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxProd = nums[0]; // Maximum product ending at the current index
        int minProd = nums[0]; // Minimum product ending at the current index
        int result = nums[0];  // Overall maximum product

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                // Swap maxProd and minProd when a negative number is encountered
                swap(maxProd, minProd);
            }

            // Update maxProd and minProd
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            // Update the result with the maximum product so far
            result = max(result, maxProd);
        }

        return result;
    }
};
