class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        
        int n=arr.size();
        
        if(n<2){
            
        return 0;
        }
        
        int l=0, r=1, c=0;
        
        while(r<n){
            
            if(arr[r]>arr[r-1]){
                
                c=c+(r-l);
            }
            else
            {
                
              l=r;
            }
            
            r++;
        }
        return c;
        
    }
};