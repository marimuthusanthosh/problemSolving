class Solution {
  public:
    bool kSubstr(string &s, int k) {
        
        
        int n=s.length();
        unordered_map<string, int>mpp;
        
        for(int i=0; i<n; i+=k){
            mpp[s.substr(i, k)]++;
        }
        if(mpp.size()==1)
        {
            return true;
        }
        if(mpp.size()==2){
            
            for(auto &it:mpp){
                
                if(it.second==1){
                    
                    return true;
                }
            }
        }
        return false;        
    }
};