class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>>ans;           
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());  
        vector<int>a; 
         int n=intervals.size();   
         int mini = intervals[0][0];
         int last = intervals[0][1];
        for(int i=0;i<n;i++)
        {
          if(last>=intervals[i][0])
          {   
           mini = min(mini, intervals[i][0]);    
           last = max(last, intervals[i][1]);
          }  
          else
          {      
             ans.push_back({mini, last});
             mini = intervals[i][0];
             last = intervals[i][1];
          }      
        }
             ans.push_back({mini, last});
        return ans;   
    }
};