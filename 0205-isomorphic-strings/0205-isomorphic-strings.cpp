// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {

//         if(s.length() != t.length())
//             return false;

//         map<char, char> mp1;
//         map<char, char> mp2; 

//         for(int i = 0; i < s.length(); i++) {

//             if(mp1.find(s[i]) == mp1.end() &&
//                mp2.find(t[i]) == mp2.end()) {

//                 mp1[s[i]] = t[i];
//                 mp2[t[i]] = s[i];
//             }
//             else {
//                 if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
//                     return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.length() != t.length())
            return false;

        int m1[256] = {0};
        int m2[256] = {0};

        for(int i = 0; i < s.length(); i++) {

            if(m1[s[i]] != m2[t[i]])
                return false;

            // store i+1 to avoid default 0 confusion
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};