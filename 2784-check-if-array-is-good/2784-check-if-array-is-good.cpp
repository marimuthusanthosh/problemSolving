class Solution {
public:

    bool isGood(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // minimum valid array is [1,1]
        if (n < 2) {
            return false;
        }

        // last two elements must be same
        if (nums[n - 1] != nums[n - 2]) {
            return false;
        }

        // check 1 to n-1
        for (int i = 0; i < n - 1; i++) {

            if (nums[i] != i + 1) {
                return false;
            }
        }

        return true;
    }
};