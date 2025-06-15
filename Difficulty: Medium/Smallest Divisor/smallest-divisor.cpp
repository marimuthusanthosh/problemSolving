class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int k) {
        // Code here
          int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = (right + left) / 2;
            int sum = 0;

            for (int num : nums) {
                sum += (num + mid - 1) / mid; 
            }

            if (sum <= k) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        return ans;
    }
};
