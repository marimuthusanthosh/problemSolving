class Solution {
  public:
    bool sameFreq(string& s) {
        map<char, int> mp;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        vector<int> freqs;
        for (auto it : mp) {
            freqs.push_back(it.second);
        }

        sort(freqs.begin(), freqs.end());

        // Case 1: All frequencies are the same
        if (freqs.front() == freqs.back()) {
            return true;
        }

        // Case 2: First frequency is 1 and all other frequencies are equal
        if (freqs[0] == 1 && freqs[1] == freqs.back()) {
            return true;
        }

        // Case 3: All frequencies except the last are equal, and last is bigger by 1
        if (freqs[0] == freqs[freqs.size() - 2] &&
            freqs.back() == freqs[freqs.size() - 2] + 1) {
            return true;
        }

        return false;
    }
};
