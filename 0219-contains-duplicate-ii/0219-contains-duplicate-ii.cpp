class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> mapp;

        for (int i = 0; i < nums.size(); i++) {
            if (mapp.find(nums[i]) != mapp.end() && i - mapp[nums[i]] <= k) 
            {
                return true;
            }
            mapp[nums[i]] = i;
        }
        return false;
    }
};
