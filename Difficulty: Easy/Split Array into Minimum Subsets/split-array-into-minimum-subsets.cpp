class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        int n=arr.size(); 
        int ans=0;
        
        for(int i=1;i<n;i++){
            
            if(arr[i-1]+1!=arr[i]){
                ans++;
            }
        }
        return ans+1;
    }
};
