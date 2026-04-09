class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        
        int l = 0, r = 0;
        vector<int> ans;

        while (l < a.size() && r < b.size()) {

            if (a[l] < b[r]) {
                l++;
            }
            else if (a[l] > b[r]) {
                r++;
            }
            else {
                // avoid duplicates
                if (ans.empty() || ans.back() != a[l]) {
                    ans.push_back(a[l]);
                }
                l++;
                r++;
            }
        }

        return ans;
    }
};