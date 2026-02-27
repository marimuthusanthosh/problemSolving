class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.length() != t.length())
            return false;

        map<char, char> mp1; // s -> t
        map<char, char> mp2; // t -> s

        for(int i = 0; i < s.length(); i++) {

            // If mapping not exists
            if(mp1.find(s[i]) == mp1.end() &&
               mp2.find(t[i]) == mp2.end()) {

                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else {
                // Check consistency
                if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};