class Solution {
public:    
    int f(int i, int n,vector<int>&a, int maxi, vector<vector<int>>& dp)
    {
        if (i == n){
            return 0;
        }    
        if (dp[i][maxi + 1] != -1){
            return dp[i][maxi + 1];
        }
        int take = 0;
        if (maxi == -1 || a[i] > a[maxi]){
           take = 1 + f(i + 1, n, a, i, dp);
        }
        int nottake = f(i + 1, n, a, maxi, dp);  
        return dp[i][maxi + 1] = max(take, nottake);
    }
public:
    int lengthOfLIS(vector<int>&a)
    {
       int n=a.size();
       vector<vector<int>> dp(n, vector<int>(n + 1, -1));
       return f(0, n, a, -1, dp);
    }
};
