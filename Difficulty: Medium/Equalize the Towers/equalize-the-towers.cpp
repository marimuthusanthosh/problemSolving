class Solution {
  public:
     int findCost(int targ, vector<int>& c, vector<int>& h){
        
        int ans = 0;
        
        for(int i=0;i<c.size() ;i++){
            ans += abs(h[i] - targ) * c[i];
        }
        
        return ans;
    }
  
    int minCost(vector<int>& heights, vector<int>& cost) {
        int l = *min_element(heights.begin() , heights.end());
        int h = *max_element(heights.begin() , heights.end());
        
        int n= cost.size();
        
        int canBeAns = 0;
        while(l<h){
            int mid1 = l+(h-l)/3;
            int mid2 = h-(h-l)/3;
            
            if(findCost(mid1,cost,heights) < findCost(mid2,cost,heights))
            {
                h = mid2-1;
            }else{

                l = mid1+1;
            }
        }
        canBeAns = l;
        return findCost(canBeAns, cost, heights);
    }
};
