class Solution {
public:
    bool f(int i, int j, const std::string &s, const std::string &p, std::vector<std::vector<int>> &dp) {
        if (i < 0 && j < 0) 
        {
            return true;
        }
        if (j < 0) 
        {
            return false;
        }
        if (i < 0) 
        {
            while (j >= 0 && p[j] == '*'){
             j--; 
            }
            return j < 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[j] == s[i] || p[j] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }
        if (p[j] == '*') 
        {
            return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) 
    {  
        int n = s.length();  
        int m = p.length();
        vector<vector<int>> dp(n,vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};
