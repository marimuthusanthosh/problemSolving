class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        map<char,int>mp; 
        
        int l=0,r=0,n=s.length(),maxi=-1;
        
        while(r<n){
            
            mp[s[r]]++;
                
            while(mp.size()>k){
                
                mp[s[l]]--; 
                
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                    l++;
            }
            if(mp.size()==k){
                
                maxi=max(maxi,r-l+1);
            }
            r++;
            
        }
        
        return maxi;
    
    }
};