class Solution {
public:
    int f(int ind, vector<int>& a, vector<int>& dp) {
        if (ind == 0) return a[0]; 
        if (ind < 0) return 0;  
        if (dp[ind] != -1) return dp[ind];  

        int take = a[ind] + f(ind - 2, a, dp); 
        int nottake = f(ind - 1, a, dp); 
        return dp[ind] = max(take, nottake); 
    }

    int rob(vector<int>& nums) {  
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> temp1, temp2;    
        for (int i = 0; i < n; i++) {    
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }
        
        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
        
        int t1 = f(temp1.size() - 1, temp1, dp1);
        int t2 = f(temp2.size() - 1, temp2, dp2);
        
        return max(t1, t2);
    }
};
