class Solution {
  public:
    int totalElements(vector<int> &a) {
        // code here
        
        int n=a.size(); 
        int l=0,r=0; 
        map<int,int>mp; 
        int maxi=0;
        
        while(r<n){
            
           mp[a[r]]++; 
           
           while(mp.size()>2){
               mp[a[l]]--; 
               
              if(mp[a[l]]==0){
                  mp.erase(a[l]);
              }
               
               l++;
           }
           
           maxi=max(maxi,r-l+1);
           r++;
           
        }
        
        return maxi;
    }
};