class Solution {
  public:
    int smallestSubstring(string s) {
        
        int n = s.size(); 
        int l = 0, r = 0;
        int mini = INT_MAX;
        
        map<char,int> mp;
        
        while(r < n){
            
            mp[s[r]]++;
            
            // shrink window
            while(mp.size() == 3){
                
                mini = min(mini, r - l + 1);
                
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                
                l++;
            }
            
            r++;
        }
        
        return (mini == INT_MAX) ? -1 : mini;
    }
};