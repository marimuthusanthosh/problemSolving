class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int zeroCount = 0;

        // Calculate the total product of all non-zero elements
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                product *= nums[i];
            } else {
                zeroCount++;
            }
        }

        vector<int> ans(n, 0); // Initialize result vector with 0's

        if (zeroCount > 1) {
            // If there are more than one zero, all products will be zero
            return ans;
        }

        for (int i = 0; i < n; i++) {
            if (zeroCount == 1) {
                // If there's exactly one zero, only the position with zero can have a non-zero product
                if (nums[i] == 0) {
                    ans[i] = product;
                }
            } else {
                // If there are no zeros, calculate the product excluding nums[i]
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};
