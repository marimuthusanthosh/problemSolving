class Solution {
public:
    string minWindow(string s, string t) {  
        unordered_map<char, int> freqT;
        int required = t.size(), formed = 0;         
        int minLength = INT_MAX, LeftIndex = 0;
        int l = 0;

        for (char c : t) freqT[c]++;

        for (int r = 0; r < s.size(); r++) {
            
            if (freqT[s[r]]-- > 0) formed++;

            while (formed == required) {  
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    LeftIndex = l;
                }

                if (++freqT[s[l]] > 0){
                     formed--;
                }
                l++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(LeftIndex, minLength);
    }
};