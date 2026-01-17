class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0; 
        for(int i=0;i<n-1;i++){
           int m1=abs(points[i+1][0]-points[i][0]);
           int m2=abs(points[i+1][1]-points[i][1]);
           ans=ans+max(m1,m2);
        }
        return ans;
    }
};