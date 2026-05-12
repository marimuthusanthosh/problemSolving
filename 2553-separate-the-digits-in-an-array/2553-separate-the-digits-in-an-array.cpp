class Solution {
public:

    void solve(int num, vector<int>& ans) {

        if (num >= 10) {
            solve(num / 10, ans);
        }

        ans.push_back(num % 10);
    }

    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {
            solve(num, ans);
        }

        return ans;
    }
};