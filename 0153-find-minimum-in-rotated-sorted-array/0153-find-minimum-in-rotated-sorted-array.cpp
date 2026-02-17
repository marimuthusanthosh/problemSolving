class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid =  (right + left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;  // Search in the right half
            } else {
                right = mid;     // Search in the left half
            }
        } 
        // cout<<right<<" "<<left;
        return nums[left];  // Minimum found at left (or right)
    }
};
