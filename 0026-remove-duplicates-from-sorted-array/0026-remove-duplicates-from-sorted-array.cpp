class Solution {
public:
    int removeDuplicates(vector<int>& nums)
     {
        int c=1; 
        int  max=nums[0];  
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=max)
            {
                c++; 
                max=nums[i];  
                ans.push_back(nums[i]);
            }
        } 
        nums.clear(); 
        nums=ans;
        return c;
      }
};