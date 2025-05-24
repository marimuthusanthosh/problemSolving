class Solution {
public:
    void f(int i, vector<vector<int>>& ans, int target, vector<int>& d, vector<int>& a) {
        if (target == 0) {
            ans.push_back(d);
            return;
        }
        

        for (int j = i; j < a.size(); ++j) {
            if (j > i && a[j] == a[j - 1]) continue; // Skip duplicates

            if(a[j]>target){
                continue;
            }
            d.push_back(a[j]);
            f(j + 1, ans, target - a[j], d, a); // Move to the next element, avoid reusing the same element
            d.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> d;
        sort(candidates.begin(), candidates.end());
        f(0, ans, target, d, candidates);
        return ans;
    }
};
