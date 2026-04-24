class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n=arr.size(); 
        int c=0,maxi=arr[0];
        
        for(int i=1;i<n;i++){
            
            if(maxi>arr[i]){
                c++;
            }
            maxi=max(maxi,arr[i]);
        }
        return n-c;
    }
};