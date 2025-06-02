class Solution {
public:    
      void f(int i,vector<vector<int>>&ans,int target,vector<int>&d,vector<int>&a)
      {
          if(i==a.size())
          {
              if(target==0)
              {
                ans.push_back(d);
              }
              return ;
          }   
          if(a[i]<=target)
          {
              d.push_back(a[i]);
              f(i,ans,target-a[i],d,a); 
              d.pop_back();
          }  
         f(i+1,ans,target,d,a); 
      }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans; 
        vector<int>d; 
        f(0,ans,target,d,candidates);   
        return ans;
    }
};