class Solution {
public:
    
    int f(int i, int curr, vector<int>& arr, int target, 
          unordered_map<string, int>& dp) {
        
        if (i == arr.size()) {
            return curr == target;
        }

        string key = to_string(i) + "," + to_string(curr);
        if (dp.find(key) != dp.end()) return dp[key];

        int add = f(i + 1, curr + arr[i], arr, target, dp);
        int sub = f(i + 1, curr - arr[i], arr, target, dp);

        return dp[key] = add + sub;
    }

    int totalWays(vector<int>& arr, int target) {
        unordered_map<string, int> dp;
        return f(0, 0, arr, target, dp);
    }
};