class Solution {
public:

    bool isGood(vector<int>& nums) {

        map<int,int> mp;

        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            mp[nums[i]]++;

            maxi = max(maxi, nums[i]);
        }

        // size must be n+1
        if (nums.size() != maxi + 1) {
            return false;
        }

        // largest element must appear twice
        if (mp[maxi] != 2) {
            return false;
        }

        // 1 to maxi-1 must appear once
        for (int i = 1; i < maxi; i++) {

            if (mp[i] != 1) {
                return false;
            }
        }

        return true;
    }
};