class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

       
    //  int maxi=INT_MIN,mini=INT_MAX;
    //   for(int x:nums){

    //     maxi=max(maxi,x);
    //     mini=min(mini,x);
    //   }
    sort(nums.begin(),nums.end());
    int n=nums.size();
    return 1LL*k*(nums[n-1]-nums[0]);

        
    }
};