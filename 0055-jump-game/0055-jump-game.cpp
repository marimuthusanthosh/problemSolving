class Solution {
public:
    vector<int> memo;

    bool f(int i, vector<int>& a, int n) {
        if(memo[n-1]==true){
            return true;
        }
        if (i == n - 1) {
            return true;
        }  
        if (memo[i] != -1) {
            return memo[i];
        }

        for (int j = 1; j <= a[i]; j++) {
            if (i + j < n) {
                if (f(i + j, a, n)) {
                    return memo[i] = true;
                }
            }
        }     
        return memo[i] = false;
    }
    
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        memo = vector<int>(n, -1);
        return f(0, nums, n);
    }
};
