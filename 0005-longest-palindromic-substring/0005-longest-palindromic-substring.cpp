class Solution {
public:
    int f(int i, int j, string &s, int &start, int &maxLength, vector<vector<int>>& dp) {   
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 0;
        if (s[i] == s[j]) { 
            int remainingLength = j - i - 1;
            if (remainingLength == f(i + 1, j - 1, s, start, maxLength, dp)) {
                take = 2 + remainingLength;
                if (take > maxLength) {
                    start = i;
                    maxLength = take;
                }
            }
        }
        int nottake_j = f(i, j - 1, s, start, maxLength, dp);
        int nottake_i = f(i + 1, j, s, start, maxLength, dp);
        dp[i][j] = max(take, max(nottake_i, nottake_j));
        return dp[i][j];
    }
    string longestPalindrome(string s) {

        int n = s.length();
        if (n == 0) return "";
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int start = 0, maxLength = 1;
        f(0, n - 1, s, start, maxLength, dp);

     
        return s.substr(start, maxLength);
        
    }
};


// class Solution {
// public:
//     string ans = "";
//     void expand(string &s , int left ,int right)
//     {
//         while(left >= 0 &&  right < s.size())
//         {
//             if(s[left] != s[right])
//                 break;
//             left--,right++;
//         }
//         if(ans.size() < right - left )
//             ans = s.substr(left + 1 , right - left - 1);
//     }
//     string longestPalindrome(string s) {
//         for(int i = 0 ; i < s.size() ; i++)
//         {
//             expand(s , i , i);
//             expand(s , i , i+1);
//         }
//         return ans;
//     }
// };