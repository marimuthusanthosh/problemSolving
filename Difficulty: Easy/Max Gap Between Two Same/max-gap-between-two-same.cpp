class Solution {
public:
    int maxCharGap(string &s) {
        
        map<char, pair<int, int>> mp;
        int n = s.length();
        int maxi = -1;

        for (int r = 0; r < n; r++) {

            if (mp.find(s[r]) == mp.end()) {
                
                mp[s[r]] = {r, 1};
            } else {
                
                mp[s[r]].second++;

                maxi = max(maxi, r - mp[s[r]].first - 1);
            }
        }

        return maxi;
    }
};