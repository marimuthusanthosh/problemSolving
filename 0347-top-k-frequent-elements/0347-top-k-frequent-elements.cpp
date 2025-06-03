class Solution {
public:
    // Comparator to sort by value
    bool compareByValue(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;  // Sort by frequency (descending)
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;

        // Count frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Convert map to vector of pairs
        vector<pair<int, int>> freqVec(mp.begin(), mp.end());

        // Sort the vector by frequency using the custom comparator
        sort(freqVec.begin(), freqVec.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            return compareByValue(a, b);
        });

        // Add the top k frequent elements to the result
        for (int i = 0; i < k; i++) {
            ans.push_back(freqVec[i].first);
        }

        return ans;
    }
};
