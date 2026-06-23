class Solution {
  public:
    int maxArea(vector<int> &a) {
        // code here
        int l=0;
        int r=a.size()-1; 
        int maxi=-1;
        int area=a[l]*a[r];
        
        while(l<=r){
            
            
            if(a[l]<a[r]){
                
                area=a[l]*(r-l-1);
                l++;
            }
            else{
                
                area=a[r]*(r-l-1);
                r--;
            }
            maxi=max(maxi,area);
        }
        return maxi;
    }
};